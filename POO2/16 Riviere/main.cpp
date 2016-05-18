#include <cstdlib>
#include "Controller.h"

int main() {
	Controller controller;
	controller.showMenu();
	while(!controller.isFinished()){
		controller.display();
		controller.nextTurn();
	}
	return EXIT_SUCCESS;
}