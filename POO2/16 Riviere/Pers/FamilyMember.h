/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : FamilyMember.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe représente un membre d'une famille
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_FAMILYMEMBER_H
#define INC_16_RIVIERE_FAMILYMEMBER_H


#include "Person.h"

class FamilyMember : public Person {

public:
	FamilyMember(const string& name);
};


#endif //INC_16_RIVIÈRE_FAMILYMEMBER_H
