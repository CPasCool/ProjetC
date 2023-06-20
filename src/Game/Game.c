#include <stdbool.h>
#include <stdio.h>
#include "../../include/src/Game.h"
#include "../../include/src/TextureConst.h"


const int MAXIMUM_CHOICE_MENU = 5;
const int MINIMUM_CHOICE_MENU = 1;

/**
 * start the game
 * @param renderer -> renderer of the windows
 * @param tile -> texture of all the level
 * @param characterTexture -> texture of character
 * @param font  -> font for write things
 * @return if a error -1 if error
 */
int LaunchGame(SDL_Renderer *renderer, SDL_Texture *tile, SDL_Texture *characterTexture, TTF_Font *font, SDL_Texture *background) {
    introduction();

    choiceMenu *menu = createChoiceMenu();
    SDL_Rect destRect = {0,0,810,810};
    SDL_RenderCopy(renderer,background,NULL,&destRect);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    while (true) {
        SDL_WaitEvent(&event);
        int choice = getChoice(menu);

        displayMenu(menu, renderer, font);
        if (event.type == SDL_QUIT)
            return 0;
        else if (event.type == SDL_KEYDOWN) {

            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_Z:
                case SDL_SCANCODE_UP:
                    SDL_RenderCopy(renderer,background,NULL,&destRect);
                    SDL_RenderPresent(renderer);
                    if (choice != MINIMUM_CHOICE_MENU) {
                        setChoice(menu, choice - 1, renderer, font);
                    }
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    SDL_RenderCopy(renderer,background,NULL,&destRect);
                    SDL_RenderPresent(renderer);
                    if (choice != MAXIMUM_CHOICE_MENU) {
                        setChoice(menu, choice + 1, renderer, font);
                    }
                    break;
                case SDL_SCANCODE_E:
                case SDL_SCANCODE_RETURN:
                    if (choice == 1) {
                        SDL_RenderCopy(renderer,background,NULL,&destRect);
                        SDL_RenderPresent(renderer);
                        int gameChoice = useNewGameMenu(renderer, font,background);
                        if (gameChoice == 1) {
                          if(play(NULL, renderer, tile, characterTexture)){
                              return 0;
                          };
                        } else if (gameChoice == 2) {
                            play(getCompliteSave(NULL), renderer, tile, characterTexture);
                        } else if (gameChoice == -1)
                            return 0;
                        SDL_RenderCopy(renderer,background,NULL,&destRect);
                        SDL_RenderPresent(renderer);
                    } else {
                        if (choice == 2) {
                            SDL_RenderCopy(renderer,background,NULL,&destRect);
                            displayCredit(renderer,font);
                            SDL_RenderPresent(renderer);
                            if (inCredit())
                                return 1;
                            SDL_RenderCopy(renderer,background,NULL,&destRect);
                            SDL_RenderPresent(renderer);
                        } else if (choice == 3) {
                            return 1;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_RenderPresent(renderer);
    };
}

/**
 * display board and catch input for game
 * @param board : board to display
 * @param renderer :
 * @param tile
 * @param Character2
 */
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
                        }
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
int play(levelChain *levelChain, SDL_Renderer *renderer, SDL_Texture *tile, SDL_Texture *characterTexture) {
    // condition de sortie du jeu
    Character *character = createCharacter("player");
    boardElements *board = createBoardElement();
    board->character = character;
    //We get/set every element of the level 1
    if (levelChain == NULL) {
        levelChain = getLevelBoard("./src/Levels/niveau1.level", levelChain);
    }

    //We put the character at is right position
    levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
    printf("character is set\n");
    SDL_bool quit = SDL_FALSE;
    // boucle de jeu
    while (!quit) {
        levelChain->current->character = character;
        displayBoard(levelChain->current->board, renderer, tile, characterTexture);
        SDL_Event event;
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT)
            return 1;
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
    return 0;
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
