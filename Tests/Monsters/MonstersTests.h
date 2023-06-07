#include "../../include/src/Monster.h"
#include "../../include/src/Coordonees.h"

#ifndef PROJETC_MONSTERSTESTS_H
#define PROJETC_MONSTERSTESTS_H

int testMonster();
int testName(monster* monster, const char* name);
int testStrength(monster* monster, int str);
int testHealth(monster *monster, int hp);
int testShield(monster *monster, int shield);

#endif //PROJETC_MONSTERSTESTS_H
