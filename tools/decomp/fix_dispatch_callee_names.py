#!/usr/bin/env python3
"""
Fix wrong callee names in dispatch copies of three functions.
"""
import re


def find_function_body_range(lines, func_name):
    """Find start/end line indices (0-based) of a __declspec(naked) function definition.
    Skips extern declarations - only matches actual definitions that have a body ({...})."""
    start_idx = None
    pattern = re.compile(r'void\s+' + re.escape(func_name) + r'\s*\(')
    for i, line in enumerate(lines):
        if pattern.search(line):
            # Skip extern declarations and forward declarations (no body)
            if 'extern' in line:
                continue
            # Must have an opening brace somewhere at/after this line (within a few lines)
            has_brace = False
            for j in range(i, min(i + 5, len(lines))):
                if '{' in lines[j]:
                    has_brace = True
                    break
            if has_brace:
                start_idx = i
                break
    if start_idx is None:
        return None, None

    brace_count = 0
    end_idx = None
    for i in range(start_idx, len(lines)):
        brace_count += lines[i].count('{') - lines[i].count('}')
        if brace_count == 0 and i > start_idx:
            end_idx = i
            break

    return start_idx, end_idx


def extern_present_before(lines, func_start_idx, sym):
    """Check if extern for sym is declared anywhere before func_start_idx."""
    for j in range(func_start_idx):
        if sym in lines[j] and 'extern' in lines[j]:
            return True
    return False


def add_extern_before_function(lines, func_name, extern_decl):
    """
    Insert extern_decl just before the function's comment block.
    Returns True if inserted (modifies lines in-place, index valid for current state).
    """
    func_def_idx = None
    pattern = re.compile(r'void\s+' + re.escape(func_name) + r'\s*\(')
    for i, line in enumerate(lines):
        if pattern.search(line) and 'extern' not in line:
            # Verify it's a definition (has opening brace nearby)
            has_brace = any('{' in lines[j] for j in range(i, min(i + 5, len(lines))))
            if has_brace:
                func_def_idx = i
                break
    if func_def_idx is None:
        return False

    # Extract symbol name from extern decl
    m = re.search(r'extern\s+void\s+(\w+)', extern_decl)
    sym = m.group(1) if m else ''

    if extern_present_before(lines, func_def_idx, sym):
        print(f"  Extern '{sym}' already declared before line {func_def_idx+1}, skipping.")
        return False

    # Walk back past comment block to find insertion point
    i = func_def_idx - 1
    insert_idx = func_def_idx
    while i >= 0:
        stripped = lines[i].strip()
        if stripped.startswith('/*') or stripped.startswith('*') or stripped.startswith('*/'):
            i -= 1
        elif stripped == '':
            insert_idx = i + 1
            break
        else:
            insert_idx = i + 1
            break

    lines.insert(insert_idx, extern_decl + '\n')
    print(f"  Added extern at line {insert_idx+1}: {extern_decl.strip()}")
    return True


def fix1_replace_after_add_01000000(lines, start_idx, end_idx, func_name):
    """
    Within function body lines[start_idx..end_idx], find 'add edx, 0x01000000'
    then change the next 'call ScaledLoadJmp_00428d20' to
    'call    InstallSelf3WayChainCmp_00428d80'.
    """
    anchor_pattern = re.compile(r'\badd\s+edx,\s+0x01000000\b')
    target_pattern = re.compile(r'(\s*call\s+)ScaledLoadJmp_00428d20')

    anchor_idx = None
    for i in range(start_idx, end_idx + 1):
        if anchor_pattern.search(lines[i]):
            anchor_idx = i
            break

    if anchor_idx is None:
        print(f"  ERROR [{func_name}]: 'add edx, 0x01000000' not found in body")
        return False

    for i in range(anchor_idx, end_idx + 1):
        if target_pattern.search(lines[i]):
            old = lines[i]
            lines[i] = target_pattern.sub(r'\1InstallSelf3WayChainCmp_00428d80', lines[i])
            print(f"  [{func_name}] Replaced line {i+1}: {old.rstrip()!r} -> {lines[i].rstrip()!r}")
            return True

    print(f"  ERROR [{func_name}]: no 'call ScaledLoadJmp_00428d20' after 'add edx, 0x01000000'")
    return False


