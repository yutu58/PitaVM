#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Hardware/hardware.cpp"
#include "Hardware/stack_operations.h"

void run(const string& file);

using namespace std;

int main() {
    initialize();

    string command;
    getline(cin, command);
    if (command.rfind("run ", 0) == 0) {
        string z = command.substr(4);
        run(z);
    }
}

void run(const string& file) {
    int load = load_program(file);
    if (load == 0) {
//        execute();
    } else {
        cerr << "Error: File not found";
    }

}


void help() {
    //TODO
}