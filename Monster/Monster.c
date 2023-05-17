#include <stdlib.h>
#include "Monster.h"

typedef struct monster_{
    char* name;
    int hp;
    int strength;
    int shield;
}monster;

monster* createNewMonster(char* name, int hp, int strength, int shield){
    monster *newMonster = (monster*) malloc(sizeof(struct monster_));
    newMonster->name = name;
    newMonster->hp = hp;
    newMonster->strength = strength;
    newMonster->shield = shield;
    return newMonster;
}

monster* setMonster(monster* monster, char* name, int hp, int strength, int shield){
    monster->name = name;
    monster->hp = hp;
    monster->strength = strength;
    monster->shield = shield;
    return monster;
}

char* getName(monster* monster){
    return monster->name;
}

int getHealth(monster* monster){
    return monster->hp;
}

int getStrength(monster* monster){
    return monster->strength;
}

int getShield(monster* monster){
    return monster->shield;
}