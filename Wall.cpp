#include "Wall.h"
#include <iostream>
#include <string>

Wall::Wall() : Obstacle('#', "You hit a wall                                 ") {

}

bool Wall::isWall() {
	return 1;
}

Wall::~Wall() {

}
