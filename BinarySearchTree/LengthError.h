/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LengthError.h
 * Author: ahierrfo7.alumnes
 *
 * Created on 10 / març / 2016, 13:40
 */

#ifndef LENGTHERROR_H
#define LENGTHERROR_H
#include <stdexcept>
using std::length_error;

class LengthError : public length_error {
public: 
    LengthError(): length_error("End of list reached") {}
};

#endif /* LENGTHERROR_H */

