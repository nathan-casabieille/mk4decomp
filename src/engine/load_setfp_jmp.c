/**
 * 5 "load+set-callback+store+tail-jmp" wrappers (25b).
 */
#include "engine/scenegraph.h"

extern unsigned int g_data_00541e84;   /* 0x00541e84 */
extern unsigned int g_data_00541e88;   /* 0x00541e88 */
extern unsigned int g_data_00541e8c;   /* 0x00541e8c */
extern unsigned int g_data_00541e90;   /* 0x00541e90 */
extern unsigned int g_data_00541e98;   /* 0x00541e98 */

extern void func_00409320(void);   /* 0x00409320 */
extern void func_004bae90(void);   /* 0x004bae90 */

/* @addr 0x00409380 */
__declspec(naked) void LoadSetFpJmp_00409380(void) {
    __asm {
        mov     eax, dword ptr [g_data_00541e8c]
        mov     dword ptr [g_walkCallback], offset func_00409320
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     func_004bae90
    }
}

/* @addr 0x004093a0 */
__declspec(naked) void LoadSetFpJmp_004093a0(void) {
    __asm {
        mov     eax, dword ptr [g_data_00541e88]
        mov     dword ptr [g_walkCallback], offset func_00409320
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     func_004bae90
    }
}

/* @addr 0x004093c0 */
__declspec(naked) void LoadSetFpJmp_004093c0(void) {
    __asm {
        mov     eax, dword ptr [g_data_00541e84]
        mov     dword ptr [g_walkCallback], offset func_00409320
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     func_004bae90
    }
}

/* @addr 0x004093e0 */
__declspec(naked) void LoadSetFpJmp_004093e0(void) {
    __asm {
        mov     eax, dword ptr [g_data_00541e90]
        mov     dword ptr [g_walkCallback], offset func_00409320
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     func_004bae90
    }
}

/* @addr 0x00409400 */
__declspec(naked) void LoadSetFpJmp_00409400(void) {
    __asm {
        mov     eax, dword ptr [g_data_00541e98]
        mov     dword ptr [g_walkCallback], offset func_00409320
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     func_004bae90
    }
}

