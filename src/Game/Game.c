#include <stdbool.h>
#include "stdio.h"
#include "../../include/src/Game.h"


const int MAXIMUM_CHOICE_MENU = 5;
const int MINIMUM_CHOICE_MENU = 1;

/**
 * Beginning menu, the player chose what to do
 * @return
 */
int LaunchGame() {
    introduction();
    printf("Use\nZ to move up\n"
           "S to move down\n and"
           "E to validate your choice\n");

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
                int gameChoice = useNewGameMenu();
                if(gameChoice == 1){
                    play(NULL);
                }else{
                    play(getCompliteSave(NULL));
                }
            } else {
                if (choice == 2) {
                    displayCredit();
                }
            }
        }
    } while (!isChoiced);
    return 0;
}

/**
 * Print the Board
 */
void displayBoard(char **board) {
    for (int i = 0; i < 30; i++) {
        printf("%s\n", board[i]);
    }
}

/**
 * The main loop
 */
void play(levelChain *levelChain) {
    // affiche les touches
    printf("Z -> move up\n"
           "S -> move down\n"
           "Q -> move left\n"
           "D -> move right\n"
           "P -> pause game\n");
    // condition de sortie du jeu
    bool inGame = true;
    Character *character = createCharacter("player");

    boardElements *board = createBoardElement();
    board->character = character;
    //We get/set every element of the level 1
    if(levelChain == NULL){
        levelChain = getLevelBoard("./src/Levels/niveau1.level", levelChain);
    }

    //We put the character at is right position
    levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
    printf("character is set\n");
    // main loop
    while (inGame) {
        levelChain->current->character = character;
        displayBoard(levelChain->current->board);
        char input = catchInput();
        if (input == 'p') {
            int result = pauseMenu(input, levelChain, board->character);
            if (result == 1) {
                inGame = false;
            }
        } else if (input == 'z' || input == 'q' || input == 's' || input == 'd') {
            levelChain = move(character, input, levelChain->current, levelChain);
        } else if (input == 'm') {
            printf("Here are all monsters\n");
            for (int i = 0; i < levelChain->current->nbMonsters; i++) {
                printMonsterStats(levelChain->current->monstersTab[i]);
                printf("\n");
            }
        } else {
            printf("Stop doing this shit !\n");
        }
        if (getLifePoint(character) <= 0) {
            inGame = false;
            printf("You are dead !\n");
        }
        if (board->aliveMonsters == 0) {
            printf("Congratulation You finished the level !!!!\n");
        }
    }
}