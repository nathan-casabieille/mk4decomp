"""fix_missing_externs.py - add missing extern declarations to __asm files.

For each .c file under src/ that contains __asm blocks, this script:
1. Parses every __asm block to find all symbols that MSVC must have declared:
   - direct calls/jumps:  call NAME, jmp NAME
   - memory operands:     dword/byte/word ptr [NAME]
   - address-of:          offset NAME / OFFSET NAME
2. Determines which of those symbols are NOT yet visible in the translation unit
   (via explicit extern declarations, via #includes, or defined in the file itself).
3. Looks up each missing symbol in the project-wide symbol database to decide
   whether it is a data global or a function.
4. Inserts the missing extern declarations (sorted, grouped) just before the first
   __declspec(naked) in the file.
5. Prints a per-file summary.

Run from the repository root:
    python3 tools/decomp/fix_missing_externs.py

Or target a subset:
    python3 tools/decomp/fix_missing_externs.py src/boot/app_init_misc8.c ...
"""

import re
import sys
from pathlib import Path

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------
ROOT = Path(__file__).resolve().parent.parent.parent
SRC_DIR = ROOT / "src"
INCLUDE_DIR = ROOT / "include"
DATA_C = SRC_DIR / "data.c"
STUBS_C = SRC_DIR / "stubs.c"
SYMBOLS_YAML = ROOT / "config" / "symbols.yaml"

# ---------------------------------------------------------------------------
# Registers and keywords to exclude from symbol extraction
# ---------------------------------------------------------------------------
X86_REGISTERS = frozenset({
    "eax", "ebx", "ecx", "edx", "esi", "edi", "esp", "ebp",
    "ax", "bx", "cx", "dx", "si", "di", "sp", "bp",
    "al", "bl", "cl", "dl", "ah", "bh", "ch", "dh",
    "st", "st0", "st1", "st2", "st3", "st4", "st5", "st6", "st7",
    "cs", "ds", "es", "fs", "gs", "ss",
    "cr0", "cr2", "cr3", "cr4",
    "dr0", "dr1", "dr2", "dr3", "dr6", "dr7",
    "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7",
    "mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7",
})

ASM_KEYWORDS = frozenset({
    "call", "jmp", "je", "jne", "jz", "jnz", "jl", "jle", "jg", "jge",
    "ja", "jae", "jb", "jbe", "js", "jns", "jo", "jno", "jp", "jnp",
    "jc", "jnc", "jcxz", "jecxz",
    "push", "pop", "mov", "lea", "add", "sub", "and", "or", "xor",
    "not", "neg", "mul", "imul", "div", "idiv", "inc", "dec",
    "cmp", "test", "shl", "shr", "sal", "sar", "rol", "ror",
    "rcl", "rcr", "nop", "ret", "retf", "iret",
    "rep", "repe", "repne", "repnz", "repz",
    "movsb", "movsw", "movsd", "lodsb", "lodsw", "lodsd",
    "stosb", "stosw", "stosd", "scasb", "scasw", "scasd",
    "cmpsb", "cmpsw", "cmpsd",
    "fld", "fst", "fstp", "fild", "fist", "fistp",
    "fadd", "faddp", "fsub", "fsubp", "fsubr", "fsubrp",
    "fmul", "fmulp", "fdiv", "fdivp", "fdivr", "fdivrp",
    "fabs", "fchs", "fsqrt", "fsin", "fcos",
    "fcom", "fcomp", "fcompp", "ftst", "fucom", "fucomp",
    "fxch", "ffree", "fwait", "fnop",
    "dword", "word", "byte", "qword", "ptr",
    "short", "SHORT", "long", "LONG",
    "offset", "OFFSET",
    "near", "far",
})

# C keywords that might appear in non-asm context
C_KEYWORDS = frozenset({
    "if", "else", "while", "for", "do", "return", "break", "continue",
    "int", "void", "char", "unsigned", "signed", "short", "long", "float",
    "double", "const", "static", "extern", "inline", "typedef", "struct",
    "union", "enum", "sizeof", "NULL",
    "If", "Else",  # sometimes seen in comment text
})

