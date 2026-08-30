/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004b2d20 (338b engine.app) - 3D vertex transform + perspective project.
 *   Reads vertex idx ecx; applies 3x3 matrix at g_vtxMat..0x7af9a0 to
 *   (x,y,z) at g_vtxIn_x/95e/964[ecx]; adds translation 0x7af9a4/a8/ac.
 *   Stores transformed XYZ at [0x7af96c/78/84][ecx*4].
 *   Perspective divide: if Z > 1, scale = 0x02000000/Z; project X via
 *   scale*0x19999a (offset 0x140 = 320 center); Y via scale * 15 * 8192/65536
 *   (offset 0xf0 = 240 center). Stores screen XY (word) at 0x7af9b4/b6.
 */
extern s16 g_vtxIn_x;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn2_y;
extern s32 g_vtxOut1_x;
extern s32 g_vtxOut1_y;
extern unsigned int g_triStripRingB;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af992;
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af996;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99a;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af99e;
extern unsigned int g_mat3x3_007af9a0;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;
extern s32 g_vtxOut1_z;
extern s16 g_dispatchSave1626;
extern s16 g_mat3x3_007af990;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_dispatchSave1626 (*(short *)MK4_VA(short, 0x7af958u))
#define g_mat3x3_007af990 (*(short *)MK4_VA(short, 0x7af990u))
#define g_mat3x3_007af992 (*(short *)MK4_VA(short, 0x7af992u))
#define g_mat3x3_007af994 (*(short *)MK4_VA(short, 0x7af994u))
#define g_mat3x3_007af996 (*(short *)MK4_VA(short, 0x7af996u))
#define g_mat3x3_007af998 (*(short *)MK4_VA(short, 0x7af998u))
#define g_mat3x3_007af99a (*(short *)MK4_VA(short, 0x7af99au))
#define g_mat3x3_007af99c (*(short *)MK4_VA(short, 0x7af99cu))
#define g_mat3x3_007af99e (*(short *)MK4_VA(short, 0x7af99eu))
#define g_mat3x3_007af9a0 (*(short *)MK4_VA(short, 0x7af9a0u))
#define g_triStripRingA (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b4u))
#define g_triStripRingB (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_vtxIn1_y (*(short *)MK4_VA(short, 0x7af95eu))
#define g_vtxIn2_y (*(short *)MK4_VA(short, 0x7af964u))
#define g_vtxMat (*(short *)MK4_VA(short, 0x7af990u))
#define g_vtxOut1_x (*(int *)MK4_VA(int, 0x7af96cu))
#define g_vtxOut1_y (*(int *)MK4_VA(int, 0x7af978u))
#define g_vtxOut1_z (*(int *)MK4_VA(int, 0x7af984u))
#define g_vtxScreenP1Y (*(short *)MK4_VA(short, 0x7af9b6u))
#define g_vtxTransX (*(int *)MK4_VA(int, 0x7af9a4u))
#define g_vtxTransY (*(int *)MK4_VA(int, 0x7af9a8u))
#define g_vtxTransZ (*(int *)MK4_VA(int, 0x7af9acu))
#define g_vtxValid (*(int *)MK4_VA(int, 0x7af9b0u))
#endif



#ifdef NON_MATCHING
/* Co-exec verified (tools/decomp/verify_project.py, slots 0/1/2).
 *
 * Transcribed from the original bytes rather than trusting the Ghidra lift,
 * which had two defects the verifier would not have caught on its own:
 *   - the perspective divide was lifted as `0x2000000 / (longlong)z`; the
 *     original is `cmp esi,1 / jle / cdq / idiv esi` - a SIGNED 32-bit idiv.
 *     The 64-bit form pulls in __divdi3 and changes the semantics.
 *   - the array strides were only correct under Ghidra's own `undefined2`
 *     typing of the globals (`&g_vtxOut1_x + param_1 * 2`). Here every base is
 *     taken as an address and cast, so the stride is fixed by the ORIGINAL
 *     instruction form (movsx word [ecx*2 + b] for inputs, [ecx*4 + b] for
 *     outputs) and does not depend on how each global happens to be declared.
 *
 * Sums accumulate through `unsigned` because three 16x16 products can exceed
 * INT_MAX; signed overflow is UB and -O2 is entitled to exploit it (the same
 * class of bug that miscompiled the triangle twins).
 */
