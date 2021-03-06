#include "Hole.h"
#include <iostream>
#include <string>

Hole::Hole() : Obstacle('O', "You fell in a hole                      ") {

}

int Hole::touched(Maze* maze, Person* person, int keyPress) {
	person->setPos(maze->getStartX(),maze->getStartY(), maze); //returns player to position 2,2
	Obstacle::touched(maze, person, keyPress);
	
	return 1; //person was moved involuntarily so touched returns 1
}

Hole::~Hole() {

}