#ifndef PROJETC_CHEAT_H
#define PROJETC_CHEAT_H

#include "Character.h"

int CheatHeath(Character * character);
int CheatDefence (Character* character);
int CheatStrength (Character* character);
void cheatMenu (char input, Character *character);
int setCheatMinus(int compt);
int setCheatPlus(int compt);
void printCheatHeath(char healthActive, char strenghActive, char defenceActive);
void printCheat(char healthActive, char strenghActive, char defenceActive);
void printCheatwStrengh(char healthActive, char strenghActive, char defenceActive);
void printCheatDefence(char healthActive, char strenghActive, char defenceActive);
void printCheatFinish(char healthActive, char strenghActive, char defenceActive);
void printMenuCheat (int choixCheat,char healthActive, char strenghActive, char defenceActive);

#endif