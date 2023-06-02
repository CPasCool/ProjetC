#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menuPause.h"
#include "..\Cheat\Cheat.h"

void printPauseMenu(){
    printf(
        "##############################\n"
        "#         Pause Menu         #\n"
        "#                            #\n"
        "#          Continue          #\n"
        "#          Save Game         #\n"
        "#          Load Game         #\n"
        "#                            #\n"
        "#           Quit             #\n"
        "#                            #\n"
        "#                            #\n"
        "#                            #\n"
        "##############################\n"
    );
}
void printCotinue(){
    printf(
        "##############################\n"
        "#         Pause Menu         #\n"
        "#                            #\n"
        "#    ####################    #\n"
        "#    #     Continue     #    #\n"
        "#    ####################    #\n"
        "#          Save Game         #\n"
        "#          Load Game         #\n"
        "#                            #\n"
        "#           Quit             #\n"
        "#                            #\n"
        "#                            #\n"
        "#                            #\n"
        "##############################\n"
    );
}

void printSave(){
    printf(
        "##############################\n"
        "#         Pause Menu         #\n"
        "#                            #\n"
        "#          Continue          #\n"
        "#    ####################    #\n"
        "#    #     Save Game    #    #\n"
        "#    ####################    #\n"
        "#          Load Game         #\n"
        "#           Quit             #\n"
        "#                            #\n"
        "#                            #\n"
        "##############################\n"
    );
}
void printLoadGame(){
    printf(
        "##############################\n"
        "#         Pause Menu         #\n"
        "#                            #\n"
        "#          Continue          #\n"
        "#          Save Game         #\n"
        "#    ####################    #\n"
        "#    #     Load Game    #    #\n"
        "#    ####################    #\n"
        "#           Quit             #\n"
        "#                            #\n"
        "#                            #\n"
        "##############################\n"
    );
}
void printQuitPause(){
    printf(
        "##############################\n"
        "#         Pause Menu         #\n"
        "#                            #\n"
        "#          Cotinue          #\n"
        "#          Save Game         #\n"
        "#          Load Game         #\n"
        "#    ####################    #\n"
        "#    #      Quit        #    #\n"
        "#    ####################    #\n"
        "#                            #\n"
        "#                            #\n"
        "##############################\n"
    );
}
int setCompteur(int Compt){
    return Compt+=1; 
}
int setZeroCompt(int Compt){
    return 0;
}
int setChoicesPlus (int choice){
    return choice+=1;
}
int setChoicesMinus (int choice){
    return choice-=1;
}
int mouvementPauseMenu(int choice){
    if (choice == 0)
    {
        printPauseMenu;
    } else if (choice == 1)
    {
        printCotinue;
    }else if(choice == 2){
        printSave;
    }else if (choice == 3)
    {
        printLoadGame;
    }else if (choice == 4)
    {
        printQuitPause;
    }
    return choice;    
}

void printCheat(int choice, int compteur){
    
}

void displayMenuPause(char keyEnter){
    int choice = 0;
    int compt = 0;
    bool choiceDone = false;
    printPauseMenu;
    while (!choiceDone)
    {
        choice = mouvementPauseMenu(choice);
        if (keyEnter == 'z' && choice != 0)
        {
            compt = setChoicesMinus(compt);
        } else if (keyEnter == 's' && choice != 4)
        {
            compt = setChoicesPlus(compt);
        }
        if (compt == 9)
        {
            cheatMenu(keyEnter);
        }
    }
    
}