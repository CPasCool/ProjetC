#include "../../include/src/Board.h"
#include "stdlib.h"

levelChain *createLevelChain(boardElements *board) {
    levelChain *levelChain = malloc(sizeof(struct LevelChain));
    levelChain->current = board;
    levelChain->next = NULL;
    levelChain->previous = NULL;
    return levelChain;
}

boardElements *createBoardElement() {
    boardElements *boardElements = malloc(sizeof(struct BoardElements));
    boardElements->board = NULL;
    boardElements->character = NULL;
    boardElements->otherLevels = NULL;
    boardElements->monstersTab = NULL;
    boardElements->nbMonsters = -1;
    boardElements->levelNumber = -1;
    boardElements->aliveMonsters = -1;

    return boardElements;
}