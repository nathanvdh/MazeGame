#include "Space.h"
#include <iostream>
#include <string>

Space::Space() : Obstacle(' ', "") {

}

bool Space::touched() {
	return 1;
}

Space::~Space() {

}