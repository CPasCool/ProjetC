#include <stdio.h>
#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "include/src/Game.h"
#include "SDL2/SDL.h"
#include "include/src/Windows.h"

int main(int argc, char *argv[]) {
    // TESTS
    testCharacter();
    testMonster();
    SDL_Window *window = init();
    if ( window == NULL){
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    SDL_DestroyWindow(window);
    Quit:
        SDL_Quit();
    return EXIT_SUCCESS;
    // Start the game
//    LaunchGame();
    //    generateBoard();
}
