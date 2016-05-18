/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Thief.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */
#include "Thief.h"
#include "../Dispatcher.h"

bool Thief::canDrive() const {
	return false;
}

void Thief::validation(const Container& container) const {
	ThiefDispatcher tf;

}