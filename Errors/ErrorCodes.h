#include <unordered_map>

#ifndef PITAVM_ERRORCODES_H
#define PITAVM_ERRORCODES_H

namespace errors {
    enum errorCodes {
        SUCCESS,
        STACKOVERFLOW_ERROR,
        OUT_OF_MEMORY_ERROR,
        UNKNOWN_OPERATION
    };

    std::unordered_map<int, std::string> messages {
        {SUCCESS, "Exited with code " + std::to_string(SUCCESS)+ ": Success"},
        {UNKNOWN_OPERATION, "Exited with code" + std::to_string(UNKNOWN_OPERATION)+ ": Unknown operation"},
    };
}

#endif //PITAVM_ERRORCODES_H
