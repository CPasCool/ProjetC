#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"

struct choixMenu_
{
    int choix;
};

void setChoixMenu(choixMenu* choixMenu, int choix){
    choixMenu -> choix = choix;
}

choixMenu* getChoixMenu (choixMenu* choixMenu){
    return choixMenu;
}
int getChoix(choixMenu* choixMenu){
    return choixMenu -> choix;
}
choixMenu* createChoixMenu(){
    choixMenu* choixMenuTemp = malloc(sizeof(choixMenu));
    choixMenuTemp -> choix = 1;
    return choixMenuTemp;
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
            "#   2 -    Load a save       #\n"
            "#   3 -    Leave             #\n"
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
            "#  # 2 -   Load a save    #  #\n"
            "#  ########################  #\n"
            "#   3 -    Leave             #\n"
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
            "#    2 -   Load a save       #\n"
            "#  ########################  #\n"
            "#  # 3 -    Leave         #  #\n"
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

void afficheCredit(){
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
void afficheMenuLancer(){
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

void afficheMenuCredit(){
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
void afficheMenuQuit(){
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
void afficheMenu(int choix){    
    if (choix == 1)
    {
        afficheMenuLancer();
    }else if (choix == 2)
    {
        afficheMenuCredit();
    } else {
        afficheMenuQuit();
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

void menu(){
    choixMenu* choixMenu = createChoixMenu();
    bool choixFait = false;
    afficheMenu(getChoix(choixMenu));
    int choix;
    while (choixFait == false)
    {
        printf("entrer votre choix");
        scanf("%d",&choix);
        
        setChoixMenu(choixMenu,choix);
        afficheMenu(getChoix(choixMenu));
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
        afficheMenu(getChoix(choiceNewgame));
    }
}