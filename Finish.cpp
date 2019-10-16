#include "Finish.h"
#include <iostream>
#include <string>

Finish::Finish() : Obstacle('X', "You reached the finish") {

}

bool Finish::touched(int yPos) {
	mvprintw(yPos, 0, "                              ");
	mvprintw(yPos,0, message.c_str());
	return 1;
}

Finish::~Finish() {

}
