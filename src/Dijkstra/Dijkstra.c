#include "../../include/src/Dijkstra.h"
#include "stdlib.h"
#include "stdio.h"


dijkstraChain *createChain() {
    dijkstraChain *dijkstraChain = malloc(sizeof(struct DijkstraChain));
    dijkstraChain->coordonees[0] = -1;
    dijkstraChain->coordonees[1] = -1;
    dijkstraChain->next = NULL;
    dijkstraChain->previous = NULL;
    return dijkstraChain;
}

dijkstraChain *addChain(dijkstraChain *dijkstraChain) {
    dijkstraChain->next = createChain();
    dijkstraChain->next->previous = dijkstraChain;
    dijkstraChain = dijkstraChain->next;
    return dijkstraChain;
}

dijkstraChain *removeChain(dijkstraChain *dijkstraChain) {
    dijkstraChain = dijkstraChain->previous;
    free(dijkstraChain->next);
    dijkstraChain->next = NULL;
    return dijkstraChain;
}

monster *getMonsterBirdly(levelChain *levelChain) {
    int *distances = malloc(sizeof(int) * levelChain->current->nbMonsters);
    for (int i = 0; i < levelChain->current->nbMonsters; i++) {
        if (levelChain->current->monstersTab[i]->hp > 0) {
            distances[i] = abs(getCharaY(levelChain->current->character) -
                               levelChain->current->monstersTab[i]->MonsterCoordonnees->y) +
                           abs(getCharaX(levelChain->current->character) -
                               levelChain->current->monstersTab[i]->MonsterCoordonnees->x);
        } else {
            distances[i] = 999999999;
        }
    }
    int val_min;
    val_min = distances[0];
    for (int i = 0; i < levelChain->current->nbMonsters; i++) {
        if (distances[i] < val_min && levelChain->current->monstersTab[i]->hp > 0) {
            val_min = i;
        }
    }
    return levelChain->current->monstersTab[val_min];
}

monster *findClosestMonster(boardElements *boardElements) {
    Character *character = boardElements->character;
    monster **monstersTab = boardElements->monstersTab;
    int *distances = malloc(sizeof(int) * boardElements->nbMonsters);

    for (int i = 0; i < boardElements->nbMonsters; i++) {

        int booleanBoard[30][30] = {{0}};
        int posLigCaseAct = getCharaX(character);
        int posColCaseAct = getCharaY(character);
        dijkstraChain *chain = createChain();
        chain = addChain(chain);

        booleanBoard[getCharaX(character)][getCharaY(character)] = 1;
        chain->coordonees[0] = getCharaX(character);
        chain->coordonees[1] = getCharaY(character);

        chain = addChain(chain);
        while (chain->previous->coordonees[0] != -1 &&
               booleanBoard[monstersTab[i]->MonsterCoordonnees->x][monstersTab[i]->MonsterCoordonnees->y] != 1) {
            if (boardElements->board[posLigCaseAct - 1][posColCaseAct] != '#' &&
                booleanBoard[posLigCaseAct - 1][posLigCaseAct] != 1) {
                printf("%d, %d\n", posLigCaseAct - 1, posColCaseAct);

                booleanBoard[posLigCaseAct - 1][posColCaseAct] = 1;
                posLigCaseAct = posLigCaseAct - 1;
                chain->coordonees[0] = posColCaseAct;
                chain->coordonees[1] = posLigCaseAct;
                chain = addChain(chain);
            } else if (boardElements->board[posLigCaseAct + 1][posColCaseAct] != '#' &&
                       booleanBoard[posLigCaseAct + 1][posLigCaseAct] != 1) {
                //printf("%c", boardElements->board[posLigCaseAct + 1][posColCaseAct]);
                booleanBoard[posLigCaseAct + 1][posColCaseAct] = 1;
                posLigCaseAct = posLigCaseAct + 1;
                chain->coordonees[0] = posColCaseAct;
                chain->coordonees[1] = posLigCaseAct;
                chain = addChain(chain);
            } else if (boardElements->board[posLigCaseAct][posColCaseAct - 1] != '#' &&
                       booleanBoard[posLigCaseAct][posLigCaseAct - 1] != 1) {
                //printf("%c", boardElements->board[posLigCaseAct][posColCaseAct - 1]);

                booleanBoard[posLigCaseAct][posColCaseAct - 1] = 1;
                posColCaseAct = posColCaseAct - 1;
                chain->coordonees[0] = posColCaseAct;
                chain->coordonees[1] = posLigCaseAct;
                chain = addChain(chain);
            } else if (boardElements->board[posLigCaseAct][posColCaseAct + 1] != '#' &&
                       booleanBoard[posLigCaseAct][posLigCaseAct + 1] != 1) {
                //printf("%c", boardElements->board[posLigCaseAct][posColCaseAct + 1]);
                booleanBoard[posLigCaseAct][posColCaseAct + 1] = 1;
                posColCaseAct = posColCaseAct + 1;
                chain->coordonees[0] = posColCaseAct;
                chain->coordonees[1] = posLigCaseAct;
                chain = addChain(chain);
            } else {
                chain = removeChain(chain);
                if (chain->previous->coordonees[0] != -1) {
                    posLigCaseAct = chain->coordonees[0];
                    posColCaseAct = chain->coordonees[1];
                }
            }
        }
        if (chain->previous->coordonees[0] != -1) {
            distances[i] =
                    abs(getCharaX(character) - chain->coordonees[0]) + abs(getCharaY(character) - chain->coordonees[1]);
        }
    }
    int val_min;
    val_min = distances[0];
    for (int i = 0; i < boardElements->nbMonsters; i++) {
        if (distances[i] < val_min && monstersTab[i]->hp > 0) {
            val_min = i;
        }
    }
    return monstersTab[val_min];
}