/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ahierrfo7.alumnes
 *
 * Created on 21 / abril / 2016, 12:31
 */

#include <cstdlib>
#include <iostream>
#include "BSTWordFinder.h"
#include "Occurrence.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    BSTWordFinder wf;
    string s;
    string line;
    string word; 
    cout << "Insereix el nom del fitxer: ";
    cin >> s;
    try {
        wf.appendText(s);
    } catch(NotFoundException ex) {
        cerr << ex.what() << endl;
    }
    clock_t t1 = clock();
    string t = "dictionary.txt";
    ifstream f(t.c_str());
    if (f.is_open()) {
        while (getline(f,line)) {
            line.erase(std::remove_if(line.begin(),line.end(), ::ispunct), line.end()); //esborrem puntuacio fent servir la funcio ispunct
            std::transform(line.begin(),line.end(), line.begin(), ::tolower); // transformem la oracio a minuscules
            istringstream iss(line); // fem servir instringstream per llegir facilment paraula per paraula
            while(iss >> word) {
                if (wf.search(word)) {
                    cout << word << wf.findOccurrences(word)->toString() << endl;
                }
            }
        }
    }
    clock_t t2 = clock();
    double temps = double(t2 - t1) / CLOCKS_PER_SEC;
    cout << "Ha tardat " << temps << " segons." << endl; 
    cout << endl << endl;
    wf.viewIndex();
    cout << endl;
    cout << "L'alçada de l'arbre es " << wf.getHeight() << endl;
    return 0;
}
    

