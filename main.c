#include <stdio.h>
#include "Board/CreateBoard.h"
#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "Board/Levels.h"
#include "Monster/Monster.h"


int main() {
    testCharacter();
    testMonster();
    generateBoard();
    printf("\n");
    char* board = createLevelBoard("../Levels/levelOne.txt");
    monster* monster = createLevelMonsters("../Levels/levelOne.txt");
    return 0;
}
