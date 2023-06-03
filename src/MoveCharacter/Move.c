#include "../../include/src/Move.h"
#include "stdlib.h"
#include "stdio.h"

/**
 * move the character on the board
 * @param character : character to move
 * @return
 */
int move(Character *character, char move, boardElements *board) {
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
    switch (board->board[coordonees->y][coordonees->x]) {
        //No collisions
        case ' ':
            moveCharacter(character, move, board->board);
            //There is an attack bonus
            printAll(character);
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
            setMaximumLifePoint(character,  3);
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
            printf("You can not go that way\n");
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
