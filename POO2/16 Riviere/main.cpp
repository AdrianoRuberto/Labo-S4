#include <cstdlib>
#include "Controller.h"

int main() {
	Controller controller;
	controller.showMenu();
	controller.display();
	while(!controller.isFinished()){
		controller.nextTurn();
	}
	return EXIT_SUCCESS;
}