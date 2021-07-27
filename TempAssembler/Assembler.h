#include <unordered_map>
#include <vector>

#ifndef PITAVM_ASSEMBLER_H
#define PITAVM_ASSEMBLER_H

namespace assembler {
    std::unordered_map<std::string, opcodes> opcode_table
            {{"nop",             nop},
             {"push_null",       push_null},
             {"push", push},
             {"push_bp",         push_bp},
             {"push_acc",        push_acc},
             {"copy",            copy},
             {"llv",  llv},
             {"slv", slv},
             {"halt",           halt},
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
             {"fetch_b", fetch_b},
             {"fetch_int", fetch_int},
             {"fetch_b_woffset", fetch_b_woffset},
             {"fetch_int_woffset", fetch_int_woffset},
             {"store_b_wref", store_b_wref},
             {"store_int_wref", store_int_wref},
             {"store_b", store_b},
             {"store_int", store_int},
             {"replace_b", replace_b},
             {"replace_int", replace_int},
             {"replace_b_woffset", replace_b_woffset},
             {"replace_int_woffset", replace_int_woffset}
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
