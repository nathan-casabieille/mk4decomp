/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004cbb30 (238b crt) - CRT environment-string parser (envp builder).
 *   Reads NUL-separated env string at [g_initRet]; counts non-'=' tokens.
 *   Allocates (count+1)*4 byte ptr array, stores at [g_dispatchSave1426].
 *   Iterates env: for each token (until '='), allocates buffer, copies chars
 *   via rep movsd/movsb, stores ptr in next slot.
 *   Frees the env source string; writes NULL terminator at end of array.
 */
extern unsigned int g_dispatchSave1426;
extern u32 g_initRet;
extern void CmpCallPushIATCall(void);
extern void FreeImpl(void);
extern void LoadArgPushCall(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void _init_main(void)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int *local_4;
  
  iVar8 = 0;
  cVar2 = *g_initRet;
  pcVar7 = g_initRet;
  while (cVar2 != '\0') {
    if (cVar2 != '=') {
      iVar8 = iVar8 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar2 != '\0');
    pcVar9 = pcVar7 + ~uVar4;
    pcVar7 = pcVar7 + ~uVar4;
    cVar2 = *pcVar9;
  }
  piVar3 = (int *)LoadArgPushCall(iVar8 * 4 + 4);
  g_dispatchSave1426 = piVar3;
  if (piVar3 == (int *)0x0) {
    __amsg_exit(9);
  }
  cVar2 = *g_initRet;
  local_4 = piVar3;
  pcVar7 = g_initRet;
  do {
    if (cVar2 == '\0') {
      FreeImpl(g_initRet);
      g_initRet = (char *)0x0;
      *piVar3 = 0;
      return;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    if (cVar2 != '=') {
      iVar8 = LoadArgPushCall(uVar4);
      *piVar3 = iVar8;
      if (iVar8 == 0) {
        __amsg_exit(9);
      }
      uVar5 = 0xffffffff;
      pcVar9 = pcVar7;
      do {
        pcVar10 = pcVar9;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar10 = pcVar9 + 1;
        cVar2 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      pcVar9 = pcVar10 + -uVar5;
      pcVar10 = (char *)*local_4;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      piVar3 = local_4 + 1;
      for (uVar5 = uVar5 & 3; local_4 = piVar3, uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    cVar2 = pcVar7[uVar4];
    pcVar7 = pcVar7 + uVar4;
  } while( true );
}
#else
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
        call    LoadArgPushCall
        mov     esi, eax
        add     esp, 4
        test    esi, esi
        mov     [esp + 0x10], esi
        mov     dword ptr [g_dispatchSave1426], esi
        jne     short L_ep_haveBuf
        push    9
        call    CmpCallPushIATCall
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
        call    LoadArgPushCall
        add     esp, 4
        mov     [esi], eax
        test    eax, eax
        jne     short L_ep_copyToken
        push    9
        call    CmpCallPushIATCall
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
        call    FreeImpl
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
#endif

