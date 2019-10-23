all:
	g++ Entity.cpp Obstacle.cpp Maze.cpp Wall.cpp Finish.cpp Space.cpp Person.cpp Hole.cpp Banana.cpp Map1.cpp main.cpp -o maze -lncurses
testing:
	g++ Entity.cpp Obstacle.cpp Maze.cpp Wall.cpp Finish.cpp Space.cpp Person.cpp Hole.cpp Banana.cpp testing.cpp -o testing -lncurses