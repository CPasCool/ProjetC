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
    if (window == NULL) {
        goto Quit;
    }
    // create the renderer
    SDL_Renderer *renderer = createRenderer(window);
    if (renderer == NULL) {
        goto Quit;
    }
    // set the icon of the current window
    setIcon(window);
    // set background color
    setBackgroundToWhite(renderer);

    // load textures
    SDL_Texture *tiles = loadImage(renderer, "assets/Images/TileSet.bmp");
    SDL_Texture *characters = loadImage(renderer, "assets/Images/Character.bmp");
    SDL_Texture *characters2 = loadImage(renderer, "assets/Images/Character2.bmp");
    // check if import is ok
    if (tiles == NULL || characters == NULL || characters2 == NULL) {
        goto Quit;
    }


    SDL_RenderPresent(renderer);
    //Start the game
    //generateBoard();
    handleEvent(renderer);

    status = EXIT_SUCCESS;
    Quit:
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);
    if (NULL != tiles)
        SDL_DestroyTexture(tiles);
    if (NULL != characters)
        SDL_DestroyTexture(characters);
    if (NULL != characters2)
        SDL_DestroyTexture(characters2);
    SDL_Quit();
    return status;
    // Start the game
//    LaunchGame();
    //    generateBoard();
}
