#include "Person.h"
#include "Obstacle.h"
#include <iostream>
Person::Person() : Entity('+') {
	xPos = 0;
	yPos = 0;
	name = "";
}
//'move' function returns 1 if player was moved involuntarily (just like 'touched') 
bool Person::move(Maze* maze, int aKey) {
	
	bool moved = 0; //value to store whether player was moved involuntarily

	mvaddch(yPos, xPos, maze->getCurrentObstacle(this)->getSprite()); //restore the character in players previous position

	//Determine the player's next position
	int nextY = yPos;
	int nextX = xPos;

	switch (aKey) {
		case KEY_UP:
				nextY--;
				
			break;
		case KEY_DOWN:
				nextY++;
				
			break;
		case KEY_LEFT:
				nextX--;
				
			break;
		case KEY_RIGHT:
				nextX++;
				
			break;
		default:
			return 0;
			
	}

	Obstacle* nextOb = maze->getNextObstacle(this, aKey);

	if (!(nextOb->isWall()))												//if the next obstacle isn't a wall
	{
		yPos = nextY;														//update the player's position
		xPos = nextX;
		 if (maze->getCurrentObstacle(this)->touched(maze, this, aKey)) {	//touch whatever is there and test if it moved the player involuntarily
		 	moved = 1; 														
		 } else {
		 	moved = 0;
		 }
	} else {
		nextOb->touched(maze, this, aKey); //there is a wall in the way, call it's touched method without moving onto it.
		moved = 0;
	}

	mvaddch(yPos,xPos, sprite);

	return moved;
}

bool Person::setPos(int x, int y, Maze* maze) {
	if (x>0 && x < maze->getMapWidth() && y>0 && y<maze->getMapHeight()) {	//check the player isnt being moved out of bounds
		xPos = x;
		yPos = y;
		return 1;
	} else {
		return 0;
	}
}

int Person::getxPos() {
	return xPos;
}
int Person::getyPos() {
	return yPos;
}

bool Person::drawPerson() {
	mvaddch(yPos,xPos, sprite);
return 1;
}

void Person::promptName() {
	std::cout << "Enter username: " << std::endl;
	std::cin >> name;
	//name = "Player: " + name;
}

std::string Person::getName() {
	return name;
}


Person::~Person() {

}
