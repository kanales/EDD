/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OutOfRange.h
 * Author: ahierrfo7.alumnes
 *
 * Created on 10 / març / 2016, 13:50
 */

#ifndef OUTOFRANGE_H
#define OUTOFRANGE_H
#include <stdexcept>
using std::out_of_range;

class OutOfRange : public out_of_range {
public: 
    OutOfRange(): out_of_range("Fora de rang") {}
};
#endif /* OUTOFRANGE_H */

