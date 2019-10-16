#include "Wall.h"
#include <iostream>
#include <string>

Wall::Wall() : Obstacle('#', "You hit a wall") {

}

bool Wall::touched(int yPos, Person* person) {
	mvprintw(8,1, message.c_str()); //make these coords relative to map height
	return 0;
}

Wall::~Wall() {

}
