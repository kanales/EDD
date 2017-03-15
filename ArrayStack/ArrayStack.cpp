/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayStack.cpp
 * Author: ivancanales
 * 
 * Created on 14 de marzo de 2016, 20:02
 */

#include "ArrayStack.h"

ArrayStack::ArrayStack() {
    this->MAX_STACK = 100;
    data = std::vector<char>(MAX_STACK);
    t = -1;
}

ArrayStack::~ArrayStack() {
}

bool ArrayStack::empty() const {
    return t == -1;
}

bool ArrayStack::full() const {
    return t == MAX_STACK;
}

void ArrayStack::push (const char item) {
    if (this->full()) {
        throw FullStackException();
    } else {
        data[++t] = item;
    }
}
void ArrayStack::pop() {
    if (this->empty()) {
        throw EmptyStackException();
    } else {
        t -= 1;
    }
}

char ArrayStack::top() const {
    if (this->empty()) {
        throw EmptyStackException();
    } else {
        return data[t];
    }
}

void ArrayStack::print() {
    std::vector<char> temp = data;
    int t_temp = t; 
    std::string s = "";
    
    while (!empty()) {
        std::cout << top() << std::endl;
        pop();
    }
    data = temp;
    t = t_temp;
}

