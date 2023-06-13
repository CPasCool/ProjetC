#include "../../include/src/Character.h"
#include <stdlib.h>
#include "stdio.h"


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
    player->coo = createCoordonne(14, 14);
    player->stat = createStats();
    player->name = name;
    return player;
}

Stats *createStats() {
    Stats *stat = malloc(sizeof(Stats));
    stat->strength = 2;
    stat->maxLifePoint = 10;
    stat->keys = 0;
    stat->currentLifePoint = 10;
    stat->defence = 1;
    return stat;
}

// getters

int getLifePoint(Character *character) {
    return character->stat->currentLifePoint;
}

int getMaximumLifePoint(Character *character) {
    return character->stat->maxLifePoint;
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

int getCharaX(Character *character) {
    return character->coo->x;
}

int getCharaY(Character *character) {
    return character->coo->y;
}

coordonees *getCoo(Character *character) {
    return character->coo;
}

// setters
int setLifePoint(Character *character, int newLifePoint) {
    character->stat->currentLifePoint = newLifePoint;
    return 0;
}

int setKeys(Character *character,int keys)
{
    character->stat->keys = keys;
}

int addKeys(Character *character) {
    character->stat->keys += 1;
    return 0;
}

int setMaxKeys(Character *character) {
    character->stat->keys = 999;
    return 0;
}

int removeKeys(Character *character) {
    character->stat->keys -= 1;
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

int setMaximumLifePoint(Character *character, int addedMax) {
    character->stat->maxLifePoint = character->stat->maxLifePoint + addedMax;
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
    printf("x = %d, y = %d\n", getCharaX(character), getCharaY(character));
    return 0;
}
