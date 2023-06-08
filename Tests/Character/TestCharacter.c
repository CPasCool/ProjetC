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

    setStrength(chara, 10);
    result += testAttack(chara, 10);

    addKeys(chara);
    result += testKeysNumber(chara, 1);

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
    if (getDefence(pCharacter) != i) {
        perror("The defence have not correctly set");
        return 1;
    }
    return 0;
}

int testKeysNumber(Character *pCharacter, int i) {
    if (getKeys(pCharacter) != i) {
        perror("The key number have not correctly set");
        return 1;
    }
    return 0;
}

int testLifePoint(Character *pCharacter, int i) {
    if (getLifePoint(pCharacter) != i) {
        perror("The life point number have not correctly set");
        return 1;
    }
    return 0;
}

int testAttack(Character *pCharacter, int i) {
    if (getStrength(pCharacter)!= i) {
        perror("The strength have not correctly set");
        return 1;
    }
    return 0;
}

int testCharacterName(Character *player, const char *name) {
    if (getName(player) != name) {
        perror("Name is not equals to");
        perror(name);
        return 1;
    }
    return 0;
}

int testCoordonnes(Character *player, int x, int y) {
    if (getCharaX(player) != x || getCharaY(player) != y) {
        perror("La fonction \" changeCoordonnes ne fonctionne pas \"");
        return 1;
    }
    return 0;
}

int testMaximumLife(Character *player, int maxLife) {
    if (getMaximumLifePoint(player) != maxLife) {
        perror("The maxLife have not correctly set");
        return 1;
    }
    return 0;
}

