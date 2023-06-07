#include "Monster.h"
#include "Character.h"
#include "Board.h"

#ifndef PROJETC_DISPLAYLEVELS_H
#define PROJETC_DISPLAYLEVELS_H

levelChain *getLevelMonsters(char* levelFile, boardElements *boardElements, levelChain *levelChain);
void createLevelMonsters(char* levelFile, monster** monsterTab, int nbMonster);
levelChain *getLevelBoard(char* levelFile, boardElements *boardElements, levelChain *levelChain);
levelChain * getOtherLevels(char *levelFile, boardElements *boardElements , levelChain *levelChain);

#endif //PROJETC_DISPLAYLEVELS_H
