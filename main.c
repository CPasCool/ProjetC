#include <stdio.h>
#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "SDL2/SDL.h"
#include "include/src/windows.h"
#include "src/EventListener/event.h"

int main(int argc, char *argv[]) {
    // TESTS
    testCharacter();
    testMonster();
    SDL_Window *window = createWindow();
    int status = EXIT_FAILURE;
    if ( window == NULL){
        goto Quit;
    }
    SDL_Renderer *renderer = createRenderer(window);
    if (renderer == NULL){
        goto Quit;
    }
    setIcon(window);
    // set background color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);


    handleEvent(renderer);



    status = EXIT_SUCCESS;
    Quit:
        if(NULL != renderer)
            SDL_DestroyRenderer(renderer);
        if(NULL != window)
            SDL_DestroyWindow(window);
        SDL_Quit();
    return status;
    // Start the game
//    LaunchGame();
    //    generateBoard();
}
