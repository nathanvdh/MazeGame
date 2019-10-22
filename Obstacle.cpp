#include "Obstacle.h"
#include <string>
#include <iostream>

Obstacle::Obstacle(char aSprite, std::string aMessage) : Entity (aSprite) {
	message = aMessage;
}

bool Obstacle::touched(Maze* maze, Person* person, int keyPress) {
	mvprintw(maze->getMapHeight(),0, message.c_str()); //print message below map
	return 0;
}

bool Obstacle::isWall() {
	return 0;
}

Obstacle::~Obstacle() {

}