# Win32 API function names - these get resolved via windows.h include
# and don't need explicit extern declarations
WIN32_API_NAMES = frozenset({
    "CloseHandle", "GetDriveTypeA", "GetModuleFileNameA",
    "QueryPerformanceCounter", "QueryPerformanceFrequency",
    "timeBeginPeriod", "timeEndPeriod", "timeSetEvent", "timeKillEvent",
    "CreateThread", "ExitProcess", "GetLastError", "SetLastError",
    "GetCurrentProcess", "GetCurrentThread", "GetCurrentThreadId",
    "OpenMutexA", "CreateMutexA", "WaitForSingleObject",
    "EnterCriticalSection", "LeaveCriticalSection",
    "InitializeCriticalSection", "DeleteCriticalSection",
    "Sleep", "SuspendThread", "ResumeThread", "TerminateThread",
    "LoadLibraryA", "FreeLibrary", "GetProcAddress",
    "GetModuleHandleA", "GetCommandLineA", "GetStartupInfoA",
    "GetVersion", "GetVersionExA",
    "VirtualAlloc", "VirtualFree", "VirtualProtect",
    "GlobalAlloc", "GlobalFree", "GlobalLock", "GlobalUnlock",
    "HeapCreate", "HeapAlloc", "HeapFree", "HeapDestroy",
    "FlushFileBuffers", "SetConsoleCtrlHandler",
    "GetStdHandle", "SetStdHandle",
    "CreateFileA", "ReadFile", "WriteFile",
    "CreateFileMappingA", "MapViewOfFile", "UnmapViewOfFile",
    "SetWindowTextA", "MessageBoxA", "ShowWindow",
    "SendMessageA", "PostMessageA", "PostQuitMessage",
    "PeekMessageA", "GetMessageA", "TranslateMessage", "DispatchMessageA",
    "DefWindowProcA", "RegisterClassA", "CreateWindowExA",
    "DestroyWindow", "GetClientRect", "GetDC", "ReleaseDC",
    "GetDeviceCaps", "GetAsyncKeyState", "GetCursorPos",
    "SetCursorPos", "ShowCursor", "ClipCursor",
    "GdiFlush", "BitBlt", "StretchBlt",
    "DirectDrawCreate", "DirectDrawEnumerateA",
    "DirectSoundCreate", "DirectSoundEnumerateA",
    "mciSendStringA", "mciSendCommandA",
    "waveOutOpen", "waveOutClose", "waveOutPrepareHeader",
    "waveOutUnprepareHeader", "waveOutWrite", "waveOutReset",
    "RegOpenKeyExA", "RegCloseKey", "RegQueryValueExA",
    "RegSetValueExA", "RegCreateKeyExA",
    "OutputDebugStringA",
    # CRT names that appear as calls in asm
    "malloc", "free", "calloc", "realloc",
    "printf", "sprintf", "vsprintf", "fprintf", "vfprintf",
    "strcpy", "strncpy", "strcat", "strncat", "strcmp", "strncmp",
    "strlen", "strchr", "strrchr", "strstr", "strtol", "strtoul",
    "memcpy", "memmove", "memset", "memcmp",
    "fopen", "fclose", "fread", "fwrite", "fseek", "ftell",
    "exit", "abort", "rand", "srand", "atoi", "atof", "atol",
    "cos", "sin", "tan", "atan", "atan2", "sqrt", "fabs", "pow",
    "floor", "ceil",
})

# ---------------------------------------------------------------------------
# Step 1: Build project-wide symbol database
# ---------------------------------------------------------------------------

