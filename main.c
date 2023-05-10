#include <stdio.h>
#include "Board/CreateBoard.h"
#include "Tests/Character/TestCharacter.h"

int main() {
    printf("Hello, World!\n");
    TestCharacter();

    generateBoard();
    return 0;
}