void Helper_EmitLine(int param_1)
{
    /* inputs: three s16 vectors, stride 2 (orig: movsx word [ecx*2 + base]) */
    const short *inX = (const short *)&g_dispatchSave1626;   /* 0x7af958 */
    const short *inY = (const short *)&g_vtxIn1_y;           /* 0x7af95e */
    const short *inZ = (const short *)&g_vtxIn2_y;           /* 0x7af964 */
    /* outputs: s32 vectors, stride 4 (orig: mov [ecx*4 + base]) */
    int *outX = (int *)&g_vtxOut1_x;                         /* 0x7af96c */
    int *outY = (int *)&g_vtxOut1_y;                         /* 0x7af978 */
    int *outZ = (int *)&g_vtxOut1_z;                         /* 0x7af984 */
    /* screen pair: two s16 packed in each 4-byte slot at 0x7af9b4/+2 */
    short *scr = (short *)&g_triStripRingA;
    const short *m = (const short *)&g_mat3x3_007af990;      /* nine s16, +2 */
    int i = param_1;
    int z, inv, t;
    unsigned acc;

    g_vtxValid = 1;


    acc = (unsigned)((int)m[0] * (int)inX[i]) + (unsigned)((int)m[1] * (int)inY[i])
        + (unsigned)((int)m[2] * (int)inZ[i]);
    outX[i] = (short)(((int)acc >> 0xc) + (int)g_vtxTransX);

    acc = (unsigned)((int)m[3] * (int)inX[i]) + (unsigned)((int)m[4] * (int)inY[i])
        + (unsigned)((int)m[5] * (int)inZ[i]);
    outY[i] = (short)(((int)acc >> 0xc) + (int)g_vtxTransY);

    acc = (unsigned)((int)m[6] * (int)inX[i]) + (unsigned)((int)m[7] * (int)inY[i])
        + (unsigned)((int)m[8] * (int)inZ[i]);
#ifdef TARGET_SDL
    /* MK4_TRACE_CLIP: the original truncates each transformed component to
     * 16 bits (movsx eax, ax). Fighters fit; a stage might not, and a
     * wrapped vertex lands on the far side of the world, which draws as a
     * long thin sliver. Count how often the value does not survive. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int seen, over;
      if (getenv("MK4_TRACE_CLIP")) {
          int px = ((int)((unsigned)((int)m[0] * (int)inX[i])
                        + (unsigned)((int)m[1] * (int)inY[i])
                        + (unsigned)((int)m[2] * (int)inZ[i])) >> 0xc)
                   + (int)g_vtxTransX;
          int pz = ((int)acc >> 0xc) + (int)g_vtxTransZ;
          seen++;
          if (px != (int)(short)px || pz != (int)(short)pz) over++;
          if ((seen % 4000) == 0)
              SDL_Log("CLIP %d/%d vertices overflow 16 bits (last x=%d z=%d)",
                      over, seen, px, pz); } }
#endif
    z = (short)(((int)acc >> 0xc) + (int)g_vtxTransZ);
    outZ[i] = z;

    inv = 0x2000000;
    if (z > 1)
        inv = 0x2000000 / z;               /* orig: cdq / idiv esi (signed) */

    t = (int)((unsigned)inv * (unsigned)outX[i]) >> 0x10;
    scr[i * 2]     = (short)((int)((unsigned)t * 0x1999au) >> 0x10) + 0x140;
    t = (int)((unsigned)inv * (unsigned)outY[i]) >> 0x10;
    scr[i * 2 + 1] = (short)((int)((unsigned)t * 0x1e000u) >> 0x10) + 0xf0;
}
#else
__declspec(naked) void Helper_EmitLine(void) {
    __asm {
        mov     ecx, [esp + 4]
        mov     dword ptr [g_vtxValid], 1
        movsx   eax, word ptr [g_vtxMat]
        movsx   edx, word ptr [ecx*2 + g_vtxIn_x]
        imul    eax, edx
        movsx   edx, word ptr [g_mat3x3_007af992]
        push    esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn1_y]
        imul    edx, esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn2_y]
        add     eax, edx
        movsx   edx, word ptr [g_mat3x3_007af994]
        imul    edx, esi
        add     eax, edx
        mov     edx, dword ptr [g_vtxTransX]
        sar     eax, 0x0c
        add     eax, edx
        movsx   eax, ax
        mov     dword ptr [ecx*4 + g_vtxOut1_x], eax
        movsx   edx, word ptr [g_mat3x3_007af996]
        movsx   eax, word ptr [ecx*2 + g_vtxIn_x]
        movsx   esi, word ptr [ecx*2 + g_vtxIn1_y]
        imul    edx, eax
        movsx   eax, word ptr [g_mat3x3_007af998]
        imul    eax, esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn2_y]
        add     edx, eax
        movsx   eax, word ptr [g_mat3x3_007af99a]
        imul    eax, esi
        add     edx, eax
        mov     eax, dword ptr [g_vtxTransY]
        sar     edx, 0x0c
        add     edx, eax
        movsx   edx, dx
        mov     dword ptr [ecx*4 + g_vtxOut1_y], edx
        movsx   eax, word ptr [g_mat3x3_007af99c]
        movsx   edx, word ptr [ecx*2 + g_vtxIn_x]
        movsx   esi, word ptr [ecx*2 + g_vtxIn1_y]
        imul    eax, edx
        movsx   edx, word ptr [g_mat3x3_007af99e]
        imul    edx, esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn2_y]
        add     eax, edx
        movsx   edx, word ptr [g_mat3x3_007af9a0]
        imul    edx, esi
        mov     esi, dword ptr [g_vtxTransZ]
        add     eax, edx
        sar     eax, 0x0c
        add     eax, esi
        movsx   esi, ax
        cmp     esi, 1
        mov     dword ptr [ecx*4 + g_triStripRingB], esi
        mov     eax, 0x02000000
        jle     short L_vp3_skipDiv
        cdq
        idiv    esi
    L_vp3_skipDiv:
        mov     edx, eax
        pop     esi
        imul    edx, dword ptr [ecx*4 + g_vtxOut1_x]
        sar     edx, 0x10
        imul    edx, 0x0001999a
        sar     edx, 0x10
        add     edx, 0x140
        mov     word ptr [ecx*4 + g_triStripRingA], dx
        imul    eax, dword ptr [ecx*4 + g_vtxOut1_y]
        sar     eax, 0x10
        lea     eax, [eax + eax*2]
        lea     eax, [eax + eax*4]
        shl     eax, 0x0d
        sar     eax, 0x10
        add     eax, 0xf0
        mov     word ptr [ecx*4 + g_vtxScreenP1Y], ax
        ret
    }
}
#endif

