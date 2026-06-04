# WASM / Web backend (TARGET=web)

Browser port via Emscripten: WebGL rasterizer + WebAudio + the Emscripten
virtual filesystem, driven by emscripten_set_main_loop. Implements the
contract in ../README.md. Build with `make wasm` (TARGET=web + emcc).

Status: stub. This is the ONLY WASM-specific code in the tree - everything
else (engine, memory model, converted C) is shared across backends.
