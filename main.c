#include <stdio.h>
#include "Board/CreateBoard.h"
#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "Game/Game.h"


int main() {
    // TESTS
    testCharacter();
    testMonster();

    // Start the game
    LaunchGame();
    //    generateBoard();
    return 0;
}
