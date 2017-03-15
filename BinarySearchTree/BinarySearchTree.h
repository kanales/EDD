/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.h
 * Author: ahierrfo7.alumnes
 *
 * Created on 21 / abril / 2016, 12:32
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdexcept>
#include <stack>
#include "Position.h"
#include "InsertException.h"
template <class KEY, class DAT>
class BinarySearchTree {
    public:
        //constructor
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& tree);
        //destructor
        ~BinarySearchTree();
        //consultors
        int size(Position<KEY,DAT>* p = NULL) const; // posem 0 per defecte
        bool empty() const;
        bool search(const KEY& key) const;
        void printPreOrder(Position<KEY,DAT>* p = NULL) const; // posem 0 per defecte
        void printPostOrder(Position<KEY,DAT>* p = NULL) const; // posem 0 per defecte
        void printInOrder(Position<KEY,DAT>* p = NULL) const; // posem 0 per defecte
        Position<KEY,DAT>* searchPosition(const KEY& e) const;
        Position<KEY,DAT>* root() const;
        int height(Position<KEY,DAT>* p = NULL) const; // posem 0 per defecte
        //modificadors
        void insert(const KEY& k, const DAT& d);
        //bool remove(Position<KEY,DAT>* e)

    private:
        void destroyNodes(Position<KEY,DAT> * p);
        Position<KEY,DAT>* r;
};

/**
 * Constructor
 */
template <class KEY, class DAT>
BinarySearchTree<KEY,DAT>::BinarySearchTree() {
    this->r = NULL;
}

/**
 * Copia del constructor
 * @param tree BinarySearchTree
 */
template <class KEY, class DAT>
BinarySearchTree<KEY,DAT>::BinarySearchTree(const BinarySearchTree& tree) {
    
}

/**
 * Destructor de nodes
 * @param p Position
 */
template <class KEY, class DAT>
void BinarySearchTree<KEY,DAT>::destroyNodes(Position<KEY,DAT> * p) {
    if (p->hasLeft()) destroyNodes(p->left());
    if (p->hasRight()) destroyNodes(p->right());
    delete p;
}

/**
 * Destructor
 */
template <class KEY, class DAT>
BinarySearchTree<KEY,DAT>::~BinarySearchTree() {
    if (!empty()) {
        destroyNodes(root());
    }
}

/**
 * Retorna el root
 * @return Position root
 */
template <class KEY, class DAT>
Position<KEY,DAT>* BinarySearchTree<KEY,DAT>::root() const {
    return r;
}

/**
 * Retorna un enter amb la mida de l'arbre
 * @param p Position
 * @return int
 */
template <class KEY, class DAT>
int BinarySearchTree<KEY,DAT>::size(Position<KEY,DAT>* p) const {
    if (p == NULL) p = root(); // si porta el valor per defecte posem el root
    if (empty()) {
        return 0;
    } else {
        int leftN = ((p->hasLeft()) ? size(p->left()):0);
        int rightN = ((p->hasRight()) ? size(p->right()):0);
        return (1 + leftN + rightN);
    }
}

/**
 * Retorna cert si l'arbre està buit
 * @return bool
 */
template <class KEY, class DAT>
bool BinarySearchTree<KEY,DAT>::empty() const {
    return (root() == NULL);
}

/**
 * Imprimeix l'arbre amb PreOrdre
 * @param p Position
 */
template <class KEY, class DAT>
void BinarySearchTree<KEY,DAT>::printPreOrder(Position<KEY,DAT>* p) const {
    if (p == NULL) p = root(); // si porta el valor per defecte posem el root
    if (empty()) {
        std::cout << "Arbre buit" << std::endl;
    } else {
        std::cout << p->getElement() << std::endl;
        if (p->hasLeft()) printPreOrder(p->left());
        if (p->hasRight()) printPreOrder(p->right());
    }
}

/**
 * Imprimeix l'arbre amb PostOrdre
 * @param p Position
 */
