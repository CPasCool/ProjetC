#include "../Monster/Monster.h"
#include "../Character/Character.h"

#ifndef PROJETC_DISPLAYLEVELS_H
#define PROJETC_DISPLAYLEVELS_H

monster** getLevelMonsters(char* levelFile);
void createLevelMonsters(char* levelFile, monster** monsterTab, int nbMonster);
char** getLevelBoard(char* levelFile);
char **getOtherLevels(char *levelFile);

#endif //PROJETC_DISPLAYLEVELS_H
