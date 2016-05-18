#include "Controller.h"
#include "Pers/Parent.h"
#include "Pers/Child.h"
#include "Pers/Cop.h"
#include "Pers/Thief.h"

int main() {
	list<Person*> persons;

	persons.push_back(new Father("pere"));
	persons.push_back(new Mother("mere"));
	persons.push_back(new Boy("paul"));
	persons.push_back(new Boy("pierre"));
	persons.push_back(new Girl("julie"));
	persons.push_back(new Girl("jeanne"));
	persons.push_back(new Cop("policier"));
	persons.push_back(new Thief("voleur"));

//	Controller controller(persons);
	return 0;
}