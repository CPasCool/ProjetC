#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../include/src/Monster.h"


monster* createNewMonster(char* name, int hp, int strength, int shield, char type, coordonees* coo){
    monster *newMonster = (monster*) malloc(sizeof(struct Monster));
    newMonster->name = name;
    newMonster->hp = hp;
    newMonster->strength = strength;
    newMonster->shield = shield;
    newMonster->type = type;
    newMonster->MonsterCoordonnees = coo;
    return newMonster;
}

char* generateRandomName() {
    const char* prefixes[] = {
            "Dark",
            "Shadow",
            "Fire",
            "Ice",
            "Thunder",
    };
    const char* suffixes[] = {
            "fang",
            "claw",
            "scale",
            "wing",
            "beast",
    };

    const int numPrefixes = sizeof(prefixes) / sizeof(prefixes[0]);
    const int numSuffixes = sizeof(suffixes) / sizeof(suffixes[0]);

    char* name = (char*)malloc(sizeof(char) * 20);

    strcpy(name, prefixes[rand() % numPrefixes]);
    strcat(name, " ");
    strcat(name, suffixes[rand() % numSuffixes]);

    return name;
}

monster* setMonster(monster* monster, char* name, int hp, int strength, int shield, coordonees *coo){
    monster->name = name;
    monster->hp = hp;
    monster->strength = strength;
    monster->shield = shield;
    monster->MonsterCoordonnees = coo;
    return monster;
}

monster* setMonsterCoordonees(monster* monster, coordonees *coo){
    monster->MonsterCoordonnees = coo;
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

char getMonsterType(monster* monster){
    return monster->type;
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

coordonees* getMonsterCoordonees(monster* monster){
    return monster->MonsterCoordonnees;
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
    printf("The monster shield is %d\n", getMonsterShield(monster));
}

void printMonsterCoordonees(monster* monster){
    printf("The monster coordonates are x: %d, y: %d\n", getMonsterCoordonees(monster)->x, getMonsterCoordonees(monster)->y);
}

void printMonsterType(monster* monster){
    printf("The monster type is %c\n", getMonsterType(monster));
}

void printMonsterStats(monster* monster){
    printMonsterName(monster);
    printMonsterHealth(monster);
    printMonsterShield(monster);
    printMonsterStrength(monster);
    printMonsterType(monster);
    printMonsterCoordonees(monster);
}