def build_symbol_db():
    """Return (fn_names: set, data_names: set, all_names: set).

    fn_names:   symbols that are functions (should get extern void NAME(void);)
    data_names: symbols that are data globals (should get extern unsigned int NAME;)
    all_names:  union of both
    """
    fn_names = set()
    data_names = set()

    # --- data.c: pick up all global variable definitions ---
    # Patterns: "unsigned int NAME" / "const unsigned int NAME" / "int NAME" / etc.
    data_def_re = re.compile(
        r'^(?:const\s+)?(?:unsigned\s+)?(?:int|char|short|long|u32|u16|u8|s32|s16|s8|float|double)\s+'
        r'([A-Za-z_][A-Za-z0-9_]*)\s*(?:=|\[|;)'
    )
    if DATA_C.exists():
        for line in DATA_C.read_text(encoding='utf-8', errors='replace').splitlines():
            line = line.strip()
            m = data_def_re.match(line)
            if m:
                data_names.add(m.group(1))

    # --- stubs.c: pick up extern global + function stub definitions ---
    stub_fn_re = re.compile(
        r'__declspec\(naked\)\s+(?:void|int|unsigned int|s32|u32)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\('
    )
    stub_data_re = re.compile(
        r'^(?:const\s+)?(?:unsigned\s+)?(?:int|char)\s+([A-Za-z_][A-Za-z0-9_]*)\s*[;=\[]'
    )
    if STUBS_C.exists():
        for line in STUBS_C.read_text(encoding='utf-8', errors='replace').splitlines():
            stripped = line.strip()
            m = stub_fn_re.search(stripped)
            if m:
                fn_names.add(m.group(1))
            else:
                m2 = stub_data_re.match(stripped)
                if m2:
                    data_names.add(m2.group(1))

    # --- symbols.yaml: all named functions ---
    # We only need the name: lines
    if SYMBOLS_YAML.exists():
        yaml_name_re = re.compile(r'^\s+name:\s+([A-Za-z_][A-Za-z0-9_]*)\s*$')
        for line in SYMBOLS_YAML.read_text(encoding='utf-8', errors='replace').splitlines():
            m = yaml_name_re.match(line)
            if m:
                fn_names.add(m.group(1))

    # --- scan all src/**/*.c for function definitions and data globals ---
    fn_def_re = re.compile(
        r'^(?:__declspec\s*\(naked\)\s+)?(?:static\s+)?'
        r'(?:void|int|unsigned int|unsigned\s+int|s32|u32|s8|u8|s16|u16|s64|u64|float|double|long|char)\s+'
        r'([A-Za-z_][A-Za-z0-9_]*)\s*\('
    )
    # Also catch __stdcall / __cdecl annotations
    fn_def_re2 = re.compile(
        r'^(?:__declspec\s*\(naked\)\s+)?(?:static\s+)?'
        r'(?:void|int|s32|u32|long)\s+(?:__stdcall|__cdecl)\s+'
        r'([A-Za-z_][A-Za-z0-9_]*)\s*\('
    )
    src_data_re = re.compile(
        r'^(?:const\s+)?(?:unsigned\s+)?(?:int|char|short|u32|u16|u8|s32|s16|s8)\s+'
        r'([A-Za-z_][A-Za-z0-9_]*)\s*(?:=|\[|;)'
    )

    for c_file in SRC_DIR.rglob("*.c"):
        if c_file == DATA_C or c_file == STUBS_C:
            continue
        try:
            text = c_file.read_text(encoding='utf-8', errors='replace')
        except Exception:
            continue
        for line in text.splitlines():
            stripped = line.strip()
            # function definition
            m = fn_def_re.match(stripped) or fn_def_re2.match(stripped)
            if m:
                fn_names.add(m.group(1))
                continue
            # data global at file scope (simple check - no indent)
            if not line.startswith(' ') and not line.startswith('\t'):
                m2 = src_data_re.match(stripped)
                if m2:
                    data_names.add(m2.group(1))

    # --- scan all include/*.h files for extern declarations ---
    extern_fn_re = re.compile(
        r'(?:extern\s+)?(?:void|int|s32|u32|s8|u8|s16|u16|float|double|char)\s+'
        r'(?:\*\s*)?([A-Za-z_][A-Za-z0-9_]*)\s*\('
    )
    extern_data_re = re.compile(
        r'^extern\s+(?:const\s+)?(?:unsigned\s+)?'
        r'(?:int|char|short|long|u32|u16|u8|s32|s16|s8|float|double|void\s*\*)\s+'
        r'(?:\*\s*)?([A-Za-z_][A-Za-z0-9_]*)\s*[\[;]'
    )
    for h_file in INCLUDE_DIR.rglob("*.h"):
        try:
            text = h_file.read_text(encoding='utf-8', errors='replace')
        except Exception:
            continue
        for line in text.splitlines():
            stripped = line.strip()
            m = extern_fn_re.match(stripped)
            if m:
                fn_names.add(m.group(1))
            m2 = extern_data_re.match(stripped)
            if m2:
                data_names.add(m2.group(1))

    # Symbols defined in both should not be in data_names if they're clearly functions
    # (symbols.yaml is authoritative for functions)
    data_names -= fn_names

    all_names = fn_names | data_names
    return fn_names, data_names, all_names


# ---------------------------------------------------------------------------
# Step 2: Collect what is already declared in a translation unit
# ---------------------------------------------------------------------------

# Cache of what each header exports (set of symbol names)
_header_symbol_cache: dict[Path, set] = {}


