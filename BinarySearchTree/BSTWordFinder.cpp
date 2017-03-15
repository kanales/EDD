/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTWordFinder.cpp
 * Author: ivancanales
 * 
 * Created on 2 de mayo de 2016, 19:01
 */

#include "BSTWordFinder.h"
/**
 * Constructor per defecte
 */
BSTWordFinder::BSTWordFinder() {
    this->tree = new BinarySearchTree<string,Occurrence>;
}

BSTWordFinder::BSTWordFinder(const BSTWordFinder& orig) {
}

BSTWordFinder::~BSTWordFinder() {
    delete tree;
}
/**
 * Retorna les ocurrencies d'una determinada paraula
 * @return vector<Occurrence>
 */
Occurrence* BSTWordFinder::findOccurrences(const string word) const {
    Position<string, Occurrence>* p;
    p = tree->searchPosition(word);
    if (p != NULL) {
        return &(p->getValue());
    } else {
        throw NotFoundException();
    }
}
/**
 * Retorna un llistat de les posicions
 */
void BSTWordFinder::viewIndex() const { // fem servir un recorregut iteratiu en inordre
    if (tree->empty()) throw (LengthError());
    else {
        Position<string, Occurrence>* t;
        stack<Position<string, Occurrence>*> s;
        s.push(tree->root()); // la posicio inicial sera el root
        while (!s.empty()) {
            t = s.top();
            if (t != NULL) {
                if (t->hasLeft()) s.push(t->left());
                else s.push(NULL); // si no queda cap element a l'esquerra un NULL fara de sentinella
            } else {
                s.pop(); // treiem el sentinella
                if (!s.empty()) { 
                    t = s.top();
                    s.pop();
                    cout << t->getElement() << t->getValue().toString() << endl;
                    if (t->hasRight()) s.push(t->right());
                    else s.push(NULL); // si no queda cap element a la dreta un NULL fara de sentinella
                }
            }
        }
    }
}

/**
 * Posa a l'arbre totes les paraules del text escollit
 * @param filename nom del fitxer que es vol posar a l'arbre
 */
void BSTWordFinder::appendText(const std::string filename) {
    ifstream f(filename.c_str());
    string line; 
    string word;
    int nLine;
    int nPos;
    
    if (f.is_open()) {
        nLine = 1;
        while (getline(f, line)) {
            line.erase(std::remove_if(line.begin(),line.end(), ::ispunct), line.end()); //esborrem puntuacio fent servir la funcio ispunct
            std::transform(line.begin(),line.end(), line.begin(), ::tolower); // transformem la oracio a minuscules
            istringstream iss(line); // fem servir instringstream per llegir facilment paraula per paraula
            nPos = 1;
            while(iss >> word) {
                insertWord(word, nLine, nPos);
                nPos++;
            }
            nLine++;
        }
        f.close();
    } else {
        throw (NotFoundException());
    }
}
/**
 * Insereix una paraula en l'arbre.
 * @param word string
 * @param line int
 * @param position int
 */
void BSTWordFinder::insertWord(string word, int line, int position) {
    Position<string, Occurrence>* p = tree->searchPosition(word);
    Occurrence* oc;
    if (p != NULL) {
        p->getValue().addOccurrence(line,position); // si ja existeix la paraula afegim una nova occurrencia
    } else {
        oc = new Occurrence(line, position);
        tree->insert(word,*oc);
    }
}

/**
 * Retorna l'alçada de l'arbre
 * @return int que dona l'alçada de l'arbre 
 */
int BSTWordFinder::getHeight() {
    return tree->height();
}

/**
 * Retorna true si troba la parauna
 * @param word string
 * @return bool
 */
bool BSTWordFinder::search(string word) {
    return tree->search(word);
}