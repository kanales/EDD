/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Occurrence.cpp
 * Author: ivancanales
 * 
 * Created on 2 de mayo de 2016, 18:32
 */

#include "Occurrence.h"
#include <iostream>
#include<string>

/**
 * Constructor per defecte
 */
Occurrence::Occurrence() {
}

/**
 * Constructor Occurrence.
 * @param l int
 * @param p int
 */
Occurrence::Occurrence(int l, int p) {
    vector<int>* a = new vector<int>;
    a->push_back(p);
    a->push_back(l);
    list.push(a);
}
/**
 * Constructor copia
 * @param orig Occurrence&
 */
Occurrence::Occurrence(const Occurrence& orig) {
}
/**
 * Destructor d'Occurrence
 */
Occurrence::~Occurrence() {
}
/**
 * Retorna la linea en el punt d'interes.
 * @return int
 */
int Occurrence::getLine() const {
    return (list.front()->at(1));
}
/**
 * Retorna la posicio en el punt d'interes
 * @return int
 */
int Occurrence::getPosition() const {
    return (list.front()->at(0));
}

/**
 * Afegeix una ocurrencia
 * @param l int
 * @param p int
 */
void Occurrence::addOccurrence(const int l, const int p) {
    vector<int>* a = new vector<int>;
    a->push_back(p);
    a->push_back(l);
    list.push(a);
} 
/**
 * Retorna una string amb la informació de la Occurrence
 * @return string
 */
string Occurrence::toString() {
    queue<vector<int>*>* temp = new queue<vector<int>*>(list);
    string s = "[";
    bool comma = false;
    while (!list.empty()){
        if(comma) s += "," ;else comma = true;
        s += "(";
        s += std::to_string(getLine());
        s += ", "; 
        s += std::to_string(getPosition()); 
        s += ")";
        list.pop();
    }
    s += "]";
    list = *temp;
    return s;
}
