#ifndef PROJETC_MENU_H
#define PROJETC_MENU_H

typedef struct choice choiceMenu;


void setChoice(choiceMenu *choiceMenu, int choice);

choiceMenu *createChoiceMenu();

int getChoice(choiceMenu *);

void displayMenu(choiceMenu*);

void menu();
void newGame();
void displayMenuNewGame(int);
void displayMenuIngame(int);
void inGame();

int pauseMenu();
#endif
