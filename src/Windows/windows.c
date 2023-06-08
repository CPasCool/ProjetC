

#include <stdio.h>
#include <stdbool.h>
#include "../../include/src/windows.h"

typedef struct button_{
    SDL_Texture* texture;
    bool isPressed;
}button;

SDL_Window *createWindow() {
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
        printf("The windows has been created\n");
    return window;
}

SDL_Renderer *createRenderer(SDL_Window *window) {
    SDL_Renderer *r = NULL;
    r = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == r) {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s\n", SDL_GetError());
    } else {
        printf("Renderer has been created\n");
    }

    return r;
}

int setIcon(SDL_Window* window){
    SDL_Surface *icon = SDL_LoadBMP("assets/Images\\Icon.bmp");
    if (icon == NULL){
        printf("error file not fund\n");
        return 1;
    }
    SDL_SetWindowIcon(window,icon);
    return 0;
}

int setBackgroundToWhite(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    return 0;
}

/**
 * load bmp image and return the texture
 * @param renderer
 * @param pathToFile
 * @return
 */
SDL_Texture* loadImage(SDL_Renderer* renderer, char* pathToFile){
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;
    image = SDL_LoadBMP(pathToFile);
    if (image == NULL){
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer,image);
    SDL_FreeSurface(image);
    if (texture == NULL){
        fprintf(stderr, "Erreur SDL_CreateTextireFromSurface : %s", SDL_GetError());
        return NULL;
    }
    return texture;
}