walltest:
	g++ Entity.cpp Obstacle.cpp Maze.cpp Wall.cpp Finish.cpp Space.cpp Person.cpp test.cpp -o walltest.exe -lncurses
ncurses:
	g++ ncurses.cpp -o ncurses.exe -lncurses
pdcurses:
	g++ ncurses.cpp -o ncurses.exe -lpdcurses
drawtest:
	g++ Entity.cpp Obstacle.cpp Wall.cpp Finish.cpp drawMapTest.cpp -o drawtest.exe -lpdcurses
