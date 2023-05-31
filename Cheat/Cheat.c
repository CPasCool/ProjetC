#include "..\Character\Character.h"
# include <stdlib.h>
#include "stdio.h"
#include <stdbool.h>

int CheatHeath(Character* character){
    return setHeathPoint(character, 10000);
}
int CheatDefence (Character* character){
    return setDefence(character, 10000);
}
int CheatStrength (Character* character){
    return setStrength(character, 10000);
}

void printCheatHeath(char HeathActive, char strenghActive, char defenceActive){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  #   ",HeathActive,"  Cheat Heath     #  #\n"
            "#  ########################  #\n"
            "#        Cheat Strengh       #\n"
            "#        Cheat Defense       #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}
void printCheat(){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#         Cheat Heath        #\n"
            "#        Cheat Strengh       #\n"
            "#        Cheat Defense       #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}
void printCheatwStrengh(){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#         Cheat Heath        #\n"
            "#  ########################  #\n"
            "#  #     Cheat Strengh    #  #\n"
            "#  ########################  #\n"
            "#        Cheat Defense       #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}
void printCheatDefence(){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#         Cheat Heath        #\n"
            "#        Cheat Strengh       #\n"
            "#  ########################  #\n"
            "#  #     Cheat Defense    #  #\n"
            "#  ########################  #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################"
    );
}
void printCheatFinish(){
    printf(
            "##############################\n"
            "#            CHEAT           #\n"
            "#                            #\n"
            "#                            #\n"
            "#         Cheat Heath        #\n"
            "#        Cheat Strengh       #\n"
            "#        Cheat Defense       #\n"
            "#  ########################  #\n"
            "#  #         Quit         #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "##############################"
    );
}

void printMenuCheat (int choixCheat){
    
    if (choixCheat == 0)
    {
        printCheat();
    }else if (choixCheat == 1)
    {
        printCheatHeath();
    }else if (choixCheat == 2)
    {
        printCheatwStrengh();
    }else if (choixCheat == 3)
    {
        printCheatDefence();
    }else if (choixCheat == 4)
    {
        printCheatFinish();
    }
    
}
void cheatMenu(Character * character, char keyEnter){
    bool choiceCheatDone = false;
    int menuCheatChoice = 0;
    while (choiceCheatDone == false)
    {
        printMenuCheat(menuCheatChoice);
        if (keyEnter == 'e' && menuCheatChoice == 1)
        {
            CheatHeath(character);
            printf("HeathCheat is activated");
        }else if (keyEnter == 'e' && menuCheatChoice == 2)
        {
            CheatStrength(character);
            printf("Strength Cheat is activated");
        }else if (keyEnter == 'e' && menuCheatChoice == 3)
        {
            CheatDefence(character);
            printf("Defense Cheat is activated");
        }else if (keyEnter == 'e' && menuCheatChoice == 4)
        {
            choiceCheatDone = true;
        }
    }
}