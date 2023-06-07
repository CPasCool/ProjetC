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
    setLifePoint(character, 0);
}

void printCheat(char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#    %c Cheat Max Health     #\n"
            "#    %c Cheat Max Strength   #\n"
            "#    %c Cheat Max Defense    #\n"
            "#    %c Cheat No Health     #\n"
            "#          Validate          #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive, noHealthActive
    );
}

void printCheatHealth(char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#  ######################### #\n"
            "#  # %c Cheat Max Health   # #\n"
            "#  ######################### #\n"
            "#    %c Cheat Max Strength   #\n"
            "#    %c Cheat Max Defense    #\n"
            "#    %c Cheat No Health     #\n"
            "#          Validate          #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive, noHealthActive
    );
}

void printCheatwStrength(char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c Cheat Max Health     #\n"
            "#  ######################### #\n"
            "#  # %c Cheat Max Strength # #\n"
            "#  ######################### #\n"
            "#    %c Cheat Max Defense    #\n"
            "#    %c Cheat No Health     #\n"
            "#          Validate          #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive, noHealthActive
    );
}

void printCheatDefence(char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c Cheat Max Health     #\n"
            "#    %c Cheat Max Strength   #\n"
            "#  ######################### #\n"
            "#  # %c Cheat Max Defense  # #\n"
            "#  ######################### #\n"
            "#    %c Cheat No Health     #\n"
            "#          Validate          #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatNoHealth(char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c Cheat Max Health     #\n"
            "#    %c Cheat Max Strength   #\n"
            "#    %c Cheat Max Defense    #\n"
            "#  ######################### #\n"
            "#  # %c Cheat No Health    # #\n"
            "#  ######################### #\n"
            "#          Validate          #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatValidate(char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c Cheat Max Health     #\n"
            "#    %c Cheat Max Strength   #\n"
            "#    %c Cheat Max Defense    #\n"
            "#    %c Cheat No Health      #\n"
            "#  ######################### #\n"
            "#  #       Validate        # #\n"
            "#  ######################### #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive, noHealthActive
    );
}
void printCheatFinish(char healthActive, char strengthActive, char defenceActive,char noHealthActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#    %c Cheat Max Health     #\n"
            "#    %c Cheat Max Strength   #\n"
            "#    %c Cheat Max Defense    #\n"
            "#    %c Cheat No Health      #\n"
            "#          Validate          #\n"
            "#  ########################  #\n"
            "#  #         Quit         #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive, noHealthActive
    );
}

/**
 * cette fonction permet d'afficher le bon menu en fonction du choix
*/
void printMenuCheat(int choixCheat, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
    if (choixCheat == 0) {
        printCheat(healthActive, strengthActive, defenceActive,noHealthActive);
    } 
    else if (choixCheat == 1) {
        printCheatHealth(healthActive, strengthActive, defenceActive,noHealthActive);
    } 
    else if (choixCheat == 2) {
        printCheatwStrength(healthActive, strengthActive, defenceActive,noHealthActive);
    } 
    else if (choixCheat == 3) {
        printCheatDefence(healthActive, strengthActive, defenceActive,noHealthActive);
    }
    else if (choixCheat == 4) {
        printCheatNoHealth(healthActive, strengthActive, defenceActive,noHealthActive);
    }  
    else if (choixCheat == 5){
        printCheatValidate(healthActive, strengthActive, defenceActive,noHealthActive);
    }
    else if (choixCheat == 6) {
        printCheatFinish(healthActive, strengthActive, defenceActive,noHealthActive);
    }
}
/**
 * cette fonction est la fonction principal d'interfaçage avec le clavier
*/
void cheatMenu(char input, Character *character) {
    bool choiceCheatDone = false;
    int menuCheatChoice = 0;
    char healthActive = ' ';
    char strengthActive = ' ';
    char defenceActive = ' ';
    char noHealthActive= ' ';
    while (choiceCheatDone == false) {
        printMenuCheat(menuCheatChoice, healthActive, strengthActive, defenceActive,noHealthActive);
        if (input == 'e' && menuCheatChoice == 1) {
            cheatHealth(character);
            healthActive = 'V';
        } else if (input == 'e' && menuCheatChoice == 2) {
            cheatStrength(character);
            strengthActive = 'V';
        } else if (input == 'e' && menuCheatChoice == 3) {
            cheatDefence(character);
            defenceActive = 'V';
        } else if (input == 'e' && menuCheatChoice == 4) {
            cheatNoHealth(character);
            noHealthActive = 'V';
        } else if (input == 'e' && menuCheatChoice == 5) {
            choiceCheatDone = true;
        } else if (input == 'e' && menuCheatChoice == 6) {
            choiceCheatDone = true;
        }
    }
}