#include "Monster.h"
#include "Character.h"
#include "Board.h"

#ifndef PROJETC_DISPLAYLEVELS_H
#define PROJETC_DISPLAYLEVELS_H

void getLevelNumber(char *levelFile, boardElements *board);
levelChain *getLevelBoard(char* levelFile, levelChain *levelChain);
char **addPrefix(char **levels, int errorCount, int size);

#endif //PROJETC_DISPLAYLEVELS_H
