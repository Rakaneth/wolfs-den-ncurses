#pragma once

#include "point.h"

typedef enum game_state_t {
    STATE_MAIN,
    STATE_INVENTORY,
    STATE_QUIT
} GameState;

void initDisplay(void);
void closeDisplay(void);
GameState handleMain(int ch);
GameState handleInv(int ch);
void gameLoop();
void printAt(int x, int y, const char* template);
void charAt(int x, int y, const char ch);
void printAtPt(Point pt, const char* text);
void charAtPt(Point pt, const char ch);