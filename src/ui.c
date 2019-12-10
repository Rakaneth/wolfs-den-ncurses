#include "ui.h"
#include <ncurses.h>
#include <stdarg.h>

static GameState CUR_STATE = STATE_MAIN;

void initDisplay(void) {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void closeDisplay(void) {
    endwin();
}

void gameLoop() {
    int ch;

    do {
        ch = getch();
        clear();
        switch(CUR_STATE) {
            case STATE_MAIN:
                CUR_STATE = handleMain(ch);
                break;
            case STATE_INVENTORY:
                CUR_STATE = handleInv(ch);
                break;
            default:
                break;
        }

    } while (CUR_STATE != STATE_QUIT);
}

GameState handleMain(int ch) {
    GameState result = STATE_MAIN;
    Point pp = {3, 5};
    Point pc = {4, 5};
    char buf[50];

    switch(ch) {
        case 'Q':
            result = STATE_QUIT;
            break;
        case 'i':
            printAt(0, 0, "Entered inventory");
            result = STATE_INVENTORY;
            break;
        default:
            printAtPt(pp, "Here is some pointed text");
            charAtPt(pc, '@');
            sprintf(buf, "Key was pressed in main: %d", ch);
            printAt(0, 0, buf);
    }
    return result;
}

GameState handleInv(int ch) {
    GameState result = STATE_INVENTORY;
    char buf[50];
    switch(ch) {
        case 'Q':
            printAt(0, 0, "Returned to main");
            result = STATE_MAIN;
            break;
        default:
            sprintf(buf, "Key was pressed in inv: %d", ch);
            printAt(0, 0, buf);
    }
    return result;
}

void printAt(int x, int y, const char* template) {
    mvprintw(y, x, template);
}

void charAt(int x, int y, const char ch) {
    mvaddch(y, x, ch);
}

void printAtPt(Point pt, const char* text) {
    printAt(pt.x, pt.y, text);
}

void charAtPt(Point pt, const char ch) {
    charAt(pt.x, pt.y, ch);
}

