#include "Space.h"
#include <iostream>
#include <string>

Space::Space() : Obstacle(' ', "\0") {

}

bool Space::touched(int yPos, Person* person, int keyPress) {
	mvprintw(yPos, 0, "                              ");
	return 1;
}

Space::~Space() {

}