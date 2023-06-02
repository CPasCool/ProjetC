#include "..\Character\Character.h"
# include <stdlib.h>
#include "stdio.h"
#include <stdbool.h>

int CheatHeath(Character* character){
    return setHeathPoint(character, 999);
}

int setCheatMinus(int compt){
    return compt-1;
}

int setCheatPlus(int compt){
    return compt+1;
}

int CheatDefence (Character* character){
    return setDefence(character, 999);
}

int CheatStrength (Character* character){
    return setStrength(character, 999);
}

void printCheatHeath(char HeathActive, char strenghActive, char defenceActive){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  #   ",HeathActive,"  Cheat Heath     #  #\n"
            "#  ########################  #\n"
            "#      ",strenghActive," Cheat Strengh       #\n"
            "#       ",defenceActive," Cheat Defense       #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}
void printCheat(char HeathActive, char strenghActive, char defenceActive){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#       ",HeathActive," Cheat Heath        #\n"
            "#      ",strenghActive," Cheat Strengh       #\n"
            "#      ",defenceActive," Cheat Defense       #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}
void printCheatwStrengh(char HeathActive, char strenghActive, char defenceActive){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#       ",HeathActive," Cheat Heath        #\n"
            "#  ########################  #\n"
            "#  #    ",strenghActive,"Cheat Strengh    #  #\n"
            "#  ########################  #\n"
            "#      ",defenceActive," Cheat Defense       #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}
void printCheatDefence(char HeathActive, char strenghActive, char defenceActive){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#       ",HeathActive," Cheat Heath        #\n"
            "#      ",strenghActive," Cheat Strengh       #\n"
            "#  ########################  #\n"
            "#  #    ",defenceActive,"Cheat Defense    #  #\n"
            "#  ########################  #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n"
    );
}
void printCheatFinish(char HeathActive, char strenghActive, char defenceActive){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#       ",HeathActive," Cheat Heath        #\n"
            "#      ",strenghActive," Cheat Strengh       #\n"
            "#      ",defenceActive," Cheat Defense       #\n"
            "#  ########################  #\n"
            "#  #         Quit         #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void printMenuCheat (int choixCheat,char HeathActive, char strenghActive, char defenceActive){
    
    if (choixCheat == 0)
    {
        printCheat(HeathActive, strenghActive, defenceActive);
    }else if (choixCheat == 1)
    {
        printCheatHeath(HeathActive, strenghActive, defenceActive);
    }else if (choixCheat == 2)
    {
        printCheatwStrengh(HeathActive, strenghActive, defenceActive);
    }else if (choixCheat == 3)
    {
        printCheatDefence(HeathActive, strenghActive, defenceActive);
    }else if (choixCheat == 4)
    {
        printCheatFinish(HeathActive, strenghActive, defenceActive);
    }
    
}

void cheatMenu (char keyEnter){
    bool choiceCheatDone = false;
    int menuCheatChoice = 0;
    char HeathActive = ' ';
    char strenghActive = ' ';
    char defenceActive = ' ';
    while (choiceCheatDone == false)
    {
        printMenuCheat(menuCheatChoice, HeathActive, strenghActive, defenceActive);
        if (keyEnter == 'e' && menuCheatChoice == 1)
        {
            CheatHeath(character);
            HeathActive = 'V';
        }else if (keyEnter == 'e' && menuCheatChoice == 2)
        {
            CheatStrength(character);
            strenghActive = 'V';
        }else if (keyEnter == 'e' && menuCheatChoice == 3)
        {
            CheatDefence(character);
            defenceActive = 'V';
        }else if (keyEnter == 'e' && menuCheatChoice == 4)
        {
            choiceCheatDone = true;
        }
    }
}