//
// Created by benfa on 10/05/2023.
//

#include "Character.h"

typedef struct character_{
    int* coordonnes;
    char* name;
    int maxLifePoint;
    int currentLifePoint;
    int defence;
} Character;