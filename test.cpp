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
	initscr(); //initialize screen
	cbreak(); //force cbreak mode (dont need to press enter to put character)
	keypad(stdscr, TRUE); //enable function/arrow keys
	curs_set(0); //disable cursor
	noecho(); //disable echoing of input
	//Maze *maze;
	Wall *wall;
	Finish *finish;
	//Person *person;
	
	Maze maze = Maze();
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

	//initCurses();
	initscr(); //initialize screen
	cbreak(); //force cbreak mode (dont need to press enter to put character)
	keypad(stdscr, TRUE); //enable function/arrow keys
	curs_set(0); //disable cursor
	noecho(); //disable echoing of input
	int inp = '\0';

	maze.drawMap();

	//initialisation of map dimensions
	const int MAPHEIGHT = 5, MAPWIDTH = 5;
	//intialisation of position variables
	int xPos=2, yPos=2;
	
	//drawing of map and text
	drawMap(map,MAPWIDTH, MAPHEIGHT);
	mvprintw(MAPHEIGHT,1,"Reach the end zone (X) to complete the game");
	mvprintw(MAPHEIGHT+2,1,"Press q to quit game");
	
	//Puts cursor at starting position
	move(yPos,xPos);
	mvaddch(yPos,xPos,'@');
	
	bool move;
	
	while (inp !='q')
	{
		inp = getch();
		
		switch (inp) {
			case: UP
				move = map[yPos++][xPos]->touched();
				if (move==1) {
					mvaddch(yPos,xPos,' ');
					player-> move(inp);
					mvaddch(yPos,xPos,'@');
				}
				break;
			case: DOWN
				move = map[yPos--][xPos]->touched();
				if (move==1) {
					mvaddch(yPos,xPos,' ');
					player-> move(inp);
					mvaddch(yPos,xPos,'@');
				}
				break;
			case: LEFT
				move = map[yPos][xPos--]->touched();
				if (move==1) {
					mvaddch(yPos,xPos,' ');
					player-> move(inp);
					mvaddch(yPos,xPos,'@');
				}
				break;
			case: RIGHT
				move = map[yPos][xPos++]->touched();
				if (move==1) {
					mvaddch(yPos,xPos,' ');
					player-> move(inp);
					mvaddch(yPos,xPos,'@');
				}
				break;
		}
		

		};

	}
	
  	getch();
  	endwin();


	return 0;
}

void initCurses() {



}
