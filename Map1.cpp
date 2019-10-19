#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
#include "Space.h"
#include "Person.h"
#include "Hole.h"
#include "Banana.h"

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

	Obstacle*** myMap = new Obstacle**[MAPHEIGHT];
	for (int i = 0; i < MAPHEIGHT; ++i) {

    		myMap[i] = new Obstacle*[MAPWIDTH];
    		for (int j = 0; j < MAPWIDTH; ++j) {
    			if (i == 0 || i == MAPHEIGHT-1 || j == 0 || j== MAPWIDTH-1) {
    				myMap[i][j] = wall;
    			} 

    			else if (i == 10 && j == 10) {
    				myMap[i][j] = finish;
    			}
	
    			else if ((i== 9 && j==10) || (i==9 && j==11) || (i==10 && j==11) || (i==11 && j==11) || (i==11 && j==10) ) {
    				myMap[i][j] = hole;
    			}

    			else if ((i==9 && j==8) || (i == 9 && j == 4)) {
    				myMap[i][j] = banana;
    			}

    			else {
    				myMap[i][j] = space;	
    			}
    		
    		}
 	}

return myMap;
}