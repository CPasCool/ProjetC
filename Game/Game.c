//
// Created by benfa on 24/05/2023.
//

#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"
#include "Game.h"
#include "../menu/menu.h"
#include "../Keyboard/Keyboard.h"
#include "../MoveCharacter/Move.h"
#include "../Board/Levels.h"
#include "../Board/Board.h"


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
        char result = 'e';//catchInput();
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
           "P -> pause game");
    // condition de sortie du jeu
    bool inGame = true;
    Character *character = createCharacter("player");

    boardElements *board = malloc(sizeof(struct BoardElements));
    board->character = character;
    //We get/set every element we have on the file
    getLevelBoard("../Levels/niveau1.level", board);
    getLevelMonsters("../Levels/niveau1.level", board);
    getOtherLevels("../Levels/niveau1.level", board);

    //We put the character at is right position
    board->board[getCharaY(character)][getCharaY(character)] = 'T';
    int cpt = 0;
    // boucle de jeu
    while (inGame) {
        displayBoard(board->board);
        char input = catchInput();
        printf("%c", input);
        if (input == 'p') {
            if (pauseMenu() == 1) {
                inGame = false;
            };
        } else {
                move(character, input, board->board, board->monstersTab, board->nbMonsters);
        }
        if(getLifePoint(character) == 0) {
            inGame = false;
        }
        cpt++;
        printf("%d", cpt);
    }
}