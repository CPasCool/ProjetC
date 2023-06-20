#ifndef PROJETC_MENU_H
#define PROJETC_MENU_H

#include "menuPause.h"
#include "Keyboard.h"
#include "../../SDL2/SDL_render.h"
#include "../../SDL2/SDL_ttf.h"

typedef struct choice choiceMenu;


void setChoice(choiceMenu *choiceMenu, int choice, SDL_Renderer *renderer, TTF_Font *font);

choiceMenu *createChoiceMenu();

void displayNewGame(SDL_Renderer *renderer, TTF_Font *font);

int getChoice(choiceMenu *);


void displayMenu(choiceMenu *choice, SDL_Renderer *renderer, TTF_Font *font);

void displayCredit(SDL_Renderer *renderer, TTF_Font *font);

void displayCreditMenu(SDL_Renderer *renderer, TTF_Font *font);

void displayChoiceGameQuit(SDL_Renderer *renderer, TTF_Font *font);


void displayMenuNewGame(int choice, SDL_Renderer *renderer, TTF_Font *font);

void displaySave(SDL_Renderer *renderer, TTF_Font *font);

int useNewGameMenu(SDL_Renderer *renderer, TTF_Font *font, SDL_Texture* background);

int inCredit();

#endif
