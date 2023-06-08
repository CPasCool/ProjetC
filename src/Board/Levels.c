#include "../../include/src/Levels.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

void getLevelNumber(char *levelFile, boardElements *board) {
    int i = 0;
    while (levelFile[i] != '\0') {
        if (isdigit(levelFile[i])) {
            if (isdigit(levelFile[i + 1])) {
                char *value = "  ";
                value[0] = levelFile[i];
                value[1] = levelFile[i + 1];
                board->levelNumber = atoi(value);
                return;
            }
            board->levelNumber = levelFile[i] - '0';

            return;
        }
        i++;
    }
}

int getFileLevelNumber(char *levelFile) {
    int i = 0;
    while (levelFile[i] != '\0') {
        if (isdigit(levelFile[i])) {
            if (isdigit(levelFile[i + 1])) {
                char *value = "  ";
                value[0] = levelFile[i];
                value[1] = levelFile[i + 1];
                return atoi(value);
            }
            return levelFile[i] - '0';
        }
        i++;
    }
}

// Get an array of monsters set with the monsters data of a given levels
levelChain *getLevelMonsters(char *levelFile, boardElements *board, levelChain *levelChain) {
    int levelNumber = getFileLevelNumber(levelFile);
    while (levelChain != NULL && levelChain->previous != NULL) {
        levelChain = levelChain->previous;
    }
    while (levelChain->next != NULL && levelChain->next->current != NULL &&
           levelChain->current->levelNumber != levelNumber) {
        levelChain = levelChain->next;
    }
    if (levelChain->current->levelNumber == levelNumber && levelChain->current->aliveMonsters != -1 &&
        levelChain->current->nbMonsters != -1 && levelChain->current->monstersTab != NULL) {
        board->aliveMonsters = levelChain->current->aliveMonsters;
        board->nbMonsters = levelChain->current->nbMonsters;
        board->monstersTab = levelChain->current->monstersTab;
        return levelChain;
    }
    FILE *levelpointer;
    int monsterCount = 0;
    fopen_s(&levelpointer, levelFile, "r");

    // Send an error if the file does not exist
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        char *newLevelFilename = malloc(sizeof(char) * 28);
        newLevelFilename[27] = '\0';
        char *prefixFile = ".";
        for (int j = 0; j < 27; j++) {
            if (j < 1) {
                newLevelFilename[j] = prefixFile[j];
            } else {
                newLevelFilename[j] = levelFile[j - 1];
            }
        }
        fopen_s(&levelpointer, newLevelFilename, "r");
        if (fopen_s(&levelpointer, newLevelFilename, "r") != 0) {
            printf("Error opening the file.\n");
            return levelChain;
        }
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
        if (letter == -62) {
            letter = (char) fgetc(levelpointer);
        }
    }
    if (monsterCount < 40) {
        monstersTab = realloc(monstersTab, sizeof(struct Monster *) * monsterCount);
    }
    fclose(levelpointer);

    // Set all monsters stats
    if (monsterCount != 0) {
        createLevelMonsters(levelFile, monstersTab, monsterCount);
    }

    printf("Monsters are setted\n");
    levelChain->current->monstersTab = monstersTab;
    levelChain->current->nbMonsters = monsterCount;
    levelChain->current->aliveMonsters = monsterCount;
    return levelChain;
}

