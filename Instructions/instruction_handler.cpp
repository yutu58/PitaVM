#include "instruction_handler.h"
using namespace instructions;

//TODO: not accessing PC in this namespace

int execute() {
    resetPC();
    bool running = true;
    while (running) {
        char instr = *PC;
        PC++;
        switch (instr) {
            case STOP:
                running = false;
                break;
            case LOAD:
                //Load immediate value
                load(*(int *) PC);
                PC += 4;
                break;
            case FETCH: //opcode, amount of bytes [1, 2, 4]
                //fetch
                fetch(*(int *) PC);
                PC++;
                break;
            case MOVE_POINTERS: //was "copy", type [1, or type 2]
                move_pointers(*(int *) PC);
                PC++;
                break;
            case JUMP:
                jump(*(int *) PC);
                break;
            case CALL:
                call(*(int *) PC);
                break;
            case RETURN:
                return_method();
                break;
            case SEVEN:
                //blah
                break;
            case PRINT:
                print(); //Print accum as ascii
                break;
            case DIR_PRINT:
                print_int(); //Print accum as integer
                break;
            case DIV_POP:
                div_pop();
                break;
            case MUL_POP:
                mul_pop();
                break;
            case SUB_POP:
                sub_pop();
                break;
            case ADD_POP:
                add_pop();
                break;
            case POP:
                pop();
                break;
            case PUSH:
                push();
                break;
            default:
                return 2; //unknown instruction;
        }
    }
    return 0;
}
