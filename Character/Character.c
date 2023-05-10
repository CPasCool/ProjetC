//
// Created by benfa on 10/05/2023.
//

#include "Character.h"
# include <stdlib.h>



// initializers
Character* createCharacter() {
    Character* player = malloc(sizeof (Character));
    player -> coo = malloc(sizeof (coordonees));
    player -> stat = createStats();
    return player;
};

stats* createStats(){
    stats* stat = malloc(sizeof (stats));
    stat->attack = 5;
    stat->maxLifePoint=10;
    stat->keys=0;
    stat->currentLifePoint = stat->maxLifePoint;
    stat->defence = 5;
    return stat;
}


// setters
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