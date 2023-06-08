#include "Monster.h"
#include "Character.h"
#include "Board.h"

#ifndef PROJETC_DISPLAYLEVELS_H
#define PROJETC_DISPLAYLEVELS_H

int getFileLevelNumber(char *levelFile);
void getLevelNumber(char *levelFile, boardElements *board);
levelChain *getLevelBoard(char* levelFile, levelChain *levelChain);
void createLevelMonsters(char* levelFile, monster** monsterTab, int nbMonster);
levelChain *getLevelMonsters(char* levelFile, boardElements *boardElements, levelChain *levelChain);
levelChain * getOtherLevels(char *levelFile, boardElements *boardElements , levelChain *levelChain);

#endif //PROJETC_DISPLAYLEVELS_H
