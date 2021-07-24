using namespace instructions;

void push_f(int value) {
    *RSP = value;
    RSP++;
}

int pop_f() {
    RSP--;
    return *RSP;
}

void nop_f() {
    //Do absolutely nothing
}

void push_null_f() {
    push_f(0); //Or whatever a null_reference is?
}

void push_bp_f() {
    push_f((int) RBP);
}

void push_acc_f() {
    push_f(accum);
}

void copy_f() {
    push_f(*RSP);
}

void load_local_var_f(int offset) {
    push_f(*(RBP+offset));
}

void store_local_var_f(int offset) {
    *(RBP+offset) = pop_f();
}

void fetch_f(int address) {
    push_f(*reinterpret_cast<int *>(address));
}

void pop_bp_f() {
    RSP = reinterpret_cast<int *>(pop_f());
}

void pop_acc_f() {
    accum = pop_f();
}

void call_f(int offset) {
    push_f((int) PC);
    PC = (char*) memory + STACK_SIZE + offset;
}

void ret_f() {
    PC = reinterpret_cast<char *>(pop_f());
}

void mov_f(char a, char b) {
    //TODO: Implement
}

void err_f(char error_code) {
    //TODO: todo
}

void add_f() {
    push_f(pop_f() + pop_f());
}

void sub_f() {
    push_f(pop_f() - pop_f());
}

//TODO: continue



