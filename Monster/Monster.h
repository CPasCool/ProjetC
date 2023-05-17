#ifndef PROJETC_MONSTER_H
#define PROJETC_MONSTER_H

typedef struct Monster monster;
monster* createNewMonster(char* name, int hp, int strenght, int shield);
monster* setMonster(monster* monster, char* name, int hp, int strength, int shield);
monster* setMonsterName(monster* monster, char* name);
monster* setMonsterHealth(monster* monster, int hp);
monster* setMonsterStrength(monster* monster, int str);
monster* setMonsterShield(monster* monster, int shield);
char* getMonsterName(monster* monster);
int getMonsterHealth(monster* monster);
int getMonsterStrength(monster* monster);
int getMonsterShield(monster* monster);
void printMonsterName(monster* monster);
void printMonsterHealth(monster* monster);
void printMonsterStrength(monster* monster);
void printMonsterShield(monster* monster);
void printAllMonster(monster* monster);

#endif //PROJETC_MONSTER_H