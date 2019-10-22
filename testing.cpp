#include "Entity.h"
#include "Obstacle.h"
#include <iostream>
#include <string>
#include "Maze.h"
#include "Person.h"
#include <curses.h>
#include "Banana.h"
#include "Hole.h"
#include "Wall.h"


using namespace std;

int main (void) {

	char inp;
	string msg;
	
	cin >> inp;
	cin >> msg;

	//testing Entity class
	Entity *entity;
	entity = new Entity();
	cout << entity->setSprite(inp) << endl;
	cout << entity->getSprite() << endl;

	//testing Obstacle class
	Obstacle *obstacle;
	Person *person;
	Maze *maze;

	char key;
	cin >> key;
	int keyPress;

	obstacle = new Obstacle(inp, msg);
	
	switch (key) {
		case 'l':
			keyPress = KEY_LEFT;
			break;
		case 'r':
			keyPress = KEY_RIGHT;
			break;
		case 'u':
			keyPress = KEY_UP;
			break;
		case 'd':
			keyPress = KEY_DOWN;
			break;
		default :
			keyPress = 1;
	}

	cout << obstacle->touched(maze, person, keyPress) << endl;

	//testing Wall class
	Wall *wall;
	wall = new Wall();
	cout << wall->isWall() << endl;

	//testing Finish class
	

	//testing Banana class
	Banana *banana;
	banana = new Banana();

	cout << banana->touched(maze, person, keyPress) << endl;

	//testing Hole class
	Hole *hole;
	hole = new Hole();
	cout << hole->touched(maze, person, keyPress) << endl;

	//testing space
	
	//testing person
	int xPos, yPos;
	cin >> xPos;
	cin >> yPos;
	cout << person->setPos(xPos, yPos) <<endl;
	cout << person->getxPos() << " " << person->getyPos() << endl;

	//draw person change to bool function
	



return 0;
}