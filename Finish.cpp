#include "Finish.h"
#include <iostream>
#include <string>

Finish::Finish() : Obstacle('X', "You reached the finish, press q to exit") {

}

bool Finish::touched(Maze* maze, Person* person, int keyPress) {
	person->move(keyPress, maze->getMap()[person->getyPos()][person->getxPos()]->getSprite());
	//mvprintw(maze->getMapHeight(), 0, "                              ");
	mvprintw(maze->getMapHeight(),0, message.c_str());
	return 1;
}

Finish::~Finish() {

}
