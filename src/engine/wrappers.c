/**
 * 43 single-arg call-and-return wrappers.
 *
 * Each compiles to `push CONST; call Target; add esp, 4; ret`
 * (14 bytes). Likely auto-generated trampolines for static-init
 * constructors or per-table dispatch helpers.
 */

/* Externs for wrapper targets. */
extern void func_004049d0(unsigned int arg);   /* 0x004049d0 */
extern void func_0041fcc0(unsigned int arg);   /* 0x0041fcc0 */
extern void func_004392c0(unsigned int arg);   /* 0x004392c0 */
extern void func_004399c0(unsigned int arg);   /* 0x004399c0 */
extern void func_004594f0(unsigned int arg);   /* 0x004594f0 */
extern void func_00489ee0(unsigned int arg);   /* 0x00489ee0 */
extern void func_0048e590(unsigned int arg);   /* 0x0048e590 */
extern void func_0048fd30(unsigned int arg);   /* 0x0048fd30 */
extern void func_00491520(unsigned int arg);   /* 0x00491520 */

/* The wrappers. */
/* @addr 0x0041fcf0 */
void Wrapper_0041fcf0(void) { func_0041fcc0(0x004de3f8u); }

/* @addr 0x0041fd00 */
void Wrapper_0041fd00(void) { func_0041fcc0(0x004d8e80u); }

/* @addr 0x00433940 */
void Wrapper_00433940(void) { func_004392c0(0x004e44f0u); }

/* @addr 0x00436490 */
void Wrapper_00436490(void) { func_004392c0(0x004e46d0u); }

/* @addr 0x00436760 */
void Wrapper_00436760(void) { func_004392c0(0x004e4708u); }

/* @addr 0x00436770 */
void Wrapper_00436770(void) { func_004392c0(0x004e4718u); }

/* @addr 0x004377c0 */
void Wrapper_004377c0(void) { func_004399c0(0x004e4810u); }

/* @addr 0x00438c40 */
void Wrapper_00438c40(void) { func_004399c0(0x004e4850u); }

/* @addr 0x00438ed0 */
void Wrapper_00438ed0(void) { func_004399c0(0x004e4950u); }

/* @addr 0x00438ee0 */
void Wrapper_00438ee0(void) { func_004399c0(0x004e4990u); }

/* @addr 0x00439310 */
void Wrapper_00439310(void) { func_0048e590(0x005422f0u); }

/* @addr 0x0043abf0 */
void Wrapper_0043abf0(void) { func_004392c0(0x004e4a58u); }

/* @addr 0x0043ac00 */
void Wrapper_0043ac00(void) { func_004392c0(0x004e4a70u); }

/* @addr 0x00471340 */
void Wrapper_00471340(void) { func_004594f0(0x004eba28u); }

/* @addr 0x0047d6d0 */
void Wrapper_0047d6d0(void) { func_004594f0(0x004ed440u); }

/* @addr 0x0047ed80 */
void Wrapper_0047ed80(void) { func_004594f0(0x004ed660u); }

/* @addr 0x00481060 */
void Wrapper_00481060(void) { func_0048fd30(0x004ed980u); }

/* @addr 0x00484470 */
void Wrapper_00484470(void) { func_004594f0(0x004ee850u); }

/* @addr 0x00484d90 */
void Wrapper_00484d90(void) { func_004594f0(0x004ee958u); }

/* @addr 0x00487140 */
void Wrapper_00487140(void) { func_004594f0(0x004eeeb0u); }

/* @addr 0x00488bd0 */
void Wrapper_00488bd0(void) { func_00491520(0x004ef1e8u); }

/* @addr 0x00488c60 */
void Wrapper_00488c60(void) { func_00491520(0x004ef208u); }

/* @addr 0x0048a250 */
void Wrapper_0048a250(void) { func_00489ee0(0x004ef980u); }

/* @addr 0x0048a260 */
void Wrapper_0048a260(void) { func_00489ee0(0x004ef828u); }

/* @addr 0x0048a270 */
void Wrapper_0048a270(void) { func_00489ee0(0x004ef948u); }

/* @addr 0x0048a280 */
void Wrapper_0048a280(void) { func_00489ee0(0x004ef810u); }

/* @addr 0x0048a300 */
void Wrapper_0048a300(void) { func_00489ee0(0x004ef898u); }

/* @addr 0x0048a310 */
void Wrapper_0048a310(void) { func_00489ee0(0x004ef910u); }

/* @addr 0x0048a320 */
void Wrapper_0048a320(void) { func_00489ee0(0x004ef900u); }

/* @addr 0x0048a330 */
void Wrapper_0048a330(void) { func_00489ee0(0x004ef878u); }

/* @addr 0x0048a340 */
void Wrapper_0048a340(void) { func_00489ee0(0x004ef8c8u); }

/* @addr 0x0048a350 */
void Wrapper_0048a350(void) { func_00489ee0(0x004ef858u); }

/* @addr 0x0048a360 */
void Wrapper_0048a360(void) { func_00489ee0(0x004ef868u); }

/* @addr 0x0048a370 */
void Wrapper_0048a370(void) { func_00489ee0(0x004ef920u); }

/* @addr 0x0048a380 */
void Wrapper_0048a380(void) { func_00489ee0(0x004ef8e0u); }

/* @addr 0x0048a390 */
void Wrapper_0048a390(void) { func_00489ee0(0x004ef8f0u); }

/* @addr 0x0048a3a0 */
void Wrapper_0048a3a0(void) { func_00489ee0(0x004ef8b0u); }

/* @addr 0x0048a3b0 */
void Wrapper_0048a3b0(void) { func_00489ee0(0x004ef888u); }

/* @addr 0x0048a3c0 */
void Wrapper_0048a3c0(void) { func_00489ee0(0x004ef838u); }

/* @addr 0x0048ec20 */
void Wrapper_0048ec20(void) { func_0048fd30(0x004f12a0u); }

/* @addr 0x0048fbc0 */
void Wrapper_0048fbc0(void) { func_0048fd30(0x004f12a8u); }

/* @addr 0x0048ff30 */
void Wrapper_0048ff30(void) { func_0048fd30(0x004f12acu); }

/* @addr 0x0049eb10 */
void Wrapper_0049eb10(void) { func_004049d0(0x00000266u); }

