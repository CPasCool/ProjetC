#ifndef PROJETC_CHEAT_H
#define PROJETC_CHEAT_H

#include "Character.h"
#include "Keyboard.h"

int cheatHealth(Character *character, char);

int cheatDefence(Character *character, char);

int cheatStrength(Character *character, char);

int cheatNoHealth(Character *character, char);

void printCheatHealth(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive);

void
printCheatStrength(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive);

void
printCheatDefence(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive);

void
printCheatNoHealth(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive);

void printCheatFinish(char keysActive, char healthActive, char strengthActive, char defenceActive, char noHealthActive);

void printMenuCheat(int choixCheat, char keysActive, char healthActive, char strengthActive, char defenceActive,
                    char noHealthActive);

int cheatMenu(char input, Character *character);

#endif