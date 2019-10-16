#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
#include "Space.h"
#include "Person.h"
//#include <string>
//#include <iostream>
#include <curses.h>

void initCurses();
//Obstacle*** createMap(int height, int width, Space* space);

int main(void)
{	

	Maze *maze;
	Wall *wall;
	Finish *finish;
	Space *space;
	Person *person;
	
	const int MAPHEIGHT = 15,
			  MAPWIDTH = 25;

	maze = new Maze(MAPHEIGHT, MAPWIDTH);
	wall = new Wall();
	finish = new Finish();
	space = new Space();
	person = new Person();

	person->setPos(2,2);
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

    		else {
    			myMap[i][j] = space;	
    		}
    		
    	}
 	}

	
	maze->setMap(myMap);


	initCurses();

	maze->drawMap();
	
	
	int inp = '\0';
	//bool move;
	//Obstacle*** map = maze.getMap();
	while (inp !='q')
	{
		person->drawPerson();
		inp = getch();

		//Switch statement checks the objects surround the player
		switch (inp) {
			case KEY_UP :
				maze->getMap()[person->getyPos()-1][person->getxPos()]->touched(maze, person, inp);
				break;
			case KEY_DOWN :
				maze->getMap()[person->getyPos()+1][person->getxPos()]->touched(maze, person, inp);
				break;
			case KEY_LEFT :
				maze->getMap()[person->getyPos()][person->getxPos()-1]->touched(maze, person, inp);
				break;
			case KEY_RIGHT :
				maze->getMap()[person->getyPos()][person->getxPos()+1]->touched(maze, person, inp);
				break;
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