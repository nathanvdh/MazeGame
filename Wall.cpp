#include "Wall.h"
#include <iostream>
#include <string>

Wall::Wall() : Obstacle('#', "You hit a wall") {

}

bool Wall::touched() {
	mvprintw(8,1, message);
	return 0;
}

Wall::~Wall() {

}
