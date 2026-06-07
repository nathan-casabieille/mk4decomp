/**
 * ECM cleanup: tear down the playback thread, the DirectSound buffer
 * and any open file handle. Called when the cinematic finishes or is
 * skipped.
 */
#include "engine/ecm.h"
#include "portable/ghidra_types.h"
#include "platform/win32.h"

/*
 * @addr 0x004b0cb0
 *

 * Naked + __asm: the function is a chain of side-effecting Win32 /
 * COM calls with very specific scheduling (push esi/edi early so
 * `Sleep` cached in edi is reused both before and after the wait
 * loop, push of the helper arg interleaved with the rep stosd, and
 * pop edi between the fclose-cleanup and the final g_ecmFile = 0
 * store). Pure C re-orders enough that we never hit byte equality.
 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void ECM_Cleanup(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (g_ecmThread != (HANDLE)0x0) {
    for (iVar1 = 0; (g_ecmThreadStatus != 0 && (iVar1 < 3000)); iVar1 = iVar1 + 100) {
      Sleep(100);
    }
    Sleep(100);
    TerminateThread(g_ecmThread,0);
    CloseHandle(g_ecmThread);
    g_ecmThread = (HANDLE)0x0;
  }
  if (g_ecmDSBuffer != (int *)0x0) {
    (*(MK4ComMethod *)(*g_ecmDSBuffer + 0x3c))(g_ecmDSBuffer,0xffffd8f0);
    (*(MK4ComMethod *)(*g_ecmDSBuffer + 0x48))(g_ecmDSBuffer);
    (*(MK4ComMethod *)(*g_ecmDSBuffer + 8))(g_ecmDSBuffer);
    g_ecmDSBuffer = (int *)0x0;
  }
  puVar2 = &g_ecmHeaderBuf;
  for (iVar1 = 0x386; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  Helper_ECM_PostCleanup(0);
  if (g_ecmFile != 0) {
    Helper_FClose(g_ecmFile);
  }
  g_ecmFile = 0;
  return;
}
#else
__declspec(naked) void ECM_Cleanup(void)
{
    __asm {
        mov     eax, dword ptr [g_ecmThread]
        push    esi
        test    eax, eax
        push    edi
        jz      after_thread
        mov     eax, dword ptr [g_ecmThreadStatus]
        mov     edi, dword ptr [Sleep]
        xor     esi, esi
        test    eax, eax
        jz      after_wait
wait_loop:
        cmp     esi, 0xbb8                          ; 3000 ms cap
        jge     after_wait
        push    100
        call    edi                                  ; Sleep(100)
        mov     eax, dword ptr [g_ecmThreadStatus]
        add     esi, 100
        test    eax, eax
        jne     wait_loop
after_wait:
        push    100
        call    edi                                  ; final Sleep(100)
        mov     eax, dword ptr [g_ecmThread]
        push    0
        push    eax
        call    dword ptr [TerminateThread]
        mov     ecx, dword ptr [g_ecmThread]
        push    ecx
        call    dword ptr [CloseHandle]
        mov     dword ptr [g_ecmThread], 0
after_thread:
        mov     eax, dword ptr [g_ecmDSBuffer]
        test    eax, eax
        jz      after_dsbuf
        mov     edx, dword ptr [eax]                 ; vtbl
        push    -10000
        push    eax
        call    dword ptr [edx + 0x3c]               ; SetVolume(-10000)
        mov     eax, dword ptr [g_ecmDSBuffer]
        push    eax
        mov     ecx, dword ptr [eax]
        call    dword ptr [ecx + 0x48]               ; Stop()
        mov     eax, dword ptr [g_ecmDSBuffer]
        push    eax
        mov     edx, dword ptr [eax]
        call    dword ptr [edx + 0x08]               ; Release()
        mov     dword ptr [g_ecmDSBuffer], 0
after_dsbuf:
        mov     ecx, 0x386                           ; 902 dwords = 3608 bytes
        xor     eax, eax
        mov     edi, offset g_ecmHeaderBuf
        push    eax                                   ; 0 arg for helper
        rep     stosd
        call    Helper_ECM_PostCleanup
        mov     eax, dword ptr [g_ecmFile]
        add     esp, 4
        test    eax, eax
        jz      after_file
        push    eax
        call    Helper_FClose
        add     esp, 4
after_file:
        pop     edi
        mov     dword ptr [g_ecmFile], 0
        pop     esi
        ret
    }
}
#endif
