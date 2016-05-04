#include <ncurses.h>
#include <stdlib.h>
#include <ctime>


void mapainicial();
int main(int argc,char*argv[])
{
	initscr();
	colors();
	mvprintw(1,1,"Hola mama como stas");
	refresh();
	getch();
	endwin();
	return 0; 
}

void mapainicial()
{

}