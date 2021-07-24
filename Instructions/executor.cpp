#include "opcodes.h"
#include "instruction_handler.cpp"

using namespace instructions;
//TODO: not accessing PC in this namespace

int load_program(const std::string &file) {
    resetPC();
    std::ifstream byte_file(file);
    if (byte_file.fail()) {
        return -1;
    }
    int byte_counter = 0;
    char byte = 0;
    while (byte_file.get(byte)) {
        *(PC + byte_counter) = byte;
        byte_counter++;
    }
    heap_entry = (PC + byte_counter + 1); //Zerobyte to define end of program?
    byte_file.close();
    return 0;
}

int execute() {
    resetPC();

    bool running = true;
    while (running) {
        char instr = *PC;
        PC++;
        switch (instr) {
            case nop:
                nop_f();
                break;
            case push_null:
                push_null_f();
                break;
            case push:

                break;
            case push_bp:
                break;
            case push_acc:
                break;
            case copy:
                break;
            case load_local_var:
                break;
            case store_local_var:
                break;
            case fetch:
                break;
            case pop:
                break;
            case pop_bp:
                break;
            case pop_acc:
                break;
            case call:
                break;
            case ret:
                break;
            case mov:
                break;
            case err:
                break;
            case add:
                break;
            case sub:
                break;
            case mul:
                break;
            case div:
                break;
            case mod:
                break;
            case b_not:
                break;
            case b_and:
                break;
            case b_or:
                break;
            case jmp:
                break;
            case jz:
                break;
            case jnz:
                break;
            case jg:
                break;
            case jgz:
                break;
            case jl:
                break;
            case jlz:
                break;
            case debug:
                break;
            case print_ascii:
                break;
            case print_int:
                break;
            case scan_ascii:
                break;
            case scan_int:
                break;
        }
    }
    return 0;
}


