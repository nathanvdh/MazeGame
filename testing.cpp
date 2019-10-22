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
#include "Space.h"


using namespace std;

int main (void) {

		//testing Entity class
	char inp;
	cin >> inp;
	
	Entity *entity;
	entity = new Entity();
	cout << entity->setSprite(inp) << endl;
	cout << entity->getSprite() << endl;


		//testing Obstacle class
	string msg;
	cin >> msg;
	char key;
	cin >> key;

	Obstacle *obstacle;
	Person *person;
	Maze *maze;

	obstacle = new Obstacle(inp, msg);
	
	int keyPress;
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
	const int MAPHEIGHT = 5, MAPWIDTH = 5; 
	Banana *banana;
	Space *space;
	banana = new Banana();
	space = new Space();
	
	std::string textMap[MAPHEIGHT] = { 

		"#####",
		"#   #",
		"#   #",
		"#   #",
		"#####",
	};
	
	char currentChar= textMap[0].at(0);
	
	Obstacle*** Map = new Obstacle**[MAPHEIGHT];
	
	for (int i = 0; i < MAPHEIGHT; ++i) {
    		Map[i] = new Obstacle*[MAPWIDTH];
    		for (int j = 0; j < MAPWIDTH; ++j) {
    			currentChar= textMap[i].at(j);
    			switch (currentChar) {
    				case '#':
    					Map[i][j] = wall;
    					break;
    				case ' ':
    					Map[i][j] = space;
    					break;
				}
    		}
 	}
	person->setPos(2, 2, MAPHEIGHT, MAPWIDTH);
	
	maze->setMap(Map);
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
	cout << person->setPos(xPos, yPos, MAPHEIGHT, MAPWIDTH) <<endl;
	cout << person->getxPos() << " " << person->getyPos() << endl;

	//draw person change to bool function
	



return 0;
}