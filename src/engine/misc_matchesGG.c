/**
 * Forty-second batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004ce290 (46b)
 *   96-bit shift left by 1: arg points to {dword[0], dword[1], dword[2]}
 *   shifts the whole 96-bit value left by 1, carrying the high bit between dwords.
 */
__declspec(naked) void Shl96By1_004ce290(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        push    edi
        mov     esi, dword ptr [eax]
        mov     edi, dword ptr [eax + 4]
        mov     ecx, esi
        add     esi, esi
        mov     dword ptr [eax], esi
        lea     esi, [edi + edi*1]
        shr     ecx, 0x1f
        or      esi, ecx
        mov     ecx, dword ptr [eax + 8]
        mov     edx, edi
        mov     dword ptr [eax + 4], esi
        shr     edx, 0x1f
        shl     ecx, 1
        or      ecx, edx
        pop     edi
        mov     dword ptr [eax + 8], ecx
        pop     esi
        ret
    }
}

/* @addr 0x004ce2c0 (45b)
 *   96-bit shift right by 1: counterpart of Shl96By1_004ce290.
 */
__declspec(naked) void Shr96By1_004ce2c0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        push    edi
        mov     edx, dword ptr [eax + 8]
        mov     ecx, dword ptr [eax + 4]
        mov     esi, edx
        mov     edi, ecx
        shl     esi, 0x1f
        shr     ecx, 1
        or      ecx, esi
        mov     dword ptr [eax + 4], ecx
        mov     ecx, dword ptr [eax]
        shl     edi, 0x1f
        shr     ecx, 1
        shr     edx, 1
        or      ecx, edi
        pop     edi
        mov     dword ptr [eax + 8], edx
        mov     dword ptr [eax], ecx
        pop     esi
        ret
    }
}

/* @addr 0x004cf6d0 (40b)
 *   switch (arg) { case 1: errno=0x21; default: ret; case 2..3: errno=0x22; }
 */
extern int *func_004c8ba0(void);
__declspec(naked) void SwitchErrorCode_004cf6d0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        cmp     eax, 1
        _emit   74h
        _emit   13h
        _emit   7eh
        _emit   1ch
        cmp     eax, 3
        _emit   7fh
        _emit   17h
        call    func_004c8ba0
        mov     dword ptr [eax], 0x22
        ret
        call    func_004c8ba0
        mov     dword ptr [eax], 0x21
        ret
    }
}

/* @addr 0x004cf740 (40b)
 *   FPU control word read/modify (preserves FPU state across helper).
 *   fstcw [ebp-4]; ((arg2 & arg1) | (~arg2 & cw)) → ebp+0xc; fldcw; ret movsx (cw).
 */
__declspec(naked) void FpuMaskMerge_004cf740(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        push    ecx
        fstcw   word ptr [ebp - 4]
        mov     eax, dword ptr [ebp + 0x0c]
        mov     ecx, dword ptr [ebp + 8]
        mov     edx, eax
        and     edx, ecx
        mov     ecx, dword ptr [ebp - 4]
        not     eax
        and     eax, ecx
        or      edx, eax
        mov     dword ptr [ebp + 0x0c], edx
        fldcw   word ptr [ebp + 0x0c]
        movsx   eax, cx
        mov     esp, ebp
        pop     ebp
        ret
    }
}

/* @addr 0x004d03c0 (51b)
 *   string convert: each digit '0'..'9' becomes 0..9 in place;
 *   semicolon (';') triggers a memmove-left tail to remove that char and continue.
 */
__declspec(naked) void StringDigitConvert_004d03c0(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
loop_a:
        mov     al,  byte  ptr [ecx]
        test    al, al
        _emit   74h
        _emit   13h
        cmp     al, 0x30
        _emit   7ch
        _emit   10h
        cmp     al, 0x39
        _emit   7fh
        _emit   0ch
        sub     al, 0x30
        mov     byte ptr [ecx], al
loop_inc:
        inc     ecx
        mov     al,  byte  ptr [ecx]
        test    al, al
        _emit   75h
        _emit   0edh
        ret
        cmp     al, 0x3b
        _emit   75h
        _emit   0f4h
        mov     eax, ecx
shift_loop:
        mov     dl,  byte  ptr [eax + 1]
        mov     byte ptr [eax], dl
        mov     dl,  byte  ptr [eax + 1]
        inc     eax
        test    dl, dl
        _emit   75h
        _emit   0f3h
        _emit   0ebh
        _emit   0e4h
    }
}

/* @addr 0x004cba90 (60b)
 *   array search: arg2 = base, edi = g_state_00522904 = entry count;
 *   linearly scan for entry whose dword == arg1; return matching slot or 0.
 */
