#include "Board.h"
#include "Character.h"
#include "Coordonees.h"
#include "FightSystem.h"
#include "Monster.h"

#ifndef PROJETC_MOVE_H
#define PROJETC_MOVE_H

int move(Character *character, char move, boardElements *board);

int *moveCharacter(Character *character, char move, char **board);

monster *getSpecificMonster(monster **monsterTab, coordonees *coordonees, int nbMonster);

#endif //PROJETC_MOVE_H
