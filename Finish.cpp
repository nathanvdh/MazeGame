#include "Finish.h"
#include <iostream>
#include <string>

Finish::Finish() : Obstacle('X', "You reached the finish, press q to exit") {

}

bool Finish::touched(int yPos, Person* person) {
	mvprintw(yPos, 0, "                              ");
	mvprintw(yPos,0, message.c_str());
	return 1;
}

Finish::~Finish() {

}
