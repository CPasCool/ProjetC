#ifndef PROJETC_MENU_H
#define PROJETC_MENU_H

#include "menuPause.h"
#include "Keyboard.h"

typedef struct choice choiceMenu;


void setChoice(choiceMenu *choiceMenu, int choice);

choiceMenu *createChoiceMenu();

int getChoice(choiceMenu *);

void displayMenu(choiceMenu *);

void displayCredit();

void displayChoiceGameQuit();

void displayMenuNewGame(int);

int useNewGameMenu();

#endif
