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

int load_program(const std::string &file) {
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

void debugger(int val, std::string help) {
    std::cout << "!!!!" << val << help << "RBP: " << RBP << " RSP: " << RSP << " PC: " << (int) PC << std::endl;
}

void load(int val) {
    accum = val;
}

void fetch(char amount) {
    accum = (*reinterpret_cast<int *>(accum) & (int) pow(2, (int) amount*8)-1);
}

void move_pointers(char mode){
    if (mode == 0) {
        RSP = RBP;
    } else if (mode == 1) {
        RBP = RSP;
    } else if (mode == 2) {
        accum = (int) RBP;
    } else if (mode == 3) {
        RSP--;
        RBP = reinterpret_cast<int *>(*RSP);
    }
}

void push() {
    *RSP = accum;
    RSP++;
}

void jump(int newOffset) {
    if (skip) {
        skip = false;
        PC += 4;
        return;
    }
    PC = (char*) memory + STACK_SIZE + newOffset;
}

void call(int newOffset){
    accum = (int) PC + 4;
    push();
    jump(newOffset);
}

void return_method() {
    RSP--;
    PC = reinterpret_cast<char *> (*RSP);
}

void pop() {
    RSP--;
    accum = *RSP;
}

void add_pop() {
    RSP--;
    accum += *RSP;
}

void sub_pop() {
    RSP--;
    accum -= *RSP;

}

void mul_pop() {
    RSP--;
    accum *= *RSP;
}

void div_pop() {
    RSP--;
    accum /= *RSP;
}


void print() {
    std::cout << (char) accum;
}

void print_int() {
    std::cout << accum;
}

void compare(char mode) {
    if (mode == 0) {
        if (accum != 0) {
            skip = true;
        }
    } else if (mode == 1) {
        if (accum < 0) {
            skip = true;
        }
    } else if (mode == 2) {
        if (accum <= 0) {
            skip = true;
        }
    } else if (mode == 3) {
        if (accum == 0) {
            skip = true;
        }
    }
}

