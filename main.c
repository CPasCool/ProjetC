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
    int status = EXIT_FAILURE;
    if ( window == NULL){
        goto Quit;
    }
    SDL_Renderer *renderer = createRenderer(window);
    if (renderer == NULL){
        goto Quit;
    }

    // set background color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);



    status = EXIT_SUCCESS;
    Quit:
        SDL_DestroyWindow(window);
        SDL_Quit();
    return status;
    // Start the game
//    LaunchGame();
    //    generateBoard();
}
