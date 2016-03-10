/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_13
 Fichier     : BinaryMatrice.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 09.03.2106
 -----------------------------------------------------------------------------------
 */
#include <stdexcept>
#include "BinaryMatrice.h"

/*
----------------------------------------------------------------------------------
Description  : Retourne le résultat d'une opération ou exclusive entre deux valeurs

Paramètre(s) : - a : première valeur booléenne
 *             - b : Deuxième valeur booléenne

----------------------------------------------------------------------------------
 */
bool xor_function(bool a, bool b){
    return a != b;
}

function<bool(bool,bool)> logical_xor = xor_function;

/*
----------------------------------------------------------------------------------
Description  : Construit une matrice binaire carrée de taille quelconque

Paramètre(s) : - size : taille de la matrice

----------------------------------------------------------------------------------
 */
BinaryMatrice::BinaryMatrice(size_t size) {
    if(size == 0)
        throw runtime_error("Une taille de 0 n'est pas acceptable");
    this->size = size;
    matrice = new bool*[size];
    for(size_t i = 0; i < size; ++i){
        matrice[i] = new bool[size];
        for(size_t j = 0; j < size; ++j){
            matrice[i][j] = rand() % 2;
        }
    }
}

/*
----------------------------------------------------------------------------------
Description  : Constructeur de recopie. Construit une nouvelle matrice binaire carrée
 *             en se basanr sur une matrice existante.

Paramètre(s) : - source : matrice existante à recopier

----------------------------------------------------------------------------------
 */
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

/*
----------------------------------------------------------------------------------
Description  : Affiche le contenu de la matrice sous la forme d'un tableau

----------------------------------------------------------------------------------
 */
void BinaryMatrice::print() {
    for(size_t i = 0 ; i < size; ++i){
        for(size_t j = 0; j < size; ++j){
            cout << matrice[i][j] << ' ';
        }
        cout << endl;
    }
}

/*
----------------------------------------------------------------------------------
Description  : Libère les espaces réservés lors de la destruction de la matrice

----------------------------------------------------------------------------------
 */
BinaryMatrice::~BinaryMatrice() {
    for(size_t i = 0; i < size; ++i)
        delete[] matrice [i];
    delete[] matrice;
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération "ou" en modifiant la matrice courrante

Paramètre(s) : - two : deuxième matrice de l'opération logique

----------------------------------------------------------------------------------
 */
void BinaryMatrice::ior(const BinaryMatrice& two) {
    ioperate(*this, two, logical_or<bool>());
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération "et" en modifiant la matrice courrante

Paramètre(s) : - two : deuxième matrice de l'opération logique

----------------------------------------------------------------------------------
 */
void BinaryMatrice::iand(const BinaryMatrice& two){
    ioperate(*this, two, logical_and<bool>());
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération "ou exclusive" en modifiant la matrice
 *             courrante

Paramètre(s) : - two : deuxième matrice de l'opération logique

----------------------------------------------------------------------------------
 */
void BinaryMatrice::ixor(const BinaryMatrice& two){
    ioperate(*this, two, logical_xor);
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération "ou" en retournant par valeur une nouvelle
 *             matrice allouée statiquement

Paramètre(s) : - two : deuxième matrice de l'opération logique

----------------------------------------------------------------------------------
 */
BinaryMatrice BinaryMatrice::vor(const BinaryMatrice& two) const{
    return voperate(*this, two, logical_or<bool>());
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération "et" en retournant par valeur une nouvelle
 *             matrice allouée statiquement

Paramètre(s) : - two : deuxième matrice de l'opération logique

----------------------------------------------------------------------------------
 */
BinaryMatrice BinaryMatrice::vand(const BinaryMatrice& two) const {
    return voperate(*this, two, logical_and<bool>());
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération "ou exclusive" en retournant par valeur une
 *             nouvelle matrice allouée statiquement

Paramètre(s) : - two : deuxième matrice de l'opération logique

----------------------------------------------------------------------------------
 */
BinaryMatrice BinaryMatrice::vxor(const BinaryMatrice& two) const{
   return voperate(*this, two, logical_xor);
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération "ou" en retournant un pointeur sur une
 *             nouvelle matrice allouée dynamiquement

Paramètre(s) : - two : deuxième matrice de l'opération logique

----------------------------------------------------------------------------------
 */
BinaryMatrice* BinaryMatrice::por(const BinaryMatrice& two) const{
    return poperate(*this, two, logical_or<bool>());
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération "et" en retournant un pointeur sur une
 *             nouvelle matrice allouée dynamiquement

Paramètre(s) : - two : deuxième matrice de l'opération logique

----------------------------------------------------------------------------------
 */
BinaryMatrice* BinaryMatrice::pand(const BinaryMatrice& two) const{
    return poperate(*this, two, logical_and<bool>());

}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération "ou exclusive" en retournant un pointeur sur une
 *             nouvelle matrice allouée dynamiquement

Paramètre(s) : - two : deuxième matrice de l'opération logique

----------------------------------------------------------------------------------
 */
BinaryMatrice* BinaryMatrice::pxor(const BinaryMatrice& two) const{
    return poperate(*this, two, logical_xor);
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération logique quelconque en modifiant la première
 *             matrice

Paramètre(s) : - one :  première matrice de l'opération logique
 *             - two :  deuxième matrice de l'opération logique
 *             - f :  opération logique

----------------------------------------------------------------------------------
 */
void BinaryMatrice::ioperate(BinaryMatrice& one, const BinaryMatrice& two, std::function<bool(bool,bool)> f){
    if(one.size != two.size)
        throw runtime_error("Les matrices ne font pas la même taille !");

    for(size_t i = 0; i < one.size; ++i){
        for(size_t j = 0; j < one.size; ++j){
            one.matrice[i][j] = f(one.matrice[i][j], two.matrice[i][j]);
        }
    }
}

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération logique quelconque en retournant par valeur une
 *             nouvelle matrice allouée statiquement
 *
Paramètre(s) : - one :  première matrice de l'opération logique
 *             - two :  deuxième matrice de l'opération logique
 *             - f :  opération logique

----------------------------------------------------------------------------------
 */
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

/*
----------------------------------------------------------------------------------
Description  : Effectue une opération logique quelconque en retournant un pointeur sur une
 *             nouvelle matrice allouée dynamiquement
 *
Paramètre(s) : - one :  première matrice de l'opération logique
 *             - two :  deuxième matrice de l'opération logique
 *             - f :  opération logique

----------------------------------------------------------------------------------
 */
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