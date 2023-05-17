#include "Levels.h"
#include <stdio.h>
#include <stdlib.h>


char* createLevelBoard(char* levelFile){
    FILE *levelpointer;
    char *board = "";
    fopen_s(&levelpointer, levelFile, "r");
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        printf("Error opening the file.\n");
        return board;
    }
    char letter = (char)  fgetc(levelpointer);
    while(letter != EOF && letter != 'E'){
        board+=letter;
        printf("%c", letter);
        letter = (char)fgetc(levelpointer);
    }
    printf("Board is displayed\n");
    fclose(levelpointer);
    return board;
}

monster* createLevelMonsters(char* levelFile){
    FILE *levelpointer;
    fopen_s(&levelpointer, levelFile, "r");
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        printf("Error opening the file.\n");
        return NULL;
    }
    int counter = 1;
    char* letters = malloc(sizeof (char) * 32);
    fgets(letters, 32, levelpointer);
    while(letters != NULL){
        printf("%s", letters);
        letters = fgets(letters, 32, levelpointer);
        counter++;
    }
    printf("Monsters are setted\n");
    fclose(levelpointer);
    return NULL;
}