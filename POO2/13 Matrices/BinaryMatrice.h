/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_13
 Fichier     : BinaryMatrice.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 09.03.2106

 But         : Cette classe a pour but de représenter des matrices binaires carrées,
 *             de taille quelconque. Elle doit mettre à disposition des fonctions
 *             permettant d'effectuer des opérations logiques stnadards entre deux
 *             matrices, à savoir: ou(or), et(and), ou exclusif(xor).
 *             De plus, ces opérations doivent pouvoir être faites:
               - en modifiant la matrice sur laquelle est invoquée la méthode, 
               - en retournant, par valeur une nouvelle matrice résultat allouée 
 *               statiquement,
               - en retournant, un pointeur sur une nouvelle matrice résultat allouée 
 *               dynamiquement.

 ----------------------------------------------------------------------------------
 */

#ifndef INC_13_MATRICES_BINARYMATRICE_H
#define INC_13_MATRICES_BINARYMATRICE_H

#include <iostream>
#include <stdlib.h>
#include <functional>


using namespace std;

class BinaryMatrice {
private:
    bool **matrice;
    size_t size;
public: // Constructeurs
    BinaryMatrice(size_t);
    ~BinaryMatrice();

public:
    void print();

    void ior(const BinaryMatrice&);
    void iand(const BinaryMatrice&);
    void ixor(const BinaryMatrice&);

    BinaryMatrice vor(const BinaryMatrice&) const;
    BinaryMatrice vand(const BinaryMatrice&) const;
    BinaryMatrice vxor(const BinaryMatrice&) const;

    BinaryMatrice* por(const BinaryMatrice&) const;
    BinaryMatrice* pand(const BinaryMatrice&) const;
    BinaryMatrice* pxor(const BinaryMatrice&) const;

    static void ioperate(BinaryMatrice&, const BinaryMatrice&, function<bool(bool,bool)>);
    static BinaryMatrice voperate(const BinaryMatrice&, const BinaryMatrice&, function<bool(bool,bool)>);
    static BinaryMatrice* poperate(const BinaryMatrice&, const BinaryMatrice&, function<bool(bool,bool)>);
};

#endif //INC_13_MATRICES_BINARYMATRICE_H