#include <stdio.h>
#include "Monster\Monster.h"
struct monster{
    char name;
    int hp;
    int strenght;
    int shield;
};

PtrMonster createNewMonster(char name, int hp, int strenght, int shield)
{
    PtrMonster newMonster = malloc(sizeof(newMonster));
    newMonster->name = name;
    newMonster->hp = hp;
    newMonster->strenght = strenght;
    newMonster->shield = shield;
    return newMonster;
}
