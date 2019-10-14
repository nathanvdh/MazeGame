#ifndef MAZE_H
#define MAZE_H

#include "Obstacle.h"

class Maze {
public:
	Maze();
	void setMap(Obstacle* aMap[5,5]);
	void drawMap(Obstacle* aMap[5,5]);
	~Maze();
	
private:
	Obstacle* map[5,5];
};

#endif //MAZE_H
