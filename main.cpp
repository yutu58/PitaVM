#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    //Byte-addressable heap / stack memory

    //For now: Heap can have arrays and strings

    //Stack has
    //  -local variable stack
    //  -operand stack
    //  -https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-2.html#jvms-2.6
    //

    //Instructions

    /*
     * Create main stackframe:
     *  initiate LVA (calloc LVA_Size)
     *  initiae OP_size (calloc OP_size)
     *  initate FD?? or other info?
     *  Store pointers to LVA and OP
     *  Store RSP from OP (kan compiler doen?)
     *
     * Store variables in LVA
     *
     * Push to OP
     * Operate on OP
     * Store back from OP
     *
     * IO?
     *
     * Branches (if's, loops ::: jmp, jne, je, etc.)
     *
     * receive bytecode to execute
     *
     */


    return 0;
}
