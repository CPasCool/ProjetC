#include "../../include/src/menu.h"
#include "../../include/src/menuPause.h"
#include "../../include/src/Keyboard.h"
#include "../../include/src/Move.h"
#include "../../include/src/Levels.h"
#include "../../include/src/Board.h"
#include "../../SDL2/SDL_render.h"
#include "../../SDL2/SDL_ttf.h"

#ifndef PROJETC_GAME_H
#define PROJETC_GAME_H

void displayBoard(char **board, SDL_Renderer *renderer, SDL_Texture *tile,
                  SDL_Texture *Character2);
void play(SDL_Renderer *renderer,SDL_Texture *tile, SDL_Texture *characterTexture, SDL_Window * window );


int LaunchGame(SDL_Renderer *renderer, SDL_Texture *background, SDL_Texture *tile, SDL_Texture *characterTexture,
               TTF_Font *font, SDL_Window *window);

#endif //PROJETC_GAME_H