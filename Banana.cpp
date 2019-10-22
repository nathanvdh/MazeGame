#include "Banana.h"
#include <iostream>
#include <string>


Banana::Banana() : Obstacle('(', "You slipped on a banana                        ") {

}

bool Banana::touched(Maze* maze, Person* person, int keyPress) {
	
	Obstacle* nextOb = maze->getNextObstacle(person, keyPress);
	while (!(nextOb->isWall())) {
		 if (person->move(maze, keyPress)) {				//if the player was moved involuntarily ('move' returns 1 if so)
		 	break;  										//break out of the banana slide
		 }
		nextOb = maze->getNextObstacle(person, keyPress); 	//get the next obstacle relative to the new position
	}

	


	Obstacle::touched(maze, person, keyPress);
	return 1; //person was moved involunatirly so touched returns 1
}

Banana::~Banana() {

}
