#!/usr/bin/env python3
"""brute_convert.py - aggressive brute-force C-source variant tester.

Given a target function (currently naked or hybrid), iterates over a
combinatorial matrix of C-source variants, applies each in-place to
the source file, compiles the .obj, and runs diff_fn_obj.py. Reports
the variant with the fewest byte-diffs against orig.

Variants are produced by chaining "axis" mutations: return type, tail
form, early-return form, literal caching, statement reordering,
pragma directives, volatile/const qualifiers, register-allocator
hints, etc. Each axis can be enabled or disabled per run.

Usage:
    # Apply a single variant string (full C function source) and test
    python3 tools/decomp/brute_convert.py <src_file> <func_name> --variant <variant_c_file>

    # Run a built-in variant matrix on a target naked function
    python3 tools/decomp/brute_convert.py <src_file> <func_name> \\
            --matrix triple_chain \\
            --output-best best_variant.c

The matrix names are defined in MATRICES below.
"""
import argparse
import itertools
import os
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent


# --- function extraction (handles naked and pure-C) ----------------

def extract_function(src, func_name):
    """Return (before, fn_text, after, is_naked)."""
    # Naked form
    pat = re.compile(
        r'((?:/\*[^*]*\*+(?:[^/*][^*]*\*+)*/\s*\n)?'
        r'__declspec\s*\(\s*naked\s*\)\s+\w+(?:\s*\*)?\s+'
        + re.escape(func_name)
        + r'\s*\([^)]*\)\s*\{[\s\S]*?\n\}\n)',
        re.MULTILINE,
    )
    m = pat.search(src)
    if m:
        return src[:m.start()], m.group(1), src[m.end():], True

    # Plain pure-C / hybrid form. Find `[ret_type] NAME(args) {` and
    # match braces.
    pat = re.compile(
        r'((?:/\*[^*]*\*+(?:[^/*][^*]*\*+)*/\s*\n)?'
        r'(?:^|\n)(?:extern\s+)?[a-zA-Z_]\w*(?:\s*\*)?\s+'
        + re.escape(func_name) + r'\s*\([^)]*\)\s*\{)',
        re.MULTILINE,
    )
    m = pat.search(src)
    if not m:
        return None, None, None, False
    open_brace = m.end() - 1
    depth = 1
    i = open_brace + 1
    while i < len(src) and depth > 0:
        c = src[i]
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                end = i + 1
                if end < len(src) and src[end] == '\n':
                    end += 1
                return src[:m.start()], src[m.start():end], src[end:], False
        i += 1
    return None, None, None, False


def find_symbol(name):
    sympath = ROOT / 'config' / 'symbols.yaml'
    cur_addr = None
    cur_name = None
    cur_size = None
    cur_file = None
    with open(sympath) as f:
        for line in f:
            s = line.strip()
            if s.startswith('- addr:'):
                if cur_name == name:
                    return cur_addr, cur_size, cur_file
                cur_addr = int(s.split(':', 1)[1].strip(), 0)
                cur_name = None
                cur_size = None
                cur_file = None
            elif s.startswith('name:'):
                cur_name = s.split(':', 1)[1].strip()
            elif s.startswith('size:'):
                cur_size = int(s.split(':', 1)[1].strip(), 0)
            elif s.startswith('file:'):
                cur_file = s.split(':', 1)[1].strip()
        if cur_name == name:
            return cur_addr, cur_size, cur_file
    return None, None, None


def compile_and_diff(src_path, obj_rel, fn_name, addr, size):
    """Touch src, run make to rebuild obj, run diff_fn_obj. Return diff
    count (0 = match) or negative on error."""
    src_path.touch()
    res = subprocess.run(
        ['make', f'build/obj/{obj_rel}'],
        cwd=ROOT, capture_output=True, text=True, timeout=180,
    )
    if res.returncode != 0:
        return -2, res.stdout + res.stderr
    obj_path = ROOT / 'build' / 'obj' / obj_rel
    diff_script = ROOT / 'tools' / 'decomp' / 'diff_fn_obj.py'
    res = subprocess.run(
        ['python3', str(diff_script), str(obj_path), fn_name, hex(addr), str(size)],
        capture_output=True, text=True, timeout=30,
    )
    output = res.stdout + res.stderr
    for line in output.split('\n'):
        if 'diffs=' in line:
            try:
                d = int(line.split('diffs=')[1].split()[0].rstrip(':'))
                return d, output
            except (ValueError, IndexError):
                pass
    if 'exceed section size' in output:
        return -3, output
    return -1, output


