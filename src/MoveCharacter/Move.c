#include "../../include/src/Move.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * move the character on the board
 * @param character : character to move
 * @return
 */
levelChain *move(Character *character, char move, boardElements *board, levelChain *levelChain) {
    monster *monster;
    coordonees *coordonees = malloc(sizeof(struct Coordonees));
    switch (move) {
        case 'z':
            printf("e\n");
            coordonees = createCoordonne(getCharaX(character), getCharaY(character)- 1);
            break;
        case 'q':
            coordonees = createCoordonne(getCharaX(character) - 1, getCharaY(character));
            break;
        case 's':
            coordonees = createCoordonne(getCharaX(character), getCharaY(character) + 1);
            break;
        case 'd':
            coordonees = createCoordonne(getCharaX(character) + 1, getCharaY(character));
            break;
        default:
            break;
    }
    printf("x = %d, y = %d\n", coordonees->x, coordonees->y);
    switch (levelChain->current->board[coordonees->y][coordonees->x]) {
        //No collisions
        case ' ':
            moveCharacter(character, coordonees, levelChain->current->board, levelChain);
            levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
            printAll(character);
            break;

            //There is an attack bonus
        case '1':
            setStrength(character, getStrength(character) + 1);
            moveCharacter(character, coordonees, levelChain->current->board, levelChain);
            levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
            printAll(character);
            break;

            //There is a Defence bonus
        case '2':
            setDefence(character, getDefence(character) + 1);
            moveCharacter(character, coordonees, levelChain->current->board, levelChain);
            levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
            printAll(character);
            break;

            //There is a life bonus
        case '3':
            setMaximumLifePoint(character, 3);
            moveCharacter(character, coordonees, levelChain->current->board, levelChain);
            levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
            printAll(character);
            break;

            //There is a key
        case '!':
            addKeys(character);
            moveCharacter(character, coordonees, levelChain->current->board, levelChain);
            levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
            printAll(character);
            break;

            //There is a door
        case 'o':
            if (getKeys(character) != 0) {
                removeKeys(character);
                moveCharacter(character, coordonees, levelChain->current->board, levelChain);
                levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
            }
            break;

            //There is a potion
        case 'P':
            setLifePoint(character, getMaximumLifePoint(character));
            moveCharacter(character, coordonees, levelChain->current->board, levelChain);
            levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
            printAll(character);
            break;

            //There is a monster
        case 'A':
        case 'B':
        case 'C':
            monster = getSpecificMonster(levelChain->current->monstersTab, coordonees,
                                         levelChain->current->nbMonsters);
            printMonsterStats(monster);
            fightWithMonster(character, monster);
            if (monster->hp <= 0) {
                printf("You killed %s\n", monster->name);
                levelChain->current->aliveMonsters--;
                moveCharacter(character, coordonees, levelChain->current->board, levelChain);
                levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
            }
            break;

            //There is a northWall
        case '#':
            printf("You can not go that way\n");
            break;
        case '?':
            moveCharacter(character, coordonees, levelChain->current->board, levelChain);
            levelChain = changeLevel(move, board, character, levelChain);
            levelChain->current->board[getCharaY(character)][getCharaX(character)] = 'T';
            break;
        default:
            break;
    }
    return levelChain;
}

int *moveCharacter(Character *character, coordonees *coordonees, char **board, levelChain *levelChain) {
    levelChain->current->board[getCharaY(character)][getCharaX(character)] = ' ';
    board[getCharaY(character)][getCharaX(character)] = ' ';
    changeCoordonnes(character, coordonees->x, coordonees->y);
    return 0;
}

levelChain *changeLevel(char direction, boardElements *boardElements, Character *character, levelChain *levelChain) {
    int digitDirection = 0;
    switch (direction) {
        case 'z':
            digitDirection = 3;
            changeCoordonnes(character, getCharaX(character), getCharaY(character) + 28);
            break;
        case 'q':
            digitDirection = 2;
            changeCoordonnes(character, getCharaX(character) + 28, getCharaY(character));
            break;

        case 's':
            digitDirection = 1;
            changeCoordonnes(character, getCharaX(character), getCharaY(character) - 28);
            break;
        case 'd':
            digitDirection = 0;
            changeCoordonnes(character, getCharaX(character) - 28, getCharaY(character));
            break;
        default:
            break;
    }
    levelChain = getLevelBoard(boardElements->otherLevels[digitDirection], levelChain);
    levelChain = levelChain->next;
    return levelChain;
}

monster *getSpecificMonster(monster **monsterTab, coordonees *coordonees, int nbMonster) {
    monster *monster = malloc(sizeof(struct Monster));
    for (int i = 0; i < nbMonster; i++) {
        if (monsterTab[i]->MonsterCoordonnees->x == coordonees->x &&
            monsterTab[i]->MonsterCoordonnees->y == coordonees->y) {
            monster = monsterTab[i];
        }
    }
    return monster;
}
