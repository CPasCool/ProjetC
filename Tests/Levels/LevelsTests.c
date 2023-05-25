#include "LevelsTests.h"
#include "stdio.h"

void launchLevelTests() {
    char **board = getLevelBoard("../Levels/niveau1.level");
    for (int i = 0; i < 30; i++) {
        printf("%s\n", board[i]);
    }
    monster **monsters = getLevelMonsters("../Levels/niveau1.level");
    // There is 11 monsters in niveau1.level, so we loop to print 11 monsters
    for (int i = 0; i < 11; i++) {
        printMonsterStats(monsters[i]);
    }
    char **levels = getOtherLevels("../Levels/niveau1.level");
    for (int i = 0; i < 4; i++) {
        printf("%s\n", levels[i]);
    }
    board = getLevelBoard(levels[3]);
    for (int i = 0; i < 30; i++) {
        printf("%s\n", board[i]);
    }
}