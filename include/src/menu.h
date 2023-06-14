#ifndef PROJETC_MENU_H
#define PROJETC_MENU_H

#include "../../SDL2/SDL_render.h"
#include "../../SDL2/SDL_ttf.h"

typedef struct choice choiceMenu;


void setChoice(choiceMenu *choiceMenu, int choice);

choiceMenu *createChoiceMenu();

int getChoice(choiceMenu *);


void displayMenu(choiceMenu *choice,SDL_Renderer* renderer, SDL_Texture* background,  TTF_Font * font );

void newGame();
void displayMenuNewGame(int);
void displayMenuIngame(int);
void inGame();

#endif
