//
// Created by benfa on 10/05/2023.
//

#ifndef PROJETC_TESTCHARACTER_H
#define PROJETC_TESTCHARACTER_H


#include "../../include/src/Character.h"

int testCharacter();
int testCharacterName(Character* player, const char* name);
int testCoordonnes(Character* player, int x, int y);
int testMaximumLife(Character *player, int maxLife);
int testDefence(Character *pCharacter, int i);
int testAttack(Character *pCharacter, int i);
int testKeysNumber(Character *pCharacter, int i);
int testLifePoint(Character *pCharacter, int i);

#endif //PROJETC_TESTCHARACTER_H
