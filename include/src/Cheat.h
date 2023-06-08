#ifndef PROJETC_CHEAT_H
#define PROJETC_CHEAT_H

#include "Character.h"
#include "Keyboard.h"

int cheatHealth(Character * character);
int cheatDefence (Character* character);
int cheatStrength (Character* character);
int cheatNoHealth(Character * character);
int setCheatMinus(int compt);
int setCheatPlus(int compt);
void printCheatHealth(char keysActive,char healthActive, char strengthActive, char defenceActive,char noHealthActive);
void printCheat(char keysActive,char healthActive, char strengthActive, char defenceActive,char noHealthActive);
void printCheatwStrengh(char keysActive,char healthActive, char strengthActive, char defenceActive,char noHealthActive);
void printCheatDefence(char keysActive,char healthActive, char strengthActive, char defenceActive,char noHealthActive);
void printCheatNoHealth(char keysActive,char healthActive, char strengthActive, char defenceActive,char noHealthActive);
void printCheatFinish(char keysActive,char healthActive, char strengthActive, char defenceActive,char noHealthActive);
void printMenuCheat (int choixCheat, char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive);
int cheatMenu(char input, Character *character);

#endif