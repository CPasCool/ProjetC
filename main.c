#include <stdio.h>
#include "Board/CreateBoard.h"
#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "Board/DisplayLevels.h"
#include "Monster/Monster.h"


int main() {
    testCharacter();
    testMonster();
    generateBoard();
    printf("\n");
    displayLevel("../Levels/levelOne.txt");
    monster* monster1 = setLevelMonsters("../Levels/levelOne.txt")[0];
    return 0;
}
