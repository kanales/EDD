/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FullStackException.h
 * Author: ivancanales
 *
 * Created on 14 de marzo de 2016, 20:32
 */

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

#ifndef FULLSTACKEXCEPTION_H
#define FULLSTACKEXCEPTION_H

#include <stdexcept>
 // stdexcept header file contains runtime_error
using std::runtime_error;

class FullStackException : public runtime_error{
    public: FullStackException(): runtime_error( "Attempted to add element to full stack."){}
}; 

#endif /* FULLSTACKEXCEPTION_H */


