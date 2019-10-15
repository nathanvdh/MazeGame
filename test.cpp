//FOR TESTING
//#include "Obstacle.h"
#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
#include "Person.h"
#include <string>
#include <iostream>
#include <curses.h>
int main(void)
{
	
	Wall *wall;
	Finish *finish;
	Person *person;
	
	wall = new Wall();
	finish = new Finish();
	person = new Person();

	std::cout << wall->getSprite() << "\n";
	wall->touched();

	
	std::cout << finish->getSprite() << '\n';
	finish->touched();

	Obstacle* myMap[5][5] = 
	{	wall,wall,wall,wall,wall,
		wall,NULL,NULL,finish,wall,
		wall,NULL,NULL,NULL,wall,
		wall,NULL,NULL,NULL,wall,
		wall,wall,wall,wall,wall,	};

	Maze maze = Maze();
	maze.setMap(myMap);
/*
	initscr(); //initialize screen
	cbreak(); //force cbreak mode (dont need to press enter to put character)
	keypad(stdscr, TRUE); //enable function/arrow keys
	curs_set(0); //disable cursor
*/
	//maze.drawMap();
/*	
	int row, column;
  	
  	for (row=0; row < 5; row++ ){
    	for (column=0; column < 5 ;column++) {
      		mvaddch(row, column, myMap[row][column]->getSprite());
    	}
  	}
*/
	//getch();
	//endwin();




	return 0;
}