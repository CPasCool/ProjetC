#include <stdio.h>
#include "Board/CreateBoard.h"
#include "Tests/Character/TestCharacter.h"

int main() {
    testCharacter();
    testMonster();
    generateBoard();
    return 0;
}
