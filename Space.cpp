#include "Space.h"
#include <iostream>
#include <string>

Space::Space() : Obstacle(' ', "\0") {

}

bool Space::touched() {
	return 1;
}

Space::~Space() {

}