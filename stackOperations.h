#include <vector>

#ifndef PITAVM_MYSTACK_H
#define PITAVM_MYSTACK_H

using namespace std;

vector<int> main_stack;

int accum = 0;

int rbp_offset = 0;
int rsp_offset = 0;

void load(int val) {
    accum = val;
}

void push() {
    main_stack.push_back(accum);
    rsp_offset++;
}

void pop() {
    accum = main_stack.back();
    main_stack.pop_back();
    rsp_offset--;
}

void add_pop() {
    accum += main_stack.back();
    main_stack.pop_back();
    rsp_offset--;
}

void sub_pop() {
    accum -= main_stack.back();
    main_stack.pop_back();
    rsp_offset--;
}

void print() {
    cout << accum;
}

#endif

