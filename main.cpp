#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stack_operations.h"
#include "instructions.h"

void run(const string& file);

void push(int val);

void pop(vector<int> stack);

using namespace std;

int* memory;

int main() {
    //4 MB
    memory = (int*)calloc(1048576, sizeof(int));

    //Heap, Stack, Registers, Accum need to have determined memory places instead of regular ints in stackOperations.h
    //They need to be in the ram allocated to this vm, normally they shouldnt be in memory

    //Maybe create 2 seperate memories, 1 the simulated (e.g. those that are not memory on a nonVM) and 1 the heap

    string command;
    getline(cin, command);
    if (command.rfind("run ", 0) == 0) {
        string z = command.substr(4);
        run(z);
    }
}

void run(const string& file) {
    load(1);
    push();
    load(2);
    push();
    pop();
    add_pop();
    print();
}