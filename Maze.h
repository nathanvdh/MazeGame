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
	//Obstacle* map[5][5];
	int mapWidth;
	int mapHeight;

	//2d dynamic array attempt
	Obstacle*** dynMap;
};

#endif //MAZE_H
