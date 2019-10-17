#include "Wall.h"
#include <iostream>
#include <string>

Wall::Wall() : Obstacle('#', "You hit a wall                                 ") {

}

bool Wall::touched(Maze* maze, Person* person, int keyPress) {
	mvprintw(maze->getMapHeight(),0, message.c_str());
	return 0;
}

Wall::~Wall() {

}