# --- variant matrices ----------------------------------------------

def variants_triple_chain_tail_jmp():
    """Variant matrix for TripleChainTailJmp_00419900.

    Axes:
      - rt: void / int
      - er: bare / pause / goto
      - tl: void_call / int_cast / return_v / void_then_return_v
      - vc: literal / local_v
      - pr: none / pragma_a_off / pragma_g_off / pragma_s_on
      - vol: none / volatile_pause
    """
    rt_opts = ['void', 'int']
    er_opts = ['bare', 'pause', 'goto']
    tl_opts = ['void_call', 'int_cast', 'return_v_after_void', 'tail_via_int_cast_no_return']
    vc_opts = ['literal', 'local_v', 'local_v_dual_use']
    pr_opts = ['none', 'a_off', 's_on', 't_on']
    vol_opts = ['none', 'pause_vol']
    order_opts = ['p_first', 'p_last', 'inline_p']

    for rt, er, tl, vc, pr, vol, order in itertools.product(
        rt_opts, er_opts, tl_opts, vc_opts, pr_opts, vol_opts, order_opts):
        # Skip nonsensical combos
        if rt == 'void' and tl in ('int_cast', 'return_v_after_void', 'tail_via_int_cast_no_return'):
            continue
        if rt == 'void' and er == 'pause':
            continue
        if rt == 'void' and er == 'goto':
            continue
        if vc == 'literal' and tl == 'return_v_after_void':
            continue
        if vc == 'literal' and tl == 'tail_via_int_cast_no_return':
            # literal and return_v require v local
            pass

        # Build the function source
        lines = []
        lines.append('extern unsigned int g_data_004d7af8;')
        if pr == 'a_off':
            lines.append('#pragma optimize("a", off)')
        elif pr == 's_on':
            lines.append('#pragma optimize("s", on)')
        elif pr == 't_on':
            lines.append('#pragma optimize("t", on)')

        sig = 'void' if rt == 'void' else 'int'
        lines.append(f'{sig} TripleChainTailJmp_00419900(void) {{')

        # Locals at top (C89)
        lines.append('    unsigned int p;')
        if vol == 'pause_vol':
            lines.append('    volatile unsigned int *p_pause = (volatile unsigned int *)&g_framePauseFlag;')
            pause_expr = '*p_pause'
        else:
            pause_expr = 'g_framePauseFlag'

        # Early-return helpers
        if er == 'bare':
            er_stmt = 'return;'
        elif er == 'pause':
            er_stmt = f'return {pause_expr};'
        elif er == 'goto':
            er_stmt = 'goto done;'

        lines.append('    MStackPush2RunCountdown_004089e0();')
        lines.append(f'    if ({pause_expr} != 0) {er_stmt}')
        lines.append('    MStackBracket7_DispatchAndChain_004b8fa0();')
        lines.append(f'    if ({pause_expr} != 0) {er_stmt}')

        # Packed-ptr setup. Vary order/style
        if order == 'p_first':
            lines.append('    p = (unsigned int)&g_data_004d7af8;')
            lines.append('    g_x_00542074 = 3;')
            lines.append('    g_data_0054204c = p >> 2;')
        elif order == 'p_last':
            lines.append('    g_x_00542074 = 3;')
            lines.append('    p = (unsigned int)&g_data_004d7af8;')
            lines.append('    g_data_0054204c = p >> 2;')
        elif order == 'inline_p':
            lines.append('    g_x_00542074 = 3;')
            lines.append('    g_data_0054204c = ((unsigned int)&g_data_004d7af8) >> 2;')

        lines.append('    SlotInitAndChainLink_004191b0();')
        lines.append(f'    if ({pause_expr} != 0) {er_stmt}')
        lines.append(f'    if ((g_state_0054208c & 4) != 0) {er_stmt}')

        # Body
        if vc == 'literal':
            lines.append('    g_walkCallback = (void (*)(void))0x11999;')
            lines.append('    *(unsigned int *)(g_eventQueueWorkType * 4 + 0x48) = 0x11999;')
        elif vc == 'local_v':
            lines.append('    {')
            lines.append('        unsigned int v = 0x11999;')
            lines.append('        g_walkCallback = (void (*)(void))v;')
            lines.append('        *(unsigned int *)(g_eventQueueWorkType * 4 + 0x48) = v;')
            lines.append('    }')
        elif vc == 'local_v_dual_use':
            lines.append('    {')
            lines.append('        unsigned int v = 0x11999;')
            lines.append('        unsigned int wt = g_eventQueueWorkType;')
            lines.append('        g_walkCallback = (void (*)(void))v;')
            lines.append('        *(unsigned int *)(wt * 4 + 0x48) = v;')
            lines.append('    }')

        lines.append('    g_state_00542054 += 0x15;')

        # Tail
        if tl == 'void_call':
            lines.append('    BootFlagChainAudioPause_00412080();')
            if rt == 'int':
                lines.append(f'    return {pause_expr};')
        elif tl == 'int_cast':
            lines.append('    return ((int (*)(void))BootFlagChainAudioPause_00412080)();')
        elif tl == 'return_v_after_void':
            # Need v from earlier
            lines.append('    BootFlagChainAudioPause_00412080();')
            lines.append('    return 0x11999;')
        elif tl == 'tail_via_int_cast_no_return':
            lines.append('    ((int (*)(void))BootFlagChainAudioPause_00412080)();')
            if rt == 'int':
                lines.append('    return 0;')

        if er == 'goto':
            lines.append('done:')
            lines.append(f'    return {pause_expr};')

        lines.append('}')

        if pr in ('a_off', 's_on', 't_on'):
            lines.append('#pragma optimize("", on)')

        name = f'rt={rt}_er={er}_tl={tl}_vc={vc}_pr={pr}_vol={vol}_o={order}'
        yield name, '\n'.join(lines) + '\n'


