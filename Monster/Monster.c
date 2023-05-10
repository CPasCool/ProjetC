#include <stdlib.h>
#include "Monster.h"
typedef struct monster_{
    char name;
    int hp;
    int strenght;
    int shield;
}monster;

monster* createNewMonster(char name, int hp, int strenght, int shield){
    monster *newMonster = (monster*) malloc(sizeof(struct monster_));
    newMonster->name = name;
    newMonster->hp = hp;
    newMonster->strenght = strenght;
    newMonster->shield = shield;
    return newMonster;
}
