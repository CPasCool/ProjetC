//
// Created by benfa on 10/05/2023.
//

#include <stdio.h>
#include "TestCharacter.h"


int testCharacter() {
    Character *chara = createCharacter("testUser");
    int result = testCharacterName(chara, "testUser");

    changeCoordonnes(chara, 5, 5);
    result += testCoordonnes(chara, 5, 5);

    setMaximumLifePoint(chara, 10);
    result += testMaximumLife(chara, 10);

    setDefence(chara, 10);
    result += testDefence(chara, 10);

    setAttack(chara, 10);
    result += testAttack(chara, 10);

    setKeys(chara, 5);
    result += testKeysNumber(chara, 5);

    setLifePoint(chara, 10);
    result += testLifePoint(chara,10);

    if (result != 0) {
        perror("The process encouter an error please check log");
        return 1;
    }
    //printAll(chara);
    return 0;
}

int testDefence(Character *pCharacter, int i) {
    if (pCharacter->stat->defence != i) {
        perror("The defence have not correctly set");
        return 1;
    }
    return 0;
}

int testKeysNumber(Character *pCharacter, int i) {
    if (pCharacter->stat->keys != i) {
        perror("The key number have not correctly set");
        return 1;
    }
    return 0;
}

int testLifePoint(Character *pCharacter, int i) {
    if (pCharacter->stat->defence != i) {
        perror("The life point number have not correctly set");
        return 1;
    }
    return 0;
}

int testAttack(Character *pCharacter, int i) {
    if (pCharacter->stat->defence != i) {
        perror("The attack have not correctly set");
        return 1;
    }
    return 0;
}

int testCharacterName(Character *player, const char *name) {
    if (player->name != name) {
        perror("Name is not equals to");
        perror(name);
        return 1;
    }
    return 0;
}

int testCoordonnes(Character *player, int x, int y) {
    if (player->coo->x != x || player->coo->y != y) {
        perror("La fonction \" changeCoordonnes ne fonctionne pas \"");
        return 1;
    }
    return 0;
}

int testMaximumLife(Character *player, int maxLife) {
    if (player->stat->maxLifePoint != maxLife) {
        perror("The maxLife have not correctly set");
        return 1;
    }
    return 0;
}

