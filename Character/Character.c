//
// Created by benfa on 10/05/2023.
//

#include "Character.h"
# include <stdlib.h>

typedef struct coordonees_ {
    int x;
    int y;
} coordonees;

typedef struct statistics_  {
    int maxLifePoint;
    int currentLifePoint;
    int attack;
    int defence;
    int keys;
} stats;

typedef struct character_ {
    coordonees* coo;
    char *name;
    stats* stat;
} Character;


Character* createCharacter() {
    Character* player = malloc(sizeof (Character));
    player -> coo = malloc(sizeof (coordonees));
    player -> stat = malloc(sizeof (stats));
    return player;
};

int setLifePoint(Character* character, int newLifePoint){
    character->stat->currentLifePoint = newLifePoint;
    return 0;
}

int setKeys(Character* character, int keyNumber){
    character->stat->keys = keyNumber;
    return 0;
}

int setAttack(Character* character, int newAttack){
    character->stat->attack = newAttack;
    return 0;
}

int setDefence(Character* character, int newDefence){
    character->stat->attack = newDefence;
    return 0;
}

int setName(Character* character, char* name){
    character->name = name;
    return 0;
}

int changeCoordonnes(Character* character, int x, int y){
       character->coo->x = x;
       character->coo->y = y;
       return 0;
};

int setMaximumLifePoint(Character* character , int newMax){
    character->stat->maxLifePoint = newMax;
    return 0;
}