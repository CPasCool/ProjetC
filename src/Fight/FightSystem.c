#include "../../include/src/FightSystem.h"
#include "stdio.h"


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

