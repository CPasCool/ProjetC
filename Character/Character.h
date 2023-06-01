//
// Created by benfa on 10/05/2023.
//

#ifndef PROJETC_CHARACTER_H
#define PROJETC_CHARACTER_H

#include "../Monster/Monster.h"

typedef struct Coordonees coordonees;
typedef struct statistics_ Stats;
typedef struct character_ Character;

// functions
// initializer
Character *createCharacter(char *name);

Stats *createStats();

// Setter
int setLifePoint(Character *character, int newLifePoint);

int addKeys(Character *character);

int removeKeys(Character *character);

int setStrength(Character *character, int newAttack);

int setDefence(Character *character, int newDefence);

int setName(Character *character, char *name);

int changeCoordonnes(Character *character, int x, int y);

int setMaximumLifePoint(Character *character, int newMax);

int printLifePoint(Stats *stat);

int printDefence(Stats *stat);

int printStrength(Stats *stat);

int printKeysNumber(Stats *stats);

int printAll(Character *);

int getLifePoint(Character *character);

int getKeys(Character *character);

int getStrength(Character *character);

int getDefence(Character *character);

int getMaximumLifePoint(Character *character);

coordonees *getCoo(Character *character);

char *getName(Character *character);

int getCharaX(Character *character);


int getCharaY(Character *character);

#endif //PROJETC_CHARACTER_H