void createLevelMonsters(char *levelFile, monster **monsterTab, int nbMonster) {
    FILE *levelpointer;
    fopen_s(&levelpointer, levelFile, "r");

    // Send an error if the file does not exist
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        char *newLevelFilename = malloc(sizeof(char) * 28);
        newLevelFilename[27] = '\0';
        char *prefixFile = ".";
        for (int j = 0; j < 27; j++) {
            if (j < 1) {
                newLevelFilename[j] = prefixFile[j];
            } else {
                newLevelFilename[j] = levelFile[j - 1];
            }
        }
        fopen_s(&levelpointer, newLevelFilename, "r");
        if (fopen_s(&levelpointer, newLevelFilename, "r") != 0) {
            printf("Error opening the file.\n");
            return;
        }
    }
    int counter = 0;
    char *line = malloc(sizeof(char) * 32);
    fgets(line, 32, levelpointer);

    // Check line starting at the 36th because we want to get the monsters stats
    while (line != NULL) {
        if (counter > 35 && counter != 40 && counter != 45) {
            char *value = malloc(sizeof(char) * 4);
            value[3] = '\0';

            // Get the stat value
            for (int i = 0; i < 32; i++) {
                if (line[i] != '\0' && isdigit(line[i])) {
                    value[0] = line[i];
                    value[1] = line[i + 1];
                    value[2] = line[i + 2];
                    break;
                }
            }

            // We know at which line we have which stat, so we check those lines
            switch (counter) {
                case 36:
                case 41:
                case 46:
                    if (counter == 36) {
                        for (int i = 0; i < nbMonster; i++) {
                            if (monsterTab[i]->type == 'A') {
                                setMonsterHealth(monsterTab[i], atoi(value));
                            }
                        }
                    } else if (counter == 41) {
                        for (int i = 0; i < nbMonster; i++) {
                            if (monsterTab[i]->type == 'B') {
                                setMonsterHealth(monsterTab[i], atoi(value));
                            }
                        }
                    } else {
                        for (int i = 0; i < nbMonster; i++) {
                            if (monsterTab[i]->type == 'C') {
                                setMonsterHealth(monsterTab[i], atoi(value));
                            }
                        }
                    }
                    break;

                case 37:
                case 42:
                case 47:
                    if (counter == 37) {
                        for (int i = 0; i < nbMonster; i++) {
                            if (monsterTab[i]->type == 'A') {
                                setMonsterStrength(monsterTab[i], atoi(value));
                            }
                        }
                    } else if (counter == 42) {
                        for (int i = 0; i < nbMonster; i++) {
                            if (monsterTab[i]->type == 'B') {
                                setMonsterStrength(monsterTab[i], atoi(value));
                            }
                        }
                    } else {
                        for (int i = 0; i < nbMonster; i++) {
                            if (monsterTab[i]->type == 'C') {
                                setMonsterStrength(monsterTab[i], atoi(value));
                            }
                        }
                    }
                    break;

                case 38:
                case 43:
                case 48:
                    if (counter == 38) {
                        for (int i = 0; i < nbMonster; i++) {
                            if (monsterTab[i]->type == 'A') {
                                setMonsterShield(monsterTab[i], atoi(value));
                            }
                        }
                    } else if (counter == 43) {
                        for (int i = 0; i < nbMonster; i++) {
                            if (monsterTab[i]->type == 'B') {
                                setMonsterShield(monsterTab[i], atoi(value));
                            }
                        }
                    } else {
                        for (int i = 0; i < nbMonster; i++) {
                            if (monsterTab[i]->type == 'C') {
                                setMonsterShield(monsterTab[i], atoi(value));
                            }
                        }
                    }
                    break;

                default:
                    break;
            }
        }
        line = fgets(line, 32, levelpointer);
        if (counter < 30 && strcmp(line, "\n") == 0) {
            line = fgets(line, 32, levelpointer);
        }
        counter++;
    }
    fclose(levelpointer);
}

levelChain *getLevelBoard(char *levelFile, levelChain *levelChain) {
    boardElements *boardElements = createBoardElement();
    getLevelNumber(levelFile, boardElements);
    // go to first
    while (levelChain != NULL && levelChain->previous != NULL) {
        levelChain = levelChain->previous;
    }
    // go to correct element or last
    while (levelChain != NULL && levelChain->next != NULL && levelChain->current != NULL &&
           levelChain->current->levelNumber != boardElements->levelNumber) {
        levelChain = levelChain->next;
    }
    if (levelChain != NULL && levelChain->next != NULL && levelChain->current != NULL &&
        levelChain->next->current->levelNumber == boardElements->levelNumber) {
        boardElements->board = levelChain->next->current->board;
        return levelChain;
    }
    FILE *levelpointer;
    // Initialize board with 0 values except \0 for end of line
    char **board = (char **) malloc(sizeof(char *) * 30);
    for (int i = 0; i < 30; i++) {
        board[i] = malloc(sizeof(char) * 31);
        board[i][30] = '\0';
    }

    fopen_s(&levelpointer, levelFile, "r");
    // Send an error if the file does not exist
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        char *newLevelFilename = malloc(sizeof(char) * 28);
        newLevelFilename[27] = '\0';
        char *prefixFile = ".";
        for (int j = 0; j < 27; j++) {
            if (j < 1) {
                newLevelFilename[j] = prefixFile[j];
            } else {
                newLevelFilename[j] = levelFile[j - 1];
            }
        }
        fopen_s(&levelpointer, newLevelFilename, "r");
        if (fopen_s(&levelpointer, newLevelFilename, "r") != 0) {
            printf("Error opening the file.\n");
            return levelChain;
        }
    }
    char letter = (char) fgetc(levelpointer);
    int counterLine = 0;
    int counterLetter = 0;

    //read the file util the board ended so until we see the E of East(Est)
    while (counterLine < 30) {
        //Print the § character --> -62 = special character ascii then skip the ° symbol because the § is split in UTF-8
        if (letter == (char) -62 || letter == 'P' || letter == '*') {
            if (letter != 'P') {
                letter = (char) fgetc(levelpointer);
            }
            board[counterLine][counterLetter] = 'P';
            counterLetter++;
        } else {
            // skip \n
            if (letter != '\n') {
                board[counterLine][counterLetter] = letter;
                counterLetter++;
            }
        }

        // Reset column
        if (counterLetter - 30 == 0) {
            counterLine++;
            counterLetter = 0;
        }
        letter = (char) fgetc(levelpointer);
    }

    fclose(levelpointer);
    boardElements->board = board;
    printf("We got the board\n");
    if (levelChain == NULL) {
        levelChain = createLevelChain(copyBoardElement(boardElements));
        return levelChain;
    }
    levelChain->next = createLevelChain(boardElements);
    levelChain->next->previous = levelChain;
    return levelChain;
}

