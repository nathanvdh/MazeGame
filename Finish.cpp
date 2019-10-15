#include "Finish.h"
#include <iostream>
#include <string>

Finish::Finish() : Obstacle('F', "You reached the finish") {

}

bool Finish::touched() {
	mvprintw(8,1, message);
	return 1;
}

Finish::~Finish() {

}
