#!/usr/bin/env python3
"""Decode the texture portion of a .geo asset.

.geo file format (reverse-engineered from MK4.EXE):

  Offset  Size   Field
  ------  -----  ----------------------------------------
  0x00    4      magic 'b"0.1v"'
  0x04    4      uint32 tex_table_offset (offset of texture table)
  0x08    4      uint32 file_size
  0x0C    ???    mesh data (yet to decode)
  ...
  @[04]   2      uint16 tex_count (or 4 bytes? interpretation pending)
  @[04]+2 2      uint16 reserved
  @[04]+4 ...    tex_count entries, each:
                    uint16 width
                    uint16 height
                    uint32 data_size
                    byte   data[data_size]   <- RLE-16

RLE-16 stream (per scanline, fixed dst stride = 256 pixels):
   if (token & 0x8000) == 0:  literal pixel (2 bytes)
   else:                       RLE run: pixel = (token & 0x7fff) ^ xor_key, run_length follows (1 byte, total 3 bytes)
                               token == 0x8000 → run of 0 (transparent)

Pixel format: 16-bit, format presumed RGB-555 or RGB-565 (TBD by visual inspection).

Usage:
    python3 tools/geo_decode.py <file.geo> [tex_index] [out.ppm]
"""
import struct
import sys
from pathlib import Path


def parse_geo_header(data):
    if data[:4] != b"0.1v":
        raise ValueError("not a 0.1v geo file")
    tex_table_offset, file_size = struct.unpack_from("<II", data, 4)
    return tex_table_offset, file_size


def parse_tex_entries(data, tex_table_offset):
    """Yield (w, h, data_offset, data_size) for each texture.

    The 4 bytes at tex_table_offset are a chunk sub-header (purpose unclear -
    differs per file; might be CRC or compile timestamp). The actual table
    starts 4 bytes later. The loader skips them via `*(int *)(buffer+4) + 4`.
    """
    sub_header = data[tex_table_offset:tex_table_offset + 4]
    p = tex_table_offset + 4
    (count,) = struct.unpack_from("<I", data, p)
    p += 4
    print(f"  sub_header bytes: {sub_header.hex()}")
    print(f"  texture count   : {count}")
    for _ in range(count):
        w, h, sz = struct.unpack_from("<HHI", data, p)
        yield w, h, p + 8, sz
        p += 8 + sz


def decode_rle16(src, src_off, src_end, width, height, xor_key=0, dst_stride=256):
    """Returns a (height x dst_stride) array of 16-bit pixels."""
    dst = bytearray(dst_stride * height * 2)
    p = src_off
    for row in range(height):
        x = 0
        row_off = row * dst_stride * 2
        while x < width and p < src_end:
            token = src[p] | (src[p + 1] << 8)
            p += 2
            if (token & 0x8000) == 0:
                # literal pixel
                dst[row_off + x * 2] = token & 0xff
                dst[row_off + x * 2 + 1] = (token >> 8) & 0xff
                x += 1
            else:
                low = token & 0x7fff
                color = (low ^ xor_key) if low != 0 else 0
                run_length = src[p]
                p += 1
                for k in range(run_length):
                    if x + k >= dst_stride:
                        break
                    dst[row_off + (x + k) * 2] = color & 0xff
                    dst[row_off + (x + k) * 2 + 1] = (color >> 8) & 0xff
                x += run_length
    return dst, p


def write_ppm_rgb555(out_path, dst, width, height, dst_stride=256):
    """Write a P6 PPM, interpreting pixels as RGB-555 (5-bit each, top bit = alpha/unused)."""
    with open(out_path, "wb") as f:
        f.write(f"P6\n{width} {height}\n255\n".encode())
        for y in range(height):
            for x in range(width):
                p = dst[y * dst_stride * 2 + x * 2] | (dst[y * dst_stride * 2 + x * 2 + 1] << 8)
                r = ((p >> 10) & 0x1f) << 3
                g = ((p >> 5) & 0x1f) << 3
                b = (p & 0x1f) << 3
                f.write(bytes([r, g, b]))


def write_ppm_rgb565(out_path, dst, width, height, dst_stride=256):
    """Write a P6 PPM, interpreting pixels as RGB-565."""
    with open(out_path, "wb") as f:
        f.write(f"P6\n{width} {height}\n255\n".encode())
        for y in range(height):
            for x in range(width):
                p = dst[y * dst_stride * 2 + x * 2] | (dst[y * dst_stride * 2 + x * 2 + 1] << 8)
                r = ((p >> 11) & 0x1f) << 3
                g = ((p >> 5) & 0x3f) << 2
                b = (p & 0x1f) << 3
                f.write(bytes([r, g, b]))


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        sys.exit(1)
    geo_path = Path(sys.argv[1])
    tex_idx = int(sys.argv[2]) if len(sys.argv) > 2 else 0
    data = geo_path.read_bytes()
    tex_off, file_size = parse_geo_header(data)
    print(f"file: {geo_path.name}")
    print(f"  tex_table_offset = 0x{tex_off:x}")
    print(f"  file_size        = {file_size} (actual: {len(data)})")

    entries = list(parse_tex_entries(data, tex_off))
    print(f"  texture entries  = {len(entries)}")
    for i, (w, h, doff, sz) in enumerate(entries):
        marker = " <-- decode" if i == tex_idx else ""
        print(f"    [{i}] {w}x{h}  data@0x{doff:08x}  size={sz}{marker}")

    if not entries or tex_idx >= len(entries):
        return
    w, h, doff, sz = entries[tex_idx]
    dst, consumed = decode_rle16(data, doff, doff + sz, w, h, xor_key=0, dst_stride=256)
    print(f"  consumed {consumed - doff} of {sz} bytes")

    out_555 = Path(sys.argv[3]) if len(sys.argv) > 3 else Path("/tmp/geo_tex_555.ppm")
    out_565 = out_555.with_suffix(".565.ppm")
    write_ppm_rgb555(out_555, dst, w, h)
    write_ppm_rgb565(out_565, dst, w, h)
    print(f"\nwrote: {out_555}  (RGB-555)")
    print(f"wrote: {out_565}  (RGB-565)")


if __name__ == "__main__":
    main()
