#include <curses.h>

void drawMap(char map[][5], int MAPLENGTH);
void initcurses(void);

int main(void)
{
	char map[][5] =
	{	'#','#','#','#','#',
		'#',' ',' ',' ','#',
		'#',' ',' ',' ','#',
		'#',' ',' ',' ','#',
		'#','#','#','#','#',	};

	int inp = '\0';

	initcurses();
	drawMap(map, 5);

	while (inp !='q')
	{
		inp = getch();

		mvaddch(2,2,inp);		
	}

	endwin();
	return 0;
}	


void drawMap(char map[][5], int MAPLENGTH) {
	int row,column;
  	for (row=0;row<MAPLENGTH;row++ ){
    	for (column=0;column<MAPLENGTH;column++) {
      		mvaddch(row,column,map[row][column]);
    	}
  	}
}

void initcurses(void) {
	initscr(); //initialize screen
	cbreak(); //force cbreak mode (dont need to press enter to put character)
	keypad(stdscr, TRUE); //enable function/arrow keys
	curs_set(0); //disable cursor
	noecho(); //disable echoing of input
}
