#include <stdio.h>
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
            "#    ####################    #\n"
            "#    #      Quit        #    #\n"
            "#    ####################    #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
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
        printQuitPause();
    }
    return choice;
}

int checkChoices(int choice, levelChain *levelChain) {
    if (choice == 1) {
        return 0;
    } else if (choice == 2) {
        //savefonction
        createSave(levelChain);
        return 2;
    } else if (choice == 3) {
        return 1;
    }
    return -1;
}

bool checkPauseCode(int pauseCode) {
    if (pauseCode == 0 || pauseCode == 1) {
        return true;
    } else {
        return false;
    }
}

int pauseMenu(char keyEnter, levelChain *levelChain, Character *character) {
    int compt = 1;
    int pauseCode = -1;
    bool choiceDone = false;
    printContinue();
    while (!choiceDone) {
        keyEnter = catchInput();
        if (keyEnter == 'z' && compt != 1) {
            compt = setChoicesMinus(compt);
        } else if (keyEnter == 's') {
            compt = setChoicesPlus(compt);

        } else if (keyEnter == 'e') {
            pauseCode = checkChoices(compt, levelChain);
        }
        if (compt == 9) {
            cheatMenu(character);
            compt = 1;
        }
        pauseMenuChange(compt);
        choiceDone = checkPauseCode(pauseCode);
    }
    printAll(character);
    return pauseCode;
}