def _symbols_from_header(h_path: Path) -> set:
    """Return set of symbol names declared in the given header (recursively)."""
    if h_path in _header_symbol_cache:
        return _header_symbol_cache[h_path]

    result: set = set()
    _header_symbol_cache[h_path] = result  # break cycles

    if not h_path.exists():
        return result

    try:
        text = h_path.read_text(encoding='utf-8', errors='replace')
    except Exception:
        return result

    # Recurse into sub-includes
    inc_re = re.compile(r'^\s*#include\s+"([^"]+)"')
    for line in text.splitlines():
        m = inc_re.match(line)
        if m:
            sub = h_path.parent / m.group(1)
            if not sub.exists():
                sub = INCLUDE_DIR / m.group(1)
            result |= _symbols_from_header(sub)

    # Collect declared names from the header itself
    any_name_re = re.compile(r'\b([A-Za-z_][A-Za-z0-9_]*)\b')
    decl_line_re = re.compile(
        r'(?:extern\s+)?'
        r'(?:const\s+)?(?:unsigned\s+)?'
        r'(?:void|int|char|short|long|float|double|'
        r'u32|u16|u8|s32|s16|s8|s64|u64|'
        r'packed_ptr|bam16|fx12|rgb555|'
        r'HANDLE|HWND|HINSTANCE|DWORD|UINT|WPARAM|LPARAM|LRESULT|BOOL|ATOM|'
        r'LSTATUS|HRESULT|LPCSTR|LPSTR|LPVOID|LPDWORD|HDC|HBRUSH|HCURSOR|'
        r'HICON|HMENU|HMODULE|HKEY|LPOLESTR)'
        r'[\s\*]+([A-Za-z_][A-Za-z0-9_]*)'
        r'\s*[\(;\[]'
    )
    for line in text.splitlines():
        stripped = line.strip()
        if stripped.startswith('//') or stripped.startswith('*') or stripped.startswith('/*'):
            continue
        m = decl_line_re.match(stripped)
        if m:
            result.add(m.group(1))
        # Also pick up #define names that might be used in asm (rare)
        if stripped.startswith('#define '):
            parts = stripped.split()
            if len(parts) >= 2:
                result.add(parts[1].rstrip('('))

    return result


def get_visible_symbols(c_file: Path) -> set:
    """Return set of symbol names that are visible in the given .c file.

    Includes:
    - Symbols from all #included headers (transitively)
    - Explicitly extern'd names in the file
    - Names defined in the file itself (functions, data, local vars, labels)
    """
    visible: set = set()

    try:
        text = c_file.read_text(encoding='utf-8', errors='replace')
    except Exception:
        return visible

    lines = text.splitlines()

    # Follow #include directives
    inc_re = re.compile(r'^\s*#include\s+"([^"]+)"')
    inc_sys_re = re.compile(r'^\s*#include\s+<[^>]+>')

    for line in lines:
        # User includes - resolve relative to src/ parent or include/
        m = inc_re.match(line)
        if m:
            inc_name = m.group(1)
            # Try relative to the file's directory
            candidate = c_file.parent / inc_name
            if not candidate.exists():
                candidate = INCLUDE_DIR / inc_name
            visible |= _symbols_from_header(candidate)
        # System includes (windows.h etc.) - add known Win32 names
        if inc_sys_re.match(line):
            visible |= WIN32_API_NAMES

    # Collect all names from extern declarations in the file
    extern_re = re.compile(
        r'^extern\s+(?:const\s+)?(?:unsigned\s+)?'
        r'\S.*?\s+(?:\(\s*\*\s*)?([A-Za-z_][A-Za-z0-9_]*)'
        r'\s*[\[;(]'
    )
    extern_fn_re = re.compile(
        r'^extern\s+(?:const\s+)?(?:unsigned\s+)?'
        r'(?:void|int|s32|u32|char|short|long|float|double|'
        r'u8|u16|u64|s8|s16|s64|packed_ptr)\s+'
        r'(?:\(\s*__stdcall\s*\*\s*)?([A-Za-z_][A-Za-z0-9_]*)'
        r'\s*[\[;(]'
    )

    for line in lines:
        stripped = line.strip()
        # Skip comments
        if stripped.startswith('//') or stripped.startswith('*') or stripped.startswith('/*'):
            continue
        m = extern_fn_re.match(stripped)
        if m:
            visible.add(m.group(1))

    # Collect names defined in the file (function definitions, data defs, labels)
    # This prevents us from adding externs for things defined in the same file.
    fn_def_re = re.compile(
        r'^(?:__declspec\s*\(naked\)\s+)?(?:static\s+)?'
        r'(?:const\s+)?(?:unsigned\s+)?'
        r'(?:void|int|char|short|long|float|double|'
        r'u32|u16|u8|s32|s16|s8|packed_ptr)\s+'
        r'(?:__stdcall\s+|__cdecl\s+)?'
        r'([A-Za-z_][A-Za-z0-9_]*)\s*\('
    )
    data_def_re = re.compile(
        r'^(?:const\s+)?(?:unsigned\s+)?'
        r'(?:int|char|short|u32|u16|u8|s32|s16|s8)\s+'
        r'([A-Za-z_][A-Za-z0-9_]*)\s*(?:=|\[|;)'
    )
    # Local label definitions in __asm blocks (NAME:)
    label_def_re = re.compile(r'^\s*([A-Za-z_][A-Za-z0-9_]*)\s*:(?!\s*\S*:)')
    # Static string literals like `static const char $SG_..[] = ...`
    sg_def_re = re.compile(r'static\s+const\s+char\s+(\$?[A-Za-z_][A-Za-z0-9_]*)\s*\[')

    in_asm = False
    for line in lines:
        stripped = line.strip()
        if '__asm' in stripped:
            in_asm = True
        if in_asm and '}' in stripped and '__asm' not in stripped:
            in_asm = False

        m = fn_def_re.match(stripped)
        if m:
            visible.add(m.group(1))
        m2 = data_def_re.match(stripped)
        if m2:
            visible.add(m2.group(1))
        # Static string defs
        m3 = sg_def_re.match(stripped)
        if m3:
            visible.add(m3.group(1))
        # Local label definitions
        if in_asm or '{' in stripped or ':' in stripped:
            m4 = label_def_re.match(stripped)
            if m4:
                visible.add(m4.group(1))

    return visible