extern unsigned int g_state_00522904;
__declspec(naked) void ArraySearch_004cba90(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        mov     esi, dword ptr [esp + 0x0c]
        push    edi
        mov     edi, dword ptr [g_state_00522904]
        mov     ecx, dword ptr [esi]
        mov     eax, esi
        cmp     ecx, edx
        _emit   74h
        _emit   11h
        lea     ecx, [edi + edi*2]
        lea     ecx, [esi + ecx*4]
loop_top:
        add     eax, 0x0c
        cmp     eax, ecx
        _emit   73h
        _emit   04h
        cmp     dword ptr [eax], edx
        _emit   75h
        _emit   0f5h
        lea     ecx, [edi + edi*2]
        lea     ecx, [esi + ecx*4]
        cmp     eax, ecx
        _emit   73h
        _emit   04h
        cmp     dword ptr [eax], edx
        _emit   74h
        _emit   02h
        xor     eax, eax
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x004cbaf0 (58b)
 *   indexed-bit test: returns true if a bit is set in g_byte_00f9f8c1[eax]
 *   masked by cl, OR if (g_word_005229a2[eax*2] & arg2) != 0; else false.
 */
extern unsigned char g_byte_00f9f8c1[];
extern unsigned short g_word_005229a2[];
__declspec(naked) void IndexedBitTest_004cbaf0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     cl,  byte  ptr [esp + 0x0c]
        and     eax, 0xff
        test    byte ptr [eax + g_byte_00f9f8c1], cl
        _emit   75h
        _emit   1fh
        mov     ecx, dword ptr [esp + 8]
        test    ecx, ecx
        _emit   74h
        _emit   10h
        xor     edx, edx
        mov     dx,  word  ptr [eax*2 + g_word_005229a2]
        mov     eax, edx
        and     eax, ecx
        _emit   0ebh
        _emit   02h
        xor     eax, eax
        test    eax, eax
        _emit   75h
        _emit   01h
        ret
        mov     eax, 1
        ret
    }
}

/* @addr 0x004cc030 (61b)
 *   if (g_state_00f9f84c == 1 || (==0 && g_state_00520064 == 1)):
 *     call F2(0xfc); call (g_state_00f9fbfc); call F2(0xff).
 */
extern unsigned int g_state_00f9f84c_gg;
extern unsigned int g_state_00520064;
extern void (*g_state_00f9fbfc)(void);
extern void func_004cc070_gg(int);
__declspec(naked) void DualCondCleanupCall_004cc030(void) {
    __asm {
        mov     eax, dword ptr [g_state_00f9f84c_gg]
        cmp     eax, 1
        _emit   74h
        _emit   0dh
        test    eax, eax
        _emit   75h
        _emit   2eh
        cmp     dword ptr [g_state_00520064], 1
        _emit   75h
        _emit   25h
        push    0xfc
        call    func_004cc070_gg
        mov     eax, dword ptr [g_state_00f9fbfc]
        add     esp, 4
        test    eax, eax
        _emit   74h
        _emit   02h
        call    eax
        push    0xff
        call    func_004cc070_gg
        add     esp, 4
        ret
    }
}

/* @addr 0x004cc4c0 (59b)
 *   FPU control word transactional update via two helpers (4cc520, 4cc5c0).
 *   Reads cw, computes new value, then sets new cw and returns the masked old value.
 */
extern int func_004cc520(int);
extern int func_004cc5c0(int);
__declspec(naked) void FpuCwTxn_004cc4c0(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        push    ecx
        push    esi
        fstcw   word ptr [ebp - 4]
        mov     eax, dword ptr [ebp - 4]
        push    eax
        call    func_004cc520
        mov     ecx, dword ptr [ebp + 0x0c]
        mov     edx, dword ptr [ebp + 8]
        mov     esi, ecx
        add     esp, 4
        not     ecx
        and     esi, edx
        and     ecx, eax
        or      esi, ecx
        push    esi
        call    func_004cc5c0
        add     esp, 4
        mov     dword ptr [ebp + 0x0c], eax
        fldcw   word ptr [ebp + 0x0c]
        mov     eax, esi
        pop     esi
        mov     esp, ebp
        pop     ebp
        ret
    }
}

/* @addr 0x004cd920 (47b)
 *   strnlen(arg, n): scan up to n bytes for NUL; return offset or n.
 */
__declspec(naked) void StrNLen_004cd920(void) {
    __asm {
        mov     edx, dword ptr [esp + 8]
        push    esi
        mov     esi, dword ptr [esp + 8]
        test    edx, edx
        push    edi
        mov     eax, esi
        lea     ecx, [edx - 1]
        _emit   74h
        _emit   0dh
loop_b:
        cmp     byte ptr [eax], 0
        _emit   74h
        _emit   08h
        inc     eax
        mov     edi, ecx
        dec     ecx
        test    edi, edi
        _emit   75h
        _emit   0f3h
done:
        cmp     byte ptr [eax], 0
        _emit   75h
        _emit   05h
        sub     eax, esi
        pop     edi
        pop     esi
        ret
        pop     edi
        pop     esi
        mov     eax, edx
        ret
    }
}
