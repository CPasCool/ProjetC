#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"

struct choice {
    int choice;
};

void setChoice(choiceMenu *choiceMenu, int choice) {
    choiceMenu->choice = choice;
    displayMenu(choiceMenu);
}


int getChoice(choiceMenu *choixMenu) {
    return choixMenu->choice;
}

choiceMenu *createChoiceMenu() {
    choiceMenu *choiceMenuTmp = malloc(sizeof(choiceMenu));
    choiceMenuTmp->choice = 1;
    return choiceMenuTmp;
}

void displayCredit() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#       Jeu réalisé par      #\n"
            "#      Korentin Kolaczek     #\n"
            "#       Benoit Fardoux       #\n"
            "#        Edouard Hoest       #\n"
            "#      Baptiste Lemattre     #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#     1 - retour au menu     #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################");
}

void displayPlayMenu() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  # 1 -   lauch a game   #  #\n"
            "#  ########################  #\n"
            "#   2 -    credit            #\n"
            "#   3 -    quitter           #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Bon chance :)       #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
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
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   lancer le jeu     #\n"
            "#  ########################  #\n"
            "#  # 2 -    credit        #  #\n"
            "#  ########################  #\n"
            "#   3 -    quitter           #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Bon chance :)       #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
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
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   lancer le jeu     #\n"
            "#    2 -    credit           #\n"
            "#  ########################  #\n"
            "#  # 3 -    quitter       #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Bon chance :)       #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
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

void menu() {
    choiceMenu *choixMenu = createChoiceMenu();
    bool choixFait = false;
    displayMenu(choixMenu);

    int choix;


    while (choixFait == false) {
        printf("entrer votre choice");
        scanf("%d", &choix);

        setChoice(choixMenu, choix);
        displayMenu(choixMenu);
    }
}