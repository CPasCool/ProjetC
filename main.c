#include "include/src/CreateBoard.h"
#include <stdio.h>
#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "include/src/Levels.h"
#include "include/src/Monster.h"
#include "Tests/Levels/LevelsTests.h"
#include "include/src/Game.h"
#include "SDL2/SDL.h"
#include "include/src/windows.h"
#include "src/EventListener/event.h"

int main(int argc, char *argv[]) {
    // TESTS
    //testCharacter();
    //testMonster();
    //generateBoard();
    //launchLevelTests();
    testCharacter();
    testMonster();
    SDL_Window *window = createWindow();
    // Status of exec
    int status = EXIT_FAILURE;
    if ( window == NULL){
        goto Quit;
    }
    // create the renderer
    SDL_Renderer *renderer = createRenderer(window);
    if (renderer == NULL){
        goto Quit;
    }
    // set the icon of the current window
    setIcon(window);
    // set background color
    setBackgroundToWhite(renderer);


    handleEvent(renderer);


    //Start the game
    //generateBoard();

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
