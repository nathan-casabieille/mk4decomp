extern unsigned int g_q;
extern void tail_func(void);

/* Use arg, then tail-call with no args */
void Try(int arg) {
    int p = arg >> 2;
    g_q = p;
    tail_func();
}