template <class KEY, class DAT>
void BinarySearchTree<KEY,DAT>::printPostOrder(Position<KEY,DAT>* p) const {
    if (p == NULL) p = root(); // si porta el valor per defecte posem el root
    if (empty()) {
        std::cout << "Arbre buit" << std::endl;
    } else {
        if (p->hasLeft()) printPostOrder(p->left());
        if (p->hasRight()) printPostOrder(p->right());
        std::cout << p->getElement() << std::endl;
    }
}

/**
 * Imprimeix l'arbre amb InOrdre
 * @param p Position
 */
template <class KEY, class DAT>
void BinarySearchTree<KEY,DAT>::printInOrder(Position<KEY,DAT>* p) const {
    if (p == NULL) p = root(); // si porta el valor per defecte posem el root
    if (empty()) {
        std::cout << "Arbre buit" << std::endl;
    } else {
        if (p->hasLeft()) {
            printInOrder(p->left());
        }
        std::cout << p->getElement() << std::endl;
        if (p->hasRight()) {    
            printInOrder(p->right());
        }
    }
}

/**
 * Inserta un element a l'arbre
 * @param element E
 */
template <class KEY, class DAT>
void BinarySearchTree<KEY,DAT>::insert(const KEY& k, const DAT& d) {
    Position<KEY,DAT>* nou = new Position<KEY,DAT>(k,d);
    Position<KEY,DAT>* p;
    KEY val;
    bool end;
    
    if (empty()) { //comprovem si existeix algun node, si no, el nou sera el root
        r = nou;
    } else {
        end = false;
        p = root();
        while (!end) {
            val = p->getElement();
            if (k > val) {
                if (p->hasRight()) { 
                    p = p->right();
                } else { 
                    p->setRight(nou);
                    end = true;
                }
            } else if (k < val) {
                if(p->hasLeft()) {
                    p = p->left();
                } else {
                    p->setLeft(nou); 
                    end = true;
                }
            } else {
                throw InsertException();
            }
        }
    } 
}

/**
 * Retorna cert si l'element esta en la llista
 * @param e E
 * @return bool
 */
template <class KEY, class DAT>
bool BinarySearchTree<KEY,DAT>::search(const KEY& e) const {
    Position<KEY,DAT>* p;
    bool trobat = false;
    bool end = false; //end es true si l'element no existeix on hauria d'estar
    
    if (empty()) {
        return false;
    }
    p = root();
    while (!end and !trobat) {
        if (p->getElement() < e) {
            if (p->hasRight()) p = p->right();
            else end = true; // e hauria d'estar a la dreta, pero ho hi es
        } else if (p->getElement() > e) {
            if (p->hasLeft()) p = p->left();
            else end = true; // e hauria d'estar a l'esquerra, pero no hi es
        } else trobat = true;
    }
    return trobat;
}

template <class KEY, class DAT>
int BinarySearchTree<KEY,DAT>::height(Position<KEY,DAT>* p) const {
    if (p == NULL) p = root(); // si porta el valor per defecte posem el root
    return ((((1 + std::max(((p->hasLeft()) ? height(p->left()):0), ((p->hasRight()) ? height(p->right()):0))))));
}

template <class KEY, class DAT>
Position<KEY,DAT>* BinarySearchTree<KEY,DAT>::searchPosition(const KEY& e) const {
    Position<KEY,DAT>* p;
    bool trobat = false;
    bool end = false; //end es true si l'element no existeix on hauria d'estar
    
    if (empty()) {
        return NULL;
    }
    p = root();
    while (!end and !trobat) {
        if (p->getElement() < e) {
            if (p->hasRight()) p = p->right();
            else end = true; // e hauria d'estar a la dreta, pero ho hi es
        } else if (p->getElement() > e) {
            if (p->hasLeft()) p = p->left();
            else end = true; // e hauria d'estar a l'esquerra, pero no hi es
        } else trobat = true;
    }
    if (trobat) return p;
    else return 0;
}
#endif /* BINARYSEARCHTREE_H */