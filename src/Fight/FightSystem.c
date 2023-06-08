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
        setLifePoint(character, getLifePoint(character) - (getMonsterStrength(monster) - getDefence(character)));
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
int *getMonstersDistances(Character *character, monster **monstersTab, int nbMonsters) {
    int *distances = malloc(sizeof(int) * nbMonsters);
    if (nbMonsters == 0) {
        return distances;
    }
    for (int i = 0; i < nbMonsters; i++) {
        if (monstersTab[i]->hp > 0) {
            distances[i] = abs(getCharaY(character) - monstersTab[i]->MonsterCoordonnees->y) +
                           abs(getCharaX(character) - monstersTab[i]->MonsterCoordonnees->x);
        } else {
            distances[i] = 999999999;
        }
    }
    return distances;
}

monster *findClosestMonster(monster **monstersTab, const int *distancesTab, int nbMonsters, int aliveMonsters) {
    int val_min = 0;
    if (nbMonsters == 0 || aliveMonsters == 0) {
        return createNewMonster("No monsters in this level", -1, -1, -1, 'Z', createCoordonne(-1, -1));
    }
    for (int i = 0; i < nbMonsters; i++) {
        if (distancesTab[i] < distancesTab[val_min] && monstersTab[i]->hp > 0) {
            val_min = i;
        }
    }
    return monstersTab[val_min];
}
