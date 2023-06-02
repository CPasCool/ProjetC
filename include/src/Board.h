#include "Character.h"
#include "Monster.h"


#ifndef PROJETC_BOARD_H
#define PROJETC_BOARD_H

typedef struct BoardElements{
    char ** board;
    Character *character;
    monster **monstersTab;
    char **otherLevels;
    int nbMonsters;
}boardElements;

#endif //PROJETC_BOARD_H