# ---------------------------------------------------------------------------
# Step 3: Extract symbol references from __asm blocks
# ---------------------------------------------------------------------------

def strip_asm_comment(line: str) -> str:
    """Remove inline assembly comments (;...) and C-style comments (//...)."""
    # Remove ; comments (asm style)
    semi = line.find(';')
    if semi >= 0:
        line = line[:semi]
    # Remove // comments
    slash = line.find('//')
    if slash >= 0:
        line = line[:slash]
    return line


def extract_asm_blocks(text: str) -> list[str]:
    """Extract the contents of all __asm { ... } blocks from a C source text.

    Handles nested braces. Returns list of raw strings (one per block,
    without the outer braces).
    """
    blocks = []
    i = 0
    n = len(text)
    # Find __asm keyword followed by optional whitespace and {
    asm_marker_re = re.compile(r'__asm\s*\{')
    for m in asm_marker_re.finditer(text):
        start = m.end()  # position after the opening {
        depth = 1
        j = start
        while j < n and depth > 0:
            if text[j] == '{':
                depth += 1
            elif text[j] == '}':
                depth -= 1
            j += 1
        # text[start:j-1] is the block contents
        blocks.append(text[start:j-1])
    return blocks


# Patterns for extracting symbol refs from a single asm instruction line
# These all produce a named group "sym"
_ASM_PATTERNS = [
    # call NAME  /  jmp NAME  (direct, not via register or [])
    re.compile(r'\bcall\s+(?:dword\s+ptr\s+\[)?([ \t]*)([A-Za-z_][A-Za-z0-9_]*)\b(?!\s*\*|\s*\[|\s*\+)'),
    re.compile(r'\bjmp\s+(?:dword\s+ptr\s+\[)?([ \t]*)([A-Za-z_][A-Za-z0-9_]*)\b(?!\s*\*|\s*\[|\s*\+)'),
    # call/jmp via register is NOT a symbol - filtered later
    # dword ptr [NAME]  /  byte ptr [NAME]  /  word ptr [NAME]
    re.compile(r'\b(?:dword|byte|word|qword)\s+ptr\s+\[\s*([A-Za-z_][A-Za-z0-9_]*)(?:\s*[\+\-\*\]]|\s*\])'),
    # offset NAME  /  OFFSET NAME
    re.compile(r'\boffset\s+([A-Za-z_][A-Za-z0-9_]*)', re.IGNORECASE),
]

# Pattern for bare "call NAME" / "jmp NAME" with no prefix
_CALL_JMP_RE = re.compile(
    r'^\s*(?:call|jmp)\s+(?:short\s+|SHORT\s+)?([A-Za-z_][A-Za-z0-9_]*)\s*$',
    re.IGNORECASE
)

# Pattern for "call dword ptr [NAME]" / "jmp dword ptr [NAME]"
# Also handles indexed: "jmp dword ptr [eax*4 + NAME]"
_CALL_MEM_RE = re.compile(
    r'^\s*(?:call|jmp)\s+dword\s+ptr\s+\[([^\]]+)\]',
    re.IGNORECASE
)

# Memory operand: dword/byte/word ptr [ANY CONTENT]
# We extract all symbol-like tokens from the bracket contents afterward.
_MEM_OP_RE = re.compile(
    r'\b(?:dword|byte|word|qword)\s+ptr\s+\[([^\]]+)\]',
    re.IGNORECASE
)

