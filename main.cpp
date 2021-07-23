#include <iostream>
#include <string>
#include "Hardware/hardware.cpp"
#include "Instructions/instruction_handler.cpp"
#include "binary_check.cpp"

using namespace std;

void run(const string& file);

int main() {
    initialize();

//    binarywriter();

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
        execute();
    } else {
        cerr << "Error: File not found";
    }
}


void help() {
    //TODO: wow
}