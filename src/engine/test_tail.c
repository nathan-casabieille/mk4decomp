extern unsigned int g_walkCallback_;
extern unsigned int g_acc_;
extern void func_target(void);

void Try1(void) {
    g_walkCallback_ = 2;
    g_acc_ = 4;
    func_target();
}

extern int func_with_arg(int);
int Try2(int x) {
    return func_with_arg(x);
}

extern void func_void_void(void);
void Try3(void) {
    func_void_void();
}
