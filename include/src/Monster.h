#include "Coordonees.h"
#ifndef PROJETC_MONSTER_H
#define PROJETC_MONSTER_H

typedef struct Monster{
    char* name;
    int hp;
    int strength;
    int shield;
    char type;
    coordonees *MonsterCoordonnees;
} monster;

monster* createNewMonster(char* name, int hp, int strenght, int shield, char type, coordonees *coo);
char* generateRandomName();
monster* setMonster(monster* monster, char* name, int hp, int strength, int shield, coordonees *coo);
monster* setMonsterName(monster* monster, char* name);
monster* setMonsterHealth(monster* monster, int hp);
monster* setMonsterStrength(monster* monster, int str);
monster* setMonsterShield(monster* monster, int shield);
monster* setMonsterCoordonees(monster* monster, coordonees *coo);
char* getMonsterName(monster* monster);
int getMonsterHealth(monster* monster);
int getMonsterStrength(monster* monster);
int getMonsterShield(monster* monster);
char getMonsterType(monster* monster);
coordonees* getMonsterCoordonees(monster* monster);
void printMonsterName(monster* monster);
void printMonsterHealth(monster* monster);
void printMonsterStrength(monster* monster);
void printMonsterShield(monster* monster);
void printMonsterCoordonees(monster* monster);
void printMonsterStats(monster* monster);
void printMonsterType(monster* monster);

#endif //PROJETC_MONSTER_H