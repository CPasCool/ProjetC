#include "Monster.h"
#include "Character.h"
#include "Board.h"

#ifndef PROJETC_DISPLAYLEVELS_H
#define PROJETC_DISPLAYLEVELS_H

void getLevelMonsters(char* levelFile, boardElements *boardElements);
void createLevelMonsters(char* levelFile, monster** monsterTab, int nbMonster);
void getLevelBoard(char* levelFile, boardElements *boardElements);
void getOtherLevels(char *levelFile, boardElements *boardElements);

#endif //PROJETC_DISPLAYLEVELS_H