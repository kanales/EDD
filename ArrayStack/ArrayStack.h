/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayStack.h
 * Author: ivancanales
 *
 * Created on 14 de marzo de 2016, 20:02
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "EmptyStackException.h"
#include "FullStackException.h"
#include <iostream>
#include <vector>
#include <string>

class ArrayStack{
    private:
        int MAX_STACK;
        std::vector<char> data; 
        int t;// top de la pila  
public:
    ArrayStack(); 
        //inicialitza una pila, buida
    ~ArrayStack();
    bool empty() const;
        //indica si la pila és buida 
    bool full() const;//indica si la pila és plena
    void push(const char item);
        //introdueix un element a la pila,
        //i retorna una excepció si no ha estat possible
    void pop(); //treu un element de la pila,
                //i retorna una excepció si no ha estat possible
    char top() const; //retorna l’element del top de la pila
                // retorna una excepció si no ha estat possible
    void print(); // imprimeix tot el contingut de la pila
};

#endif /* ARRAYSTACK_H */

