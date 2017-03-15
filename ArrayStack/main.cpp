/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ivancanales
 *
 * Created on 14 de marzo de 2016, 20:01
 */

#include <cstdlib>
#include <iostream>
#include "EmptyStackException.h"
#include "FullStackException.h"
#include <string>
#include "ArrayStack.h"

/*
 * 
 */
char pairChar(char c) {
    char p;
    switch (c) {
        case '(': p = ')'; break;
        case '{': p = '}'; break;
        case '[': p = ']'; break;
        default: p = ' ';
    } 
    return p;
}

bool isOpen(char c) {
    return (c == '(' || c == '{'|| c== '[');
}

bool isClosed(char c) {
    return (c ==')'||c=='}'||c==']');
}

bool isBalanced(ArrayStack &pila, std::string s) {
    int i = 0;
    char c;
    bool end = false;

    while ( !end && (i < s.size()) ) {
        c = s.at(i);
        if (isOpen(c)) {
            pila.push(c);
        } else if (isClosed(c)){
            if (pila.empty() || pairChar(pila.top()) != c) {
                end = true;
            } else {
                pila.pop();
            }
        }
        i++;
    }
    return !end && pila.empty();
}

int main(int argc, char** argv) {
    ArrayStack pila;
    char c, pair;
    std::string s;
    bool end, correcte;
    
    try {
        pila.push('a');
        pila.push('b');
        pila.push('c');
        pila.pop();
    } catch (FullStackException ex) {
        std::cerr << ex.what() << std::endl;
    } catch (EmptyStackException ex) {
        std::cerr << ex.what() << std::endl;
    }
    
    while (!pila.empty()) {
        pila.pop();
    }
    ////
    std::cout <<  "Introdueix una expressió numèrica" << std::endl;
    getline(std::cin, s); // obtenim una string

    correcte = isBalanced(pila, s);

    if (correcte) std::cout << "L’expressió està ben aparellada" << std::endl;
    else std::cout << "L’expressió està mal aparellada" << std::endl;
    return 0;
}