def variants_gated_double_setup():
    """Variant matrix for GatedDoubleSetupJmp_00412450.

    The near-miss with diffs=4 had: stores in order [new_wc, a, b].
    Orig wants: stores in [a, b, new_wc]. The challenge is preventing
    MSVC from interleaving the new_wc load between the a-store and b-store.
    """
    decl_order_opts = ['a_b_nw', 'a_nw_b', 'nw_a_b', 'b_a_nw']
    store_order_opts = ['a_b_nw', 'a_nw_b', 'nw_a_b', 'b_a_nw']
    nw_form_opts = ['shr_local', 'shr_inline_store']
    pr_opts = ['none', 'a_off', 's_on', 't_on']

    for decl, store, nw, pr in itertools.product(
            decl_order_opts, store_order_opts, nw_form_opts, pr_opts):

        lines = []
        lines.append('extern unsigned int g_data_004d5888;')
        if pr in ('a_off', 's_on', 't_on'):
            lines.append(f'#pragma optimize("{pr.split("_")[0]}", {"off" if pr == "a_off" else "on"})')

        lines.append('void GatedDoubleSetupJmp_00412450(void) {')
        # Declare locals at top per C89
        local_lines_decl = []
        local_lines_assign = []
        # Build decls in specified order
        order_keys = decl.split('_')
        for k in order_keys:
            if k == 'a':
                local_lines_decl.append('    unsigned int a;')
                local_lines_assign.append('    a = g_scaledInit_00542044;')
            elif k == 'b':
                local_lines_decl.append('    unsigned int b;')
                local_lines_assign.append('    b = (unsigned int)g_walkCallback;')
            elif k == 'nw' and nw == 'shr_local':
                local_lines_decl.append('    unsigned int new_wc;')
                local_lines_assign.append('    new_wc = (unsigned int)&g_data_004d5888 >> 2;')
        # Emit decls before the if-block
        for d in local_lines_decl:
            lines.append(d)
        lines.append('    if (g_x_004f360c == 0) {')
        lines.append('        g_state_0054208c |= 4;')
        lines.append('        return;')
        lines.append('    }')
        lines.append('    g_state_004d57ac++;')
        lines.append('    *(unsigned int *)(g_state_004d57ac * 4) = g_eventQueueWorkType;')
        lines.append('    g_state_004d57ac++;')
        lines.append('    *(unsigned int *)(g_state_004d57ac * 4) = g_cj_0054205c;')
        for a in local_lines_assign:
            lines.append(a)

        # Stores in specified order
        store_a = '    g_eventQueueWorkType = a;'
        store_b = '    g_x_00542074 = b;'
        if nw == 'shr_local':
            store_nw = '    g_walkCallback = (void (*)(void))new_wc;'
        else:
            store_nw = '    g_walkCallback = (void (*)(void))((unsigned int)&g_data_004d5888 >> 2);'

        store_map = {'a': store_a, 'b': store_b, 'nw': store_nw}
        for k in store.split('_'):
            lines.append(store_map[k])

        lines.append('    BootChainBuildAndStep_004124c0();')
        lines.append('}')

        if pr in ('a_off', 's_on', 't_on'):
            lines.append('#pragma optimize("", on)')

        name = f'decl={decl}_store={store}_nw={nw}_pr={pr}'
        yield name, '\n'.join(lines) + '\n'


