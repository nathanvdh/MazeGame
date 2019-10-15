#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
//#include "Person.h"
//#include <string>
//#include <iostream>
#include <curses.h>

void initCurses();

int main(void)
{	

	//Maze *maze;
	Wall *wall;
	Finish *finish;
	//Person *person;
	
	const int MAPHEIGHT = 5,
			  MAPWIDTH = 6;

	Maze maze = Maze(MAPHEIGHT, MAPWIDTH);
	wall = new Wall();
	finish = new Finish();
	//person = new Person();
	
	Obstacle* myMap[MAPHEIGHT][MAPWIDTH] = 
	{	wall,wall,wall,wall,wall,wall,
		wall,NULL,NULL,NULL,finish,wall,
		wall,NULL,NULL,NULL,NULL,wall,
		wall,NULL,NULL,NULL,NULL,wall,
		wall,wall,wall,wall,wall,wall,	};

	Obstacle*** newMap = new Obstacle**[MAPHEIGHT];
	for (int i = 0; i < MAPHEIGHT; ++i)
  	{
    	newMap[i] = new Obstacle*[MAPWIDTH];
    	for (int j = 0; j < MAPWIDTH; ++j)
    	{
    		newMap[i][j] = myMap[i][j];
    	}
 	}



	maze.setMap(newMap);


	initCurses();

	maze.drawMap();

  	getch();
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