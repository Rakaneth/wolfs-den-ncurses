#include "ui.h"

#include <stdarg.h>

static GameState CUR_STATE = STATE_MAIN;
static WINDOW* mapWin;
static WINDOW* statWin;
static WINDOW* infoWin;
static WINDOW* skilWin;
static WINDOW* msgWin;

void initDisplay(void) {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    mapWin = newwin(30, 60, 0, 0);
    statWin = newwin(30, 40, 0, 60);
    infoWin = newwin(10, 40, 30, 60);
    skilWin = newwin(10, 30, 30, 30);
    msgWin = newwin(10, 30, 30, 0);
}

void closeDisplay(void) { endwin(); }

void gameLoop() {
    int ch = 0;

    do {
        // ch = getch();
        // clear();
        switch (CUR_STATE) {
            case STATE_MAIN:
                if (ch)
                    CUR_STATE = handleMain(ch);
                renderMain();
                break;
            case STATE_INVENTORY:
                if (ch)
                    CUR_STATE = handleInv(ch);
                renderInv();
                break;
            default:
                break;
        }
        if (CUR_STATE != STATE_QUIT)
            ch = getch();

    } while (CUR_STATE != STATE_QUIT);
}

GameState handleMain(int ch) {
    GameState result = STATE_MAIN;
    char buf[50];

    switch (ch) {
        case 'Q':
            result = STATE_QUIT;
            break;
        default:
            sprintf(buf, "Key was pressed in main: %d", ch);
            printAt(msgWin, 0, 0, buf);
    }
    return result;
}

GameState handleInv(int ch) {
    GameState result = STATE_INVENTORY;
    // char buf[50];
    // switch (ch) {
    //     case 'Q':
    //         printAt(0, 0, "Returned to main");
    //         result = STATE_MAIN;
    //         break;
    //     default:
    //         sprintf(buf, "Key was pressed in inv: %d", ch);
    //         printAt(0, 0, buf);
    // }
    return result;
}

void printAt(WINDOW* win, int x, int y, const char* template) {
    mvwprintw(win, y, x, template);
}

void charAt(WINDOW* win, int x, int y, const char ch) {
    mvwaddch(win, y, x, ch);
}

void printAtPt(WINDOW* win, Point pt, const char* text) {
    printAt(win, pt.x, pt.y, text);
}

void charAtPt(WINDOW* win, Point pt, const char ch) {
    charAt(win, pt.x, pt.y, ch);
}

void refreshAll() {
    WINDOW* windows[5] = {mapWin, statWin, msgWin, infoWin, skilWin};
    for (int i = 0; i < 5; i++) {
        wrefresh(windows[i]);
    }
}

void renderMain() {
    box(mapWin, 0, 0);
    box(statWin, 0, 0);
    box(msgWin, 0, 0);
    box(infoWin, 0, 0);
    box(skilWin, 0, 0);
    refreshAll();
}

void renderInv() { /* not implemented */
}