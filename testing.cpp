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
#include "Finish.h"


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

	Obstacle*** Map = new Obstacle**[MAPHEIGHT];
	for (int i = 0; i < MAPHEIGHT; ++i) {
    		Map[i] = new Obstacle*[MAPWIDTH];
    		for (int j = 0; j < MAPWIDTH; ++j) {
				if (i==0 || i== MAPHEIGHT-1 || j == 0 || j == MAPWIDTH-1) {
    				Map[i][j]= wall;
				} else {
					Map[i][j]=space;
				}
    		}
 	}

	cout << maze->setMap(Map) << endl;
	cout << maze->getMapHeight() << " " << maze->getMapWidth() << endl;
	//cout << maze->drawMap(person) << endl; //this requires curses
	//getMap()

	//person class testing
	cout<< "testing person class" << endl;
	int xPos, yPos;
	cin >> xPos;
	cin >> yPos;	
	cout << person->setPos(xPos, yPos, maze) <<endl;
	cout << person->getxPos() << " " << person->getyPos() << endl;
	//cout << maze->getNextObstacle(person, keyPress)[person->getyPos()][person->getxPos()]->getSprite() << endl;
	cout << person->move(maze, keyPress) <<endl;
	//cout << person->drawPerson() << endl; //this requires curses

		//Hole class testing
	cout<< "testing Hole class" << endl;
	Hole *hole;
	hole = new Hole();
	cout << hole->touched(maze, person, keyPress) << endl;

	//testing Finish class
	cout << "testing Finish class" << endl;
	Finish *finish;
	finish = new Finish();
	//cout << finish->touched(maze, person, keyPress) << endl; //Finish::touched calls exit(0)

		// Banana class testing
	cout<< "testing Banana class" << endl;
	cout << banana->touched(maze, person, keyPress) << endl;

	//testing space	



return 0;
}