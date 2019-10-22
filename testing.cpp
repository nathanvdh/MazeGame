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

		//Entity class testing
	cout<< "testing Entity class" << endl;
	char inp;
	cin >> inp;
	
	Entity *entity;
	entity = new Entity();
	cout << entity->setSprite(inp) << endl;
	cout << entity->getSprite() << endl;


		//Obstacle class testing
	cout<< "testing Obstacle class" << endl;
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
			keyPress = KEY_RIGHT;
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

		// Wall class testing
	cout<< "testing Wall class" << endl;
	Wall *wall;
	wall = new Wall();
	cout << wall->isWall() << endl;

		//testing Finish class
	
		//maze class testing
	cout<< "testing maze class" << endl;
	int MAPHEIGHT, MAPWIDTH;
	cin >> MAPHEIGHT;
	cin >> MAPWIDTH;
	Banana *banana;
	Space *space;
	banana = new Banana();
	space = new Space();
	maze = new Maze(MAPHEIGHT, MAPWIDTH);

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

	cout << maze->setMap(Map) << endl;
	cout << maze->getMapHeight() << endl;
	cout << maze->getMapWidth() << endl;

	//person class testing
	cout<< "testing person class" << endl;
	int xPos, yPos;
	cin >> xPos;
	cin >> yPos;	
	cout << person->setPos(xPos, yPos, MAPHEIGHT, MAPWIDTH) <<endl;
	cout << person->getxPos() << " " << person->getyPos() << endl;

		//Hole class testing
	cout<< "testing Hole class" << endl;
	Hole *hole;
	hole = new Hole();
	cout << hole->touched(maze, person, keyPress) << endl;

		// Banana class testing
	cout<< "testing Banana class" << endl;
	cout << banana->touched(maze, person, keyPress) << endl;


	//testing space
	
	

	//draw person change to bool function
	



return 0;
}