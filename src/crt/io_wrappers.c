/**
 * 3 "file-handle CRT wrapper" helpers (114 bytes each).
 *
 * MSVC 5.0 CRT pattern for file-handle-based ops (_read / _write /
 * _lseek). Each wrapper:
 *   1. Validates handle against g_handleCount (out-of-bounds -> errno).
 *   2. Indexes into g_validityTable to check the handle bit.
 *   3. Calls _lock_fhandle (0x004cd2b0).
 *   4. Tail-calls into the per-op implementation (FileOpen / Read /
 *      LSeek -- one of three).
 *   5. Calls _unlock_fhandle (0x004cd320).
 *   6. Returns the saved op result, or sets errno on validation fail.
 *
 * Pattern (decoded layout):
 *   mov     eax, [g_handleCount]
 *   push    esi
 *   mov     esi, [esp+8]
 *   push    edi
 *   cmp     esi, eax
 *   jae     .err
 *   mov     eax, esi
 *   mov     ecx, esi
 *   and     eax, 0x1f
 *   sar     ecx, 5
 *   lea     edx, [eax + eax*8]            ; edx = 5 * eax
 *   mov     eax, [ecx*4 + g_validityTable]
 *   test    byte ptr [eax + edx*4 + 4], 1
 *   jne     .ret_zero                     ; (or actual fall-through?)
 *   push    esi
 *   call    _lock_fhandle
 *   mov     ecx, [esp+0x18]
 *   mov     edx, [esp+0x14]
 *   add     esp, 4
 *   push    ecx
 *   push    edx
 *   push    esi
 *   call    OpImpl                         ; per-helper
 *   add     esp, 0x0c
 *   mov     edi, eax
 *   push    esi
 *   call    _unlock_fhandle
 *   add     esp, 4
 *   mov     eax, edi
 *   pop     edi
 *   pop     esi
 *   ret
 * .err:
 *   call    _doserrno_addr
 *   mov     [eax], 9
 *   call    _errno_addr
 *   mov     [eax], 0
 *   pop     edi
 *   or      eax, -1
 *   pop     esi
 *   ret
 */

extern unsigned int g_handleCount_004ffae0;   /* 0x004ffae0 */
extern unsigned int g_validityTable_004fdae0; /* 0x004fdae0 (-> indexed by ecx*4) */

extern void func_004cd2b0(int);   /* _lock_fhandle */
extern void func_004cd320(int);   /* _unlock_fhandle */
extern void *func_004c8ba0(void); /* &__doserrno */
extern void *func_004c8bb0(void); /* &errno */

extern int  func_004c8e50(int handle, int a, int b);   /* per-helper op */
extern int  func_004c9040(int handle, int a, int b);
extern int  func_004c9b60(int handle, int a, int b);

/* @addr 0x004c8dd0 */
__declspec(naked) void IOWrapper_004c8dd0(void) {
    __asm {
        mov     eax, dword ptr [g_handleCount_004ffae0]
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    edi
        cmp     esi, eax
        _emit   73h
        _emit   47h
        mov     eax, esi
        mov     ecx, esi
        and     eax, 0x1f
        sar     ecx, 5
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [ecx*4 + g_validityTable_004fdae0]
        test    byte ptr [eax + edx*4 + 4], 1
        _emit   74h
        _emit   2ch
        push    esi
        call    func_004cd2b0
        mov     ecx, dword ptr [esp + 0x18]
        mov     edx, dword ptr [esp + 0x14]
        add     esp, 4
        push    ecx
        push    edx
        push    esi
        call    func_004c8e50
        add     esp, 0x0c
        mov     edi, eax
        push    esi
        call    func_004cd320
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
        call    func_004c8ba0
        mov     dword ptr [eax], 9
        call    func_004c8bb0
        mov     dword ptr [eax], 0
        pop     edi
        or      eax, 0xffffffff
        pop     esi
        ret
    }
}

/* @addr 0x004c8fc0 */
__declspec(naked) void IOWrapper_004c8fc0(void) {
    __asm {
        mov     eax, dword ptr [g_handleCount_004ffae0]
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    edi
        cmp     esi, eax
        _emit   73h
        _emit   47h
        mov     eax, esi
        mov     ecx, esi
        and     eax, 0x1f
        sar     ecx, 5
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [ecx*4 + g_validityTable_004fdae0]
        test    byte ptr [eax + edx*4 + 4], 1
        _emit   74h
        _emit   2ch
        push    esi
        call    func_004cd2b0
        mov     ecx, dword ptr [esp + 0x18]
        mov     edx, dword ptr [esp + 0x14]
        add     esp, 4
        push    ecx
        push    edx
        push    esi
        call    func_004c9040
        add     esp, 0x0c
        mov     edi, eax
        push    esi
        call    func_004cd320
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
        call    func_004c8ba0
        mov     dword ptr [eax], 9
        call    func_004c8bb0
        mov     dword ptr [eax], 0
        pop     edi
        or      eax, 0xffffffff
        pop     esi
        ret
    }
}

/* @addr 0x004c9ae0 */
__declspec(naked) void IOWrapper_004c9ae0(void) {
    __asm {
        mov     eax, dword ptr [g_handleCount_004ffae0]
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    edi
        cmp     esi, eax
        _emit   73h
        _emit   47h
        mov     eax, esi
        mov     ecx, esi
        and     eax, 0x1f
        sar     ecx, 5
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [ecx*4 + g_validityTable_004fdae0]
        test    byte ptr [eax + edx*4 + 4], 1
        _emit   74h
        _emit   2ch
        push    esi
        call    func_004cd2b0
        mov     ecx, dword ptr [esp + 0x18]
        mov     edx, dword ptr [esp + 0x14]
        add     esp, 4
        push    ecx
        push    edx
        push    esi
        call    func_004c9b60
        add     esp, 0x0c
        mov     edi, eax
        push    esi
        call    func_004cd320
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
        call    func_004c8ba0
        mov     dword ptr [eax], 9
        call    func_004c8bb0
        mov     dword ptr [eax], 0
        pop     edi
        or      eax, 0xffffffff
        pop     esi
        ret
    }
}
