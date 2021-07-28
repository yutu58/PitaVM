#include <iostream>
#include <string>
#include "Hardware/hardware.cpp"
#include "Instructions/executor.cpp"
#include "TempAssembler/Assembler.cpp"
#include "Errors/ErrorCodes.h"

using namespace std;

void run(const string& file);
void help();
void info();

bool running;
bool flag_exitCodes;

int main(int argc, char* argv[]) {
    running = true;
    initialize();

    if (argc == 1) {
        flag_exitCodes = true;

        while (running) {
            string command;
            getline(cin, command);
            if (command.rfind("run ", 0) == 0) {
                string z = command.substr(4);
                run(z);
            } else if (command.rfind("assemble ", 0) == 0) {
                string z = command.substr(9);
                assemble(z);
            } else if (command == "help") {
                help();
            } else if (command == "info") {
                info();
            } else if (command == "q") {
                running = false;
            }
        }
    }
    else if (argc > 2) {
        if (strcmp(argv[1], "run") == 0) {
            run(argv[2]);
        }
        else if (strcmp(argv[1], "assemble") == 0) {
            assemble(argv[2]);
        }
        else if (strcmp(argv[1], "ar") == 0) { //assemble and run
            run(assemble(argv[2]));
        }
    }
}

void run(const string& file) {
    if (file.empty()) {
        return;
    }
    int load = load_program(file);
    if (load == 0) {
        int res = execute();
        if (flag_exitCodes) {
            cout << endl << endl << errors::messages.find(res)->second << endl;
        }
    } else {
        cerr << "Error: Could not find file to run" << endl;
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