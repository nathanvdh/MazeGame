#include "Person.h"
Person::Person() : Entity('@') {
	xPos = 0;
	yPos = 0;
}

bool Person::move(int aKey) {
	switch (aKey) {
		case KEY_UP:
				yPos--;
				return 1;
			break;
		case KEY_DOWN:
				yPos++;
				return 1;
			break;
		case KEY_LEFT:
				xPos--;
				return 1;
			break;
		case KEY_RIGHT:
				xPos++;
				return 1;
			break;
		default:
			return 0;
	}
}

void Person::setPos(int x, int y) {
	xPos = x;
	yPos = y;
}

int Person::getxPos() {
	return xPos;
}
int Person::getyPos() {
	return yPos;
}

Person::~Person() {

}
