#include "Cheat.h"
#include "Keyboard.h"
#include "Character.h"
#include "save.h"
#include <stdbool.h>


int pauseMenu(char keyEnter, levelChain *levelChain, Character *character);

int pauseMenuChange(int choice);

int setChoicesMinus(int choice);

int setChoicesPlus(int choice);

void printQuitPause();

void printSave();

void printContinue();

bool checkPauseCode(int pauseCode);

