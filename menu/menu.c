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

int pauseMenu(){
    //TODO return 1 si le joueur quitte la partie;
    return 0;
}



int getChoice(choiceMenu *choixMenu) {
    return choixMenu->choice;
}

choiceMenu *createChoiceMenu() {
    choiceMenu *choiceMenuTmp = malloc(sizeof(choiceMenu));
    choiceMenuTmp->choice = 1;
    return choiceMenuTmp;
}
//affichage du menu avant de lancer la partie
void displayNewGame()
{
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
            "#  # 1 -   New Game       #  #\n"
            "#  ########################  #\n"
            "#   2 -    Load Game         #\n"
            "#   3 -    Quit              #\n"
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
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}

void displaySave()
{
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
            "#    1 -   New Game          #\n"
            "#  ########################  #\n"
            "#  # 2 -   Load Game      #  #\n"
            "#  ########################  #\n"
            "#   3 -    Quit              #\n"
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
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}
void displayQuitNewGame(){
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
            "#    1 -   New Game          #\n"
            "#    2 -   Load Game         #\n"
            "#  ########################  #\n"
            "#  # 3 -    Quit          #  #\n"
            "#  ########################  #\n"
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
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}
void displayPlayIngame()
{
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  # 1 -   Play           #  #\n"
            "#  ########################  #\n"
            "#   2 -    Save              #\n"
            "#   3 -    Leave             #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}

void displayLeaveIngame()
{
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#   1 -    Play              #\n"
            "#   2 -    Save              #\n"
            "#  ########################  #\n"
            "#  # 3 -   Leave          #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}
void displaySaveIngame()
{
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#  # 1 -   Play           #  #\n"
            "#  ########################  #\n"
            "#  # 2 -   Save           #  #\n"
            "#  ########################  #\n"
            "#   3 -    Leave             #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}
void displayCredit(){

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

void displayMenuNewGame(int choice){
    if (choice == 1)
    {
        displayNewGame();
    }else if (choice == 2)
    {
        displaySave();
    } else {
        displayQuitNewGame();
    }
}

void displayMenuIngame(int choice)
{
    if (choice == 1)
    {
        displayPlayIngame();
    }else if (choice == 2)
    {
        displaySaveIngame();
    } else {
        displayLeaveIngame();
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

void newGame(){
    choixMenu* choiceNewgame = createChoixMenu();
    bool choiceDo = false;
    displayMenuNewGame(getChoix(choiceNewgame));
    int choice;
    while (choiceDo == false)
    {
        printf("entrer votre choix");
        scanf("%d",&choice);
        setChoixMenu(choiceNewgame,choice);
        displayMenuNewGame(getChoix(choiceNewgame));
    }
}

void inGame()
{
    choixMenu* choiceIngame = createChoixMenu();
    bool choiceDo = false;
    displayMenuIngame((getChoix(choiceIngame)));
    int choice;
    while (choiceDo == false)
    {
        printf("entrer votre choix");
        scanf("%d",&choice);
        setChoixMenu(choiceIngame,choice);
        displayMenuIngame(getChoix(choiceIngame));
    }

}