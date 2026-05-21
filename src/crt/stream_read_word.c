/**
 * Stream read - 16-bit word (advances pointer by 4 to match the 32-bit
 * sister functions stream_read_dword.c and stream_read_qword.c).
 */
#include "engine/scenegraph.h"

/* @addr 0x004c83c0 (18b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [eax]
 *   mov     edx, [ecx]
 *   add     ecx, 4
 *   mov     [eax], ecx
 *   movzx   eax, dx
 *   ret
 */
unsigned short StreamReadWord_004c83c0(unsigned char **stream) {
    unsigned char *p = *stream;
    *stream = p + 4;
    p = *stream;
    return *(unsigned short *)(p - 4);
}
