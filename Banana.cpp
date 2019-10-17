#include "Banana.h"
#include <iostream>
#include <string>


Banana::Banana() : Obstacle('(', "You slipped on a banana                        ") {

}

bool Banana::touched(Maze* maze, Person* person, int keyPress) {
	mvprintw(maze->getMapHeight(),0, message.c_str());
	//moves person onto and off banana
	movePerson(maze, person, keyPress);	
	//person->move(keyPress,maze->getMap()[person->getyPos()][person->getxPos()]->getSprite());
	//continually moves person
	while (maze->getNextObstacle(person, keyPress)->getSprite() != '#') {
		

		if (maze->getNextObstacle(person, keyPress)->touched(maze, person, keyPress))
		{

			break;
		}

	}


	return 1;
}

Banana::~Banana() {

}
