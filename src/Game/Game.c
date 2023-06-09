#include <stdbool.h>
#include <stdio.h>
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
    levelChain = getLevelMonsters("./src/Levels/niveau1.level", board, levelChain);
    levelChain = getOtherLevels("./src/Levels/niveau1.level", board, levelChain);

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
                case SDL_SCANCODE_UNKNOWN:
                    break;
                case SDL_SCANCODE_A:
                    break;
                case SDL_SCANCODE_B:
                    break;
                case SDL_SCANCODE_C:
                    break;
                case SDL_SCANCODE_E:
                    break;
                case SDL_SCANCODE_F:
                    break;
                case SDL_SCANCODE_G:
                    break;
                case SDL_SCANCODE_H:
                    break;
                case SDL_SCANCODE_I:
                    break;
                case SDL_SCANCODE_J:
                    break;
                case SDL_SCANCODE_K:
                    break;
                case SDL_SCANCODE_L:
                    break;
                case SDL_SCANCODE_M:
                    break;
                case SDL_SCANCODE_N:
                    break;
                case SDL_SCANCODE_O:
                    break;
                case SDL_SCANCODE_R:
                    break;
                case SDL_SCANCODE_T:
                    break;
                case SDL_SCANCODE_U:
                    break;
                case SDL_SCANCODE_V:
                    break;
                case SDL_SCANCODE_W:
                    break;
                case SDL_SCANCODE_X:
                    break;
                case SDL_SCANCODE_Y:
                    break;
                case SDL_SCANCODE_1:
                    break;
                case SDL_SCANCODE_2:
                    break;
                case SDL_SCANCODE_3:
                    break;
                case SDL_SCANCODE_4:
                    break;
                case SDL_SCANCODE_5:
                    break;
                case SDL_SCANCODE_6:
                    break;
                case SDL_SCANCODE_7:
                    break;
                case SDL_SCANCODE_8:
                    break;
                case SDL_SCANCODE_9:
                    break;
                case SDL_SCANCODE_0:
                    break;
                case SDL_SCANCODE_RETURN:
                    break;
                case SDL_SCANCODE_BACKSPACE:
                    break;
                case SDL_SCANCODE_TAB:
                    break;
                case SDL_SCANCODE_SPACE:
                    break;
                case SDL_SCANCODE_MINUS:
                    break;
                case SDL_SCANCODE_EQUALS:
                    break;
                case SDL_SCANCODE_LEFTBRACKET:
                    break;
                case SDL_SCANCODE_RIGHTBRACKET:
                    break;
                case SDL_SCANCODE_BACKSLASH:
                    break;
                case SDL_SCANCODE_NONUSHASH:
                    break;
                case SDL_SCANCODE_SEMICOLON:
                    break;
                case SDL_SCANCODE_APOSTROPHE:
                    break;
                case SDL_SCANCODE_GRAVE:
                    break;
                case SDL_SCANCODE_COMMA:
                    break;
                case SDL_SCANCODE_PERIOD:
                    break;
                case SDL_SCANCODE_SLASH:
                    break;
                case SDL_SCANCODE_CAPSLOCK:
                    break;
                case SDL_SCANCODE_F1:
                    break;
                case SDL_SCANCODE_F2:
                    break;
                case SDL_SCANCODE_F3:
                    break;
                case SDL_SCANCODE_F4:
                    break;
                case SDL_SCANCODE_F5:
                    break;
                case SDL_SCANCODE_F6:
                    break;
                case SDL_SCANCODE_F7:
                    break;
                case SDL_SCANCODE_F8:
                    break;
                case SDL_SCANCODE_F9:
                    break;
                case SDL_SCANCODE_F10:
                    break;
                case SDL_SCANCODE_F11:
                    break;
                case SDL_SCANCODE_F12:
                    break;
                case SDL_SCANCODE_PRINTSCREEN:
                    break;
                case SDL_SCANCODE_SCROLLLOCK:
                    break;
                case SDL_SCANCODE_PAUSE:
                    break;
                case SDL_SCANCODE_INSERT:
                    break;
                case SDL_SCANCODE_HOME:
                    break;
                case SDL_SCANCODE_PAGEUP:
                    break;
                case SDL_SCANCODE_DELETE:
                    break;
                case SDL_SCANCODE_END:
                    break;
                case SDL_SCANCODE_PAGEDOWN:
                    break;
                case SDL_SCANCODE_NUMLOCKCLEAR:
                    break;
                case SDL_SCANCODE_KP_DIVIDE:
                    break;
                case SDL_SCANCODE_KP_MULTIPLY:
                    break;
                case SDL_SCANCODE_KP_MINUS:
                    break;
                case SDL_SCANCODE_KP_PLUS:
                    break;
                case SDL_SCANCODE_KP_ENTER:
                    break;
                case SDL_SCANCODE_KP_1:
                    break;
                case SDL_SCANCODE_KP_2:
                    break;
                case SDL_SCANCODE_KP_3:
                    break;
                case SDL_SCANCODE_KP_4:
                    break;
                case SDL_SCANCODE_KP_5:
                    break;
                case SDL_SCANCODE_KP_6:
                    break;
                case SDL_SCANCODE_KP_7:
                    break;
                case SDL_SCANCODE_KP_8:
                    break;
                case SDL_SCANCODE_KP_9:
                    break;
                case SDL_SCANCODE_KP_0:
                    break;
                case SDL_SCANCODE_KP_PERIOD:
                    break;
                case SDL_SCANCODE_NONUSBACKSLASH:
                    break;
                case SDL_SCANCODE_APPLICATION:
                    break;
                case SDL_SCANCODE_POWER:
                    break;
                case SDL_SCANCODE_KP_EQUALS:
                    break;
                case SDL_SCANCODE_F13:
                    break;
                case SDL_SCANCODE_F14:
                    break;
                case SDL_SCANCODE_F15:
                    break;
                case SDL_SCANCODE_F16:
                    break;
                case SDL_SCANCODE_F17:
                    break;
                case SDL_SCANCODE_F18:
                    break;
                case SDL_SCANCODE_F19:
                    break;
                case SDL_SCANCODE_F20:
                    break;
                case SDL_SCANCODE_F21:
                    break;
                case SDL_SCANCODE_F22:
                    break;
                case SDL_SCANCODE_F23:
                    break;
                case SDL_SCANCODE_F24:
                    break;
                case SDL_SCANCODE_EXECUTE:
                    break;
                case SDL_SCANCODE_HELP:
                    break;
                case SDL_SCANCODE_MENU:
                    break;
                case SDL_SCANCODE_SELECT:
                    break;
                case SDL_SCANCODE_STOP:
                    break;
                case SDL_SCANCODE_AGAIN:
                    break;
                case SDL_SCANCODE_UNDO:
                    break;
                case SDL_SCANCODE_CUT:
                    break;
                case SDL_SCANCODE_COPY:
                    break;
                case SDL_SCANCODE_PASTE:
                    break;
                case SDL_SCANCODE_FIND:
                    break;
                case SDL_SCANCODE_MUTE:
                    break;
                case SDL_SCANCODE_VOLUMEUP:
                    break;
                case SDL_SCANCODE_VOLUMEDOWN:
                    break;
                case SDL_SCANCODE_KP_COMMA:
                    break;
                case SDL_SCANCODE_KP_EQUALSAS400:
                    break;
                case SDL_SCANCODE_INTERNATIONAL1:
                    break;
                case SDL_SCANCODE_INTERNATIONAL2:
                    break;
                case SDL_SCANCODE_INTERNATIONAL3:
                    break;
                case SDL_SCANCODE_INTERNATIONAL4:
                    break;
                case SDL_SCANCODE_INTERNATIONAL5:
                    break;
                case SDL_SCANCODE_INTERNATIONAL6:
                    break;
                case SDL_SCANCODE_INTERNATIONAL7:
                    break;
                case SDL_SCANCODE_INTERNATIONAL8:
                    break;
                case SDL_SCANCODE_INTERNATIONAL9:
                    break;
                case SDL_SCANCODE_LANG1:
                    break;
                case SDL_SCANCODE_LANG2:
                    break;
                case SDL_SCANCODE_LANG3:
                    break;
                case SDL_SCANCODE_LANG4:
                    break;
                case SDL_SCANCODE_LANG5:
                    break;
                case SDL_SCANCODE_LANG6:
                    break;
                case SDL_SCANCODE_LANG7:
                    break;
                case SDL_SCANCODE_LANG8:
                    break;
                case SDL_SCANCODE_LANG9:
                    break;
                case SDL_SCANCODE_ALTERASE:
                    break;
                case SDL_SCANCODE_SYSREQ:
                    break;
                case SDL_SCANCODE_CANCEL:
                    break;
                case SDL_SCANCODE_CLEAR:
                    break;
                case SDL_SCANCODE_PRIOR:
                    break;
                case SDL_SCANCODE_RETURN2:
                    break;
                case SDL_SCANCODE_SEPARATOR:
                    break;
                case SDL_SCANCODE_OUT:
                    break;
                case SDL_SCANCODE_OPER:
                    break;
                case SDL_SCANCODE_CLEARAGAIN:
                    break;
                case SDL_SCANCODE_CRSEL:
                    break;
                case SDL_SCANCODE_EXSEL:
                    break;
                case SDL_SCANCODE_KP_00:
                    break;
                case SDL_SCANCODE_KP_000:
                    break;
                case SDL_SCANCODE_THOUSANDSSEPARATOR:
                    break;
                case SDL_SCANCODE_DECIMALSEPARATOR:
                    break;
                case SDL_SCANCODE_CURRENCYUNIT:
                    break;
                case SDL_SCANCODE_CURRENCYSUBUNIT:
                    break;
                case SDL_SCANCODE_KP_LEFTPAREN:
                    break;
                case SDL_SCANCODE_KP_RIGHTPAREN:
                    break;
                case SDL_SCANCODE_KP_LEFTBRACE:
                    break;
                case SDL_SCANCODE_KP_RIGHTBRACE:
                    break;
                case SDL_SCANCODE_KP_TAB:
                    break;
                case SDL_SCANCODE_KP_BACKSPACE:
                    break;
                case SDL_SCANCODE_KP_A:
                    break;
                case SDL_SCANCODE_KP_B:
                    break;
                case SDL_SCANCODE_KP_C:
                    break;
                case SDL_SCANCODE_KP_D:
                    break;
                case SDL_SCANCODE_KP_E:
                    break;
                case SDL_SCANCODE_KP_F:
                    break;
                case SDL_SCANCODE_KP_XOR:
                    break;
                case SDL_SCANCODE_KP_POWER:
                    break;
                case SDL_SCANCODE_KP_PERCENT:
                    break;
                case SDL_SCANCODE_KP_LESS:
                    break;
                case SDL_SCANCODE_KP_GREATER:
                    break;
                case SDL_SCANCODE_KP_AMPERSAND:
                    break;
                case SDL_SCANCODE_KP_DBLAMPERSAND:
                    break;
                case SDL_SCANCODE_KP_VERTICALBAR:
                    break;
                case SDL_SCANCODE_KP_DBLVERTICALBAR:
                    break;
                case SDL_SCANCODE_KP_COLON:
                    break;
                case SDL_SCANCODE_KP_HASH:
                    break;
                case SDL_SCANCODE_KP_SPACE:
                    break;
                case SDL_SCANCODE_KP_AT:
                    break;
                case SDL_SCANCODE_KP_EXCLAM:
                    break;
                case SDL_SCANCODE_KP_MEMSTORE:
                    break;
                case SDL_SCANCODE_KP_MEMRECALL:
                    break;
                case SDL_SCANCODE_KP_MEMCLEAR:
                    break;
                case SDL_SCANCODE_KP_MEMADD:
                    break;
                case SDL_SCANCODE_KP_MEMSUBTRACT:
                    break;
                case SDL_SCANCODE_KP_MEMMULTIPLY:
                    break;
                case SDL_SCANCODE_KP_MEMDIVIDE:
                    break;
                case SDL_SCANCODE_KP_PLUSMINUS:
                    break;
                case SDL_SCANCODE_KP_CLEAR:
                    break;
                case SDL_SCANCODE_KP_CLEARENTRY:
                    break;
                case SDL_SCANCODE_KP_BINARY:
                    break;
                case SDL_SCANCODE_KP_OCTAL:
                    break;
                case SDL_SCANCODE_KP_DECIMAL:
                    break;
                case SDL_SCANCODE_KP_HEXADECIMAL:
                    break;
                case SDL_SCANCODE_LCTRL:
                    break;
                case SDL_SCANCODE_LSHIFT:
                    break;
                case SDL_SCANCODE_LALT:
                    break;
                case SDL_SCANCODE_LGUI:
                    break;
                case SDL_SCANCODE_RCTRL:
                    break;
                case SDL_SCANCODE_RSHIFT:
                    break;
                case SDL_SCANCODE_RALT:
                    break;
                case SDL_SCANCODE_RGUI:
                    break;
                case SDL_SCANCODE_MODE:
                    break;
                case SDL_SCANCODE_AUDIONEXT:
                    break;
                case SDL_SCANCODE_AUDIOPREV:
                    break;
                case SDL_SCANCODE_AUDIOSTOP:
                    break;
                case SDL_SCANCODE_AUDIOPLAY:
                    break;
                case SDL_SCANCODE_AUDIOMUTE:
                    break;
                case SDL_SCANCODE_MEDIASELECT:
                    break;
                case SDL_SCANCODE_WWW:
                    break;
                case SDL_SCANCODE_MAIL:
                    break;
                case SDL_SCANCODE_CALCULATOR:
                    break;
                case SDL_SCANCODE_COMPUTER:
                    break;
                case SDL_SCANCODE_AC_SEARCH:
                    break;
                case SDL_SCANCODE_AC_HOME:
                    break;
                case SDL_SCANCODE_AC_BACK:
                    break;
                case SDL_SCANCODE_AC_FORWARD:
                    break;
                case SDL_SCANCODE_AC_STOP:
                    break;
                case SDL_SCANCODE_AC_REFRESH:
                    break;
                case SDL_SCANCODE_AC_BOOKMARKS:
                    break;
                case SDL_SCANCODE_BRIGHTNESSDOWN:
                    break;
                case SDL_SCANCODE_BRIGHTNESSUP:
                    break;
                case SDL_SCANCODE_DISPLAYSWITCH:
                    break;
                case SDL_SCANCODE_KBDILLUMTOGGLE:
                    break;
                case SDL_SCANCODE_KBDILLUMDOWN:
                    break;
                case SDL_SCANCODE_KBDILLUMUP:
                    break;
                case SDL_SCANCODE_EJECT:
                    break;
                case SDL_SCANCODE_SLEEP:
                    break;
                case SDL_SCANCODE_APP1:
                    break;
                case SDL_SCANCODE_APP2:
                    break;
                case SDL_SCANCODE_AUDIOREWIND:
                    break;
                case SDL_SCANCODE_AUDIOFASTFORWARD:
                    break;
                case SDL_SCANCODE_SOFTLEFT:
                    break;
                case SDL_SCANCODE_SOFTRIGHT:
                    break;
                case SDL_SCANCODE_CALL:
                    break;
                case SDL_SCANCODE_ENDCALL:
                    break;
                case SDL_NUM_SCANCODES:
                    break;
            }
        if (getLifePoint(character) <= 0) {
            loadImage(renderer,"assets/Images/deathScreen");


//            quit = SDL_TRUE;
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
