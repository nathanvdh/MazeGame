#ifndef MAZE_H
#define MAZE_H

class Maze {
public:
	Maze();
	void setmap(char aMap[20,20]);
	~Maze();
private:
	char map[20,20];
};

#endif //MAZE_H