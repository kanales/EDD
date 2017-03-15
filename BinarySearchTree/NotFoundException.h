/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NotFoundException.h
 * Author: ivancanales
 *
 * Created on 2 de mayo de 2016, 19:32
 */

#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H
#include <stdexcept>
class NotFoundException : public std::runtime_error {
public:
    NotFoundException(string s = "Does not exist." ): std::runtime_error(s) {}
};


#endif /* NOTFOUNDEXCEPTION_H */

