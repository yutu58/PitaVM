#include <map>

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
}

#endif //PITAVM_ASSEMBLER_H
