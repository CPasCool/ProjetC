#include "../../include/src/Cheat.h"
#include "stdio.h"
#include <stdbool.h>

int cheatHealth(Character *character) {
    return setLifePoint(character, 999);
}

int setCheatMinus(int compt) {
    return compt - 1;
}

int setCheatPlus(int compt) {
    return compt + 1;
}

int cheatDefence(Character *character) {
    return setDefence(character, 999);
}

int cheatStrength(Character *character) {
    return setStrength(character, 999);
}

int cheatNoHealth (Character * character){
    return setLifePoint(character, 0);
}

int cheatKeys(Character *character){
    return setMaxKeys(character);
}

void printCheatKey(char keysActive,char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#  ######################### #\n"
            "#  #  %c  Max Keys          # #\n"
            "#  ######################### #\n"
            "#    %c  Cheat Max Health     #\n"
            "#    %c  Cheat Max Strength   #\n"
            "#    %c  Cheat Max Defense    #\n"
            "#    %c  Cheat No Health      #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", keysActive, healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatHealth(char keysActive,char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c  Max Keys             #\n"
            "#  ######################### #\n"
            "#  # %c  Cheat Max Health   # #\n"
            "#  ######################### #\n"
            "#    %c  Cheat Max Strength   #\n"
            "#    %c  Cheat Max Defense    #\n"
            "#    %c  Cheat No Health      #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", keysActive,healthActive, strengthActive, defenceActive, noHealthActive
    );
}

void printCheatwStrength(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c  Max Keys             #\n"
            "#    %c  Cheat Max Health     #\n"
            "#  ######################### #\n"
            "#  # %c  Cheat Max Strength # #\n"
            "#  ######################### #\n"
            "#    %c  Cheat Max Defense    #\n"
            "#    %c  Cheat No Health      #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", keysActive,healthActive, strengthActive, defenceActive, noHealthActive
    );
}

void printCheatDefence(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c  Max Keys             #\n"
            "#    %c  Cheat Max Health     #\n"
            "#    %c  Cheat Max Strength   #\n"
            "#  ######################### #\n"
            "#  # %c  Cheat Max Defense  # #\n"
            "#  ######################### #\n"
            "#    %c  Cheat No Health      #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", keysActive, healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatNoHealth(char keysActive,char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c  Max Keys             #\n"
            "#    %c  Cheat Max Health     #\n"
            "#    %c  Cheat Max Strength   #\n"
            "#    %c  Cheat Max Defense    #\n"
            "#  ######################### #\n"
            "#  # %c  Cheat No Health    # #\n"
            "#  ######################### #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", keysActive,healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatFinish(char keysActive,char healthActive, char strengthActive, char defenceActive,char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c  Max Keys             #\n"
            "#    %c  Cheat Max Health     #\n"
            "#    %c  Cheat Max Strength   #\n"
            "#    %c  Cheat Max Defense    #\n"
            "#    %c  Cheat No Health      #\n"
            "#  ########################  #\n"
            "#  #         Quit         #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "##############################\n", keysActive, healthActive, strengthActive, defenceActive, noHealthActive
    );
}

/**
 * cette fonction permet d'afficher le bon menu en fonction du choix
*/
void printMenuCheat(int choixCheat, char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    if (choixCheat == 1) {
        printCheatKey(keysActive,healthActive, strengthActive, defenceActive,noHealthActive);
    } 
    else if (choixCheat == 2) {
        printCheatHealth(keysActive,healthActive, strengthActive, defenceActive,noHealthActive);
    } 
    else if (choixCheat == 3) {
        printCheatwStrength(keysActive,healthActive, strengthActive, defenceActive,noHealthActive);
    } 
    else if (choixCheat == 4) {
        printCheatDefence(keysActive,healthActive, strengthActive, defenceActive,noHealthActive);
    }
    else if (choixCheat == 5) {
        printCheatNoHealth(keysActive,healthActive, strengthActive, defenceActive,noHealthActive);
    }  
    else if (choixCheat == 6) {
        printCheatFinish(keysActive,healthActive, strengthActive, defenceActive,noHealthActive);
    }
}
/**
 * cette fonction east la fonction principal d'interfaçage avec le clavier
*/
int cheatMenu(char input, Character *character) {
    bool choiceCheatDone = false;
    int menuCheatChoice = 1;
    char healthActive = 'x';
    char strengthActive = 'x';
    char defenceActive = 'x';
    char noHealthActive= 'x';
    char keyActive = 'x';
    printMenuCheat(menuCheatChoice, keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
    while (choiceCheatDone == false) {
        input = catchInput();
        if (input == 's' && menuCheatChoice != 6){
            menuCheatChoice += 1;
            printMenuCheat(menuCheatChoice,keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
        } else if (input == 'z' && menuCheatChoice !=1){
            menuCheatChoice -= 1;
            printMenuCheat(menuCheatChoice,keyActive, healthActive, strengthActive, defenceActive,noHealthActive);
        }
        else if (input == 'e' && menuCheatChoice == 1) {
            cheatKeys(character);
            keyActive = 'V';
            printMenuCheat(menuCheatChoice, keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
        }
        else if (input == 'e' && menuCheatChoice == 2) {
            cheatHealth(character);
            healthActive = 'V';
            printMenuCheat(menuCheatChoice, keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
        } else if (input == 'e' && menuCheatChoice == 3) {
            cheatStrength(character);
            strengthActive = 'V';
            printMenuCheat(menuCheatChoice,keyActive, healthActive, strengthActive, defenceActive,noHealthActive);
        } else if (input == 'e' && menuCheatChoice == 4) {
            cheatDefence(character);
            defenceActive = 'V';
            printMenuCheat(menuCheatChoice,keyActive, healthActive, strengthActive, defenceActive,noHealthActive);
        } else if (input == 'e' && menuCheatChoice == 5) {
            cheatNoHealth(character);
            noHealthActive = 'V';
            printMenuCheat(menuCheatChoice,keyActive, healthActive, strengthActive, defenceActive,noHealthActive);
        } else if (input == 'e' && menuCheatChoice == 6) {
            choiceCheatDone = true;
        }
    }
    return 0;
}