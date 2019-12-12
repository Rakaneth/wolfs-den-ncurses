#pragma once

#include "point.h"
#include <ncurses.h>

typedef enum game_state_t { STATE_MAIN, STATE_INVENTORY, STATE_QUIT } GameState;

void initDisplay(void);
void closeDisplay(void);
GameState handleMain(int ch);
GameState handleInv(int ch);
void gameLoop();
void printAt(WINDOW* win, int x, int y, const char* template);
void charAt(WINDOW* win, int x, int y, const char ch);
void printAtPt(WINDOW* win, Point pt, const char* text);
void charAtPt(WINDOW* win, Point pt, const char ch);
void renderMain();
void renderInv();
void refreshAll();