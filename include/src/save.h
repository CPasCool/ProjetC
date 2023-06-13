#include "Character.h"
#include "Monster.h"
#include "Board.h"
#include "Levels.h"


#ifndef PROJETC_SAVE_H
#define PROJETC_SAVE_H

int createSave(levelChain *levelChain);

levelChain *getLevelBoardSave(levelChain *levelChain);

levelChain *getCharacterSave(levelChain *levelChain);

levelChain *getCompliteSave(levelChain *levelChain);

#endif //PROJETC_SAVE_H
