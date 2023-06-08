//
// Created by benfa on 24/05/2023.
//

#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"
#include "../../include/src/Game.h"
#include "../../include/src/menu.h"
#include "../../include/src/Keyboard.h"
#include "../../include/src/Move.h"
#include "../../include/src/Levels.h"
#include "../../include/src/Board.h"
#include "../../include/src/FightSystem.h"


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
                play();
            }
        }
    } while (!isChoiced);
    return 0;
}

void displayBoard(char **board) {
    for (int i = 0; i < 30; i++) {
        printf("%s\n", board[i]);
    }
}


void play() {
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
    levelChain *levelChain = NULL;
    board->character = character;
    printAll(character);
    //We get/set every element we have on the file
    levelChain = getLevelBoard("./src/Levels/niveau1.level", levelChain);
    levelChain = getLevelMonsters("./src/Levels/niveau1.level", board, levelChain);
    levelChain = getOtherLevels("./src/Levels/niveau1.level", board, levelChain);

    //We put the character at is right position
    levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
    printf("character is set\n");
    // boucle de jeu
    while (inGame) {
        if(levelChain->current->character == NULL) {
            levelChain->current->character = character;
        }
        displayBoard(levelChain->current->board);
        char input = catchInput();
        if (input == 'p') {
            if (pauseMenu() == 1) {
                inGame = false;
            }
        } else if (input == 'z' || input == 'q' || input == 's' || input == 'd') {
            levelChain = move(character, input, levelChain->current, levelChain);
        } else if (input == 'm') {
            printf("Here are all monsters\n");
            for(int i =0; i<levelChain->current->nbMonsters; i++) {
                printMonsterStats(levelChain->current->monstersTab[i]);
                printf("\n");
            }
        } else {
            printf("Stop doing this shit !\n");
        }
    }
    if (getLifePoint(character) <= 0) {
        inGame = false;
        printf("You are dead !\n");
    }
    if (board->aliveMonsters == 0) {
        printf("Congratulation You finished the level !!!!\n");
    }
}
