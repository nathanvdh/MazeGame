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
	
	Maze maze = new Maze();
	wall = new Wall();
	finish = new Finish();
	//person = new Person();
	
	Obstacle* myMap[5][5] = 
	{	wall,wall,wall,wall,wall,
		wall,NULL,NULL,finish,wall,
		wall,NULL,NULL,NULL,wall,
		wall,NULL,NULL,NULL,wall,
		wall,wall,wall,wall,wall,	};

	maze.setMap(myMap);

	initCurses();

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