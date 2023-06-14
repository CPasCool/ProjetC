#include <stdbool.h>
#include <stdio.h>
#include "../../include/src/Game.h"
#include "../../include/src/TextureConst.h"


const int MAXIMUM_CHOICE_MENU = 5;
const int MINIMUM_CHOICE_MENU = 1;

/**
 * start the game
 * @param renderer -> renderer of the windows
 * @param background -> texture of the background
 * @param font -> font for write text
 * @param window -> game window for future usage
 * @return if a error -1 if error
 */
int LaunchGame(SDL_Renderer *renderer, SDL_Texture *background, SDL_Texture *tile, SDL_Texture *characterTexture,
               TTF_Font *font, SDL_Window *window) {
    printf("Z -> move up\n"
           "S -> move down\n"
           "E -> validate choice\n");

    choiceMenu *menu = createChoiceMenu();
    bool isChoiced = false;
    do {
        int choice = getChoice(menu);

        displayMenu(menu, renderer, background, font);
        char result = catchInput();
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            return 0;
        switch (event.type) {
            case SDL_SCANCODE_Z:
            case SDL_SCANCODE_UP:
                if (choice != MINIMUM_CHOICE_MENU) {
                    setChoice(menu, choice - 1, renderer, background, font);
                }
                break;
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
                if (choice != MAXIMUM_CHOICE_MENU) {
                    setChoice(menu, choice + 1, renderer, background, font);
                }
                break;
            case SDL_SCANCODE_E:
            case SDL_SCANCODE_KP_ENTER:
                isChoiced = true;
                if (choice == 1) {
                    play(renderer, tile, characterTexture, window);
                } else {
                    if (choice == 2) {
                        displayCredit();
                    }
                }
                break;
            default:
                break;
        }
    } while (!isChoiced);
    return 0;
}

void displayBoard(char **board, SDL_Renderer *renderer, SDL_Texture *tile, SDL_Texture *Character2) {
    int size = 27;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            SDL_Rect destination = {j * size, i * size, size, size};
            SDL_RenderCopy(renderer, tile, &ground, &destination);
            SDL_bool asWallUp = SDL_FALSE;
            SDL_bool asWallDown = SDL_FALSE;
            SDL_bool asWallLeft = SDL_FALSE;
            SDL_bool asWallRight = SDL_FALSE;

            switch (board[i][j]) {
                case 'T':
                    SDL_RenderCopy(renderer, Character2, &playerCharacter, &destination);
                    break;

                case '1':
                    SDL_RenderCopy(renderer, tile, &strengthBonus, &destination);
                    break;

                    //There is a Defence bonus
                case '2':
                    SDL_RenderCopy(renderer, tile, &shield, &destination);
                    break;
                    //There is a life bonus
                case '3':
                    SDL_RenderCopy(renderer, tile, &heart, &destination);

                    break;

                    //There is a key
                case '!':

                    SDL_RenderCopy(renderer, tile, &key, &destination);

                    break;

                    //There is a door
                case 'o':
                    SDL_RenderCopyEx(renderer, tile, &door, &destination, south, NULL, SDL_FLIP_NONE);

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

                    //There is a northWall
                case '#':
                    SDL_RenderCopy(renderer, tile, &wallGround, &destination);

                    if (j != 0)
                        if (board[i][j - 1] != '#') {
                            asWallLeft = SDL_TRUE;
                            SDL_RenderCopy(renderer, tile, &westWall, &destination);
                        }
                    if (j != 29)
                        if (board[i][j + 1] != '#') {
                            asWallRight = SDL_TRUE;
                            SDL_RenderCopy(renderer, tile, &eastWall, &destination);
                        }
                    if (i != 0)
                        if (board[i - 1][j] != '#') {
                            asWallUp = SDL_TRUE;
                            SDL_RenderCopy(renderer, tile, &northWall, &destination);
                        }
                    if (i != 29) {
                        if (board[i + 1][j] != '#') {
                            asWallDown = SDL_TRUE;
                            SDL_RenderCopy(renderer, tile, &southWall, &destination);
                        };
                    }
                    if (asWallUp && asWallRight && !asWallDown && !asWallLeft) {
                        SDL_RenderCopyEx(renderer, tile, &externCorner, &destination, east, NULL, SDL_FLIP_NONE);
                    }
                    if (asWallUp && asWallLeft && (!asWallDown) && !asWallRight) {
                        SDL_RenderCopyEx(renderer, tile, &externCorner, &destination, north, NULL, SDL_FLIP_NONE);

                    }
                    break;

                case '?':
                    if (i == 0)
                        SDL_RenderCopyEx(renderer, tile, &ladder, &destination, south, NULL, SDL_FLIP_NONE);
                    else if (j == 0)
                        SDL_RenderCopyEx(renderer, tile, &ladder, &destination, east, NULL, SDL_FLIP_NONE);
                    else if (j == 29)
                        SDL_RenderCopyEx(renderer, tile, &ladder, &destination, west, NULL, SDL_FLIP_NONE);
                    else if (i == 29)
                        SDL_RenderCopyEx(renderer, tile, &ladder, &destination, north, NULL, SDL_FLIP_NONE);


                    break;
                default:
                    break;
            }
        }
    }
    SDL_RenderPresent(renderer);
}

/**
 * launch game loop
 * @param renderer => renderer of the game
 * @param tile => tile of the game assets
 * @param characterTexture => tile of the characters
 * @param window => game windows for resizing (SDL_SetWindowSize(window, h, w);)
 */
void play(SDL_Renderer *renderer, SDL_Texture *tile, SDL_Texture *characterTexture, SDL_Window *window) {
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
        displayBoard(levelChain->current->board, renderer, tile, characterTexture);
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            return;
        else if (event.type == SDL_KEYDOWN)
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_P:
                case SDL_SCANCODE_ESCAPE:
                    if (pauseMenu('p', levelChain, board->character) == 1) {
                        quit = true;
                    }
                    break;
            case SDL_SCANCODE_M:
                // TODO : ajouter me menu pour afficher les monstres et leur stats
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
//            loadImage(renderer, "assets/Images/deathScreen");


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
