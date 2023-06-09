#include "LevelsTests.h"
#include "stdio.h"
#include "stdlib.h"

void launchLevelTests() {
    levelChain *levelChain = malloc(sizeof (struct LevelChain));
    boardElements *board = malloc(sizeof (struct BoardElements));
    getLevelBoard("../Levels/niveau1.level", levelChain);
    for (int i = 0; i < 30; i++) {
        printf("%s\n", board->board[i]);
    }
    // There is 11 monsters in niveau1.level, so we loop to print 11 monsters
    for (int i = 0; i < 11; i++) {
        printMonsterStats(board->monstersTab[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%s\n", board->otherLevels[i]);
    }
    getLevelBoard(board->otherLevels[3], levelChain);
    for (int i = 0; i < 30; i++) {
        printf("%s\n", board->board[i]);
    }
}