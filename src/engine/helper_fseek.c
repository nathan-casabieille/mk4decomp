/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c5a90 (50b): wrapper that calls 3 functions on arg */
extern void RangePathIATDispatch_Lock(int);
extern int FSeekImpl(int, int, int);
extern void RangePathIATDispatch_TableLookupIatCall(int);
int Helper_FSeek(int arg0, int arg1, int arg2) {
    int saved;
    RangePathIATDispatch_Lock(arg0);
    saved = FSeekImpl(arg0, arg1, arg2);
    RangePathIATDispatch_TableLookupIatCall(arg0);
    return saved;
}

