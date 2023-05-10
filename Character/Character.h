//
// Created by benfa on 10/05/2023.
//

#ifndef PROJETC_CHARACTER_H
#define PROJETC_CHARACTER_H
typedef struct character_ Character;
typedef struct statistics_ stats;
typedef struct coordonees_ coordonees;

// functions
// initializer
Character* createCharacter();
stats* createStats();
// Setter
int setLifePoint(Character* character, int newLifePoint);
int setKeys(Character* character, int keyNumber);
int setAttack(Character* character, int newAttack);
int setDefence(Character* character, int newDefence);
int setName(Character* character, char* name);
int changeCoordonnes(Character* character, int x, int y);
int setMaximumLifePoint(Character* character , int newMax);

#endif //PROJETC_CHARACTER_H
