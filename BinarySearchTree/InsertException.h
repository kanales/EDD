/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputException.h
 * Author: ahierrfo7.alumnes
 *
 * Created on 25 / abril / 2016, 15:24
 */

#ifndef INSERTEXCEPTION_H
#define INSERTEXCEPTION_H
#include <stdexcept>
class InsertException : public std::runtime_error {
public:
    InsertException(): std::runtime_error("Error al inserir.") {}
};

#endif /* INSERTEXCEPTION_H */

