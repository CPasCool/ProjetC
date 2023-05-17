//
// Created by benfa on 10/05/2023.
//

#include "Character.h"
# include <stdlib.h>
#include "stdio.h"


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
    stat->attack = 5;
    stat->maxLifePoint = 10;
    stat->keys = 0;
    stat->currentLifePoint = stat->maxLifePoint;
    stat->defence = 5;
    return stat;
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

int setAttack(Character *character, int newAttack) {
    character->stat->attack = newAttack;
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

int printAttack(Stats *stat) {
    printf("Attack : %d\n", stat->attack);
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
    printAttack(character->stat);
    printDefence(character->stat);
    return 0;
}

/**
 * move the character to the up in board
 * @param character : character to move
 * @return
 */
int moveUp(Character *character){
    // TODO : verifier les collisions
    character->coo->y +=1;
    return 0;
}
/**
 * move the character to the down in board
 * @param character : character to move
 * @return
 */
int moveDown(Character *character){
    // TODO : verifier les collisions
    character->coo->y -= 1;
    return 0;
}

/**
 * move the character to the right in board
 * @param character : character to move
 * @return
 */
int moveRight(Character *character){
    // TODO : verifier les collisions
    character->coo->x +=1;
    return 0;
};

/**
 * move the character to the left in board
 * @param character : character to move
 * @return
 */
int moveLeft(Character *character){
    // TODO : verifier les collisions

    character->coo->x +=1;
    return 0;
};

