//
// Created by benfa on 10/05/2023.
//

#include "Character.h"


typedef struct coordonees_{
    int x;
    int y;
} coordonees;

typedef struct statistics_{
    int maxLifePoint;
    int currentLifePoint;
    int attack;
    int defence;
    int keys;
}stats;

typedef struct character_{
    coordonees coo;
    char* name;
    stats stat;
} Character;

