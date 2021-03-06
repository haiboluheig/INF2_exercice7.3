
/* 
 * File:   main.cpp
 * Author: lvhb_
 *
 * Created on February 21, 2018, 3:14 PM
 */

#include <cstdlib>
#include<iostream>
#include <string>
#include<vector>
#include <algorithm>

#include "maclasse.h"
using namespace std;

int main() {
    //exe 7.3

    Pays suisse("Suisse", 8.121830, 41285),
            france("france", 66.663766, 547030),
            italie("Italie", 61.855120, 301230),
            allemagne("Allemagne", 80.854408, 357021);

    vector<Pays> pays = {suisse, france, italie, allemagne};
    
   sort(pays.begin(), pays.end(),
            []( const Pays& pays_1, const Pays & pays_2) {
                return pays_1.getSuerficie() > pays_2.getSuerficie();
            });
            cout<<"Pays ayant la plus grande superficie                 : "<<pays.front().getNom()<<endl;

    cout << "Pays ayant la plus grande superficie                 : "
            << max_element(pays.begin(), pays.end(),
            []( const Pays& pays_1, const Pays & pays_2) {
                return pays_1.getSuerficie() < pays_2.getSuerficie();
            })->getNom()
            << endl;
    cout << "Pays ayant le plus d'habitantsn                      : "
            << max_element(pays.begin(), pays.end(),
            [](const Pays& pays_1, const Pays& pays_2) {
                return pays_1.getPopulation() < pays_2.getPopulation();
            })->getNom()
            <<endl;
    cout << "Pays ayant la densite de population la plus grande   : "
         << max_element(pays.begin(), pays.end(), [](const Pays& pays_1, const Pays& pays_2) {
                return pays_1.densitePopulation()< pays_2.densitePopulation() ;
            })->getNom()
            <<endl;
    return EXIT_SUCCESS;
}