#include "ui.h"
#include "gamedata.h"

int main(void) {    
    readData("data/test.dat", DATA_CREATURE);
    initDisplay();
    gameLoop();
    closeDisplay();
    return 0;
}