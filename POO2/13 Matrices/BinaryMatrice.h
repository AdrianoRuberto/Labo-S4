/**
 * Labo
 * Author : Adriano Ruberto, Matthieu Villard
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
    BinaryMatrice(const BinaryMatrice&);

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
