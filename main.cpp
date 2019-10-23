#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
#include "Space.h"
#include "Person.h"
#include "Hole.h"
#include "Banana.h"
#include <string>
#include <iostream>
#include <curses.h>

void initCurses();
extern Obstacle*** Map1(int MAPHEIGHT, int MAPWIDTH, Maze *maze, Person *person, Wall *wall, Finish *finish, Space *space, Hole *hole, Banana *banana);

int main(void)
{	
	const int MAPHEIGHT = 15,
			  MAPWIDTH = 25,
			  STARTYPOS = 2,
			  STARTXPOS = 1;
	
	Maze *maze;
	Person *person;
	Wall *wall;
	Finish *finish;
	Space *space;
	Hole *hole;
	Banana *banana;

	maze = new Maze(MAPHEIGHT, MAPWIDTH, STARTYPOS, STARTXPOS);
	person = new Person();
	wall = new Wall();
	finish = new Finish();
	space = new Space();
	hole = new Hole();
	banana = new Banana();
 	
	//Create and set map in maze
	Obstacle*** myMap = Map1(MAPHEIGHT, MAPWIDTH, maze, person, wall, finish, space, hole, banana);
	maze->setMap(myMap);
	
	//delete unneeded myMap
	for (int i = 0; i < MAPHEIGHT; ++i)
 		{
    		delete[] myMap[i];
  		}

  	delete[] myMap;
	
	//set starting position of player and ask for username
	person->setPos(maze->getStartX(), maze->getStartY(), maze);
	std::string name;
	std::cout << "Enter player name: " << std::endl;
	std::cin >> name;
	person->setName(name);

	initCurses();

	//draw map and player to the screen
	maze->drawMap(person);
	person->drawPerson();
	
	int keyPress = '\0';

	//loop getting input and moving the player
	while (keyPress !='q')
	{
		keyPress = getch();
		
		if (keyPress == KEY_UP || keyPress == KEY_DOWN || keyPress == KEY_LEFT || keyPress == KEY_RIGHT )
		{
			if (person->move(maze, keyPress) == 2) {
				keyPress = 'q';
			}
		}
		
	}

	delete maze;
	delete person;
	delete wall;
	delete finish;
	delete space;
	delete hole;
	delete banana;
  	
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
