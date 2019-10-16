#include "Wall.h"
#include <iostream>
#include <string>

Hole::Hole() : Obstacle('#', "You fell in a hole") {

}

bool Wall::touched(int yPos, Person* player) {
	player->setPos(1,1);
	mvprintw(yPos,0, message.c_str());
	return 0;
}

Wall::~Wall() {

}
