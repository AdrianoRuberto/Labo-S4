/**
 * Labo
 * Author : Adriano Ruberto, Matthieu Villard
 *
 */
#include <stdexcept>
#include "BinaryMatrice.h"


bool xor_function(bool a, bool b){
    return a != b;
}

function<bool(bool,bool)> logical_xor = xor_function;

BinaryMatrice::BinaryMatrice(size_t size) {
    this->size = size;
    matrice = new bool*[size];
    for(size_t i = 0; i < size; ++i){
        matrice[i] = new bool[size];
        for(size_t j = 0; j < size; ++j){
            matrice[i][j] = rand() % 2;
        }
    }
}

BinaryMatrice::BinaryMatrice(const BinaryMatrice& source) {
    size = source.size;
    matrice = new bool *[size];
    for (size_t i = 0; i < size; ++i) {
        matrice[i] = new bool[size];
        for (size_t j = 0; j < size; ++j) {
            matrice[i][j] = source.matrice[i][j];
        }
    }
}

void BinaryMatrice::print() {
    for(size_t i = 0 ; i < size; ++i){
        for(size_t j = 0; j < size; ++j){
            cout << matrice[i][j] << ' ';
        }
        cout << endl;
    }
}

BinaryMatrice::~BinaryMatrice() {
    for(size_t i = 0; i < size; ++i)
        delete[] matrice [i];
    delete[] matrice;
}


void BinaryMatrice::ior(const BinaryMatrice& two) {
    ioperate(*this, two, logical_or<bool>());
}
void BinaryMatrice::iand(const BinaryMatrice& two){
    ioperate(*this, two, logical_and<bool>());
}

void BinaryMatrice::ixor(const BinaryMatrice& two){
    ioperate(*this, two, logical_xor);
}

BinaryMatrice BinaryMatrice::vor(const BinaryMatrice& two) const{
    return voperate(*this, two, logical_or<bool>());
}
BinaryMatrice BinaryMatrice::vand(const BinaryMatrice& two) const {
    return voperate(*this, two, logical_and<bool>());
}
BinaryMatrice BinaryMatrice::vxor(const BinaryMatrice& two) const{
   return voperate(*this, two, logical_xor);
}

BinaryMatrice* BinaryMatrice::por(const BinaryMatrice& two) const{
    return poperate(*this, two, logical_or<bool>());
}
BinaryMatrice* BinaryMatrice::pand(const BinaryMatrice& two) const{
    return poperate(*this, two, logical_and<bool>());

}
BinaryMatrice* BinaryMatrice::pxor(const BinaryMatrice& two) const{
    return poperate(*this, two, logical_xor);
}


void BinaryMatrice::ioperate(BinaryMatrice& one, const BinaryMatrice& two, std::function<bool(bool,bool)> f){
    BinaryMatrice* bm = poperate(one, two, f);
     one = BinaryMatrice(*bm);
    delete bm;
}

BinaryMatrice BinaryMatrice::voperate(const BinaryMatrice& one, const BinaryMatrice& two, function<bool(bool,bool)> f){
    if(one.size != two.size)
        throw runtime_error("Les matrices ne font pas la même taille !");

    BinaryMatrice res(one.size);

    for(size_t i = 0; i < one.size; ++i){
        for(size_t j = 0; j < one.size; ++j){
            res.matrice[i][j] = f(one.matrice[i][j], two.matrice[i][j]);
        }
    }

    return res;
}

BinaryMatrice* BinaryMatrice::poperate(const BinaryMatrice& one, const BinaryMatrice& two, function<bool(bool,bool)> f) {
    if(one.size != two.size)
        throw runtime_error("Les matrices ne font pas la même taille !");

    BinaryMatrice* res = new BinaryMatrice(one.size);

    for(size_t i = 0; i < one.size; ++i){
        for(size_t j = 0; j < one.size; ++j){
            res->matrice[i][j] = f(one.matrice[i][j], two.matrice[i][j]);
        }
    }

    return res;
}