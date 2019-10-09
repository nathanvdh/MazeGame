#ifndef MAZE_H
#define MAZE_H

#include "Obstacle.h"

class Maze {
public:
	Maze();
	void setmap(Obstacle* aMap[20,20]);
	~Maze();
	
private:
	Obstacle* map[20,20];
};

#endif //MAZE_H