def variants_gated_double_helper():
    """Variant matrix for GatedDoubleSetupJmp_00412450 using helper-function patterns.

    Tests the static __inline helper approach that succeeded with 3-separate helpers.
    """
    helper_styles = ['single_3arg', 'three_separate', 'two_then_one', 'inline_only']
    decl_orders = ['a_b_c', 'a_c_b', 'b_a_c', 'b_c_a', 'c_a_b', 'c_b_a']

    for hs in helper_styles:
        for decl in decl_orders:
            lines = ['extern unsigned int g_data_004d5888;']
            if hs == 'three_separate':
                lines.extend([
                    'static __inline void _set_eqwt(unsigned int v) { g_eventQueueWorkType = v; }',
                    'static __inline void _set_x74(unsigned int v) { g_x_00542074 = v; }',
                    'static __inline void _set_wc(unsigned int v) { g_walkCallback = (void (*)(void))v; }',
                ])
            elif hs == 'single_3arg':
                lines.append(
                    'static __inline void _set3(unsigned int a, unsigned int b, unsigned int c) {'
                    ' g_eventQueueWorkType = a; g_x_00542074 = b; g_walkCallback = (void (*)(void))c; }')
            elif hs == 'two_then_one':
                lines.extend([
                    'static __inline void _set2(unsigned int a, unsigned int b) {'
                    ' g_eventQueueWorkType = a; g_x_00542074 = b; }',
                    'static __inline void _set_wc(unsigned int v) { g_walkCallback = (void (*)(void))v; }',
                ])

            lines.append('void GatedDoubleSetupJmp_00412450(void) {')
            lines.append('    if (g_x_004f360c == 0) {')
            lines.append('        g_state_0054208c |= 4;')
            lines.append('        return;')
            lines.append('    }')
            lines.append('    g_state_004d57ac++;')
            lines.append('    *(unsigned int *)(g_state_004d57ac * 4) = g_eventQueueWorkType;')
            lines.append('    g_state_004d57ac++;')
            lines.append('    *(unsigned int *)(g_state_004d57ac * 4) = g_cj_0054205c;')

            arg_a = 'g_scaledInit_00542044'
            arg_b = '(unsigned int)g_walkCallback'
            arg_c = '((unsigned int)&g_data_004d5888) >> 2'
            arg_map = {'a': arg_a, 'b': arg_b, 'c': arg_c}

            if hs == 'three_separate':
                # 3 separate calls in the decl order
                for k in decl.split('_'):
                    if k == 'a':
                        lines.append(f'    _set_eqwt({arg_a});')
                    elif k == 'b':
                        lines.append(f'    _set_x74({arg_b});')
                    elif k == 'c':
                        lines.append(f'    _set_wc({arg_c});')
            elif hs == 'single_3arg':
                lines.append(f'    _set3({arg_a}, {arg_b}, {arg_c});')
            elif hs == 'two_then_one':
                lines.append(f'    _set2({arg_a}, {arg_b});')
                lines.append(f'    _set_wc({arg_c});')
            elif hs == 'inline_only':
                # No helpers, just inline stores
                lines.append(f'    g_eventQueueWorkType = {arg_a};')
                lines.append(f'    g_x_00542074 = {arg_b};')
                lines.append(f'    g_walkCallback = (void (*)(void)){arg_c};')

            lines.append('    BootChainBuildAndStep_004124c0();')
            lines.append('}')

            yield f'hs={hs}_decl={decl}', '\n'.join(lines) + '\n'


MATRICES = {
    'triple_chain': variants_triple_chain_tail_jmp,
    'gated_double': variants_gated_double_setup,
    'gated_double_helper': variants_gated_double_helper,
}