// get all the possible levels in an array, string is set to \0 if there is no level on this way
// the levels file locations are in the same order that in the original file, so 0 = East, 1 = South, 2 = West, 3 = North
levelChain *getOtherLevels(char *levelFile, boardElements *boardElements, levelChain *levelChain) {
    int levelNumber = getFileLevelNumber(levelFile);
    while (levelChain != NULL && levelChain->previous != NULL) {
        levelChain = levelChain->previous;
    }
    while (levelChain->next != NULL && levelChain->next->current != NULL &&
           levelChain->current->levelNumber != levelNumber) {
        levelChain = levelChain->next;
    }
    if (levelChain->current->levelNumber == levelNumber && levelChain->current->otherLevels != NULL) {
        boardElements->otherLevels = levelChain->current->otherLevels;
        return levelChain;
    }
    FILE *levelpointer;
    // Initialize the levels array with empty strings
    int errorCount = 0;
    fopen_s(&levelpointer, levelFile, "r");

    // Send an error if the file does not exist
    if (fopen_s(&levelpointer, levelFile, "r") != 0) {
        errorCount++;
        char *newLevelFilename = malloc(sizeof(char) * 28);
        newLevelFilename[27] = '\0';
        char *prefixFile = ".";
        for (int j = 0; j < 27; j++) {
            if (j < 1) {
                newLevelFilename[j] = prefixFile[j];
            } else {
                newLevelFilename[j] = levelFile[j - 1];
            }
        }
        fopen_s(&levelpointer, newLevelFilename, "r");
        if (fopen_s(&levelpointer, newLevelFilename, "r") != 0) {
            printf("Error opening the file.\n");
            return levelChain;
        }
    }
    int size = 27;
    if (errorCount > 0) {
        size++;
    }
    char **levels = (char **) malloc(sizeof(char *) * 4);
    for (int i = 0; i < 4; i++) {
        levels[i] = malloc(sizeof(char) * size);
        levels[i][size - 1] = '\0';
    }
    int counterLine = 0;
    int counterLevel = 0;
    char *line = malloc(sizeof(char) * 32);
    fgets(line, 32, levelpointer);

    // get all the suffixes as niveauX.level
    while (line != NULL && counterLine < 34) {
        int savePos = 0;
        if (counterLine >= 30) {
            for (int i = 0; i < 32; i++) {
                if (line[i] == ':') {
                    i += 2;
                    savePos = i;
                    break;
                }
            }
            if (line[savePos - 1] != '\n') {
                for (int i = savePos; i < 32; i++) {
                    if (line[i] != '\n') {
                        if (line[i] != ' ' && line[i] != '\r') {
                            levels[counterLevel][i - savePos] = line[i];
                        }
                    } else {
                        break;
                    }
                }
            } else {
                levels[counterLevel][0] = '\0';
            }
            counterLevel++;
        }
        counterLine++;
        line = fgets(line, 32, levelpointer);
        if (strcmp(line, "\n") == 0) {
            line = fgets(line, 32, levelpointer);
        }
    }
    // add prefix to have the right file path
    char *prefix = "./src/Levels/";
    int sizePrefix = 13;
    if (errorCount > 0) {
        prefix = "../src/Levels/";
        sizePrefix++;
    }
    char *prefixedLevelName = malloc(sizeof(char) * size);
    for (int i = 0; i < 4; i++) {
        if (levels[i][0] != '\0') {
            for (int j = 0; j < size; j++) {
                if (j < sizePrefix) {
                    prefixedLevelName[j] = prefix[j];
                } else {
                    prefixedLevelName[j] = levels[i][j - sizePrefix];
                }
            }
            prefixedLevelName[size - 1] = '\0';
            strcpy(levels[i], prefixedLevelName);
        }
        if (errorCount > 0) {
            prefix = "../src/Levels/";
        } else {
            prefix = "./src/Levels/";
        }
    }
    printf("We got the other levels\n");
    fclose(levelpointer);
    levelChain->current->otherLevels = levels;
    return levelChain;
}
