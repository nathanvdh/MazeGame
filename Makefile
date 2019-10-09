walltest:
	g++ Entity.cpp Obstacle.cpp Wall.cpp Finish.cpp test.cpp -o walltest.exe
ncurses:
	g++ ncurses.cpp -o ncurses.exe -lcurses