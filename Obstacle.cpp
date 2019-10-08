#include "Obstacle.h"
#include <string>
#include <iostream>


Obstacle::Obstacle() : Entity() {
	message = "Oh no you've hit a generic obstacle";
}

Obstacle::Obstacle(char aSprite) : Entity (aSprite) {
	message = "Oh no you've hit a generic obstacle";
}

void Obstacle::touched() {
	std::cout << message << "\n";
}

Obstacle::~Obstacle() {

}