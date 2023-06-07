

#include <stdio.h>
#include "../../include/src/Windows.h"


SDL_Window *init() {
    SDL_Window *window = NULL;
    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        return NULL;
    }
    window = SDL_CreateWindow("Roguelike", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              500, 500, SDL_WINDOW_SHOWN);
    if (NULL == window)
        fprintf(stderr, "Erreur de creation de la fenetre : %s\n", SDL_GetError());
    else
        printf("The windows has been created");
    return window;
}

SDL_Renderer *createRenderer(SDL_Window *window) {
    SDL_Renderer *r = NULL;
    r = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == r) {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
    } else {
        printf("Renderer has been created");
    }

    return r;
}