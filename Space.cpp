#include "Space.h"
#include <iostream>
#include <string>

Space::Space() : Obstacle(' ', "                                       ") {

}

bool Space::touched(Maze* maze, Person* person, int keyPress) {
	movePerson(maze, person, keyPress);
	mvprintw(maze->getMapHeight(), 0, message.c_str());
		
			
	
	return 0;
}

Space::~Space() {

}