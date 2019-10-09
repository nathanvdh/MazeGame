#include <curses.h>

int main(void)
{
	initscr(); //initialize screen
	cbreak(); //force cbreak mode (dont need to press enter to put character)
	keypad(stdscr, TRUE); //enable function/arrow keys
	curs_set(0); //disable cursor
	noecho(); //disable echoing of input
	int inp = '\0';
	
	while (inp !='q')
	{
		inp = getch();

		mvaddch(5,50,inp);		
	}

	endwin();
	return 0;
}	

