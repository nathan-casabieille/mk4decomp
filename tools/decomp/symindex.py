"""Build symbol -> defining .c file index for the engine corpus."""
import re, json
from pathlib import Path
# A definition: optional storage/qualifiers, return type, NAME(args) {  -- at top level.
# Catch both pure-C and naked. Exclude 'extern' decls and calls.
defre = re.compile(r'^(?:__declspec\(naked\)\s*)?(?:static\s+)?'
                   r'(?:unsigned\s+|signed\s+)?[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*\{',
                   re.M)
idx = {}
for f in Path('src').rglob('*.c'):
    s = f.read_text(errors='ignore')
    # strip line comments crudely to avoid false hits
    for m in defre.finditer(s):
        name = m.group(1)
        # skip control keywords
        if name in ('if','for','while','switch','return','sizeof','do'): continue
        idx.setdefault(name, []).append(str(f))
json.dump(idx, open('/tmp/symidx.json','w'))
print('indexed symbols:', len(idx), 'from', len(list(Path("src").rglob("*.c"))), 'files')
# sanity
for n in ['GameLogicStep','DrawScene','FlushDrawQueue','BeginFrame']:
    print('  %-16s -> %s'%(n, idx.get(n)))
