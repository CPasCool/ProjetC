//
// Created by benfa on 24/05/2023.
//

#include "FightSystem.h"


/**
 * fight with target monster
 * @param character : character of the player
 * @param monster : target monster to fight
 * @return
 */
int fightWithMonster(Character *character, monster *monster) {
    // attribue degat au monste
    if (getStrength(character) - getMonsterShield(monster) > 0) {
        setMonsterHealth(monster, getMonsterHealth(monster) - (character->stat->strength - getMonsterShield(monster)));
    } else {
        setMonsterHealth(monster, getMonsterHealth(monster) - 1);
    }

    if (getMonsterHealth(monster) > 0) {
        setMonsterHealth(getLifePoint(character) - getMonsterStrength(monster) - getDefence(character));
        return 1;
    }

    return 0;
}
