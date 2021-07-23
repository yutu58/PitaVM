#ifndef PITAVM_HARDWARE_H
#define PITAVM_HARDWARE_H

namespace hardware {
    char *memory;
    char *PC;
    int *RBP;
    int *RSP;
    char *heap_entry;
    int accum;
    bool skip;

    const int STACK_SIZE = (1048576) * 4; // stack van 4 mb;

    void resetPC() {
        PC = memory + STACK_SIZE;
    }
}

#endif //PITAVM_HARDWARE_H
