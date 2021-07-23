//
// Created by yutu58 on 22/07/2021.
//

#ifndef PITAVM_INSTRUCTION_HANDLER_H
#define PITAVM_INSTRUCTION_HANDLER_H

namespace instructions {
    enum opcodes {
        STOP,               //00000000 00 WORKS
        LOAD,               //00000001 01 WORKS
        FETCH,              //00000010 02 //NOT IMPLEMENTED YET
        MOVE_POINTERS,      //00000011 03
        JUMP,               //00000100 04 WORKS
        CALL,               //00000101 05 WORKS
        RETURN,             //00000110 06 WORKS
        SEVEN,              //00000111 07
        PRINT,              //00001000 08 WORKS
        DIR_PRINT,          //00001001 09 WORKS
        DIV_POP,            //00001010 0A WORKS (beware of order)
        MUL_POP,            //00001011 0B WORKS
        SUB_POP,            //00001100 0C WORKS (beware of order)
        ADD_POP,            //00001101 0D WORKS
        POP,                //00001110 0E WORKS //special pop to rbp
        PUSH,               //00001111 0F WORKS
        CMP
    };
}


#endif //PITAVM_INSTRUCTION_HANDLER_H
