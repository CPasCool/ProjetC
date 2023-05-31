#include <stdlib.h>
#include <stdio.h>
#include "../../include/src/Monster.h"

typedef struct Monster{
    char* name;
    int hp;
    int strength;
    int shield;
}monster;

monster* createNewMonster(char* name, int hp, int strength, int shield){
    monster *newMonster = (monster*) malloc(sizeof(struct Monster));
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

monster* setMonsterName(monster* monster, char* name){
    monster->name = name;
    return monster;
}

monster* setMonsterHealth(monster* monster, int hp){
    monster->hp = hp;
    return monster;
}

monster* setMonsterStrength(monster* monster, int str){
    monster->strength = str;
    return monster;
}

monster* setMonsterShield(monster* monster, int shield){
    monster->shield = shield;
    return monster;
}

char* getMonsterName(monster* monster){
    return monster->name;
}

int getMonsterHealth(monster* monster){
    return monster->hp;
}

int getMonsterStrength(monster* monster){
    return monster->strength;
}

int getMonsterShield(monster* monster){
    return monster->shield;
}

void printMonsterName(monster* monster){
    printf("The monster name is %s\n", getMonsterName(monster));
}

void printMonsterHealth(monster* monster){
    printf("The monster health is %d\n", getMonsterHealth(monster));
}

void printMonsterStrength(monster* monster){
    printf("The monster strength is %d\n", getMonsterStrength(monster));
}

void printMonsterShield(monster* monster){
    printf("Th monster shield is %d\n", getMonsterShield(monster));
}

void printAllMonster(monster* monster){
    printMonsterName(monster);
    printMonsterHealth(monster);
    printMonsterShield(monster);
    printMonsterStrength(monster);
}