# --- generic variant generators (work on any function) -------------

# Match a simple local declaration line at the function head:
#     <type> <name>;
# where <type> is a single token like `unsigned`, `int`, `unsigned int`,
# or two-token `unsigned int` / `signed char`. We restrict to scalar
# types to keep ordering safe.
_DECL_RE = re.compile(
    r'^(\s*)((?:unsigned\s+|signed\s+)?(?:int|char|short|long|u(?:8|16|32)|s(?:8|16|32)))\s+(\w+)\s*;\s*$'
)


def parse_decl_block(fn_text):
    """Return (head_lines, decl_lines, body_lines, tail_line).

    head_lines: lines from start (signature, opening brace, leading comments) up to the
                first matched declaration line.
    decl_lines: consecutive declaration lines parsed via _DECL_RE.
    body_lines: everything after the declaration block up to the closing brace.
    tail_line:  the closing `}` line.
    Returns (None, None, None, None) if no decl block found.
    """
    lines = fn_text.split('\n')
    # Find the opening brace
    open_idx = None
    for i, ln in enumerate(lines):
        if ln.rstrip().endswith('{'):
            open_idx = i
            break
    if open_idx is None:
        return None, None, None, None
    # Find consecutive decl lines after the opening brace
    decls = []
    body_start = open_idx + 1
    while body_start < len(lines):
        m = _DECL_RE.match(lines[body_start])
        if not m:
            break
        decls.append((lines[body_start], m.group(3)))  # (raw_line, var_name)
        body_start += 1
    if len(decls) < 2:
        return None, None, None, None
    head_lines = lines[:open_idx + 1]
    decl_lines = [d[0] for d in decls]
    body_lines = lines[body_start:-1]  # everything between decls and final `}`
    tail_line = lines[-1]
    return head_lines, decl_lines, body_lines, tail_line


def variants_perm_decls(fn_text, max_n=24):
    """Generate variants by permuting the local-declaration block.

    Works on already-pure-C function. Useful when MSVC's natural decl-order
    register allocation differs from orig - reordering decls flips it.

    Yields (name, full_function_text). Skips if the function has < 2 decls
    in the head block.
    """
    head, decls, body, tail = parse_decl_block(fn_text)
    if decls is None:
        return
    n = len(decls)
    if n < 2:
        return
    # Cap at 24 (4!) to keep the search space manageable
    perms = list(itertools.permutations(range(n)))
    if len(perms) > max_n:
        perms = perms[:max_n]
    for perm in perms:
        new_decls = [decls[i] for i in perm]
        lines = head + new_decls + body + [tail]
        order_names = []
        for i in perm:
            # Extract var name from decl line
            m = _DECL_RE.match(decls[i])
            order_names.append(m.group(3) if m else f'd{i}')
        yield f'decl_order=' + '_'.join(order_names), '\n'.join(lines)


MATRICES['perm_decls'] = None  # marker - handled specially in main()


# Match a "simple global store" line in a function body:
#     <global> = <expr>;
# where <global> is a single identifier (not a deref). Used by
# helpers_split to find consecutive distinct stores.
_STORE_RE = re.compile(
    r'^(\s*)(g_\w+)\s*=\s*([^;]+?);\s*$'
)


def find_store_sequence(body_lines):
    """Find the longest run of consecutive direct-global stores in body_lines.

    Returns (start_idx, end_idx, [(line_idx, indent, global_name, expr), ...])
    or None if no run of length >= 3 found.
    """
    runs = []
    cur = []
    for i, ln in enumerate(body_lines):
        m = _STORE_RE.match(ln)
        if m:
            cur.append((i, m.group(1), m.group(2), m.group(3).strip()))
        else:
            if len(cur) >= 3:
                runs.append(cur)
            cur = []
    if len(cur) >= 3:
        runs.append(cur)
    if not runs:
        return None
    # Pick the longest run
    longest = max(runs, key=len)
    start_idx = longest[0][0]
    end_idx = longest[-1][0]
    return start_idx, end_idx, longest


