#include "../../include/src/menu.h"
#include "../../include/src/menuPause.h"
#include "../../include/src/Keyboard.h"
#include "../../include/src/Move.h"
#include "../../include/src/Levels.h"
#include "../../include/src/Board.h"
#include "../../include/src/CreateBoard.h"
#include "../../include/src/Dijkstra.h"


#ifndef PROJETC_GAME_H
#define PROJETC_GAME_H

void play(levelChain *levelChain);

int LaunchGame();

#endif //PROJETC_GAME_H