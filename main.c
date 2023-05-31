#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "include/src/Game.h"


int main() {
    // TESTS
    testCharacter();
    testMonster();

    // Start the game
    LaunchGame();
    //    generateBoard();
    return 0;
}
