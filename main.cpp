#include <iostream>
#include <string>
#include "Hardware/hardware.cpp"
#include "Instructions/executor.cpp"
#include "TempAssembler/Assembler.cpp"
#include "binary_check.cpp"
#include "Errors/ErrorCodes.h"

using namespace std;

void run(const string& file);
void help();
void info();

bool running;

int main() {
    running = true;
    initialize();

    while (running) {
        string command;
        getline(cin, command);
        if (command.rfind("run ", 0) == 0) {
            string z = command.substr(4);
            run(z);
        }
        else if (command.rfind("assemble ", 0) == 0) {
            string z = command.substr(9);
            assemble(z);
        }
        else if (command == "help") {
            help();
        }
        else if (command == "info") {
            info();
        }
        else if (command == "q") {
            running = false;
        }
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

void info() {
    cout << "PitaVM version 0.0.1" << endl;
}

void help() {
    cout << "Run the following commands to get: " << endl << endl;
    cout << "  Help - This menu" << endl;
    cout << "  Run [bytecode_file] - Execute a program" << endl;
}