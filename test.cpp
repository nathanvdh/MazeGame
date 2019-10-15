#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
#inlcude "Space.h"
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
	Space *space;
	//Person *person;
	
	const int MAPHEIGHT = 5,
			  MAPWIDTH = 6;

	Maze maze = Maze(MAPHEIGHT, MAPWIDTH);
	wall = new Wall();
	finish = new Finish();
	space = new Space();
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
	
	//drawing of map and text
	mvprintw(MAPHEIGHT,1,"Reach the end zone (X) to complete the game");
	mvprintw(MAPHEIGHT+2,1,"Press q to quit game");
	
	/* Not ready to compile yet
	//Puts cursor at starting position
	move(yPos,xPos);
	mvaddch(yPos,xPos,'@');
	
	bool move;
	
	while (inp !='q')
	{
		inp = getch();
		
		//Switch statement checks the objects surround the player
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
	*/
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
