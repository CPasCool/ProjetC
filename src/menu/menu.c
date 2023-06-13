#include <stdio.h>
#include <stdlib.h>
#include "../../include/src/menu.h"

struct choice {
    int choice;
};

void setChoice(choiceMenu *choiceMenu, int choice) {
    choiceMenu->choice = choice;
    displayMenu(choiceMenu);
}


int getChoice(choiceMenu *choiceMenu) {
    return choiceMenu->choice;
}

choiceMenu *createChoiceMenu() {
    choiceMenu *choiceMenuTmp = malloc(sizeof(choiceMenu));
    choiceMenuTmp->choice = 1;
    return choiceMenuTmp;
}

//affichage du menu avant de lancer la partie
void displayNewGame() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  # 1 -   New Game       #  #\n"
            "#  ########################  #\n"
            "#   2 -    Load a save       #\n"
            "#   3 -    Quit              #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Good luck :)        #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void displaySave() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   New Game          #\n"
            "#  ########################  #\n"
            "#  # 2 -   Load a save    #  #\n"
            "#  ########################  #\n"
            "#   3 -    Quit              #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Good luck :)        #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void displayChoiceGameQuit() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   New Game          #\n"
            "#    2 -   Load a save       #\n"
            "#  ########################  #\n"
            "#  # 3 -    Quit          #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Good luck :)        #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}


void displayPlayMenu() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  # 1 -   Play           #  #\n"
            "#  ########################  #\n"
            "#   2 -    Credits           #\n"
            "#   3 -    Quit              #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void displayCreditMenu() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   Play              #\n"
            "#  ########################  #\n"
            "#  # 2 -   Credits       #  #\n"
            "#  ########################  #\n"
            "#   3 -    Quit              #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void displayExitMenu() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   Play              #\n"
            "#    2 -   Credits           #\n"
            "#  ########################  #\n"
            "#  # 3 -   Quit           #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void displayCredit() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#      Game developed by     #\n"
            "#      Korentin Kolaczek     #\n"
            "#       Benoit Fardoux       #\n"
            "#        Edouard Hoest       #\n"
            "#      Baptiste Lemattre     #\n"
            "#                            #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  #  1 - Back to menu    #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n");
}

void displayMenu(choiceMenu *choice) {
    if (getChoice(choice) == 1) {
        displayPlayMenu();
    } else if (getChoice(choice) == 2) {
        displayCreditMenu();
    } else {
        displayExitMenu();
    }
}

void displayMenuNewGame(int choice) {
    if (choice == 1) {
        displayNewGame();
    } else if (choice == 2) {
        displaySave();
    } else {
        displayChoiceGameQuit();
    }
}
