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

void printCheat(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#    %c  Max Keys             #\n"
            "#    %c  Cheat Max Health     #\n"
            "#    %c  Cheat Max Strength   #\n"
            "#    %c  Cheat Max Defense    #\n"
            "#    %c  Cheat No Health      #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n", keysActive, healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatKey(char keyActive,char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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
            "##############################\n", keyActive, healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatHealth(char keyActive,char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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
            "##############################\n", keyActive,healthActive, strengthActive, defenceActive, noHealthActive
    );
}

void printCheatwStrength(char keyActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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
            "##############################\n", keyActive,healthActive, strengthActive, defenceActive, noHealthActive
    );
}

void printCheatDefence(char keyActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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
            "##############################\n", keyActive, healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatNoHealth(char keyActive,char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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
            "##############################\n", keyActive,healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatFinish(char keyActive,char healthActive, char strengthActive, char defenceActive,char noHealthActive) {
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
            "##############################\n", keyActive, healthActive, strengthActive, defenceActive, noHealthActive
    );
}

/**
 * cette fonction permet d'afficher le bon menu en fonction du choix
*/
void printMenuCheat(int choixCheat, char keyActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    if (choixCheat == 0) {
        printCheat(keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
    } else if (choixCheat == 1) {
        printCheatKey(keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
    } 
    else if (choixCheat == 2) {
        printCheatHealth(keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
    } 
    else if (choixCheat == 3) {
        printCheatwStrength(keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
    } 
    else if (choixCheat == 4) {
        printCheatDefence(keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
    }
    else if (choixCheat == 5) {
        printCheatNoHealth(keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
    }  
    else if (choixCheat == 6) {
        printCheatFinish(keyActive,healthActive, strengthActive, defenceActive,noHealthActive);
    }
}
/**
 * cette fonction est la fonction principal d'interfaçage avec le clavier
*/
int cheatMenu(char input, Character *character) {
    bool choiceCheatDone = false;
    int menuCheatChoice = 0;
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
        } else if (input == 'z' && menuCheatChoice !=0){
            menuCheatChoice -= 1;
            printMenuCheat(menuCheatChoice,keyActive, healthActive, strengthActive, defenceActive,noHealthActive);
        }
        else if (input == 'e' && menuCheatChoice == 1) {
            cheatKeys(character);
            healthActive = 'V';
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
            printf("%s", choiceCheatDone ? "true" : "false");
        }
    }
    printf("return");
    return 0;
}