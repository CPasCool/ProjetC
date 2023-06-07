//
// Created by benfa on 31/05/2023.
//

#ifndef PROJETC_WINDOWS_H
#define PROJETC_WINDOWS_H

#include "../../SDL2/SDL.h"

SDL_Window* createWindow();
SDL_Renderer *createRenderer(SDL_Window *window);
int setIcon(SDL_Window* window);
#endif //PROJETC_WINDOWS_H
