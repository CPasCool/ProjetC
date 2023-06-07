#include "../../include/src/Move.h"
#include "stdlib.h"
#include "stdio.h"


/**
 * move the character on the board
 * @param character : character to move
 * @return
 */
int move(Character *character, char move, boardElements *board, levelChain *levelChain) {
    monster *monster;
    coordonees *coordonees = malloc(sizeof(struct Coordonees));
    switch (move) {
        case 'z':
            coordonees = createCoordonne(getCharaX(character), getCharaY(character) - 1);
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
    switch (board->board[coordonees->y][coordonees->x]) {
        //No collisions
        case ' ':
            printf("x = %d, y = %d\n", coordonees->x, coordonees->y);
            moveCharacter(character, move, board->board);
            //There is an attack bonus
            printAll(character);
            printf("x = %d, y = %d\n", coordonees->x, coordonees->y);
            break;
        case '1':
            setStrength(character, getStrength(character) + 1);
            moveCharacter(character, move, board->board);
            printAll(character);
            break;

            //There is a Defence bonus
        case '2':
            setDefence(character, getDefence(character) + 1);
            moveCharacter(character, move, board->board);
            printAll(character);
            break;

            //There is a life bonus
        case '3':
            setMaximumLifePoint(character, 3);
            moveCharacter(character, move, board->board);
            printAll(character);
            break;

            //There is a key
        case '!':
            addKeys(character);
            moveCharacter(character, move, board->board);
            printAll(character);
            break;

            //There is a door
        case 'o':
            if (getKeys(character) != 0) {
                removeKeys(character);
                moveCharacter(character, move, board->board);
            }
            break;

            //There is a potion
        case 'P':
            setLifePoint(character, getMaximumLifePoint(character));
            moveCharacter(character, move, board->board);
            printAll(character);
            break;

            //There is a monster
        case 'A':
        case 'B':
        case 'C':
            printf("element in board is : %c\n", board->board[coordonees->y][coordonees->x]);
            monster = getSpecificMonster(board->monstersTab, coordonees,
                                         board->nbMonsters);
            fightWithMonster(character, monster);
            if (monster->hp <= 0) {
                printf("You killed %s\n", monster->name);
                board->aliveMonsters--;
                moveCharacter(character, move, board->board);
            }
            break;

            //There is a wall
        case '#':
            printf("x = %d, y = %d 2\n", coordonees->x, coordonees->y);
            printf("element in board is : %c\n", board->board[coordonees->y][coordonees->x]);
            printf("You can not go that way\n");
            break;
        case '?':
            moveCharacter(character, move, board->board);
            changeLevel(move, board, character, levelChain);
            break;
        default:
            break;
    }
    return 0;
}

int *moveCharacter(Character *character, char move, char **board) {
    switch (move) {
        case 'z':
            board[getCharaY(character)][getCharaX(character)] = ' ';
            changeCoordonnes(character, getCharaX(character), getCharaY(character) - 1);
            board[getCharaY(character)][getCharaX(character)] = 'T';
            break;
        case 'q':
            board[getCharaY(character)][getCharaX(character)] = ' ';
            changeCoordonnes(character, getCharaX(character) - 1, getCharaY(character));
            board[getCharaY(character)][getCharaX(character)] = 'T';
            break;
        case 's':
            board[getCharaY(character)][getCharaX(character)] = ' ';
            changeCoordonnes(character, getCharaX(character), getCharaY(character) + 1);
            board[getCharaY(character)][getCharaX(character)] = 'T';
            break;
        case 'd':
            board[getCharaY(character)][getCharaX(character)] = ' ';
            changeCoordonnes(character, getCharaX(character) + 1, getCharaY(character));
            board[getCharaY(character)][getCharaX(character)] = 'T';
            break;
        default:
            break;
    }
    return 0;
}

void changeLevel(char direction, boardElements *boardElements, Character *character, levelChain *levelChain) {
    switch (direction) {
        case 'z':
            levelChain = getLevelBoard(boardElements->otherLevels[3], levelChain);
            printf("test1");
            levelChain = getOtherLevels(boardElements->otherLevels[3], boardElements, levelChain);
            printf("test2");
            levelChain = getLevelMonsters(boardElements->otherLevels[3], boardElements, levelChain);
            printf("%d", boardElements->levelNumber);
            changeCoordonnes(character, getCharaX(character), getCharaY(character));
            boardElements->board[getCharaY(character)][getCharaX(character)] = 'T';
            break;
        case 'q':
            levelChain = getLevelBoard(boardElements->otherLevels[2], levelChain);
            levelChain = getOtherLevels(boardElements->otherLevels[2], boardElements, levelChain);
            levelChain = getLevelMonsters(boardElements->otherLevels[2], boardElements, levelChain);
            changeCoordonnes(character, getCharaX(character), getCharaY(character));
            boardElements->board[getCharaY(character)][getCharaX(character)] = 'T';
            break;

        case 's':
            levelChain = getLevelBoard(boardElements->otherLevels[1], levelChain);
            levelChain = getOtherLevels(boardElements->otherLevels[1], boardElements, levelChain);
            levelChain = getLevelMonsters(boardElements->otherLevels[1], boardElements, levelChain);
            changeCoordonnes(character, getCharaX(character), getCharaY(character));
            boardElements->board[getCharaY(character)][getCharaX(character)] = 'T';
            break;
        case 'd':
            levelChain = getLevelBoard(boardElements->otherLevels[0], levelChain);
            levelChain = getOtherLevels(boardElements->otherLevels[0], boardElements, levelChain);
            levelChain = getLevelMonsters(boardElements->otherLevels[0], boardElements, levelChain);
            changeCoordonnes(character, getCharaX(character), getCharaY(character));
            boardElements->board[getCharaY(character)][getCharaX(character)] = 'T';
            break;
        default:
            return;
    }
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
