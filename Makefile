all:
	g++ Entity.cpp Obstacle.cpp Maze.cpp Wall.cpp Finish.cpp Space.cpp Person.cpp Hole.cpp Banana.cpp Map1.cpp main.cpp -o maze.exe -lpdcurses
ncurses:
	g++ ncurses.cpp -o ncurses.exe -lncurses
pdcurses:
	g++ ncurses.cpp -o ncurses.exe -lpdcurses
drawtest:
	g++ Entity.cpp Obstacle.cpp Wall.cpp Finish.cpp drawMapTest.cpp -o drawtest.exe -lpdcurses
