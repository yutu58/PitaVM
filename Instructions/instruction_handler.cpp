#include <string>

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
    RBP = reinterpret_cast<int *>(pop_f());
}

void pop_acc_f() {
    accum = pop_f();
}

void call_f(int offset) {
    push_f((int) PC + 4);
    PC = (char*) memory + STACK_SIZE + offset;
}

void ret_f() {
    PC = reinterpret_cast<char *>(pop_f());
}

void mov_f(char a, char b) {
    int all[4] = {(int) RBP, (int) RSP, (int) PC, accum};
    int temp = all[a];
//    std::cout << "a: " << (int) a << " b: " << (int) b << std::endl;
    switch (b) {
        case 0:
            RBP = reinterpret_cast<int*>(temp);
            break;
        case 1:
            RSP = reinterpret_cast<int*>(temp);
            break;
        case 2:
            PC =  reinterpret_cast<char*>(temp);
            break;
        case 3:
            accum = temp;
            break;
        default:
            return;
    }
}

void exception_f(char error_code) {
    //TODO: todo
}

void add_f() {
    push_f(pop_f() + pop_f());
}

void sub_f() {
    push_f(pop_f() - pop_f());
}

void mul_f() {
    push_f(pop_f() * pop_f());
}

void div_f() {
    push_f(pop_f() / pop_f());
}

void mod_f() {
    push_f(pop_f() % pop_f());
}

void b_not_f() {
    push_f(~pop_f());
}

void b_and_f() {
    push_f(pop_f() & pop_f());
}

void b_or_f() {
    push_f(pop_f() | pop_f());
}

void jmp_f(int offset) {
    PC = (char*) memory + STACK_SIZE + offset;
}

void jz_f(int offset) {
    if (pop_f() == 0) {
        PC = (char*) memory + STACK_SIZE + offset;
    }
}

void jnz_f(int offset) {
    if (pop_f() != 0) {
        PC = (char*) memory + STACK_SIZE + offset;
    }
}

void jg_f(int offset) {
    if (pop_f() > 0) {
        PC = (char*) memory + STACK_SIZE + offset;
    }
}

void jge_f(int offset) {
    if (pop_f() >= 0) {
        PC = (char*) memory + STACK_SIZE + offset;
    }
}

void jl_f(int offset) {
    if (pop_f() < 0) {
        PC = (char *) memory + STACK_SIZE + offset;
    }
}

void jle_f(int offset) {
    if (pop_f() <= 0) {
        PC = (char*) memory + STACK_SIZE + offset;
    }
}

void debug_f() {
    std::cout << "RBP:" << RBP << " RSP:" << RSP << " *RSP-1:" << *(RSP-1) << " PC_offset:"
        <<(int) PC - (int) memory - STACK_SIZE << std::endl;
}

void print_ascii_f() {
    std::cout << (char) pop_f();
}

void print_int_f() {
    std::cout << (int) pop_f();
}

void scan_ascii_f() {
    //TODO: to_be_implemented;
}

void scan_int_f() {
    std::string b;
    std::cin >> b;
    push_f(std::stoi(b));
}


