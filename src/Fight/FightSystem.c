//
// Created by benfa on 24/05/2023.
//

#include "../../include/src/FightSystem.h"
#include "stdio.h"
#include <stdlib.h>


/**
 * fight with target monster
 * @param character : character of the player
 * @param monster : target monster to fight
 * @return
 */
int fightWithMonster(Character *character, monster *monster) {
    printf("FIGHT\n");
    printMonsterStats(monster);
    printAll(character);
    // attribue degat au monstre
    if (getStrength(character) - getMonsterShield(monster) > 0) {
        setMonsterHealth(monster, getMonsterHealth(monster) - (getStrength(character) - getMonsterShield(monster)));
    } else {
        setMonsterHealth(monster, getMonsterHealth(monster) - 1);
    }

    if (getMonsterHealth(monster) > 0) {
        setLifePoint(character,getLifePoint(character) - (getMonsterStrength(monster) - getDefence(character)));
        return 1;
    }

    return 0;
}

/**
 * get the distances between player and all monsters
 * @param character : character of the player
 * @param monster : monsters we need distances
 * @return
 */
int *getMonstersDistances(Character *character, monster **monsterTab, int nbMonsters){
    int *distances = malloc(sizeof (int)*nbMonsters);
    for (int i=0; i<nbMonsters; i++){
        if(monsterTab[i]->hp>0){
            distances[i] = abs(getCharaY(character) - monsterTab[i]->MonsterCoordonnees->y) + abs(getCharaX(character) - monsterTab[i]->MonsterCoordonnees->x);
        }else{
            distances[i] = 999999999;
        }
    }
    return distances;
}

monster* findClosestMonster(monster **monstersTab, const int* distancesTab, int nbMonsters){
    int val_min;
    val_min = distancesTab[0];
    for (int i=0; i<nbMonsters; i++){
        if (distancesTab[i] < val_min){
            val_min = i;
        }
    }
    return monstersTab[val_min];
}
