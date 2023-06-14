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
#include "SDL2/SDL_ttf.h"

int main(int argc, char *argv[]) {
    // TESTS
    //testCharacter();
    //testMonster();
    //generateBoard();
    //launchLevelTests();
//    testCharacter();
//    testMonster();
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
    SDL_Texture *tiles = loadImage(renderer, "assets/Images/v2/Dungeon_Tileset.bmp");
    SDL_Texture *characters = loadImage(renderer, "assets/Images/Character.bmp");
    SDL_Texture *characters2 = loadImage(renderer, "assets/Images/v2/Character2.bmp");
    SDL_Texture *background = loadImage(renderer, "assets/Images/menu.bmp");
    TTF_Font *font = TTF_OpenFont("assets/font/04B_31__.TTF", 32);

    // check if import is ok
    if (tiles == NULL || characters == NULL || characters2 == NULL || font == NULL) {
        goto Quit;
    }


    SDL_SetRenderTarget(renderer, NULL);
//    SDL_QueryTexture(tiles, NULL, NULL, &dst.w, &dst.h);
//    SDL_RenderCopy(renderer, tiles, &wallGround, &dst);
//    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(renderer,background,NULL,NULL);
    SDL_RenderPresent(renderer);
    LaunchGame(renderer,tiles,characters2,font);
//    play(NULL,renderer, tiles, characters2);

    //Start the game
    //generateBoard();

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
    if (NULL != font)
        TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    printf("%d", status);
    fflush(stdout);
    return status;
    // Start the game
//    LaunchGame();
    //    generateBoard();
}
