#include "Hole.h"
#include <iostream>
#include <string>

Hole::Hole() : Obstacle('O', "You fell in a hole                      ") {

}

bool Hole::touched(Maze* maze, Person* person, int keyPress) {
	person->setPos(2,2);
	Obstacle::touched(maze, person, keyPress);
	
	return 1; //person was moved involuntarily so touched returns 1
}

Hole::~Hole() {

}