def variants_helpers_split(fn_text):
    """Generate helper-split variants of an existing pure-C function.

    Finds a run of consecutive direct global stores in the body and
    tries replacing them with helper-function call patterns:
    - all-inline (baseline)
    - single N-arg helper
    - N separate single-arg helpers
    - 2-then-rest split
    """
    head, decls, body, tail = parse_decl_block(fn_text)
    if body is None:
        # No decl block - try whole function
        lines = fn_text.split('\n')
        open_idx = None
        for i, ln in enumerate(lines):
            if ln.rstrip().endswith('{'):
                open_idx = i
                break
        if open_idx is None:
            return
        head = lines[:open_idx+1]
        decls = []
        body = lines[open_idx+1:-1]
        tail = lines[-1]

    run = find_store_sequence(body)
    if run is None:
        return
    start_idx, end_idx, store_list = run

    # Unique global names (lose duplicates)
    seen_globals = []
    unique_stores = []
    for i, indent, g, expr in store_list:
        if g in seen_globals:
            continue
        seen_globals.append(g)
        unique_stores.append((i, indent, g, expr))

    if len(unique_stores) < 3:
        return

    n = len(unique_stores)
    if n > 6:
        unique_stores = unique_stores[:6]
        n = 6

    # Find the function name (for helper naming hash)
    fn_name_match = re.search(r'\b(\w+)\s*\(', '\n'.join(head))
    fn_name = fn_name_match.group(1) if fn_name_match else 'fn'
    suffix = re.sub(r'[^a-zA-Z0-9]', '_', fn_name)[-12:]

    indent = unique_stores[0][1]

    def emit_helpers_separate(stores_to_split):
        """Emit N separate single-arg static __inline helpers."""
        helpers = []
        calls = []
        for j, (_, _, g, expr) in enumerate(stores_to_split):
            hname = f'_set_{j}_{suffix}'
            # Determine cast: if g is a function pointer name, use cast
            if 'walkCallback' in g or 'Callback' in g:
                helpers.append(f'static __inline void {hname}(unsigned int v) {{ {g} = (void (*)(void))v; }}')
                calls.append(f'{indent}{hname}({expr});')
            else:
                helpers.append(f'static __inline void {hname}(unsigned int v) {{ {g} = v; }}')
                calls.append(f'{indent}{hname}({expr});')
        return helpers, calls

    # Variant 1: all separate single-arg helpers
    for cast_walkcb in (False,):  # only relevant variant
        helpers, calls = emit_helpers_separate(unique_stores)
        # Build full function
        new_body = body[:start_idx] + calls + body[end_idx+1:]
        full = '\n'.join(helpers) + '\n' + '\n'.join(head + decls + new_body + [tail])
        yield 'separate_helpers', full

    # Variant 2: single N-arg helper
    helper_args = ', '.join(f'unsigned int a{j}' for j in range(n))
    helper_body = []
    for j, (_, _, g, _) in enumerate(unique_stores):
        if 'Callback' in g:
            helper_body.append(f'{g} = (void (*)(void))a{j};')
        else:
            helper_body.append(f'{g} = a{j};')
    helper = f'static __inline void _set_n_{suffix}({helper_args}) {{ {" ".join(helper_body)} }}'
    call_args = ', '.join(s[3] for s in unique_stores)
    new_calls = [f'{indent}_set_n_{suffix}({call_args});']
    new_body = body[:start_idx] + new_calls + body[end_idx+1:]
    full = helper + '\n' + '\n'.join(head + decls + new_body + [tail])
    yield 'single_nargs', full


MATRICES['helpers_split'] = None  # marker


# --- driver ---------------------------------------------------------

