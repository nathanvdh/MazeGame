#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
#include "Space.h"
#include "Person.h"
#include "Hole.h"
#include "Banana.h"
//#include <string>
//#include <iostream>
#include <curses.h>

void initCurses();
//Obstacle*** createMap(int height, int width, Space* space);

int main(void)
{	
	const int MAPHEIGHT = 15,
			  MAPWIDTH = 25;

			  
	Maze *maze;
	Wall *wall;
	Finish *finish;
	Space *space;
	Person *person;
	Hole *hole;
	Banana *banana;

	maze = new Maze(MAPHEIGHT, MAPWIDTH);
	wall = new Wall();
	finish = new Finish();
	space = new Space();
	person = new Person();
	hole = new Hole();
	banana = new Banana();
	
	//creates the map

	Obstacle*** myMap = new Obstacle**[MAPHEIGHT];
	for (int i = 0; i < MAPHEIGHT; ++i)
  	{
    	myMap[i] = new Obstacle*[MAPWIDTH];
    	for (int j = 0; j < MAPWIDTH; ++j)
    	{
    		if (i == 0 || i == MAPHEIGHT-1 || j == 0 || j== MAPWIDTH-1)
    		{
    			myMap[i][j] = wall;
    		} 

    		else if (i == 10 && j == 10) {
    			myMap[i][j] = finish;
    		}

    		else if ((i== 9 && j==10) || (i==9 && j==11) || (i==10 && j==11) || (i==11 && j==11) || (i==11 && j==10) ){
    			myMap[i][j] = hole;
    		}

    		else if ((i==9 && j==8) || (i == 9 && j == 4)) {
    			myMap[i][j] = banana;
    		}

    		else {
    			myMap[i][j] = space;	
    		}
    		
    	}
 	}

 	person->setPos(2,2);

	maze->setMap(myMap);
	initCurses();
	maze->drawMap();
	
	int keyPress = '\0';
	//bool move;
	//Obstacle*** map = maze.getMap();
	while (keyPress !='q')
	{
		person->drawPerson();
		keyPress = getch();
		
		if (keyPress == KEY_UP || keyPress == KEY_DOWN || keyPress == KEY_LEFT || keyPress == KEY_RIGHT )
		{
			maze->getNextObstacle(person, keyPress)->touched(maze, person, keyPress);
		}
		
	}
  	
  	endwin();
	return 0;
}

void initCurses() {

	initscr(); //initialize screen
	cbreak(); //force cbreak mode (dont need to press enter to put character)
	keypad(stdscr, TRUE); //enable function/arrow keys
	curs_set(0); //disable cursor
	noecho(); //disable echoing of input

}
/*
Obstacle*** createMap(int height, int width, Space* space) {
	//create and fill with spaces
	Obstacle*** myMap = new Obstacle**[height];
	for (int i = 0; i < height; ++i)
  	{
    	myMap[i] = new Obstacle*[width];
    	for (int j = 0; j < width; ++j)
    	{
    		myMap[i][j] = space;
    	}
 	}




}
*/