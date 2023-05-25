#include "Levels.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Get an array of monsters set with the monsters data of a given levels
monster **getLevelMonsters(char *levelFile) {
    FILE *levelpointer;
    int monsterCount = 0;
    fopen_s(&levelpointer, levelFile, "r");

    // Send an error if the file does not exist
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        printf("Error opening the file.\n");
        return NULL;
    }
    monster **monstersTab = (monster **) malloc(sizeof(struct Monster *) * 40);

    //use to get a monster coordinates
    int counterLine = 0;
    int counterLetter = 0;
    char letter = (char) fgetc(levelpointer);

    // Put all monsters in an array set with their coordinates and type
    while (letter != EOF && letter != 'E') {
        if (letter == 'A' || letter == 'B' || letter == 'C') {
            if (letter == 'A') {
                monstersTab[monsterCount] = createNewMonster(generateRandomName(), 0, 0, 0, 'A',
                                                             createCoordonne(counterLetter, counterLine));
            } else {
                if (letter == 'B') {
                    monstersTab[monsterCount] = createNewMonster(generateRandomName(), 0, 0, 0, 'B',
                                                                 createCoordonne(counterLetter, counterLine));
                } else {
                    monstersTab[monsterCount] = createNewMonster(generateRandomName(), 0, 0, 0, 'C',
                                                                 createCoordonne(counterLetter, counterLine));
                }
            }
            monsterCount++;
        }

        // Skip \n
        if (letter != '\n') {
            counterLetter++;
        }

        // reset column
        if (counterLetter - 30 == 0) {
            counterLine++;
            counterLetter = 0;
        }
        letter = (char) fgetc(levelpointer);
    }
    if (monsterCount < 40) {
        monstersTab = realloc(monstersTab, sizeof(struct Monster *) * monsterCount);
    }
    printf("Board is displayed\n");
    fclose(levelpointer);

    // Set all monsters stats
    createLevelMonsters(levelFile, monstersTab, monsterCount);
    printf("%d", monsterCount);
    return monstersTab;
}

void createLevelMonsters(char *levelFile, monster **monsterTab, int nbMonster) {
    FILE *levelpointer;
    fopen_s(&levelpointer, levelFile, "r");

    // Send an error if the file does not exist
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        printf("Error opening the file.\n");
        return;
    }
    int counter = 0;
    char *line = malloc(sizeof(char) * 32);
    fgets(line, 32, levelpointer);
    while (line != NULL) {
        if (counter > 36 && counter != 41 && counter != 46) {
            char *value = malloc(sizeof(char) * 4);
            value[3] = '\0';
            for (int i = 0; i < 32; i++) {
                if (line[i] != '\0' && isdigit(line[i])) {
                    value[0] = line[i];
                    value[1] = line[i + 1];
                    value[2] = line[i + 2];
                    break;
                }
            }
            if (counter == 37 || counter == 42 || counter == 47) {
                if (counter == 37) {
                    for (int i = 0; i < 10; i++) {
                        if (monsterTab[i]->type == 'A') {
                            setMonsterHealth(monsterTab[i], atoi(value));
                        }
                    }
                } else {
                    if (counter == 42) {
                        for (int i = 0; i < 10; i++) {
                            if (monsterTab[i]->type == 'B') {
                                setMonsterHealth(monsterTab[i], atoi(value));
                            }
                        }
                    } else {
                        for (int i = 0; i < 10; i++) {
                            if (monsterTab[i]->type == 'C') {
                                setMonsterHealth(monsterTab[i], atoi(value));
                            }
                        }
                    }
                }
            } else {
                if (counter == 38 || counter == 43 || counter == 48) {
                    if (counter == 38) {
                        for (int i = 0; i < 10; i++) {
                            if (monsterTab[i]->type == 'A') {
                                setMonsterStrength(monsterTab[i], atoi(value));
                            }
                        }
                    } else {
                        if (counter == 43) {
                            for (int i = 0; i < 10; i++) {
                                if (monsterTab[i]->type == 'B') {
                                    setMonsterStrength(monsterTab[i], atoi(value));
                                }
                            }
                        } else {
                            for (int i = 0; i < 10; i++) {
                                if (monsterTab[i]->type == 'C') {
                                    setMonsterStrength(monsterTab[i], atoi(value));
                                }
                            }
                        }
                    }
                } else {
                    if (counter == 39 || counter == 44 || counter == 49) {
                        if (counter == 39) {
                            for (int i = 0; i < 10; i++) {
                                if (monsterTab[i]->type == 'A') {
                                    setMonsterShield(monsterTab[i], atoi(value));
                                }
                            }
                        } else {
                            if (counter == 44) {
                                for (int i = 0; i < 10; i++) {
                                    if (monsterTab[i]->type == 'B') {
                                        setMonsterShield(monsterTab[i], atoi(value));
                                    }
                                }
                            } else {
                                for (int i = 0; i < 10; i++) {
                                    if (monsterTab[i]->type == 'C') {
                                        setMonsterShield(monsterTab[i], atoi(value));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        line = fgets(line, 32, levelpointer);
        counter++;
    }
    printf("Monsters are setted\n");
    fclose(levelpointer);
}

char **getLevelBoard(char *levelFile) {
    FILE *levelpointer;
    char **board = (char **) malloc(sizeof(char *) * 30);
    for (int i = 0; i < 30; i++) {
        board[i] = malloc(sizeof(char) * 31);
    }
    for (int i = 0; i < 30; i++) {
        board[i][30] = '\0';
    }
    fopen_s(&levelpointer, levelFile, "r");
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        printf("Error opening the file.\n");
        return board;
    }
    char letter = (char) fgetc(levelpointer);
    int counterLine = 0;
    int counterLetter = 0;

    while (counterLine <= 30 && letter != 'E') {
        //Print the § character --> -62 = special character ascii then skip the ° symbol because the § is split in UTF-8
        if (letter == (char) -62) {
            letter = (char) fgetc(levelpointer);
            board[counterLine][counterLetter] = 'P';
            counterLetter++;
        } else {
            if (letter != '\n') {
                board[counterLine][counterLetter] = letter;
                counterLetter++;
            }
        }
        if (counterLetter - 30 == 0) {
            counterLine++;
            counterLetter = 0;
        }
        letter = (char) fgetc(levelpointer);
    }
    printf("We got the board\n");
    fclose(levelpointer);
    return board;
}

char** getOtherLevels(char* levelFile){

}