# Bare bracket: [CONTENT] without a preceding "ptr" keyword
# Catches patterns like: mov [eax*4 + g_sym], reg  or  cmp eax, [g_sym]
_BARE_BRACKET_RE = re.compile(r'(?<!ptr\s)\[([^\]]+)\]')

# offset NAME
_OFFSET_RE = re.compile(r'\boffset\s+([A-Za-z_][A-Za-z0-9_]*)', re.IGNORECASE)

# Extracts identifiers from bracket contents (for indexed addressing like [eax*4 + g_name])
_BRACKET_IDENT_RE = re.compile(r'\b([A-Za-z_][A-Za-z0-9_]+)\b')


def _extract_from_bracket(bracket_content: str) -> list[str]:
    """Extract identifiers from a memory operand bracket expression.

    Filters out registers and small numeric tokens; returns remaining names
    that could be global symbols.
    """
    names = []
    for m in _BRACKET_IDENT_RE.finditer(bracket_content):
        name = m.group(1)
        if name.lower() not in X86_REGISTERS and name.lower() not in ASM_KEYWORDS:
            names.append(name)
    return names


def extract_symbols_from_asm(asm_blocks: list[str]) -> set[str]:
    """Return set of all external symbol names referenced in the given asm blocks."""
    syms: set[str] = set()

    for block in asm_blocks:
        for raw_line in block.splitlines():
            line = strip_asm_comment(raw_line)
            line_stripped = line.strip()

            if not line_stripped:
                continue

            # call/jmp NAME (no prefix)
            m = _CALL_JMP_RE.match(line)
            if m:
                syms.add(m.group(1))
                continue

            # call/jmp dword ptr [BRACKET CONTENT]
            m = _CALL_MEM_RE.match(line)
            if m:
                for name in _extract_from_bracket(m.group(1)):
                    syms.add(name)
                continue

            # memory operands: [BRACKET CONTENT] after ptr
            for m in _MEM_OP_RE.finditer(line):
                for name in _extract_from_bracket(m.group(1)):
                    syms.add(name)

            # bare brackets: [eax*4 + g_sym]  (no "ptr" prefix)
            for m in _BARE_BRACKET_RE.finditer(line):
                for name in _extract_from_bracket(m.group(1)):
                    syms.add(name)

            # offset NAME
            for m in _OFFSET_RE.finditer(line):
                syms.add(m.group(1))

    return syms


def filter_symbols(raw: set[str], local_labels: set[str]) -> set[str]:
    """Remove registers, asm keywords, C keywords, Win32 API names,
    local labels, numeric-only tokens, and $SG_... string literal names."""
    result = set()
    for s in raw:
        # Skip empty
        if not s:
            continue
        # Skip if starts with digit
        if s[0].isdigit():
            continue
        # Skip $SG_ string literals (compiler-generated)
        if s.startswith('$') or s.startswith('__'):
            continue
        # Skip registers
        if s.lower() in X86_REGISTERS:
            continue
        # Skip asm mnemonics / keywords
        if s.lower() in ASM_KEYWORDS or s in ASM_KEYWORDS:
            continue
        # Skip C keywords
        if s in C_KEYWORDS:
            continue
        # Skip Win32 API names resolved via windows.h
        if s in WIN32_API_NAMES:
            continue
        # Skip local labels defined in this file
        if s in local_labels:
            continue
        result.add(s)
    return result


def collect_local_labels(text: str) -> set[str]:
    """Return set of label names defined anywhere in the source text."""
    labels: set[str] = set()
    # Match lines like "  L_foo:" or "  L_foo:  " in asm blocks
    # Also "L_foo$123:" style labels
    label_def_re = re.compile(r'^\s+([A-Za-z_\$][A-Za-z0-9_\$]*)\s*:')
    for line in text.splitlines():
        m = label_def_re.match(line)
        if m:
            labels.add(m.group(1))
    # Also collect static string literal names
    sg_re = re.compile(r'static\s+const\s+char\s+(\$?[A-Za-z_][A-Za-z0-9_]*)\s*\[')
    for m in sg_re.finditer(text):
        labels.add(m.group(1))
    return labels


# ---------------------------------------------------------------------------
# Step 4: Classify missing symbols as function or data global
# ---------------------------------------------------------------------------

def classify_symbol(name: str, fn_names: set, data_names: set) -> str:
    """Return 'fn', 'data', or 'unknown'."""
    if name in fn_names:
        return 'fn'
    if name in data_names:
        return 'data'
    # Heuristic: g_* prefix -> data
    if name.startswith('g_'):
        return 'data'
    # Heuristic: starts with uppercase or known function naming patterns -> function
    return 'fn'


