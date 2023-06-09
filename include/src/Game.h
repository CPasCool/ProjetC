#include "../../include/src/menu.h"
#include "../../include/src/menuPause.h"
#include "../../include/src/Keyboard.h"
#include "../../include/src/Move.h"
#include "../../include/src/Levels.h"
#include "../../include/src/Board.h"
#include "../../SDL2/SDL_render.h"

#ifndef PROJETC_GAME_H
#define PROJETC_GAME_H
void displayBoard(char **board, SDL_Renderer *renderer,SDL_Texture *tile,SDL_Texture *Character1, SDL_Texture *Character2);
void play(SDL_Renderer *renderer,SDL_Texture *tile,SDL_Texture *character1, SDL_Texture *character2 );

int LaunchGame();

#endif //PROJETC_GAME_H