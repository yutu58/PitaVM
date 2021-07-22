#include <vector>

#ifndef PITAVM_STACKOPS_H
#define PITAVM_STACKOPS_H

using namespace std;

void load(int val) {
    accum = val;
}

void push() {
    *RSP = accum;
    RSP++;
}

void pop() {
    RSP--;
    accum = *RSP;
}

void add_pop() {
    RSP--;
    accum += *RSP;
}

void sub_pop() {
    RSP--;
    accum -= *RSP;
}

void print() {
    cout << *(char*) accum;
}

void print_int() {
    cout << accum;
}

#endif
