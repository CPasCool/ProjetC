#include "../Monster/Monster.h"


#ifndef PROJETC_DISPLAYLEVELS_H
#define PROJETC_DISPLAYLEVELS_H

monster* getLevelMonsters(char* levelFile);
monster* createLevelMonsters(char* levelFile, int nbMonsterA, int nbMonsterB, int nbMonsterC);
char** getLevelBoard(char* levelFile);

#endif //PROJETC_DISPLAYLEVELS_H
