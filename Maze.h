#ifndef MAZE_H
#define MAZE_H

#include "Obstacle.h"
#include <curses.h>
class Maze {
public:
	Maze();
	void setMap(Obstacle* aMap[5][5]);
	void drawMap();
	~Maze();
	
private:
	Obstacle* map[5][5];
	int mapWidth;
	int mapHeight;
};

#endif //MAZE_H
