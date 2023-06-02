//
// Created by benfa on 24/05/2023.
//

#ifndef PROJETC_FIGHTSYSTEM_H
#define PROJETC_FIGHTSYSTEM_H

#include "Monster.h"
#include "Character.h"

int fightWithMonster(Character *character, monster *monster);
int *getMonstersDistances(Character *character, monster **monstersTab, int nbMonsters);
monster* findClosestMonster(monster **monstersTab, const int* distancesTab, int nbMonsters);

#endif //PROJETC_FIGHTSYSTEM_H
