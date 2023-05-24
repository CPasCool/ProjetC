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
    char** board = getLevelBoard("../Levels/levelOne.txt");
    for(int i =0; i<30; i++){
        printf("%s\n", board[i]);
    }
    return 0;
}
