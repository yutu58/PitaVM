#include <fstream>
#include "hardware.h"


using namespace hardware;

void initialize() {
    memory = (char *) calloc(1048576, 1024); //1GB RAM for now
    RBP = reinterpret_cast<int *>(memory);
    RSP = RBP;
    accum = 0;
    PC = memory + STACK_SIZE;
}

