#include <stdio.h>
#include "MonstersTests.h"



int testMonster() {
    coordonees * coo = createCoordonne(5,5);
    monster *testedMonster = createNewMonster("blibli", 5, 4, 5, 'A', coo);
    int result = testName(testedMonster, "blibli");

    setMonsterShield(testedMonster, 10);
    result += testShield(testedMonster, 10);

    setMonsterHealth(testedMonster, 10);
    result += testHealth(testedMonster, 10);

    setMonsterStrength(testedMonster, 5);
    result += testStrength(testedMonster, 5);

    if (result != 0) {
        perror("The process encouter an error please check log");
        return 1;
    }
    //printMonsterStats(testedMonster);
    return 0;
}

int testName(monster *monster, const char *name) {
    if (getMonsterName(monster) != name) {
        perror("Name is not equals to");
        perror(name);
        return 1;
    }
    return 0;
}

int testShield(monster *monster, int i) {
    if (getMonsterShield(monster) != i) {
        perror("The shield have not correctly set");
        return 1;
    }
    return 0;
}

int testHealth(monster *monster, int i) {
    if (getMonsterHealth(monster) != i) {
        perror("The Health number have not correctly set");
        return 1;
    }
    return 0;
}

int testStrength(monster *monster, int i) {
    if (getMonsterStrength(monster) != i) {
        perror("The strength number have not correctly set");
        return 1;
    }
    return 0;
}
