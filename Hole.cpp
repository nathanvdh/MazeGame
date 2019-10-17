#include "Hole.h"
#include <iostream>
#include <string>

Hole::Hole() : Obstacle('O', "You fell in a hole                      ") {

}

bool Hole::touched(Maze* maze, Person* person, int keyPress) {
	mvaddch(person->getyPos(),person->getxPos(),maze->getMap()[person->getyPos()][person->getxPos()]->getSprite());
	person->setPos(2,2);
	mvprintw(maze->getMapHeight(),0, message.c_str());

	return 1;
}

Hole::~Hole() {

}