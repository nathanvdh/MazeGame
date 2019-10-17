#include "Banana.h"
#include <iostream>
#include <string>

Banana::Banana() : Obstacle('.', "You slipped on a Banana") {

}

bool Banana::touched(Maze* maze, Person* person, int keyPress) {
	mvprintw(maze->getMapHeight(),0, message.c_str());
	//moves person onto and off banana
	person->move(keyPress,maze->getMap()[person->getyPos()][person->getxPos()]->getSprite());
	person->move(keyPress,maze->getMap()[person->getyPos()][person->getxPos()]->getSprite());
	//continually moves person
	while(maze->getMap()[person->getyPos()][person->getxPos()]->getSprite() == (' ')) {
		person->move(keyPress,maze->getMap()[person->getyPos()][person->getxPos()]->getSprite());
	}
	return 0;
}

Banana::~Banana() {

}
