#include "DisplayLevels.h"
#include "../Monster/Monster.h"
#include <stdio.h>


void displayLevel(char* levelFile){
    FILE *levelpointer;
    fopen_s(&levelpointer, levelFile, "r");
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        printf("Error opening the file.\n");
        return;
    }
    char letter = (char)  fgetc(levelpointer);
    while(letter != EOF && letter != 'E'){
        printf("%c", letter);
        letter = (char)fgetc(levelpointer);
    }
    printf("Board is displayed\n");
    fclose(levelpointer);
}

monster* createLevelMonsters(char* levelFile){
    FILE *levelpointer;
    fopen_s(&levelpointer, levelFile, "r");
    char* letters = NULL;
    fgets(letters, 30, levelpointer);
    while(letters != NULL){
            printf("%c", letters);
            letters = fgets(letters, 30, levelpointer);
    }
    printf("Monsters are setted\n");
    fclose(levelpointer);
    return NULL;
}