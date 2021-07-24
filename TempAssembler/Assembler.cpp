#include "Assembler.h"
#include <vector>

using namespace assembler;

void assemble(const std::string& file) {
    std::vector<char> all;
    std::ifstream assembly_file(file);
    std::string word;
    if (assembly_file.fail()) {
        return;
    }
    while (assembly_file >> word) {
        std::cout << word;
        auto opcode = opcode_table.find(word);
        if (opcode != opcode_table.end()) {
            all.push_back((char) opcode->second);
        }
        else {
            all.push_back((char) std::stoi(word));
            all.push_back((char) 0);
            all.push_back((char) 0);
            all.push_back((char) 0);
        }
    }
    assembly_file.close();

    std::ofstream binaryFile("assembled.bpitab");
    for (char i : all) {
        binaryFile.put(i);
    }
    binaryFile.close();
}



