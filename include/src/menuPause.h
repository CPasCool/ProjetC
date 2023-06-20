#include "Cheat.h"
#include "Keyboard.h"
#include "Character.h"
#include "save.h"
#include "../../SDL2/SDL_render.h"
#include "../../SDL2/SDL_ttf.h"
#include <stdbool.h>


int pauseMenu(char keyEnter, levelChain *levelChain, Character *character,SDL_Renderer *renderer, TTF_Font *font);

int pauseMenuChange(int choice,SDL_Renderer *renderer, TTF_Font *font);

int setChoicesMinus(int choice);

int setChoicesPlus(int choice);

void printQuitPause(SDL_Renderer *renderer, TTF_Font *font);

void printSave(SDL_Renderer *renderer, TTF_Font *font);

void printContinue(SDL_Renderer *renderer, TTF_Font *font);

bool checkPauseCode(int pauseCode);

