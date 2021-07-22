//
// Created by Mattheo on 22/07/2021.
//

#include "hardware.h"

using namespace std;

void initialize() {
    memory = (char*)calloc(1048576, 1024); //1GB RAM for now
    RBP = reinterpret_cast<int *>(memory);
    RSP = RBP;
    accum = 0;
    PC =  memory + STACK_SIZE;
}

int load_program(const string& file) {
    ifstream byte_file(file);
    if (byte_file.fail()) {
        return -1;
    }
    int byte_counter = 0;
    char byte = 0;
    while(byte_file.get(byte)) {
        *(PC + byte_counter) = byte;
        byte_counter++;
    }
    heap_entry = (PC + byte_counter + 1);
    byte_file.close();
    return 0;
}