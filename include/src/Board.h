#include "Character.h"
#include "Monster.h"


#ifndef PROJETC_BOARD_H
#define PROJETC_BOARD_H

typedef struct BoardElements{
    int levelNumber;
    char ** board;
    Character *character;
    monster **monstersTab;
    char **otherLevels;
    int nbMonsters;
    int aliveMonsters;
}boardElements;

typedef struct LevelChain{
    struct BoardElements *current;
    struct LevelChain *previous;
    struct LevelChain *next;
}levelChain;

levelChain *createLevelChain(boardElements *board);
boardElements *createBoardElement();

#endif //PROJETC_BOARD_H
