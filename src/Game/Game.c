#include <stdbool.h>
#include <stdio.h>
#include "stdlib.h"
#include "../../include/src/Game.h"
#include "../../SDL2/SDL_render.h"
#include "../../include/src/TextureConst.h"
#include "../../SDL2/SDL_events.h"
#include "../../include/src/windows.h"


const int MAXIMUM_CHOICE_MENU = 5;
const int MINIMUM_CHOICE_MENU = 1;


int LaunchGame() {
    printf("Z -> move up\n"
           "S -> move down\n"
           "E -> validate choice\n");

    choiceMenu *menu = createChoiceMenu();
    bool isChoiced = false;
    do {
        int choice = getChoice(menu);

        displayMenu(menu);
        char result = catchInput();
        if (result == 'z') {
            if (choice != MINIMUM_CHOICE_MENU) {
                setChoice(menu, choice - 1);
            }
        } else if (result == 's') {
            if (choice != MAXIMUM_CHOICE_MENU) {
                setChoice(menu, choice + 1);
            }
        } else if (result == 'e') {
            isChoiced = true;
            if (choice == 1) {
//                play();
                break;
            }
        }
    } while (!isChoiced);
    return 0;
}

void displayBoard(char **board, SDL_Renderer *renderer, SDL_Texture *tile, SDL_Texture *Character1,
                  SDL_Texture *Character2) {
    int size = 27;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            SDL_Rect destination = {j * size, i * size, size, size};
            SDL_RenderCopy(renderer, tile, &ground, &destination);
            switch (board[i][j]) {
                case 'T':
                    SDL_RenderCopy(renderer, Character2, &playerCharacter, &destination);
                    break;

                case '1':

                    break;

                    //There is a Defence bonus
                case '2':
                    SDL_RenderCopy(renderer, tile, &shield, &destination);
                    break;
                    //There is a life bonus
                case '3':

                    break;

                    //There is a key
                case '!':

                    SDL_RenderCopy(renderer, tile, &key, &destination);

                    break;

                    //There is a door
                case 'o':

                    break;

                    //There is a potion
                case 'P':
                    SDL_RenderCopy(renderer, tile, &potion, &destination);

                    break;

                    //There is a monster
                case 'A':
                    SDL_RenderCopy(renderer, Character2, &aMonster, &destination);

                    break;
                case 'B':
                    SDL_RenderCopy(renderer, Character2, &bMonster, &destination);

                    break;
                case 'C':
                    SDL_RenderCopy(renderer, Character2, &cMonster, &destination);

                    break;

                    //There is a wall
                case '#':
                    SDL_RenderCopy(renderer, tile, &wallGround, &destination);
                    break;

                case '?':
                    break;
                default:
                    break;
            }
        }
//        printf("%s\n", board[i]);
    }
    SDL_RenderPresent(renderer);
}


void play(SDL_Renderer *renderer, SDL_Texture *tile, SDL_Texture *character1, SDL_Texture *character2) {
    // condition de sortie du jeu
    Character *character = createCharacter("player");

    boardElements *board = createBoardElement();
    levelChain *levelChain = NULL;
    board->character = character;
    //We get/set every element we have on the file
    levelChain = getLevelBoard("./src/Levels/niveau1.level", levelChain);

    //We put the character at is right position
    levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
    printf("character is set\n");
    SDL_bool quit = SDL_FALSE;
    // boucle de jeu
    while (!quit) {
        levelChain->current->character = character;
        displayBoard(levelChain->current->board, renderer, tile, character1, character2);
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            return;
        else if (event.type == SDL_KEYDOWN)
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_P:
                case SDL_SCANCODE_ESCAPE:
                    if (pauseMenu('p', board->character) == 1)
                        quit = true;
                    break;
                case SDL_SCANCODE_Z:
                case SDL_SCANCODE_UP:
                    levelChain = move(character, 'z', levelChain->current, levelChain);
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    levelChain = move(character, 's', levelChain->current, levelChain);
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    levelChain = move(character, 'd', levelChain->current, levelChain);
                    break;
                case SDL_SCANCODE_Q:
                case SDL_SCANCODE_LEFT:
                    levelChain = move(character, 'q', levelChain->current, levelChain);
                    break;
                default:
                    break;
            }
        if (getLifePoint(character) <= 0) {
            loadImage(renderer,"assets/Images/deathScreen");


            quit = SDL_TRUE;
            printf("You are dead !\n");
        }
        if (board->aliveMonsters == 0) {
            printf("Congratulation You finished the level !!!!\n");
        }
        fflush(stdout);
        }
    }
//        if (input == 'p') {
//            if (pauseMenu(input, board->character) == 1) {
//                inGame = false;
//            }
//        } else if (input == 'z' || input == 'q' || input == 's' || input == 'd') {
//            levelChain = move(character, input, levelChain->current, levelChain);
//        } else if (input == 'm') {
//            printf("Here are all monsters\n");
//            for (int i = 0; i < levelChain->current->nbMonsters; i++) {
//                printMonsterStats(levelChain->current->monstersTab[i]);
//                printf("\n");
//            }
//        } else {
//            printf("Stop doing this shit !\n");
//        }
//        if (getLifePoint(character) <= 0) {
//            inGame = false;
//            printf("You are dead !\n");
//        }
//        if (board->aliveMonsters == 0) {
//            printf("Congratulation You finished the level !!!!\n");
//        }
//        fflush(stdout);
//
//    }