# ---------------------------------------------------------------------------
# Step 5: Insert extern declarations into a .c file
# ---------------------------------------------------------------------------

def make_extern_decl(name: str, kind: str) -> str:
    """Return a C extern declaration string for the symbol."""
    if kind == 'data':
        return f'extern unsigned int {name};'
    else:
        # Default to void NAME(void) for functions
        return f'extern void {name}(void);'


def find_insertion_point(lines: list[str]) -> int:
    """Return the line index just before the first function that contains __asm.

    Handles both __declspec(naked) functions and regular functions with
    inline __asm {} blocks.  Walks backwards from the first __asm keyword
    to find the opening of its surrounding function.
    """
    # Find the first line that contains __asm (block or single-line)
    first_asm = None
    for i, line in enumerate(lines):
        if '__asm' in line:
            first_asm = i
            break

    if first_asm is None:
        return len(lines)

    # Walk backwards from first_asm to find the start of the surrounding function.
    # We look for a line at column 0 that looks like a function definition
    # (ends with '{' or is followed immediately by '{').
    fn_start_re = re.compile(
        r'^(?:__declspec\s*\(naked\)\s+)?'
        r'(?:static\s+)?(?:const\s+)?(?:unsigned\s+)?'
        r'(?:void|int|char|short|long|float|double|'
        r'u32|u16|u8|s32|s16|s8|s64|u64|packed_ptr)\b'
    )
    for i in range(first_asm, -1, -1):
        line = lines[i]
        stripped = line.strip()
        # A function definition starts at column 0 and matches a return type
        if not line.startswith(' ') and not line.startswith('\t') and stripped:
            if fn_start_re.match(stripped) and '(' in stripped:
                return i
            # Also catch __declspec(naked) alone on its own line
            if '__declspec(naked)' in stripped:
                return i

    # Fallback: before first __asm line
    return first_asm


def insert_externs(c_file: Path, missing: dict[str, str]) -> bool:
    """Insert extern declarations for missing symbols into c_file.

    missing: {name -> kind}  where kind is 'fn' or 'data'

    Also relocates any extern declarations that were previously placed AFTER
    the insertion point (wrong position) to BEFORE it.

    Returns True if the file was modified.
    """
    try:
        text = c_file.read_text(encoding='utf-8', errors='replace')
    except Exception as e:
        print(f"  ERROR reading {c_file}: {e}")
        return False

    lines = text.splitlines(keepends=True)
    ins_idx = find_insertion_point(lines)

    # Find any extern declarations that already exist in the file but AFTER
    # the insertion point (wrong position from a previous script run).
    # We'll move them to before the insertion point.
    extern_line_re = re.compile(
        r'^extern\s+(?:const\s+)?(?:unsigned\s+)?'
        r'\S.*?\s+(?:\(\s*\*\s*)?([A-Za-z_][A-Za-z0-9_]*)'
        r'\s*[\[;(]'
    )
    misplaced_indices = []
    for i in range(ins_idx, len(lines)):
        stripped = lines[i].strip()
        m = extern_line_re.match(stripped)
        if m:
            name = m.group(1)
            # Only relocate if this name is one of our missing symbols or is
            # a g_* / function name that clearly belongs before the function
            if name in missing or name.startswith('g_') or (
                re.match(r'^[A-Z][a-zA-Z0-9_]+$', name) and
                re.match(r'^extern\s+void\s+', stripped)
            ):
                misplaced_indices.append(i)

    # Collect the to-relocate lines and add any new missing ones
    to_add = {}
    to_add.update(missing)

    relocate_lines = []
    for i in sorted(misplaced_indices):
        stripped = lines[i].strip()
        m = extern_line_re.match(stripped)
        if m:
            name = m.group(1)
            # Will be re-added before the function; mark for removal from current spot
            relocate_lines.append(i)
            # Determine kind if not in missing
            if name not in to_add:
                if 'void' in stripped and '(' in stripped:
                    to_add[name] = 'fn'
                else:
                    to_add[name] = 'data'

    if not to_add and not relocate_lines:
        return False

    # Remove misplaced extern lines (and any trailing blank line just after them)
    indices_to_remove = set(relocate_lines)
    # Also remove a blank line that immediately follows a block of misplaced externs
    # to avoid double blank lines
    for i in sorted(indices_to_remove, reverse=True):
        if i + 1 < len(lines) and lines[i + 1].strip() == '' and (i + 1) not in indices_to_remove:
            # Only remove the trailing blank if ALL the preceding lines were extern
            # (i.e., this blank was added as a separator by us)
            if i > 0 and extern_line_re.match(lines[i - 1].strip() if i > 0 else ''):
                pass  # leave it; removing the blank separately is risky
    lines_after_removal = [l for idx, l in enumerate(lines) if idx not in indices_to_remove]

    # Recalculate insertion point after removal
    ins_idx2 = find_insertion_point(lines_after_removal)

    # Group: data globals first, then functions
    data_decls = sorted(
        make_extern_decl(n, k) for n, k in to_add.items() if k == 'data'
    )
    fn_decls = sorted(
        make_extern_decl(n, k) for n, k in to_add.items() if k == 'fn'
    )

    new_block_lines = []
    if data_decls:
        for d in data_decls:
            new_block_lines.append(d + '\n')
    if fn_decls:
        for f in fn_decls:
            new_block_lines.append(f + '\n')
    # Trailing blank line to separate from the function that follows
    new_block_lines.append('\n')

    new_lines = lines_after_removal[:ins_idx2] + new_block_lines + lines_after_removal[ins_idx2:]

    try:
        c_file.write_text(''.join(new_lines), encoding='utf-8')
    except Exception as e:
        print(f"  ERROR writing {c_file}: {e}")
        return False

    return True


