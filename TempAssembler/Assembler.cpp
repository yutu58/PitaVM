#include "Assembler.h"
#include <map>
#include <vector>

using namespace assembler;

void assemble(const std::string& file) {

    std::map<std::string, int> labels;
    std::map<int, std::string> label_references;

    std::vector<char> all;
    std::ifstream assembly_file(file);
    std::string word;
    if (assembly_file.fail()) {
        return;
    }
    int byteCount = 0;
    while (assembly_file >> word) {
        if (word.rfind('#', 0) == 0) {
            std::string temp;
            std::getline(assembly_file, temp);
        }
        auto opcode = opcode_table.find(word);
        if (opcode != opcode_table.end()) {
            all.push_back((char) opcode->second);
            byteCount++;

            if (opcode->second == instructions::mov) {
                assembly_file >> word;
                all.push_back((char) std::stoi(word, nullptr, 2));
                byteCount++;
            }
        }
        else {
            try {
                std::vector<char> v = convertIntToBytes(std::stoi(word));
                for (char c : v) {
                    all.push_back(c);
                    byteCount++;
                }
            } catch (std::exception &err) {
                if (word.at(word.size()-1) == ':') {
                    //Label definition
                    int label_offset = byteCount;
                    word = word.substr(0, word.size()-1);
                    labels.insert({word, label_offset});
                    for (auto & label_reference : label_references) {
                        if (label_reference.second == word) {
                            std::vector<char> v = convertIntToBytes(label_offset);
                            auto iterator = all.begin() + label_reference.first;
                            for (char c : v) {
                                *iterator = c;
                                iterator++;
                            }
                        }
                    }
                } else {
                    if (labels.find(word) != labels.end()) {
                        std::vector<char> v = convertIntToBytes(labels.find(word)->second);
                        for (char c : v) {
                          all.push_back(c);
                          byteCount++;
                        }
                    } else {
                        label_references.insert({byteCount, word});
                        for (int i = 0; i < 4; i++) {
                            all.push_back(0);
                            byteCount++;
                        }
                    }
                }
            }
        }
    }
    assembly_file.close();

    std::ofstream binaryFile("assembled.bpitab", std::ios_base::binary);
    for (char i : all) {
        binaryFile.put(i);
    }
    binaryFile.close();
}



