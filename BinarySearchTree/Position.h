/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Position.h
 * Author: ahierrfo7.alumnes
 *
 * Created on 21 / abril / 2016, 12:32
 */

#ifndef POSITION_H
#define POSITION_H

template <class KEY, class DAT>
class Position {
    public:
        //Position(const KEY& k, const DAT& d);
        Position(const KEY& k, const DAT& d);
        Position(Position<KEY,DAT>& p);
        ~Position();
        //consultores
        KEY& getElement();
        DAT& getValue();
        bool hasRight() const; // metode extra
        bool hasLeft() const; // metode extra
        bool isRoot() const;
        bool isExternal() const;
        bool isVisited() const;
        //modificadores
        void setElement(const KEY& element);
        void setValue(const DAT& d);
        Position<KEY,DAT>* right() const;
        Position<KEY,DAT>* left() const;
        Position<KEY,DAT>* parent() const;
        void setRight( Position<KEY,DAT>* a);
        void setLeft( Position<KEY,DAT>* b);
        void setParent(Position<KEY,DAT>* c);
        void makeChild(Position<KEY,DAT>* c); // metode extra
        
    private:
        KEY k;
        DAT d;
        Position* r;
        Position* l;
        Position* p;
};

/**
 * Constructor
 * @param element E
 */
template <class KEY, class DAT>
Position<KEY,DAT>::Position(const KEY& k, const DAT& d): d(d), k(k) {
    this->k = k;
    this->d = d;
    this->p = NULL;
    this->l = NULL;
    this->r = NULL;
}

/**
 * Constructor copia
 * @param p Position
 */
template <class KEY, class DAT>
Position<KEY,DAT>::Position(Position<KEY,DAT>& p) {
    
}

/**
 * Destructor
 */
template <class KEY, class DAT>
Position<KEY,DAT>::~Position() {
}
/**
 * Retorna el valor asociat a una posicio
 * @return valor
 */
template <class KEY, class DAT>
DAT & Position<KEY,DAT>::getValue() {
    return d;
}
template <class KEY, class DAT>
/**
 * Modifica el valor d'una posicio
 * @param v
 */
void Position<KEY, DAT>::setValue(const DAT& v) {
    this->d = v;
}
/**
 * Retorna l'element en la posicio
 * @return element E
 */
template <class KEY, class DAT>
KEY & Position<KEY,DAT>::getElement() {
    return k;
}

/**
 * Modifica l'element en la posicio
 * @param element E
 */
template <class KEY, class DAT>
void Position<KEY,DAT>::setElement(const KEY& k) {
    this->k = k;
}

/**
 * Retorna la posicio de l'element de la dreta
 * @return r Position
 */
template <class KEY, class DAT>
Position<KEY,DAT>* Position<KEY,DAT>::right() const {
    return r;
}

/**
 * Retorna la posicio de l'element de l'esquerra
 * @return l Position
 */
template <class KEY, class DAT>
Position<KEY,DAT>* Position<KEY,DAT>::left() const {
    return l;
}

/**
 * Retorna  la posicio del pare
 * @return p Position
 */
template <class KEY, class DAT>
Position<KEY,DAT>* Position<KEY,DAT>::parent() const {
    return p;
}


template <class KEY, class DAT>
/**
 * Posa una posicio com a fill right
 * @param b Position
 */
void Position<KEY,DAT>::setRight( Position<KEY,DAT>* a) {
    setParent(this);
    this->r = a;
}

template <class KEY, class DAT>
/**
 * Posa una posicio com a fill left
 * @param b Position
 */
void Position<KEY,DAT>::setLeft( Position<KEY,DAT>* b) {
    setParent(this);
    this->l = b;
}

/**
 * Modifica la posicio del pare
 * @param c Position
 */
template <class KEY, class DAT>
void Position<KEY,DAT>::setParent(Position<KEY,DAT>* c) {
    this->p = c;
}

/**
 * Retorna cert si l'arbre te root
 * @return bool
 */
template <class KEY, class DAT>
bool Position<KEY,DAT>::isRoot() const {
    return (parent() == NULL); //és root si no té pare
}

/**
 * Retorna cert si una posicio es externa
 * @return bool
 */
template <class KEY, class DAT>
bool Position<KEY,DAT>::isExternal() const {
    return !(hasRight() or hasLeft()); //és extern si no té fills
}

/**
 * Retorna cert si l'element te un fill dret
 * @return bool
 */
template <class KEY, class DAT>
bool Position<KEY,DAT>::hasRight() const {
    return (right() != NULL);
}

/**
 * Retorna cert si l'element te un fill esquerra
 * @return bool
 */
template <class KEY, class DAT>
bool Position<KEY,DAT>::hasLeft() const {
    return (left() != NULL);
}

#endif /* POSITION_H */

