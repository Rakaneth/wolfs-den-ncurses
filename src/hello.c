#include <stdio.h>
#include <ncurses.h>

int main(void) {    
    initscr();
    printw("Hello World from Curses!");
    refresh();
    getch();
    endwin();
    return 0;
}