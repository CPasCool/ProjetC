//
// Created by benfa on 31/05/2023.
//

#ifndef PROJETC_WINDOWS_H
#define PROJETC_WINDOWS_H

#include "../../SDL2/SDL.h"
typedef struct button_ button;
SDL_Window* createWindow();
SDL_Renderer *createRenderer(SDL_Window *window);
int setIcon(SDL_Window* window);
int setBackgroundToWhite(SDL_Renderer* renderer);
SDL_Texture* loadImage(SDL_Renderer* renderer, char* pathToFile);

#endif //PROJETC_WINDOWS_H