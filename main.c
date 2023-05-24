#include <stdio.h>
#include "Board/CreateBoard.h"
#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "menu/menu.h"


int main() {
    testCharacter();
    testMonster();
    generateBoard();
    menu();
    return 0;
}
