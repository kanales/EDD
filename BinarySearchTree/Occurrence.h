/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Occurrence.h
 * Author: ivancanales
 *
 * Created on 2 de mayo de 2016, 18:32
 */

#ifndef OCCURRENCE_H
#define OCCURRENCE_H
#include <string>
#include <queue>
using namespace std;
class Occurrence {
public:
    Occurrence();
    Occurrence(const int l, const int p);
    Occurrence(const Occurrence& orig);
    //consultors
    int getLine() const;
    int getPosition() const;
    string toString();
    //modificadors
    void addOccurrence(const int l, const int p);
    //destructor
    virtual ~Occurrence();
private:
    queue<vector<int>*> list;
};

#endif /* OCCURRENCE_H */

