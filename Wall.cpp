#include "Wall.h"
#include <iostream>
#include <string>

Wall::Wall() : Obstacle('#', "You hit a wall") {

}

bool Wall::touched() {
	//Put player backward or don't let them move forward (or something like that)
	//But would that be tight coupling?
	std::cout << message << "\n";
	return 0;
}

Wall::~Wall() {

}
