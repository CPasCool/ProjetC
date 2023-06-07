#ifndef PROJETC_CHEAT_H
#define PROJETC_CHEAT_H

#include "Character.h"

int cheatHealth(Character * character);
int cheatDefence (Character* character);
int cheatStrength (Character* character);
int cheatNoHealth(Character * character);
void cheatMenu (char input, Character *character);
int setCheatMinus(int compt);
int setCheatPlus(int compt);
void printCheatHealth(char healthActive, char strenghActive, char defenceActive, char noHealthActive);
void printCheat(char healthActive, char strenghActive, char defenceActive,char noHealthActive);
void printCheatwStrengh(char healthActive, char strenghActive, char defenceActive,char noHealthActive);
void printCheatDefence(char healthActive, char strenghActive, char defenceActive, char noHealthActive);
void printCheatNoHealth(char healthActive, char strenghActive, char defenceActive, char noHealthActive);
void printCheatValidate(char healthActive, char strenghActive, char defenceActive, char noHealthActive);
void printCheatFinish(char healthActive, char strenghActive, char defenceActive,char noHealthActive);
void printMenuCheat (int choixCheat,char healthActive, char strenghActive, char defenceActive,char noHealthActive);
void cheatMenu(char input, Character *character);

#endif