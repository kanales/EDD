/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackException.h
 * Author: ivancanales
 *
 * Created on 14 de marzo de 2016, 20:26
 */

#ifndef EMPTYSTACKEXCEPTION_H
#define EMPTYSTACKEXCEPTION_H

#include <stdexcept>
 // stdexcept header file contains runtime_error
using std::runtime_error;

class EmptyStackException : public runtime_error{
public: EmptyStackException(): runtime_error( "Attempted to acces empty stack."){}
}; 

#endif /* EMPTYSTACKEXCEPTION_H */

