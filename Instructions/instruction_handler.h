//
// Created by yutu58 on 22/07/2021.
//

#ifndef PITAVM_INSTRUCTION_HANDLER_H
#define PITAVM_INSTRUCTION_HANDLER_H

namespace instructions {
    enum opcodes {
        STOP,
        LOAD,
        FETCH,
        MOVE_POINTERS,
        JUMP,
        CALL,
        RETURN,
        SEVEN,
        PRINT,
        DIR_PRINT,
        DIV_POP,
        MUL_POP,
        SUB_POP,
        ADD_POP,
        POP,
        PUSH
    };
}


#endif //PITAVM_INSTRUCTION_HANDLER_H
