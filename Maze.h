#ifndef MAZE_H
#define MAZE_H

#include <curses.h>
#include "Person.h"
class Obstacle;
class Maze {
public:
	Maze(int height, int width);
	void setMap(Obstacle*** aDynMap);
	void drawMap();
	Obstacle*** getMap();
	Obstacle* getNextObstacle(Person* person, int keyPress);
	int getMapHeight();
	~Maze();
	
private:
	int mapWidth;
	int mapHeight;

	Obstacle*** dynMap;
};

#endif //MAZE_H
