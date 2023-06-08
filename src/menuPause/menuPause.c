#include <stdio.h>
#include <stdbool.h>
#include "../../include/src/menuPause.h"


void printContinue() {
    printf(
            "\n"
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
            "##############################\n"
    );
}

void printSave() {
    printf(
            "\n"
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

void printLoadGame() {
    printf(
            "\n"
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

void printQuitPause() {
    printf(
            "\n"
            "##############################\n"
            "#         Pause Menu         #\n"
            "#                            #\n"
            "#          Continue          #\n"
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

int setCompteur(int Compt) {
    return Compt += 1;
}

int setZeroCompt(int Compt) {
    return 0;
}

int setChoicesPlus(int choice) {
    return choice += 1;
}

int setChoicesMinus(int choice) {
    return choice -= 1;
}

int pauseMenuChange(int choice) {
    if (choice == 1) {
        printContinue();
    } else if (choice == 2) {
        printSave();
    } else if (choice == 3) {
        printLoadGame();
    } else if (choice == 4) {
        printQuitPause();
    }
    return choice;
}
int checkChoices(int choice){
    if(choice == 1){
        return 0;
    }
    else if (choice == 2){
        //savefonction
        printf("game saved");
        return 2;
    } else if (choice == 3){
        //loadGameFonction
        printf("load game");
        return 3;
    }else if (choice == 4){
        return 1;
    }
    return 0;
}
bool checkPauseCode(int pauseCode){
    if(pauseCode == 0 || pauseCode == 1){
        return true;
    }else
    {
        return false;
    }
}
int pauseMenu(char keyEnter, Character *character) {
    int compt = 1;
    int pauseCode;
    bool choiceDone = false;
    printContinue();
    while (!choiceDone) {
        keyEnter = catchInput();
        if (keyEnter == 'z' && compt != 1) {
            compt = setChoicesMinus(compt); 
        } else if (keyEnter == 's') {
            compt = setChoicesPlus(compt);
            
        }else if (keyEnter =='e')
        {
            pauseCode = checkChoices(compt);
        }
        if (compt == 9) {
            cheatMenu(' ', character);
            compt = 1;
        }
        pauseMenuChange(compt);
        choiceDone = checkPauseCode(pauseCode);
    }
    printAll(character);
    return pauseCode;
}