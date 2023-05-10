#include <stdio.h>
#include "Monster\Monster.h"
typedef struct monster_{
    char name;
    int hp;
    int strenght;
    int shield;
}monster;

monster createNewMonster(char name, int hp, int strenght, int shield)
{
    monster newMonster = malloc(sizeof(newMonster));
    newMonster->name = name;
    newMonster->hp = hp;
    newMonster->strenght = strenght;
    newMonster->shield = shield;
    return newMonster;
}
