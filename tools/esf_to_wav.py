#!/usr/bin/env python3
"""Convert MK4 .esf audio files to standard .wav.

Format (reverse-engineered from MK4.EXE's ESF_Open at 0x004b1090):

    offset  size  field
    0       4     magic = 'E','S','F',0x06  (= 0x06465345 LE)
    4       4     header DWORD:
                    bits 0..28 : data byte count
                    bit 29     : 0=8-bit / 1=16-bit
                    bit 30     : 0=11025 Hz / 1=22050 Hz
                    bit 31     : mono(0) / stereo(1)
    8       N     raw PCM samples
                    8-bit  : unsigned, centered at 128
                    16-bit : signed (little-endian)

Usage:
    python3 tools/esf_to_wav.py <input.esf> [<output.wav>]
    python3 tools/esf_to_wav.py --batch <input_dir> <output_dir>
"""
import struct
import sys
from pathlib import Path

ESF_MAGIC = 0x06465345

# Standard IMA ADPCM tables, verified to match MK4's tables at 0x004f44e0 / 0x004f4520
IMA_INDEX_TABLE = [-1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8]
IMA_STEP_TABLE = [
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118, 130, 143, 157, 173, 190, 209, 230,
    253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658, 724, 796, 876, 963,
    1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024,
    3327, 3660, 4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493,
    10442, 11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623,
    27086, 29794, 32767,
]
assert len(IMA_INDEX_TABLE) == 16
assert len(IMA_STEP_TABLE) == 89


def decode_ima_adpcm(encoded: bytes, output_byte_count: int) -> bytes:
    """Decode MK4's IMA-style ADPCM. Initial state (predictor=0, step_index=0).

    Reverse-engineered from FUN_004ac200 in MK4.EXE — high nibble first, then
    low nibble. Produces signed 16-bit PCM little-endian.
    """
    out = bytearray(output_byte_count)
    # Cap by the actual encoded bytes (each byte contributes 2 nibbles = 2 samples).
    # Some files declare a decoded size 1 sample bigger than encoded * 2 — stop short.
    max_samples_from_input = len(encoded) * 2
    n_samples = min(output_byte_count // 2, max_samples_from_input)
    predictor = 0
    step_index = 0
    step = IMA_STEP_TABLE[step_index]
    out_off = 0
    src_off = 0
    nibble_high = False
    cur_byte = 0
    for _ in range(n_samples):
        if not nibble_high:
            if src_off >= len(encoded):
                break
            cur_byte = encoded[src_off]
            src_off += 1
            nibble = cur_byte >> 4
        else:
            nibble = cur_byte & 0xF
        nibble_high = not nibble_high

        step_index += IMA_INDEX_TABLE[nibble & 0xF]
        if step_index < 0:
            step_index = 0
        elif step_index > 88:
            step_index = 88

        diff = step >> 3
        if nibble & 4: diff += step
        if nibble & 2: diff += step >> 1
        if nibble & 1: diff += step >> 2
        if nibble & 8: diff = -diff

        predictor += diff
        if predictor > 32767: predictor = 32767
        elif predictor < -32768: predictor = -32768

        step = IMA_STEP_TABLE[step_index]
        out[out_off]     = predictor & 0xFF
        out[out_off + 1] = (predictor >> 8) & 0xFF
        out_off += 2
    return bytes(out)


def parse_esf(data: bytes):
    if len(data) < 8:
        raise ValueError("file too short for ESF header")
    magic, header = struct.unpack_from('<II', data, 0)
    if magic != ESF_MAGIC:
        raise ValueError(f"bad magic 0x{magic:08x}, expected 0x{ESF_MAGIC:08x}")
    bits = 16 if (header >> 29) & 1 else 8
    rate = 22050 if (header >> 30) & 1 else 11025
    stereo = (header >> 31) & 1
    channels = 2 if stereo else 1
    if bits == 8:
        # 8-bit raw PCM, unsigned, centered at 128
        data_size = header & 0x1FFFFFFF
        pcm = data[8:8 + data_size]
    else:
        # 16-bit IMA ADPCM (4:1 compression)
        encoded_size = (header >> 2) & 0x07FFFFFF
        decoded_size = header & 0x1FFFFFFF
        encoded = data[8:8 + encoded_size]
        pcm = decode_ima_adpcm(encoded, decoded_size)
    return bits, rate, channels, pcm


def write_wav(out_path: Path, bits: int, rate: int, channels: int, pcm: bytes):
    bytes_per_sample = bits // 8
    block_align = channels * bytes_per_sample
    byte_rate = rate * block_align
    data_size = len(pcm)
    riff_size = 36 + data_size

    with open(out_path, 'wb') as f:
        f.write(b'RIFF')
        f.write(struct.pack('<I', riff_size))
        f.write(b'WAVE')
        f.write(b'fmt ')
        f.write(struct.pack('<IHHIIHH',
                            16,             # subchunk1 size
                            1,              # PCM format
                            channels,
                            rate,
                            byte_rate,
                            block_align,
                            bits))
        f.write(b'data')
        f.write(struct.pack('<I', data_size))
        f.write(pcm)


def convert(in_path: Path, out_path: Path):
    bits, rate, channels, pcm = parse_esf(in_path.read_bytes())
    write_wav(out_path, bits, rate, channels, pcm)
    return bits, rate, channels, len(pcm)


def main():
    args = sys.argv[1:]
    if not args:
        print(__doc__)
        sys.exit(1)
    if args[0] == '--batch':
        if len(args) != 3:
            print("usage: --batch <input_dir> <output_dir>")
            sys.exit(1)
        in_dir, out_dir = Path(args[1]), Path(args[2])
        out_dir.mkdir(parents=True, exist_ok=True)
        n_ok = n_fail = 0
        for esf in sorted(in_dir.glob('*.esf')):
            wav = out_dir / (esf.stem + '.wav')
            try:
                convert(esf, wav)
                n_ok += 1
            except Exception as e:
                print(f"  FAIL {esf.name}: {e}")
                n_fail += 1
        print(f"\n{n_ok} OK, {n_fail} fail")
    else:
        in_path = Path(args[0])
        out_path = Path(args[1]) if len(args) > 1 else in_path.with_suffix('.wav')
        bits, rate, channels, n = convert(in_path, out_path)
        print(f"OK  {bits}-bit {rate} Hz {'stereo' if channels==2 else 'mono'}, "
              f"{n} samples → {out_path}")


if __name__ == '__main__':
    main()
