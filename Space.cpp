#include "Space.h"
#include <iostream>
#include <string>

Space::Space() : Obstacle(' ', "\0") {

}

bool Space::touched(Maze* maze, Person* person, int keyPress) {
	person->move(keyPress, maze->getMap()[person->getyPos()][person->getxPos()]->getSprite());
	mvprintw(maze->getMapHeight(), 0, "                                              ");
	return 1;
}

Space::~Space() {

}