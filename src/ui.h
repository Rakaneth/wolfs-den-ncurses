#pragma once

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
