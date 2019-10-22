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
extern Obstacle*** Map1(int MAPHEIGHT, int MAPWIDTH, Maze *maze, Person *person);

int main(void)
{	
	const int MAPHEIGHT = 15,
			  MAPWIDTH = 25;
	  
	Maze *maze;
	Person *person;
	
	maze = new Maze(MAPHEIGHT, MAPWIDTH);
	person = new Person();

 	person->setPos(2,2);
	Obstacle*** myMap = Map1(MAPHEIGHT, MAPWIDTH, maze, person);
	std::cout << "Enter user name: " << std::endl;
	std::string name;
	std::cin >> name;
	name = "Player: " + name;
	
	
	
	maze->setMap(myMap);
	initCurses();
	maze->drawMap();
	person->drawPerson();
	mvprintw(MAPHEIGHT+4,0,name.c_str());
	
	int keyPress = '\0';

	while (keyPress !='q')
	{
		keyPress = getch();
		
		if (keyPress == KEY_UP || keyPress == KEY_DOWN || keyPress == KEY_LEFT || keyPress == KEY_RIGHT )
		{
			person->move(maze, keyPress);
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
