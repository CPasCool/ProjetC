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
    getLevelBoard("../Levels/levelOne.txt");
    char** board = getLevelBoard("../Levels/levelOne.txt");
    return 0;
}
