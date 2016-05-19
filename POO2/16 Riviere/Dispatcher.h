/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Dispatcher.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe est une implémentation du Visitor pattern
               Nous nous sommes inspiré du code trouvé à l'adresse :
               https://www.wikiwand.com/en/Visitor_pattern#/C.2B.2B_example

               A noter qu'étant donner que les classes Father et Mother sont pris en
               charge par notre Dispatcher, il est nécessaire d'appeler Parent::accept
               qui lui appelera FamilyMember::accept pour s'assurer qu'ils soient bien
               pris en compte en tant que Father et Mother mais aussi en tant que
               FamilyMember. FamilyMember étant utilisé par le ThiefDispatcher.
 ----------------------------------------------------------------------------------
 */


#ifndef INC_16_RIVIERE_DISPATCHER_H
#define INC_16_RIVIERE_DISPATCHER_H

class Father;
class Mother;
class FamilyMember;
class Cop;

class Dispatcher {

public:
	virtual void dispatch(const Father&);

	virtual void dispatch(const Mother&);

	virtual void dispatch(const FamilyMember&);

	virtual void dispatch(const Cop&);
};

class ThiefDispatcher : public Dispatcher {
private:
	bool _fm = false;
	bool _cop = false;
public:

	bool familyMember();

	bool cop();

	virtual void dispatch(const FamilyMember&);

	virtual void dispatch(const Cop&);
};

class ChildDispatcher : public Dispatcher {
private:
	bool _father = false;
	bool _mother = false;
public:

	bool father();

	bool mother();

	virtual void dispatch(const Father&);

	virtual void dispatch(const Mother&);
};

#endif //INC_16_RIVIÈRE_DISPATCHER_H