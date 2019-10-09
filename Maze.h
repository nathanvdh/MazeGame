#ifndef MAZE_H
#define MAZE_H

#include "Obstacle.h"

class Maze {
public:
	Maze();
	void setmap(Obstacle* aMap[5,5]);
	~Maze();
	
private:
	Obstacle* map[5,5];
};

#endif //MAZE_H
