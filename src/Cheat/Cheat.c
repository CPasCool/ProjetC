#include "../../include/src/Cheat.h"
#include "stdio.h"
#include <stdbool.h>

int CheatHealth(Character *character) {
    return setLifePoint(character, 999);
}

int setCheatMinus(int compt) {
    return compt - 1;
}

int setCheatPlus(int compt) {
    return compt + 1;
}

int CheatDefence(Character *character) {
    return setDefence(character, 999);
}

int CheatStrength(Character *character) {
    return setStrength(character, 999);
}

void printCheat(char healthActive, char strengthActive, char defenceActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#      %c Cheat Health       #\n"
            "#      %c Cheat Strength     #\n"
            "#      %c Cheat Defense      #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive
    );
}

void printCheatHealth(char healthActive, char strengthActive, char defenceActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#  ######################### #\n"
            "#  #   %c Cheat Health     # #\n"
            "#  ######################### #\n"
            "#      %c Cheat Strength     #\n"
            "#      %c Cheat Defense      #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive
    );
}

void printCheatwStrength(char healthActive, char strengthActive, char defenceActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#       %c Cheat Health      #\n"
            "#  ######################### #\n"
            "#  #    %c Cheat Strength  # #\n"
            "#  ######################### #\n"
            "#       %c Cheat Defense     #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive
    );
}

void printCheatDefence(char healthActive, char strengthActive, char defenceActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#      %c Cheat Health       #\n"
            "#      %c Cheat Strength     #\n"
            "#  ######################### #\n"
            "#  #   %c Cheat Defense    # #\n"
            "#  ######################### #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive
    );
}

void printCheatFinish(char healthActive, char strengthActive, char defenceActive) {
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#      %c Cheat Health       #\n"
            "#      %c Cheat Strength     #\n"
            "#      %c Cheat Defense      #\n"
            "#  ########################  #\n"
            "#  #         Quit         #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "##############################\n", healthActive, strengthActive, defenceActive
    );
}

void printMenuCheat(int choixCheat, char healthActive, char strengthActive, char defenceActive) {

    if (choixCheat == 0) {
        printCheat(healthActive, strengthActive, defenceActive);
    } else if (choixCheat == 1) {
        printCheatHealth(healthActive, strengthActive, defenceActive);
    } else if (choixCheat == 2) {
        printCheatwStrength(healthActive, strengthActive, defenceActive);
    } else if (choixCheat == 3) {
        printCheatDefence(healthActive, strengthActive, defenceActive);
    } else if (choixCheat == 4) {
        printCheatFinish(healthActive, strengthActive, defenceActive);
    }

}

void cheatMenu(char input, Character *character) {
    bool choiceCheatDone = false;
    int menuCheatChoice = 0;
    char healthActive = ' ';
    char strengthActive = ' ';
    char defenceActive = ' ';
    while (choiceCheatDone == false) {
        printMenuCheat(menuCheatChoice, healthActive, strengthActive, defenceActive);
        if (input == 'e' && menuCheatChoice == 1) {
            CheatHealth(character);
            healthActive = 'V';
        } else if (input == 'e' && menuCheatChoice == 2) {
            CheatStrength(character);
            strengthActive = 'V';
        } else if (input == 'e' && menuCheatChoice == 3) {
            CheatDefence(character);
            defenceActive = 'V';
        } else if (input == 'e' && menuCheatChoice == 4) {
            choiceCheatDone = true;
        }
    }
}