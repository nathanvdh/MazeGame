#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
#include "Space.h"
#include "Person.h"
#include "Hole.h"
#include "Banana.h"
#include <string>
Obstacle*** Map1(int MAPHEIGHT, int MAPWIDTH, Maze *maze, Person *person) {
//creates the map

	Wall *wall;
	Finish *finish;
	Space *space;
	Hole *hole;
	Banana *banana;

	wall = new Wall();
	finish = new Finish();
	space = new Space();
	hole = new Hole();
	banana = new Banana();


	std::string textMap[MAPHEIGHT] = { 

		"#########################",
		"#                       #",
		"#                       #",
		"#                       #",
		"#                       #",
		"#  (        O           #",
		"#                       #",
		"#                    (  #",
		"#                       #",
		"#                       #",
		"#                    O  #",
		"#                   OXO #",
		"#  O                    #",
		"#                       #",
		"#########################",
	};
	
	char currentChar= textMap[0].at(0);
	
	Obstacle*** myMap = new Obstacle**[MAPHEIGHT];
	
	for (int i = 0; i < MAPHEIGHT; ++i) {

    		myMap[i] = new Obstacle*[MAPWIDTH];
    		
    		for (int j = 0; j < MAPWIDTH; ++j) {
    			currentChar= textMap[i].at(j);

    			switch (currentChar) {
    				case '#':
    					myMap[i][j] = wall;
    					break;
    				case ' ':
    					myMap[i][j] = space;
    					break;
    				case 'O':
    					myMap[i][j] = hole;
    					break;
    				case '(':
    					myMap[i][j] = banana;
    					break;
    				case 'X': 
    					myMap[i][j] = finish;
    					break;
    			}
    		
    		}
 	}

return myMap;
}