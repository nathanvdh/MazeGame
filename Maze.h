#ifndef MAZE_H
#define MAZE_H

#include "Obstacle.h"
#include <curses.h>
class Maze {
public:
	Maze(int height, int width);
	void setMap(Obstacle*** aDynMap);
	void drawMap();
	Obstacle*** getMap();
	~Maze();
	
private:
	int mapWidth;
	int mapHeight;

	Obstacle*** dynMap;
};

#endif //MAZE_H