# ---------------------------------------------------------------------------
# Main driver
# ---------------------------------------------------------------------------

def process_file(c_file: Path, fn_names: set, data_names: set, all_names: set) -> int:
    """Process one .c file. Returns count of missing symbols added."""
    try:
        text = c_file.read_text(encoding='utf-8', errors='replace')
    except Exception:
        return 0

    # Quick skip: no __asm blocks at all
    if '__asm' not in text:
        return 0

    # Extract __asm block contents
    asm_blocks = extract_asm_blocks(text)
    if not asm_blocks:
        # May have single-line __asm ret etc. - skip
        return 0

    # Collect local labels to filter out
    local_labels = collect_local_labels(text)

    # Extract referenced symbols from all asm blocks
    raw_refs = extract_symbols_from_asm(asm_blocks)
    refs = filter_symbols(raw_refs, local_labels)

    # What's already visible?
    visible = get_visible_symbols(c_file)

    # What's missing?
    missing_names = refs - visible

    # Further filter: skip anything not in our project symbol db
    # (this avoids adding externs for Win32 types, CRT items, etc.)
    # But keep names that start with g_ since those are always ours.
    confirmed_missing = {}
    for name in sorted(missing_names):
        if name in all_names:
            kind = classify_symbol(name, fn_names, data_names)
            confirmed_missing[name] = kind
        elif name.startswith('g_'):
            # Data global not yet in db but clearly ours
            confirmed_missing[name] = 'data'
        elif re.match(r'^[A-Z][a-z]|^[A-Z]{2,}', name):
            # Capitalized or all-caps names that look like functions
            # Only add if they pass a quick sanity check
            if re.match(r'^[A-Za-z_][A-Za-z0-9_]+$', name) and len(name) > 3:
                # Only if we can find it defined somewhere in src/
                confirmed_missing[name] = 'fn'
        # Otherwise skip (could be a local C variable, macro, etc.)

    rel_path = c_file.relative_to(ROOT)

    if confirmed_missing:
        print(f"\n{rel_path}")
        for name, kind in sorted(confirmed_missing.items()):
            tag = "data" if kind == "data" else "fn  "
            print(f"  + [{tag}] {name}")

    # insert_externs also handles relocation of misplaced externs from a
    # previous script run (externs placed after function bodies).
    if insert_externs(c_file, confirmed_missing):
        return max(len(confirmed_missing), 1)
    return 0


def main():
    # Optionally accept a list of files on the command line
    if len(sys.argv) > 1:
        target_files = [Path(a).resolve() for a in sys.argv[1:]]
    else:
        target_files = list(SRC_DIR.rglob("*.c"))

    print("Building project symbol database...")
    fn_names, data_names, all_names = build_symbol_db()
    print(f"  {len(fn_names)} function symbols, {len(data_names)} data globals")

    total_files_changed = 0
    total_syms_added = 0

    for c_file in sorted(target_files):
        if not c_file.exists():
            print(f"WARNING: {c_file} not found, skipping")
            continue
        added = process_file(c_file, fn_names, data_names, all_names)
        if added:
            total_files_changed += 1
            total_syms_added += added

    print(f"\n--- Summary ---")
    print(f"Files modified : {total_files_changed}")
    print(f"Externs added  : {total_syms_added}")


if __name__ == "__main__":
    main()
