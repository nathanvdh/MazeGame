#include "Obstacle.h"
//#include "Maze.h"
#include <string>
#include <iostream>

//Obstacle is an abstract class and cannot be instantiated

Obstacle::Obstacle(char aSprite, std::string aMessage) : Entity (aSprite) {
	message = aMessage;
}

Obstacle::~Obstacle() {

}