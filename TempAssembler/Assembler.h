#include <map>
#include <vector>

#ifndef PITAVM_ASSEMBLER_H
#define PITAVM_ASSEMBLER_H

namespace assembler {
    std::map<std::string, opcodes> opcode_table =
            {{"nop",             nop},
             {"push_null",       push_null},
             {"push", push},
             {"push_bp",         push_bp},
             {"push_acc",        push_acc},
             {"copy",            copy},
             {"load_local_var",  load_local_var},
             {"store_local_var", store_local_var},
             {"fetch",           fetch},
             {"pop",             pop},
             {"pop_bp",          pop_bp},
             {"pop_acc",         pop_acc},
             {"call",            call},
             {"ret",             ret},
             {"mov",             mov},
             {"exception",       exception},
             {"add",             add},
             {"sub",             sub},
             {"mul",             mul},
             {"div",             opcodes::div},
             {"mod",             mod},
             {"b_not",           b_not},
             {"b_and",           b_and},
             {"b_or",            b_or},
             {"jmp",             jmp},
             {"jz",              jz},
             {"jnz",             jnz},
             {"jg",              jg},
             {"jge",             jge},
             {"jl",              jl},
             {"jle",             jle},
             {"debug",           debug},
             {"print_ascii",     print_ascii},
             {"print_int",       print_int},
             {"scan_ascii", scan_ascii},
             {"scan_int", scan_int},
             {"halt", halt}
            };

    std::vector<char> convertIntToBytes(int integer) {
        std::vector<char> res;
        res.push_back((char) (integer & 0xff));
        res.push_back((char) ((integer >> 8) & 0xff));
        res.push_back((char) ((integer >> 16) & 0xff));
        res.push_back((char) ((integer >> 24) & 0xff));
        return res;
    }
}

#endif //PITAVM_ASSEMBLER_H
