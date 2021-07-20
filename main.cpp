#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stackOperations.h"
#include "instructions.h"

void run(const string& file);

void push(int val);

void pop(vector<int> stack);

using namespace std;

int main() {
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