#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
#include "Space.h"
#include "Person.h"
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
	Person *person;
	
	const int MAPHEIGHT = 5,
			  MAPWIDTH = 6;

	Maze maze = Maze(MAPHEIGHT, MAPWIDTH);
	wall = new Wall();
	finish = new Finish();
	space = new Space();
	person = new Person();
	
	Obstacle* myMap[MAPHEIGHT][MAPWIDTH] = 
	{	wall,wall,wall,wall,wall,wall,
		wall,space,space,space,finish,wall,
		wall,space,space,space,space,wall,
		wall,space,space,space,space,wall,
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
	mvprintw(MAPHEIGHT+1,0,"Reach the end zone (X) to complete the game");
	mvprintw(MAPHEIGHT+2,0,"Press q to quit game");
	
	//Puts cursor at starting position
	//move(yPos,xPos);
	
	int inp = '\0';
	bool move;
	//Obstacle*** map = maze.getMap();
	while (inp !='q')
	{
		inp = getch();
		
		person->drawPerson();
		yPos = person.getyPos();
		xPos = person.getxPos();
		//Switch statement checks the objects surround the player
		switch (inp) {
			case KEY_UP :
				move = maze.getMap()[yPos++][xPos]->touched();
				if (move==1) {
					mvaddch(yPos,xPos,' ');
					player-> move(inp);
					mvaddch(yPos,xPos,'@');
				}
				break;
			case KEY_DOWN :
				move = maze.getMap()[yPos--][xPos]->touched();
				if (move==1) {
					mvaddch(yPos,xPos,' ');
					player-> move(inp);
					mvaddch(yPos,xPos,'@');
				}
				break;
			case KEY_LEFT :
				move = maze.getMap()[yPos][xPos--]->touched();
				if (move==1) {
					mvaddch(yPos,xPos,' ');
					player-> move(inp);
					mvaddch(yPos,xPos,'@');
				}
				break;
			case KEY_RIGHT :
				move = maze.getMap()[yPos][xPos++]->touched();
				if (move==1) {
					mvaddch(yPos,xPos,' ');
					player-> move(inp);
					mvaddch(yPos,xPos,'@');
				}
				break;
		}
		

		}
	
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
