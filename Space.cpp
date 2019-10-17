#include "Space.h"
#include <iostream>
#include <string>

Space::Space() : Obstacle(' ', "\0") {

}

bool Space::touched(Maze* maze, Person* person, int keyPress) {
	movePerson(maze, person, keyPress);	
	mvprintw(maze->getMapHeight(), 0, "                                              ");
	return 1;
}

Space::~Space() {

}