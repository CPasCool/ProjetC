//
// Created by benfa on 10/05/2023.
//

#include "Character.h"
# include <stdlib.h>
#include "stdio.h"
#include "../Monster/Monster.h"

typedef struct coordonees_ {
    int x;
    int y;
} coordonees;

typedef struct statistics_ {
    int maxLifePoint;
    int currentLifePoint;
    int strength;
    int defence;
    int keys;
} Stats;

typedef struct character_ {
    coordonees *coo;
    char *name;
    Stats *stat;
} Character;


// initializers
Character *createCharacter(char *name) {
    Character *player = malloc(sizeof(Character));
    player->coo = malloc(sizeof(coordonees));
    player->stat = createStats();
    player->name = name;
    return player;
}

Stats *createStats() {
    Stats *stat = malloc(sizeof(Stats));
    stat->strength = 5;
    stat->maxLifePoint = 10;
    stat->keys = 0;
    stat->currentLifePoint = stat->maxLifePoint;
    stat->defence = 5;
    return stat;
}

// getters

int getLifePoint(Character *character) {
    return character->stat->currentLifePoint;
}

int getMaximumLifePoint(Character *character) {
    return character->stat->currentLifePoint;
}

char *getName(Character *character) {
    return character->name;
}

int getKeys(Character *character) {
    return character->stat->keys;
}

int getStrength(Character *character) {
    return character->stat->strength;
}

int getDefence(Character *character) {
    return character->stat->defence;
}

coordonees *getCoo(Character *character) {
    return character->coo;
}

int getX(Character *character) {
    return getCoo(character)->x;
}

int getY(Character *character) {
    return getCoo(character)->y;
}

// setters
int setLifePoint(Character *character, int newLifePoint) {
    character->stat->currentLifePoint = newLifePoint;
    return 0;
}

int setKeys(Character *character, int keyNumber) {
    character->stat->keys = keyNumber;
    return 0;
}

int setStrength(Character *character, int newAttack) {
    character->stat->strength = newAttack;
    return 0;
}

int setDefence(Character *character, int newDefence) {
    character->stat->defence = newDefence;
    return 0;
}

int setName(Character *character, char *name) {
    character->name = name;
    return 0;
}

int changeCoordonnes(Character *character, int x, int y) {
    character->coo->x = x;
    character->coo->y = y;
    return 0;
}

int setMaximumLifePoint(Character *character, int newMax) {
    character->stat->maxLifePoint = newMax;
    return 0;
}

// display stats
int printLifePoint(Stats *stat) {
    printf("Life total : %d/%d\n", stat->currentLifePoint, stat->maxLifePoint);
    return 0;
}

int printStrength(Stats *stat) {
    printf("Attack : %d\n", stat->strength);
    return 0;
}

int printDefence(Stats *stats) {
    printf("Defence : %d\n", stats->defence);
    return 0;
}

int printKeysNumber(Stats *stats) {
    printf("Number of key : %d\n", stats->keys);
    return 0;
}

int printAll(Character *character) {
    printLifePoint(character->stat);
    printKeysNumber(character->stat);
    printStrength(character->stat);
    printDefence(character->stat);
    return 0;
}

/**
 * move the character to the up in board
 * @param character : character to move
 * @return
 */
int moveUp(Character *character) {
    // TODO : verifier les collisions
    // TODO : verifier si il y a un monstre
    character->coo->y += 1;
    return 0;
}

/**
 * move the character to the down in board
 * @param character : character to move
 * @return
 */
int moveDown(Character *character) {
    // TODO : verifier les collisions
    // TODO : verifier si il y a un monstre
    character->coo->y -= 1;
    return 0;
}

/**
 * move the character to the right in board
 * @param character : character to move
 * @return
 */
int moveRight(Character *character) {
    // TODO : verifier les collisions
    // TODO : verifier si il y a un monstre
    character->coo->x += 1;
    return 0;
}

/**
 * move the character to the left in board
 * @param character : character to move
 * @return
 */
int moveLeft(Character *character) {
    // TODO : verifier les collisions
    // TODO : verifier si il y a un monstre
    character->coo->x += 1;
    return 0;
}

/**
 * fight with target monster
 * @param character : character of the player
 * @param monster : target monster to fight
 * @return
 */
int fightWithMonster(Character *character, monster *monster) {
    // attribue degat au monste
    if (character->stat->strength - getMonsterShield(monster) > 0) {
        setMonsterHealth(monster, getMonsterHealth(monster) - (character->stat->strength - getMonsterShield(monster)));
    } else {
        setMonsterHealth(monster, getMonsterHealth(monster) - 1);
    }

    if (getMonsterHealth(monster) > 0) {
        character->stat->currentLifePoint -= getMonsterStrength(monster) - character->stat->defence;
        return 1;
    }

    return 0;
}

