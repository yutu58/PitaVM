#include "opcodes.h"
#include "instruction_handler.cpp"
#include "Errors/ErrorCodes.h"

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
    ram = (PC + byte_counter + 1); //add 0 byte
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
                push_f(*(int *) PC);
                PC += 4;
                break;
            case push_bp:
                push_bp_f();
                break;
            case push_acc:
                push_acc_f();
                break;
            case copy:
                copy_f();
                break;
            case llv:
                load_local_var_f(*(int *) PC);
                PC += 4;
                break;
            case slv:
                store_local_var_f(*(int *) PC);
                PC += 4;
                break;
            case pop:
                pop_f();
                break;
            case pop_bp:
                pop_bp_f();
                break;
            case pop_acc:
                pop_acc_f();
                break;
            case call:
                call_f(*(int *) PC);
                //not +4 because PC changed
                break;
            case ret:
                ret_f();
                break;
            case mov:
            {
                char a = *PC;
                char b = (char) ((int) a >> 4);
                char c = (char) ((int) a & 0x0f);
                mov_f(b, c);
                PC++;
            }
                break;
            case exception:
                exception_f(*PC);
                running = false;
                break;
            case add:
                add_f();
                break;
            case sub:
                sub_f();
                break;
            case mul:
                mul_f();
                break;
            case opcodes::div:
                div_f();
                break;
            case mod:
                mod_f();
                break;
            case b_not:
                b_not_f();
                break;
            case b_and:
                b_and_f();
                break;
            case b_or:
                b_or_f();
                break;
            case jmp:
                jmp_f(*(int*) PC);
                break;
            case jz:
            {
                int offset = (*(int*) PC);
                PC += 4;
                jz_f(offset);
            }
                break;
            case jnz:
            {
                int offset = (*(int*) PC);
                PC += 4;
                jnz_f(offset);
            }
                break;
            case jg:
            {
                int offset = (*(int*) PC);
                PC += 4;
                jg_f(offset);
            }
                break;
            case jge:
            {
                int offset = (*(int*) PC);
                PC += 4;
                jge_f(offset);
            }
                break;
            case jl:
            {
                int offset = (*(int*) PC);
                PC += 4;
                jl_f(offset);
            }
                break;
            case jle:
            {
                int offset = (*(int*) PC);
                PC += 4;
                jle_f(offset);
            }
                break;
            case debug:
                debug_f();
                break;
            case print_ascii:
                print_ascii_f();
                break;
            case print_int:
                print_int_f();
                break;
            case scan_ascii:
                scan_ascii_f();
                break;
            case scan_int:
                scan_int_f();
                break;
            case halt:
                running = false;
                break;
            case fetch_b:
                fetch_b_f();
                break;
            case fetch_int:
                fetch_int_f();
                break;
            case fetch_b_woffset:
                fetch_b_woffset_f();
                break;
            case fetch_int_woffset:
                fetch_int_woffset_f();
                break;
            case store_b_wref:
                store_b_wref_f();
                break;
            case store_int_wref:
                store_int_wref_f();
                break;
            case store_b:
                store_b_f();
                break;
            case store_int:
                store_int_f();
                break;
            case replace_b:
                replace_b_f();
                break;
            case replace_int:
                replace_int_f();
                break;
            case replace_b_woffset:
                replace_b_woffset_f();
                break;
            case replace_int_woffset:
                replace_int_woffset_f();
                break;
            default:
                return errors::UNKNOWN_OPERATION;
        }
    }
    return errors::SUCCESS;
}