def update_forward_decls(src, func_name, new_type):
    pat = re.compile(r'\bextern\s+\w+(\s+' + re.escape(func_name) + r'\b)')
    return pat.sub(f'extern {new_type}' + r'\1', src)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('src', help='C source file containing the naked function')
    ap.add_argument('func', help='Function name')
    ap.add_argument('--matrix', choices=list(MATRICES.keys()),
                    help='Built-in variant matrix to iterate')
    ap.add_argument('--variant-file', help='Single variant from a file (overrides --matrix)')
    ap.add_argument('--max', type=int, default=10000,
                    help='Max variants to try (default 10000)')
    ap.add_argument('--apply-best', action='store_true',
                    help='Leave best-matching variant applied (default: restore)')
    ap.add_argument('--needs-extern-update', action='store_true',
                    help='Update extern decls when return type changes')
    args = ap.parse_args()

    src_path = Path(args.src).resolve()
    if not src_path.exists():
        print(f'ERROR: {src_path} not found', file=sys.stderr)
        sys.exit(2)

    addr, size, decl_file = find_symbol(args.func)
    if addr is None:
        print(f'ERROR: symbol {args.func} not found in symbols.yaml', file=sys.stderr)
        sys.exit(2)

    rel = src_path.relative_to(ROOT / 'src').as_posix()
    obj_rel = rel[:-2] + '.obj'

    original = src_path.read_text()
    before, fn_text, after, is_naked = extract_function(original, args.func)
    if fn_text is None:
        print(f'ERROR: function {args.func} not found in {src_path}', file=sys.stderr)
        sys.exit(2)

    print(f'Target: {args.func} @ {addr:#x} size={size} ({"naked" if is_naked else "pure-C"})')

    # Build variants list
    variants = []
    if args.variant_file:
        with open(args.variant_file) as f:
            variants = [('variant_file', f.read())]
    elif args.matrix == 'perm_decls':
        # Generic permutation of local declarations - operates on the existing fn_text
        if is_naked:
            print('ERROR: perm_decls requires a pure-C function (not naked). Convert first.',
                  file=sys.stderr)
            sys.exit(2)
        variants = list(variants_perm_decls(fn_text))[:args.max]
        if not variants:
            print('ERROR: perm_decls found no permutable decl block (need >= 2 scalar decls at function head)',
                  file=sys.stderr)
            sys.exit(2)
    elif args.matrix == 'helpers_split':
        if is_naked:
            print('ERROR: helpers_split requires a pure-C function (not naked). Convert first.',
                  file=sys.stderr)
            sys.exit(2)
        variants = list(variants_helpers_split(fn_text))[:args.max]
        if not variants:
            print('ERROR: helpers_split found no run of >=3 consecutive direct global stores',
                  file=sys.stderr)
            sys.exit(2)
    elif args.matrix:
        variants = list(MATRICES[args.matrix]())[:args.max]
    else:
        print('ERROR: --matrix or --variant-file required', file=sys.stderr)
        sys.exit(2)

    print(f'Testing {len(variants)} variants...')
    t_start = time.time()

    results = []
    best = None  # (diffs, name, src)

    try:
        for i, (name, fn_src) in enumerate(variants):
            full_src = before + fn_src + after
            # If variant has `int ` return, update externs in the same file
            if re.match(r'(?:#pragma[^\n]*\n)*\s*int\s+' + re.escape(args.func), fn_src):
                full_src = update_forward_decls(full_src, args.func, 'int ')
            elif re.match(r'(?:#pragma[^\n]*\n)*\s*void\s+' + re.escape(args.func), fn_src):
                full_src = update_forward_decls(full_src, args.func, 'void')

            src_path.write_text(full_src)
            diffs, output = compile_and_diff(src_path, obj_rel, args.func, addr, size)

            t = time.time() - t_start
            mark = 'MATCH' if diffs == 0 else (f'{diffs}' if diffs > 0 else f'err{diffs}')
            print(f'  [{i+1}/{len(variants)}] ({t:.1f}s) {mark:<8} {name}', flush=True)

            results.append((diffs, name, fn_src))
            if diffs == 0:
                best = (0, name, fn_src)
                print('\nMATCH FOUND - stopping early')
                break
    finally:
        # Always restore (unless --apply-best)
        if args.apply_best and best:
            full_src = before + best[2] + after
            if re.match(r'(?:#pragma[^\n]*\n)*\s*int\s+', best[2]):
                full_src = update_forward_decls(full_src, args.func, 'int ')
            src_path.write_text(full_src)
            print(f'\nLeft applied: {best[1]}')
        else:
            src_path.write_text(original)

    # Report
    valid = [r for r in results if r[0] >= 0]
    if valid:
        valid.sort(key=lambda r: r[0])
        print('\nTop 5 variants:')
        for d, n, _ in valid[:5]:
            print(f'  diffs={d:3d}  {n}')
        if valid[0][0] == 0:
            print(f'\n=== MATCH: {valid[0][1]} ===')
            sys.exit(0)
        else:
            print(f'\nBest near-miss: {valid[0][0]} diffs ({valid[0][1]})')
            sys.exit(1)
    else:
        print('No valid variants compiled.')
        sys.exit(2)


if __name__ == '__main__':
    main()
