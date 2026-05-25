/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004cbb30 (238b crt) - CRT environment-string parser (envp builder).
 *   Reads NUL-separated env string at [g_initRet]; counts non-'=' tokens.
 *   Allocates (count+1)*4 byte ptr array, stores at [g_dispatchSave1426_00f9f820].
 *   Iterates env: for each token (until '='), allocates buffer, copies chars
 *   via rep movsd/movsb, stores ptr in next slot.
 *   Frees the env source string; writes NULL terminator at end of array.
 */
extern unsigned int g_dispatchSave1426_00f9f820;
extern u32 g_initRet;
extern void CmpCallPushIATCall_004c6e60(void);
extern void FreeImpl_004c55f0(void);
extern void LoadArgPushCall_004c54b0(void);

__declspec(naked) void _init_main(void) {
    __asm {
        push    ecx
        mov     edx, dword ptr [g_initRet]
        push    ebx
        push    ebp
        push    esi
        mov     al, [edx]
        xor     esi, esi
        test    al, al
        push    edi
        jz      short L_ep_alloc
    L_ep_countLoop:
        cmp     al, 0x3d
        jz      short L_ep_skipInc
        inc     esi
    L_ep_skipInc:
        mov     edi, edx
        or      ecx, -1
        xor     eax, eax
        repne   scasb
        not     ecx
        dec     ecx
        mov     al, [edx + ecx + 1]
        lea     edx, [edx + ecx + 1]
        test    al, al
        jne     short L_ep_countLoop
    L_ep_alloc:
        lea     eax, [esi*4 + 4]
        push    eax
        call    LoadArgPushCall_004c54b0
        mov     esi, eax
        add     esp, 4
        test    esi, esi
        mov     [esp + 0x10], esi
        mov     dword ptr [g_dispatchSave1426_00f9f820], esi
        jne     short L_ep_haveBuf
        push    9
        call    CmpCallPushIATCall_004c6e60
        add     esp, 4
    L_ep_haveBuf:
        mov     ebp, dword ptr [g_initRet]
        mov     dl, [ebp]
        test    dl, dl
        jz      short L_ep_finalize
    L_ep_outer:
        mov     edi, ebp
        or      ecx, -1
        xor     eax, eax
        repne   scasb
        not     ecx
        dec     ecx
        mov     ebx, ecx
        inc     ebx
        cmp     dl, 0x3d
        jz      short L_ep_advance
        push    ebx
        call    LoadArgPushCall_004c54b0
        add     esp, 4
        mov     [esi], eax
        test    eax, eax
        jne     short L_ep_copyToken
        push    9
        call    CmpCallPushIATCall_004c6e60
        add     esp, 4
    L_ep_copyToken:
        mov     edi, ebp
        or      ecx, -1
        xor     eax, eax
        repne   scasb
        mov     eax, [esp + 0x10]
        not     ecx
        sub     edi, ecx
        mov     edx, ecx
        mov     esi, edi
        mov     edi, [eax]
        shr     ecx, 2
        rep     movsd
        mov     ecx, edx
        and     ecx, 3
        add     eax, 4
        rep     movsb
        mov     [esp + 0x10], eax
        mov     esi, eax
    L_ep_advance:
        mov     dl, [ebp + ebx]
        add     ebp, ebx
        test    dl, dl
        jne     short L_ep_outer
    L_ep_finalize:
        mov     eax, dword ptr [g_initRet]
        push    eax
        call    FreeImpl_004c55f0
        add     esp, 4
        mov     dword ptr [g_initRet], 0
        mov     dword ptr [esi], 0
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}

