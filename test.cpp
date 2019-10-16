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
	//need to implement better map -> do loop idea - can put it in a function
	Obstacle* myMap[MAPHEIGHT][MAPWIDTH] = 
	{	wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,finish,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
		wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,
	};
		
	Obstacle*** newMap = new Obstacle**[MAPHEIGHT];
	for (int i = 0; i < MAPHEIGHT; ++i)
  	{
    	newMap[i] = new Obstacle*[MAPWIDTH];
    	for (int j = 0; j < MAPWIDTH; ++j)
    	{
    		newMap[i][j] = myMap[i][j];
    	}
 	}
	
	maze->setMap(newMap);


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
