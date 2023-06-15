#include <stdlib.h>
#include <stdbool.h>
#include "../../include/src/menu.h"


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
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Play", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Credits", textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quit", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_RenderFillRect(renderer, &textRect);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
}

//affichage du menu avant de lancer la partie
void displayNewGame(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer,
                                                            TTF_RenderText_Solid(font, "New Game", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Load a game", textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quit", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_RenderFillRect(renderer, &textRect);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
}


void displaySave(SDL_Renderer *renderer, TTF_Font *font) {

    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer,
                                                            TTF_RenderText_Solid(font, "New Game", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Load a game", textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quit", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_RenderFillRect(renderer, &textRect2);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
}

void displayChoiceGameQuit(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer,
                                                            TTF_RenderText_Solid(font, "New Game", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Load a game", textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quit", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_RenderFillRect(renderer, &textRect3);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
}


void displayCreditMenu(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Play", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Credits", textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quit", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_RenderFillRect(renderer, &textRect2);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
}

void displayExitMenu(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Play", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Credits", textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quit", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_RenderFillRect(renderer, &textRect3);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
}

void displayCredit(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer,
                                                            TTF_RenderText_Solid(font, "Game developed by", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Korentin Kolaczek",
                                                                                            textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Benoit Fardoux", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_Texture *textTexture4 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Edouard Hoest", textColor));
    SDL_Rect textRect4 = {250, 500, 300, 40};
    SDL_Texture *textTexture5 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Baptiste Lemattre",
                                                                                            textColor));
    SDL_Rect textRect5 = {250, 600, 300, 40};
    SDL_Texture *textTexture6 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quit", textColor));
    SDL_Rect textRect6 = {250, 700, 300, 40};

    SDL_RenderFillRect(renderer, &textRect6);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_RenderCopy(renderer, textTexture4, NULL, &textRect4);
    SDL_RenderCopy(renderer, textTexture5, NULL, &textRect5);
    SDL_RenderCopy(renderer, textTexture6, NULL, &textRect6);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
    SDL_DestroyTexture(textTexture4);
    SDL_DestroyTexture(textTexture5);
    SDL_DestroyTexture(textTexture6);
}

void displayMenu(choiceMenu *choice, SDL_Renderer *renderer, TTF_Font *font) {
    if (getChoice(choice) == 1) {
        displayPlayMenu(renderer, font);
    } else if (getChoice(choice) == 2) {
        displayCreditMenu(renderer, font);
    } else {
        displayExitMenu(renderer, font);
    }
}

void displayMenuNewGame(int choice, SDL_Renderer *renderer, TTF_Font *font) {
    if (choice == 1) {
        displayNewGame(renderer, font);
        SDL_RenderPresent(renderer);
    } else if (choice == 2) {
        displaySave(renderer, font);
        SDL_RenderPresent(renderer);
    } else {
        displayChoiceGameQuit(renderer, font);
        SDL_RenderPresent(renderer);
    }
}

int useNewGameMenu(SDL_Renderer *renderer, TTF_Font *font, SDL_Texture *background) {
    int choice = 1;
    displayMenuNewGame(choice, renderer, font);
    SDL_Event event;
    while (1) {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT)
            return -1;

        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_Z:
                case SDL_SCANCODE_UP:
                    if (choice != 1)
                        choice -= 1;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    if (choice != 3)
                        choice += 1;
                    break;
                case SDL_SCANCODE_RETURN:
                case SDL_SCANCODE_E:
                    return choice;
                default:
                    break;
            }
            SDL_RenderCopy(renderer, background, NULL, NULL);
            displayMenuNewGame(choice, renderer, font);
            SDL_RenderPresent(renderer);
        }
    }
}

/**
 *
 */
int inCredit() {
    while (true) {
        SDL_Event event;
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT)
            return 1;
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_E:
                case SDL_SCANCODE_RETURN:
                    return 0;
                default:
                    break;
            }
        }
    }
}