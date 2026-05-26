/**
 * Minimal Release-only COM facade for renderer cleanup patterns.
 *
 * Many "release-and-null" sequences in the renderer cleanup paths
 * compile to `mov ecx,[eax]; push eax; call [ecx+8]` - i.e. read
 * vtable pointer at +0, then call vtable slot 2 (= IUnknown::Release).
 *
 * Using `p->vtbl->Release(p)` instead of
 * `((unsigned int (__stdcall **)(void*))(*(void**)p))[2](p)` produces
 * byte-identical MSVC SP3 codegen.
 *
 * Named `Mk4ComObj` to avoid colliding with the MSVC 5.0 standard
 * `IUnknown` / `IUnknownVtbl` definitions in <objbase.h>.
 */
#ifndef MK4_ENGINE_COM_H
#define MK4_ENGINE_COM_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Mk4ComObj Mk4ComObj;
typedef unsigned int (__stdcall *Mk4ComObj_Release_t)(Mk4ComObj *self);

typedef struct Mk4ComObjVtbl {
    void               *m_0_to_1[2];   /* QueryInterface, AddRef */
    Mk4ComObj_Release_t Release;       /* slot 2 = offset 0x08   */
} Mk4ComObjVtbl;

struct Mk4ComObj {
    Mk4ComObjVtbl *vtbl;
};

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_COM_H */
