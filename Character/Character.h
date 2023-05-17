//
// Created by benfa on 10/05/2023.
//

#ifndef PROJETC_CHARACTER_H
#define PROJETC_CHARACTER_H
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
} Stats;

typedef struct character_ {
    coordonees* coo;
    char *name;
    Stats* stat;
} Character;

// functions
// initializer
Character* createCharacter(char* name);
Stats* createStats();
// Setter
int setLifePoint(Character* character, int newLifePoint);
int setKeys(Character* character, int keyNumber);
int setAttack(Character* character, int newAttack);
int setDefence(Character* character, int newDefence);
int setName(Character* character, char* name);
int changeCoordonnes(Character* character, int x, int y);
int setMaximumLifePoint(Character* character , int newMax);
int printLifePoint(Stats* stat);
int printDefence(Stats *stat);
int printAttack(Stats *stat);
int printKeysNumber(Stats *stats);
int printAll(Character*);
#endif //PROJETC_CHARACTER_H
