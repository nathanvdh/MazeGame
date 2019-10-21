#include "Obstacle.h"
#include <string>
#include <iostream>

//Obstacle is an abstract class and cannot be instantiated

Obstacle::Obstacle(char aSprite, std::string aMessage) : Entity (aSprite) {
	message = aMessage;
}

void Obstacle::movePerson(Maze* maze, Person* person, int keyPress) {
	person->move(keyPress, maze->getMap()[person->getyPos()][person->getxPos()]->getSprite());
}

Obstacle::~Obstacle() {

}