def process_fix1_file(filepath):
    """Apply Fix 1 to both target functions in filepath (if definitions present)."""
    funcs = [
        'InstallSelfThreeStateScaledLoad_0047f2e0',
        'InstallSelfThreeStateSiblingPair_00495480',
    ]
    print(f"\n[Fix1] Processing {filepath}")

    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    modified = False
    for func_name in funcs:
        start_idx, end_idx = find_function_body_range(lines, func_name)
        if start_idx is None:
            print(f"  {func_name}: not defined in this file, skipping.")
            continue

        print(f"  {func_name}: body at lines {start_idx+1}..{end_idx+1}")

        # Add extern if needed (modifies lines, so recalculate after)
        extern_added = add_extern_before_function(
            lines, func_name, 'extern void InstallSelf3WayChainCmp_00428d80(void);'
        )
        if extern_added:
            # Recalculate indices after insertion
            start_idx, end_idx = find_function_body_range(lines, func_name)

        ok = fix1_replace_after_add_01000000(lines, start_idx, end_idx, func_name)
        if ok:
            modified = True

    if modified:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.writelines(lines)
        print(f"  Written.")
    else:
        print(f"  No changes needed.")
    return modified


def process_fix2_file(filepath):
    """
    Fix 2: Within InstallSelfFourStatePauseChain_0049b000 body,
    change 'call Mul10SumSqrt_00425830' -> 'call    CallSetPause_0041f830'.
    """
    func_name = 'InstallSelfFourStatePauseChain_0049b000'
    print(f"\n[Fix2] Processing {filepath} for {func_name}")

    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    start_idx, end_idx = find_function_body_range(lines, func_name)
    if start_idx is None:
        print(f"  {func_name}: not defined in this file, skipping.")
        return False

    print(f"  {func_name}: body at lines {start_idx+1}..{end_idx+1}")

    target = re.compile(r'(\s*call\s+)Mul10SumSqrt_00425830')
    changed = False
    for i in range(start_idx, end_idx + 1):
        if target.search(lines[i]):
            old = lines[i]
            lines[i] = target.sub(r'\1CallSetPause_0041f830', lines[i])
            print(f"  Replaced line {i+1}: {old.rstrip()!r} -> {lines[i].rstrip()!r}")
            changed = True
            break

    if not changed:
        print(f"  ERROR: 'call Mul10SumSqrt_00425830' not found in {func_name}")
        return False

    with open(filepath, 'w', encoding='utf-8') as f:
        f.writelines(lines)
    print(f"  Written.")
    return True


def process_fix3_file(filepath):
    """
    Fix 3: Within InstallSelfChainedDispatch_0046cb70 body,
    change 'call TripleFieldCopyJmpHi_0048f740' -> 'call    ScaledZeroFour_00490740'.
    """
    func_name = 'InstallSelfChainedDispatch_0046cb70'
    print(f"\n[Fix3] Processing {filepath} for {func_name}")

    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    start_idx, end_idx = find_function_body_range(lines, func_name)
    if start_idx is None:
        print(f"  {func_name}: not defined in this file, skipping.")
        return False

    print(f"  {func_name}: body at lines {start_idx+1}..{end_idx+1}")

    target = re.compile(r'(\s*call\s+)TripleFieldCopyJmpHi_0048f740')
    changed = False
    for i in range(start_idx, end_idx + 1):
        if target.search(lines[i]):
            old = lines[i]
            lines[i] = target.sub(r'\1ScaledZeroFour_00490740', lines[i])
            print(f"  Replaced line {i+1}: {old.rstrip()!r} -> {lines[i].rstrip()!r}")
            changed = True
            break

    if not changed:
        print(f"  ERROR: 'call TripleFieldCopyJmpHi_0048f740' not found in {func_name}")
        return False

    with open(filepath, 'w', encoding='utf-8') as f:
        f.writelines(lines)
    print(f"  Written.")
    return True


def main():
    base = '/Users/nathan_casab/Documents/MK4/src/engine'

    # Fix 1: files that may define both InstallSelfThreeStateScaledLoad and SiblingPair
    fix1_files = [
        f'{base}/five_block_dispatch_variants.c',
        f'{base}/install3_state_m_stack_counter_dispatch.c',
        f'{base}/install_self_state_countdown.c',
        f'{base}/prefix_thunk_install_self3_state.c',
        # Small files - will skip gracefully if function not defined there
        f'{base}/install4_state_merge.c',
        f'{base}/throw_grab_pose_copy_cluster.c',
    ]

    for fp in fix1_files:
        process_fix1_file(fp)

    # Fix 2
    fix2_files = [
        f'{base}/five_block_dispatch_variants.c',
        f'{base}/install_self_state_countdown.c',
        f'{base}/install3_state_m_stack_counter_dispatch.c',
        f'{base}/prefix_thunk_install_self3_state.c',
    ]
    for fp in fix2_files:
        process_fix2_file(fp)

    # Fix 3
    fix3_files = [
        f'{base}/five_block_dispatch_variants.c',
        f'{base}/install_self_state_countdown.c',
        f'{base}/install3_state_m_stack_counter_dispatch.c',
        f'{base}/prefix_thunk_install_self3_state.c',
        f'{base}/hit_state_cluster.c',
    ]
    for fp in fix3_files:
        process_fix3_file(fp)


if __name__ == '__main__':
    main()
