#include "../../include/src/Cheat.h"
#include "stdio.h"
#include <stdbool.h>

int cheatHealth(Character *character, char healthActive) {
    if (healthActive == 'V') {
        return setLifePoint(character, 999);
    } else {
        return setLifePoint(character, 10);
    }
}


int cheatDefence(Character *character, char defenceActive) {
    if (defenceActive == 'V') {
        return setDefence(character, 999);
    } else {
        return setDefence(character, 1);
    }
}

int cheatStrength(Character *character, char strengthActive) {
    if (strengthActive == 'V') {
        return setStrength(character, 999);
    } else {
        return setStrength(character, 2);
    }
}

int cheatNoHealth(Character *character, char noHealthActive) {
    if (noHealthActive == 'V') {
        return setLifePoint(character, 0);
    } else {
        return setLifePoint(character, 10);
    }
}

int cheatKeys(Character *character, char keyActive) {
    if (keyActive == 'V') {
        return setMaxKeys(character);
    } else {
        return setKeys(character, 0);
    }
}

void printCheatKey(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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

void
printCheatHealth(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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
            "##############################\n", keysActive, healthActive, strengthActive, defenceActive, noHealthActive
    );
}

void
printCheatStrength(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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
            "##############################\n", keysActive, healthActive, strengthActive, defenceActive, noHealthActive
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

void
printCheatNoHealth(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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
            "##############################\n", keysActive, healthActive, strengthActive, defenceActive, noHealthActive
    );
}

void
printCheatFinish(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive) {
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
void printMenuCheat(int choixCheat, char keysActive, char healthActive, char strengthActive, char defenceActive,
                    char noHealthActive) {
    if (choixCheat == 1) {
        printCheatKey(keysActive, healthActive, strengthActive, defenceActive, noHealthActive);
    } else if (choixCheat == 2) {
        printCheatHealth(keysActive, healthActive, strengthActive, defenceActive, noHealthActive);
    } else if (choixCheat == 3) {
        printCheatStrength(keysActive, healthActive, strengthActive, defenceActive, noHealthActive);
    } else if (choixCheat == 4) {
        printCheatDefence(keysActive, healthActive, strengthActive, defenceActive, noHealthActive);
    } else if (choixCheat == 5) {
        printCheatNoHealth(keysActive, healthActive, strengthActive, defenceActive, noHealthActive);
    } else if (choixCheat == 6) {
        printCheatFinish(keysActive, healthActive, strengthActive, defenceActive, noHealthActive);
    }
}

/**
 * cette fonction est la fonction principal d'interfaçage avec le clavier
 * Elle defini si un cheat est actif ou non via le charactère 'x' ou 'V'
*/
int cheatMenu(char input, Character *character) {
    bool choiceCheatDone = false;
    int menuCheatChoice = 1;
    char healthActive = 'x';
    char strengthActive = 'x';
    char defenceActive = 'x';
    char noHealthActive = 'x';
    char keyActive = 'x';
    if (getLifePoint(character) >= 900) {
        healthActive = 'V';
    }
    if (getLifePoint(character) == 0) {
        keyActive = 'V';
    }
    if (getStrength(character) >= 900) {
        strengthActive = 'V';
    }
    if (getDefence(character) >= 900) {
        defenceActive = 'V';
    }
    if (getKeys(character) >= 900) {
        keyActive = 'V';
    }

    // affiche si un cheat est activé ou non, si un cheat est desactiver, le joueur recupere les stats de base
    printMenuCheat(menuCheatChoice, keyActive, healthActive, strengthActive, defenceActive, noHealthActive);
    while (choiceCheatDone == false) {
        input = catchInput();
        if (input == 's' && menuCheatChoice != 6) {
            menuCheatChoice += 1;
        } else if (input == 'z' && menuCheatChoice != 1) {
            menuCheatChoice -= 1;
        } else if (input == 'e') {
            if (menuCheatChoice == 1) {
                if (keyActive == 'x') {
                    keyActive = 'V';
                } else {
                    keyActive = 'x';
                }
                cheatKeys(character, keyActive);
            } else if (menuCheatChoice == 2) {
                if (healthActive == 'x') {
                    healthActive = 'V';
                } else {
                    healthActive = 'x';
                }
                cheatHealth(character, healthActive);
            } else if (menuCheatChoice == 3) {
                if (strengthActive == 'x') {
                    strengthActive = 'V';
                } else {
                    strengthActive = 'x';
                }
                cheatStrength(character, strengthActive);
            } else if (menuCheatChoice == 4) {
                if (defenceActive == 'x') {
                    defenceActive = 'V';
                } else {
                    defenceActive = 'x';
                }
                cheatDefence(character, defenceActive);
            } else if (menuCheatChoice == 5) {
                if (defenceActive == 'x') {
                    defenceActive = 'V';
                } else {
                    defenceActive = 'x';
                }
                cheatNoHealth(character, noHealthActive);
            } else if (menuCheatChoice == 6) {
                choiceCheatDone = true;
            }
        }
        if (choiceCheatDone != true) {
            printMenuCheat(menuCheatChoice, keyActive, healthActive, strengthActive, defenceActive, noHealthActive);
        }
    }
    return 0;
}