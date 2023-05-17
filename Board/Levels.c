#include "Levels.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


monster* getLevelMonsters(char* levelFile){
    FILE *levelpointer;
    char *board = "";
    int nbMonsterA = 0;
    int nbMonsterB = 0;
    int nbMonsterC = 0;
    fopen_s(&levelpointer, levelFile, "r");
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        printf("Error opening the file.\n");
        return NULL;
    }
    //TODO create monsters tab to add monsters coordinates
    char letter = (char)  fgetc(levelpointer);
    while(letter != EOF && letter != 'E'){
        board+=letter;
        printf("%c", letter);
        if(letter == 'A'){
            nbMonsterA++;
        }else{
            if(letter == 'B'){
                nbMonsterB++;
            } else {
                if(letter == 'C'){
                    nbMonsterC++;
                }
            }
        }
        letter = (char)fgetc(levelpointer);
    }
    printf("Board is displayed\n");
    fclose(levelpointer);
    monster* monsterTable = createLevelMonsters(levelFile, nbMonsterA, nbMonsterB, nbMonsterC);
    return monsterTable;
}

monster* createLevelMonsters(char* levelFile, int nbMonsterA, int nbMonsterB, int nbMonsterC){
    int nbMonster = nbMonsterA + nbMonsterB + nbMonsterC;
    monster *monsterTable = (monster*) malloc(sizeof(struct Monster)*nbMonster);
    FILE *levelpointer;
    fopen_s(&levelpointer, levelFile, "r");
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        printf("Error opening the file.\n");
        return NULL;
    }
    int counter = 1;
    char* line = malloc(sizeof (char) * 32);
    fgets(line, 32, levelpointer);
    while(line != NULL){
        if(counter > 36 && counter != 41 && counter != 46){
            monster* monster = createNewMonster(generateRandomName(), 0,0,0);
            char* value = malloc(sizeof (char) * 3);
            for(int i = 0; i<32; i++){
                if(line[i]!='\0' && isdigit(line[i])){
                    value+=line[i];
                }
            }
            if(counter == 37 || counter == 42 || counter == 47){
                setMonsterHealth(monster, atoi(value));
            }else {
                if(counter == 38 || counter == 43 || counter == 48){
                    setMonsterStrength(monster, atoi(value));
                }else{
                    if(counter == 39 || counter == 44 || counter == 49){
                        setMonsterShield(monster, atoi(value));
                    }
                }
            }
        }
        line = fgets(line, 32, levelpointer);
        counter++;
    }
    printf("Monsters are setted\n");
    fclose(levelpointer);
    return NULL;
}

char** getLevelBoard(char* levelFile){
    FILE *levelpointer;
    char **board = (char**)malloc(sizeof (char*)*30);
    int nbMonsterA = 0;
    int nbMonsterB = 0;
    int nbMonsterC = 0;
    fopen_s(&levelpointer, levelFile, "r");
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        printf("Error opening the file.\n");
        return board;
    }
    char letter = (char)  fgetc(levelpointer);

    //char* line = malloc(sizeof (char) * 32);
    //fgets(line, 32, levelpointer);

    //while(line != NULL){
    while(letter != EOF && letter != 'E'){
        //Print the § character --> -62 = special character ascii then skip the ° symbol because the § is split in UTF-8
        if(letter == (char)-62){
            printf("%c", 21);
            letter = (char)  fgetc(levelpointer);
        }else{
            printf("%c", letter);
        }
        letter = (char)  fgetc(levelpointer);
        //line = fgets(line, 32, levelpointer);
    }
    printf("Board is displayed\n");
    fclose(levelpointer);
    monster* monsterTable = createLevelMonsters(levelFile, nbMonsterA, nbMonsterB, nbMonsterC);
    return board;
}
