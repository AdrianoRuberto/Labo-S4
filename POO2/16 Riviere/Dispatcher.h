//
// Created by Nykros on 19.05.2016.
//

#ifndef INC_16_RIVIERE_DISPATCHER_H
#define INC_16_RIVIERE_DISPATCHER_H


#include "Pers/Parent.h"
#include "Pers/Child.h"
#include "Pers/Thief.h"
#include "Pers/Cop.h"

class Dispatcher {

public:
	virtual void dispatch(const Father&);

	virtual void dispatch(const Mother&);

	virtual void dispatch(const FamilyMember&);

	virtual void dispatch(const Cop&);
};

class ThiefDispatcher : public Dispatcher {
public:
	bool _fm = false;
	bool _cop = false;

	virtual void dispatch(const FamilyMember&);

	virtual void dispatch(const Cop&);
};

class BoyDispatcher : public Dispatcher {
public:
	bool _father = false;
	bool _mother = false;

	virtual void dispatch(const Father&);

	virtual void dispatch(const Mother&);
};


#endif //INC_16_RIVIÈRE_DISPATCHER_H