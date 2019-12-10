#include "ui.h"
#include <ncurses.h>

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
        }

    } while (CUR_STATE != STATE_QUIT);
}

GameState handleMain(int ch) {
    GameState result = STATE_MAIN;

    switch(ch) {
        case 'Q':
            result = STATE_QUIT;
            break;
        case 'i':
            mvprintw(0, 0, "Entered inventory");
            result = STATE_INVENTORY;
            break;
        default:
            mvprintw(0, 0, "Key was pressed in main: %d", ch);
    }
    return result;
}

GameState handleInv(int ch) {
    GameState result = STATE_INVENTORY;
    switch(ch) {
        case 'Q':
            mvprintw(0, 0, "Returned to main");
            result = STATE_MAIN;
            break;
        default:
            mvprintw(0, 0, "Key was pressed in inv: %d", ch);
    }
    return result;
}