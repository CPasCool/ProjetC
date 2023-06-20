#include <stdio.h>
#include "../../include/src/menuPause.h"



void printContinue(SDL_Renderer *renderer, TTF_Font *font) {
    printf(
            "\n"
            "##############################\n"
            "#         Pause Menu         #\n"
            "#                            #\n"
            "#    ####################    #\n"
            "#    #     Continue     #    #\n"
            "#    ####################    #\n"
            "#          Save Game         #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "##############################\n"
    );
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Continuer", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Sauvegarder", textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quitter", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_RenderFillRect(renderer, &textRect);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
}

void printSave(SDL_Renderer *renderer, TTF_Font *font) {
    printf(
            "\n"
            "##############################\n"
            "#         Pause Menu         #\n"
            "#                            #\n"
            "#          Continue          #\n"
            "#    ####################    #\n"
            "#    #     Save Game    #    #\n"
            "#    ####################    #\n"
            "#           Quit             #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Continuer", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Sauvegarder", textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quitter", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_RenderFillRect(renderer, &textRect2);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
}

void printQuitPause(SDL_Renderer *renderer, TTF_Font *font) {
    printf(
            "\n"
            "##############################\n"
            "#         Pause Menu         #\n"
            "#                            #\n"
            "#          Continue          #\n"
            "#          Save Game         #\n"
            "#    ####################    #\n"
            "#    #      Quit        #    #\n"
            "#    ####################    #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################\n"
    );
    SDL_Color textColor = {255, 255, 255}; // Couleur du texte (blanc dans cet exemple)
    SDL_SetRenderDrawColor(renderer, 191, 112, 77, 255); // Couleur du rectangle (bleu dans cet exemple)
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Continuer", textColor));
    SDL_Rect textRect = {250, 200, 300, 40};
    SDL_Texture *textTexture2 = SDL_CreateTextureFromSurface(renderer,
                                                             TTF_RenderText_Solid(font, "Sauvegarder", textColor));
    SDL_Rect textRect2 = {250, 300, 300, 40};
    SDL_Texture *textTexture3 = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, "Quitter", textColor));
    SDL_Rect textRect3 = {250, 400, 300, 40};
    SDL_RenderFillRect(renderer, &textRect3);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
    SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
}

int setChoicesPlus(int choice) {
    return choice += 1;
}

int setChoicesMinus(int choice) {
    return choice -= 1;
}

int pauseMenuChange(int choice,SDL_Renderer *renderer, TTF_Font *font) {
    if (choice == 1) {
        printContinue(renderer,font);
    } else if (choice == 2) {
        printSave(renderer,font);
    } else if (choice == 3) {
        printQuitPause(renderer,font);
    }
    return choice;
}

int checkChoices(int choice, levelChain *levelChain) {
    if (choice == 1) {
        return 0;
    } else if (choice == 2) {
        //savefonction
        createSave(levelChain);
        return 2;
    } else if (choice == 3) {
        return 1;
    }
    return -1;
}

bool checkPauseCode(int pauseCode) {
    if (pauseCode == 0 || pauseCode == 1) {
        return true;
    } else {
        return false;
    }
}

int pauseMenu(char keyEnter, levelChain *levelChain, Character *character,SDL_Renderer *renderer, TTF_Font *font) {
    int compt = 1;
    int pauseCode = -1;
    bool choiceDone = false;
    printContinue(renderer,font);
    while (!choiceDone) {
        
        SDL_Event event;
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT){
            return 1;
        } else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_Z:
                case SDL_SCANCODE_UP:
                    keyEnter = 'z';
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    keyEnter = 's';
                    break;
                case SDL_SCANCODE_RETURN:
                case SDL_SCANCODE_E:
                    keyEnter = 'e';
                    break;
                default:
                    break;
            }
        }
        if (keyEnter == 'z' && compt != 1) {
            compt = setChoicesMinus(compt);
        } else if (keyEnter == 's') {
            compt = setChoicesPlus(compt);

        } else if (keyEnter == 'e') {
            pauseCode = checkChoices(compt, levelChain);
        }
        if (compt == 9) {
            cheatMenu(character);
            compt = 1;
        }
        pauseMenuChange(compt,renderer,font);
        choiceDone = checkPauseCode(pauseCode);
    }
    SDL_RenderPresent(renderer);
    printAll(character);
    return pauseCode;
}