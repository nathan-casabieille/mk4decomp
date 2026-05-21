/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c5a90 (50b): wrapper that calls 3 functions on arg */
extern void RangePathIATDispatch_004c6ff0(int);
extern int FSeekImpl_004c5ad0(int, int, int);
extern void RangePathIATDispatch_004c7060(int);
int Helper_FSeek(int arg0, int arg1, int arg2) {
    int saved;
    RangePathIATDispatch_004c6ff0(arg0);
    saved = FSeekImpl_004c5ad0(arg0, arg1, arg2);
    RangePathIATDispatch_004c7060(arg0);
    return saved;
}

