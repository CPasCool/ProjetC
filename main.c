#include <stdio.h>
#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "include/src/Game.h"
#include "include/SDL2/SDL.h"

int main(int argc, char *argv[]) {
    // TESTS
    testCharacter();
    testMonster();
    printf("test");
    SDL_Window *window = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        return -1;
    }
    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              500, 500, SDL_WINDOW_SHOWN);
    if(NULL == window)
        fprintf(stderr, "Erreur de creation de la fenetre : %s\n", SDL_GetError());
    else
    {
            while (1){
                printf("test");
                printf("test2");
            }
//        SDL_Delay(500);
    }
//    SDL_Quit();
    return 0;
    // Start the game
//    LaunchGame();
    //    generateBoard();
    return 0;
}
