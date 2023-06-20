#include "../../include/src/menu.h"
#include "../../include/src/menuPause.h"
#include "../../include/src/Keyboard.h"
#include "../../include/src/Move.h"
#include "../../include/src/Levels.h"
#include "../../include/src/Board.h"
#include "../../SDL2/SDL_render.h"
#include "../../SDL2/SDL_ttf.h"
#include "../../include/src/CreateBoard.h"
#include "../../include/src/Dijkstra.h"


#ifndef PROJETC_GAME_H
#define PROJETC_GAME_H

void displayBoard(char **board, SDL_Renderer *renderer, SDL_Texture *tile,
                  SDL_Texture *Character2);
int play(levelChain *levelChain ,SDL_Renderer *renderer,SDL_Texture *tile, SDL_Texture *characterTexture );


int LaunchGame(SDL_Renderer *renderer, SDL_Texture *tile, SDL_Texture *characterTexture, TTF_Font *font,SDL_Texture *background);

#endif //PROJETC_GAME_H