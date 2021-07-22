//
// Created by Mattheo on 22/07/2021.
//

#ifndef PITAVM_HARDWARE_H
#define PITAVM_HARDWARE_H

char* memory;
char* PC;
int* RBP;
int* RSP;
char* heap_entry;
int accum;

const int STACK_SIZE = (1048576)*4; // stack van 4 mb;

#endif //PITAVM_HARDWARE_H
