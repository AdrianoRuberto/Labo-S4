/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Bank.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe définit une rive
 ----------------------------------------------------------------------------------
 */
#ifndef INC_16_RIVIERE_BANK_H
#define INC_16_RIVIERE_BANK_H


#include "Container.h"

class Bank : public Container {

public:
	Bank(const string& name) : Container(name) { }
};


#endif //INC_16_RIVIERE_BANK_H
