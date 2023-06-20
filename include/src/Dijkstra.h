#include "Monster.h"
#include "Board.h"

#ifndef PROJETC_DIJKSTRA_H
#define PROJETC_DIJKSTRA_H

typedef struct DijkstraChain {
    int coordonees[2];
    struct DijkstraChain *next;
    struct DijkstraChain *previous;
} dijkstraChain;

dijkstraChain *createChain();

dijkstraChain *addChain(dijkstraChain *dijkstraChain);

dijkstraChain *removeChain(dijkstraChain *dijkstraChain);

monster *findClosestMonster(boardElements *boardElements);

monster *getMonsterBirdly(levelChain *levelChain);

#endif //PROJETC_DIJKSTRA_H
