//
// Created by Mattheo on 24/07/2021.
//

#ifndef PITAVM_OPCODES_H
#define PITAVM_OPCODES_H

namespace instructions {
    enum opcodes {
        nop,                        //0000 0000, 00, No operation, 0 arguments
        push_null,                  //0000 0001, 01, Push null reference on the stack
        push,                       //0000 0010, 02, Push 4 bytes on the stack, 1 argument of 4 bytes (what value to push)
        push_bp,                    //0000 0011, 03, Push value of RBP to stack
        push_acc,                   //0000 0100, 04, Push value of accumulator to stack
        copy,                       //0000 0101, 05, Repeat the last value on the stack
        load_local_var,             //0000 0110, 06, Push the xth local variable, 1 argument of 1 byte (index of argument, starting at 0) -> basically fetch [rbp + index]
        store_local_var,            //0000 0111, 07, Store at the xth local variable, 1 argument of 1 byte (index of argument, starting at 0) //Nessecary?
        fetch,                      //0000 1000, 08, Retrieve int value at given address, 1 argument of 1 byte (how many bytes to retrieve)
        pop,                        //0000 1001, 09, Discard top value of stack
        pop_bp,                     //0000 1010, 0A, Top value of stack becomes base pointer
        pop_acc,                    //0000 1011, 0B, Pop value of stack to accumulator
        call,                       //0000 1100, 0C, Push current value of PC to stack and change PC to new value
        ret,                        //0000 1101, 0D, Pop current top of stack into PC
        mov,                        //0000 1110, 0E, Copy value from 1 "register" to another, 2 arguments of 4 bits, [src, dst]
                                    //0001 -> BP, 0010 -> RP, 0100 -> PC, 0101 -> ACC
        exception,                  //0000 1111, 0F, Give error code and stop program, 1 argument of 1 byte (error code)
        add,                        //0001 0000, 10, adds 2 top values of stack
        sub,                        //0001 0001, 11, subtracts 2 top values of stack
        mul,                        //0001 0010, 12, multiplies top values on stack
        div,                        //0001 0011, 13, integer division of top values on stack
        mod,                        //0001 0100, 14, modulo, takes 2 from stack
        b_not,                      //0001 0101, 15, bitwise not (takes 1 pushes 1)
        b_and,                      //0001 0110, 16, bitwise and (takes 2 pushes 1)
        b_or,                       //0001 0111, 17, bitwise or (takes 2 pushes 2)
        jmp,                        //0001 1000, 18, 1 arg -> address to jump to
        jz,                         //0001 1001, 19, 1 arg -> address to jump to, takes 1 from stack
        jnz,                        //0001 1010, 1A, 1 arg -> address to jump to, takes 1 from stack
        jg,                         //0001 1011, 1B, 1 arg -> address to jump to, takes 1 from stack
        jge,                        //0001 1100, 1C, 1 arg -> address to jump to, takes 1 from stack
        jl,                         //0001 1101, 1D, 1 arg -> address to jump to, takes 1 from stack
        jle,                        //0001 1110, 1E, 1 arg -> address to jump to, takes 1 from stack
        debug,                      //0001 1111, 1F
        print_ascii,                //0010 0000, 20
        print_int,                  //0010 0001, 21
        scan_ascii,                 //0010 0010, 22
        scan_int,                   //0010 0011, 23
        halt                        //0010 0100, 24
    };
}

#endif //PITAVM_OPCODES_H
