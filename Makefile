walltest:
	g++ Entity.cpp Obstacle.cpp Wall.cpp Finish.cpp test.cpp -o walltest.exe
ncurses:
	g++ ncurses.cpp -o ncurses.exe -lncurses
pdcurses:
	g++ ncurses.cpp -o ncurses.exe -lpdcurses
drawtest:
	g++ Entity.cpp Obstacle.cpp Wall.cpp Finish.cpp drawMapTest.cpp -o drawtest.exe -lpdcurses