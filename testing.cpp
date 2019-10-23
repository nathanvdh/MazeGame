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
	cout << endl;
	cout<< "testing Entity class" << endl;
	Entity *entity;
	entity = new Entity();
	
	char inp = '#';

				//compares get sprite to value passed to set sprite
	entity->setSprite(inp);
	if (entity->getSprite() == inp) {
		cout << "success: setSprite \n";
	}	else {
		cout << "fail: setSprite \n";
	}



	
	// Wall class testing
	cout << endl;
	cout<< "testing Wall class" << endl;
	Wall *wall;
	wall = new Wall();

				//checks that the isWall function can correctly identify a wall
	if (wall->isWall()) {
		cout << "success: wall is wall\n";
	} else {
		cout << "fail: wall not wall\n";
	}




	//maze class testing
	Person *person;
	Maze *maze;
	Space *space;

	int MAPHEIGHT=10, MAPWIDTH=10, STARTYPOS=2, STARTXPOS=2;
	person = new Person();
	maze = new Maze(MAPHEIGHT, MAPWIDTH, STARTYPOS, STARTXPOS);
	space = new Space();

	cout << endl;
	cout<< "testing maze class" << endl;

				//Checks that the getMapHeight and getMapWidth functions return the values
				//set to the maze constructor
	if (maze->getMapHeight() == MAPHEIGHT && maze->getMapWidth() == MAPWIDTH) {
		cout << "success: map dimensions match\n";
	} else {
		cout << "fail: map dimensions don't match\n";
	}
				//creates a map
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

 				//checks that the getMap function returns the expected map
	maze->setMap(Map);
	bool mapCheck = 0;
	for (int i = 0; i < MAPHEIGHT; ++i) {
    	for (int j = 0; j < MAPWIDTH; ++j)
			if (maze->getMap()[i][j] == Map[i][j]) {
				mapCheck = 1;
			} else {
				mapCheck = 0;
				break;
			}
	}
			
	if (mapCheck)
	{
		cout << "sucess: maps match\n";
	} else {
		cout << "maps don't match\n";
	}
	
	for (int i = 0; i < MAPHEIGHT; ++i)
 		{
    		delete[] Map[i];
  		}
  	delete[] Map;

  				//checks if the drawMap function is successful
	if (maze->drawMap(person)) {
		cout << "success: map is drawn successfully\n";
	} else {
		cout << "fail: map was not drawn\n";
	}

				//checks the getCurrentObstacle returns the correct obstacle that the person is on
	person->setPos(2,2, maze);
	if (maze->getCurrentObstacle(person)==space)
	{
		cout << "success: getCurrentObstacle\n";
	} else {
		cout << "fail: getCurrentObstacle\n";
	}

				//checks the getNextObstacle returns the correct obstacle surrounding the person in all directions
	if (maze->getNextObstacle(person,KEY_RIGHT)==space && maze->getNextObstacle(person,KEY_LEFT)==space && maze->getNextObstacle(person,KEY_UP)==space && maze->getNextObstacle(person,KEY_DOWN)==space)
	{
		cout << "success: getNextObstacle\n";
	} else {
		cout << "fail: getNextObstacle\n";
	}

	//check the getStartY and getStartX functions
	if (maze->getStartY() == STARTYPOS && maze->getStartX() == STARTXPOS)
	{
		cout << "success: start position is correct\n";
	}	else {
		cout << "fail: start position does not match\n";
	}





				//test creating an invalid map with negative dimensions
	Maze* negMaze = new Maze(-5,-4,2,2);
	if (negMaze->getMapWidth() == 0 && negMaze->getMapHeight()==0)
	{
		cout << "success: map with negative dimensions is not created\n";
	} else {
		cout << "fail: map with negative dimensions does not default to 0s\n";
	}

	
				//test creating an invalid map with zero dimensions
	Maze* zeroMaze = new Maze(0,0,2,2);

	if (zeroMaze->getMapWidth() == 0 && zeroMaze->getMapHeight()==0)
	{
		cout << "success: map with zero dimensions is not created\n";
	} else {
		cout << "fail: map with zero dimensions does not default to 0s\n";
	}

	delete zeroMaze;
	delete negMaze;




	//Person class testing
	cout << endl;
	cout<< "testing person class" << endl;
	int xPos=3, yPos=3;

				//compares the getxPos and getyPos values to the inputted setPos values
	person->setPos(xPos, yPos, maze);
	if (person->getxPos()== xPos && person->getyPos()== yPos) {
		cout << "success: setPos\n";
	} else {
		cout << "fail: setPos\n";
	}

				//checks that the string returned from getName is the string that was passed to
				//setName
	string name = "myName";	
	person->setName(name);
	if (person->getName() == name)
	{
		cout << "success: setName\n";
	} else {
		cout << "fail: setName\n";
	}

				//Checks if the person object can move in all four directions over a space
	person->move(maze, KEY_RIGHT);
	if (person->getxPos() == xPos++ && person->getyPos() == yPos)
	{
		cout << "success: person move (right)\n";
	}
	
	person->move(maze, KEY_LEFT);
	if (person->getxPos() == xPos-- && person->getyPos() == yPos)
	{
		cout << "success: person move (left)\n";
	}

	person->move(maze, KEY_UP);
	if (person->getxPos() == xPos && person->getyPos() == yPos--)
	{
		cout << "success: person move (up)\n";
	}

	person->move(maze, KEY_DOWN);
	if (person->getxPos() == xPos && person->getyPos() == yPos++)
	{
		cout << "success: person move (down)\n";
	}

				//checks that the person object does not move into a wall
	person->setPos(1,1, maze);
	person->move(maze, KEY_UP);
	if (person->getxPos() == 1 && person->getyPos() == 1)
	{
		cout << "success: person can't move into wall\n";
	} else {
		cout << "fail: person moved when wall should block them";
	}

				//checks that the drawPerson function is sucessful	
	if (person->drawPerson()) {
		cout << "success: drawPerson";
	} else {
		cout << "fail: drawPerson";
	}




	//Obstacle class testing
	cout << endl;
	cout<< "\ntesting Obstacle class" << endl;

	Obstacle *obstacle;
	obstacle = new Obstacle(inp, "message");

				//checks that an obstacle can identify when a person is moved on to it from
				//all four directions
	if (obstacle->touched(maze, person, KEY_LEFT)==0 && obstacle->touched(maze, person, KEY_RIGHT)==0 && obstacle->touched(maze, person, KEY_UP)==0 && obstacle->touched(maze, person, KEY_DOWN) ==0) {
		cout << "obstacle touched: success\n";
	} else {
		cout << "obstacle touched: failed\n";
	}




	// Banana class testing
	cout << endl;
	cout<< "testing Banana class" << endl;
	
	Banana *banana;
	banana = new Banana();
	
	Map[1][2] = banana;
	maze->setMap(Map);
	person->move(maze, KEY_RIGHT);

				//checks that a banana moves a person to the expected position
	if (person->getxPos() == 8 && person->getyPos() == 1) {
		cout << "success: banana moved player to expected position";
	} else {
		cout << "fail: banana did not move player to expected position";
	}

	


	//Hole class testing
	cout << endl;
	cout<< "\ntesting Hole class" << endl;
	Hole *hole;
	hole = new Hole();

	Map[2][8] = hole;
	maze->setMap(Map);
	person->move(maze, KEY_DOWN);

				//checks that a hole moves a person to the expected position
	if (person->getxPos() == 2 && person->getyPos() == 2)
	{
		cout << "success: Hole moved player to 2,2\n";
	} else {
		cout << "fail: Hole did not move player to 2,2\n";
	}

return 0;
}