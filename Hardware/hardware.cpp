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

void load(int val) {
    accum = val;
}

void fetch(int amount) {
    accum = (*(int*) accum & (int) pow(2, accum*8));
}

void move_pointers(int mode){
    if (mode == 1) {
        RSP = RBP;
    } else if (mode == 2) {
        RBP = RSP;
    }
}

void push() {
    *RSP = accum;
    RSP++;
}

void jump(int newOffset) {
    PC = (char*) memory + STACK_SIZE + newOffset;
}

void call(int newOffset){
    accum = (int) PC;
    push();
    jump(newOffset);
}

void return_method() {
    RSP--;
    PC = (char*) (*RSP);
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
    std::cout << *(char*) accum;
}

void print_int() {
    std::cout << accum;
}