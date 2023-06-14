#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   
#include "../../include/src/menu.h"
#include "../../SDL2/SDL_render.h"
#include "../../SDL2/SDL_ttf.h"

struct choice {
    int choice;
};

void setChoice(choiceMenu *choiceMenu, int choice, SDL_Renderer *renderer, TTF_Font *font) {
    choiceMenu->choice = choice;
    displayMenu(choiceMenu, renderer, font);
}


int getChoice(choiceMenu *choiceMenu) {
    return choiceMenu->choice;
}

choiceMenu *createChoiceMenu() {
    choiceMenu *choiceMenuTmp = malloc(sizeof(choiceMenu));
    choiceMenuTmp->choice = 1;
    return choiceMenuTmp;
}
/**
 * first screen of the main menu interface
 * @param renderer : renderer of the game
 * @param font : font to write the choices
 */
void displayPlayMenu(SDL_Renderer *renderer, TTF_Font *font) {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  # 1 -   Play           #  #\n"
            "#  ########################  #\n"
            "#   2 -    Credits           #\n"
            "#   3 -    Quit              #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

//affichage du menu avant de lancer la partie
void displayNewGame(SDL_Renderer *renderer, TTF_Font *font) {

    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  # 1 -   New Game       #  #\n"
            "#  ########################  #\n"
            "#   2 -    Load a save       #\n"
            "#   3 -    Quit              #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Good luck :)        #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void displaySave() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   New Game          #\n"
            "#  ########################  #\n"
            "#  # 2 -   Load a save    #  #\n"
            "#  ########################  #\n"
            "#   3 -    Quit              #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Good luck :)        #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void displayChoiceGameQuit() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   New Game          #\n"
            "#    2 -   Load a save       #\n"
            "#  ########################  #\n"
            "#  # 3 -    Quit          #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Good luck :)        #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}



void displayCreditMenu() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   Play              #\n"
            "#  ########################  #\n"
            "#  # 2 -   Credits       #  #\n"
            "#  ########################  #\n"
            "#   3 -    Quit              #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void displayExitMenu() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   Play              #\n"
            "#    2 -   Credits           #\n"
            "#  ########################  #\n"
            "#  # 3 -   Quit           #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
}

void displayCredit() {
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#      Game developed by     #\n"
            "#      Korentin Kolaczek     #\n"
            "#       Benoit Fardoux       #\n"
            "#        Edouard Hoest       #\n"
            "#      Baptiste Lemattre     #\n"
            "#                            #\n"
            "#                            #\n"
            "#  ########################  #\n"
            "#  #  1 - Back to menu    #  #\n"
            "#  ########################  #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n");
}

void displayMenu(choiceMenu *choice, SDL_Renderer *renderer, TTF_Font *font) {
    if (getChoice(choice) == 1) {
        displayPlayMenu(renderer,font);
    } else if (getChoice(choice) == 2) {
        displayCreditMenu();
    } else {
        displayExitMenu();
    }
}

void displayMenuNewGame(int choice, SDL_Renderer *renderer,TTF_Font *font) {
    if (choice == 1) {
        displayNewGame(renderer, font);
    } else if (choice == 2) {
        displaySave();
    } else {
        displayChoiceGameQuit();
    }
}

int useNewGameMenu(SDL_Renderer *renderer, TTF_Font *font) {
    int choice = 1;
    char keyEnter;
    displayMenuNewGame(choice,renderer,font);
    while (1) {
        keyEnter = catchInput();
        if (keyEnter == 'z' && choice != 1) {
            choice -= 1;
        } else if (keyEnter == 's' && choice !=3) {
            choice += 1;
        } else if (keyEnter == 'e'){
            return choice;
        }
        displayMenuNewGame(choice,renderer,font);
    }
}
