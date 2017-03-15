/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTWordFinder.h
 * Author: ivancanales
 *
 * Created on 2 de mayo de 2016, 19:01
 */

#ifndef BSTWORDFINDER_H
#define BSTWORDFINDER_H
#include "BinarySearchTree.h"
#include "Occurrence.h"
#include "Position.h"
#include "NotFoundException.h"
#include "InsertException.h"
#include "LengthError.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stack>
using namespace std;

class BSTWordFinder {
public:
    //constructors
    BSTWordFinder();
    BSTWordFinder(const BSTWordFinder& orig);
    //destructor
    virtual ~BSTWordFinder();
    //consultors
    Occurrence* findOccurrences(const string nom) const;
    void viewIndex() const;
    int getHeight();
    bool search(string word);
    //modificadors
    void appendText(const string filename);
    void insertWord(string word, int line, int position);
    
private:
    BinarySearchTree<string, Occurrence>* tree;
};

#endif /* BSTWORDFINDER_H */

