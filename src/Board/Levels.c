#include "../../include/src/Levels.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

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
            (levelChain->next->current->levelNumber == boardElements->levelNumber || boardElements->levelNumber == 1) &&
        levelChain->current->aliveMonsters != -1 && levelChain->current->nbMonsters != -1 &&
        levelChain->current->monstersTab != NULL && levelChain->current->otherLevels != NULL) {

        if(boardElements->levelNumber == 1){
            boardElements->board = levelChain->current->board;
            boardElements->otherLevels = levelChain->current->otherLevels;
            boardElements->nbMonsters = levelChain->current->nbMonsters;
            boardElements->monstersTab = levelChain->current->monstersTab;
            boardElements->aliveMonsters = levelChain->current->aliveMonsters;
        }
        boardElements->board = levelChain->next->current->board;
        boardElements->otherLevels = levelChain->next->current->otherLevels;
        boardElements->nbMonsters = levelChain->next->current->nbMonsters;
        boardElements->monstersTab = levelChain->next->current->monstersTab;
        boardElements->aliveMonsters = levelChain->next->current->aliveMonsters;
        return levelChain;
    }
    FILE *levelpointer;
    // Initialize board with 0 values except \0 for end of line
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
    char **board = (char **) malloc(sizeof(char *) * 30);
    for (int i = 0; i < 30; i++) {
        board[i] = malloc(sizeof(char) * 31);
        board[i][30] = '\0';
    }
    monster **monstersTab = (monster **) malloc(sizeof(struct Monster *) * 40);
    int size = 27;
    if (errorCount > 0) {
        size++;
    }
    char **levels = (char **) malloc(sizeof(char *) * 4);
    for (int i = 0; i < 4; i++) {
        levels[i] = malloc(sizeof(char) * size);
        levels[i][size - 1] = '\0';
    }
    monster **monsters = malloc(sizeof(struct Monster) * 3);
    for (int i = 0; i < 3; i++) {
        monsters[i] = createNewMonster("A", 0, 0, 0, 'a', createCoordonne(0, 0));
    }
    char *letter = malloc(sizeof(char));
    char *line = malloc(sizeof(char) * 32);
    int counterLine = 0;
    int counterLetter = 0;
    int monsterCount = 0;
    int counterLevel = 0;

    //read the file util the board ended so until we finished read the other levels name
    while (line != NULL && counterLine < 51) {
        int savePos = 0;
        if (counterLine < 30) {
            //Handle the § character --> -62 = special character ascii then skip the ° symbol because the § is split in UTF-8
            *letter = (char) fgetc(levelpointer);
            if (*letter == (char) -62 || *letter == 'P' || *letter == '*') {
                if (*letter != 'P' && *letter != '*') {
                    fgetc(levelpointer);
                    *letter = 'P';
                }
            } else if (*letter == 'A' || *letter == 'B' || *letter == 'C') {
                if (*letter == 'A') {
                    monstersTab[monsterCount] = createNewMonster(generateRandomName(), 0, 0, 0, 'A',
                                                                 createCoordonne(counterLetter, counterLine));
                } else {
                    if (*letter == 'B') {
                        monstersTab[monsterCount] = createNewMonster(generateRandomName(), 0, 0, 0, 'B',
                                                                     createCoordonne(counterLetter, counterLine));
                    } else {
                        monstersTab[monsterCount] = createNewMonster(generateRandomName(), 0, 0, 0, 'C',
                                                                     createCoordonne(counterLetter, counterLine));
                    }
                }
                monsterCount++;
            }
            // skip \n
            if (*letter != '\n') {
                board[counterLine][counterLetter] = *letter;
                counterLetter++;
            }
        } else if (counterLine > 31 && counterLine < 36) {
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
        } else if (counterLine > 37 && counterLine != 42 && counterLine != 47) {
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
            switch (counterLine) {
                case 38:
                    setMonsterHealth(monsters[0], atoi(value));
                    break;
                case 39:
                    setMonsterStrength(monsters[0], atoi(value));
                    break;
                case 40:
                    setMonsterShield(monsters[0], atoi(value));
                    break;
                case 43:
                    setMonsterHealth(monsters[1], atoi(value));
                    break;
                case 44:
                    setMonsterStrength(monsters[1], atoi(value));
                    break;
                case 45:
                    setMonsterShield(monsters[1], atoi(value));
                    break;
                case 48:
                    setMonsterHealth(monsters[2], atoi(value));
                    break;
                case 49:
                    setMonsterStrength(monsters[2], atoi(value));
                    break;
                case 50:
                    setMonsterShield(monsters[2], atoi(value));
                    break;
                default:
                    break;
            }
        }
        // Reset column
        if (counterLine >=30) {
            line = fgets(line, 32, levelpointer);
            counterLine++;
        }
        if (counterLine < 30 && counterLetter - 30 == 0) {
            counterLine++;
            counterLetter = 0;
        }
    }
    for (int i = 0; i < monsterCount; i++) {
        if (monstersTab[i]->type == 'A') {
            monstersTab[i] = setMonsterHealth(monstersTab[i], monsters[0]->hp);
            monstersTab[i] = setMonsterStrength(monstersTab[i], monsters[0]->strength);
            monstersTab[i] = setMonsterShield(monstersTab[i], monsters[0]->shield);

        } else if (monstersTab[i]->type == 'B') {
            monstersTab[i] = setMonsterHealth(monstersTab[i], monsters[1]->hp);
            monstersTab[i] = setMonsterStrength(monstersTab[i], monsters[1]->strength);
            monstersTab[i] = setMonsterShield(monstersTab[i], monsters[1]->shield);
        } else {
            monstersTab[i] = setMonsterHealth(monstersTab[i], monsters[2]->hp);
            monstersTab[i] = setMonsterStrength(monstersTab[i], monsters[2]->strength);
            monstersTab[i] = setMonsterShield(monstersTab[i], monsters[2]->shield);
        }
    }
    fclose(levelpointer);
    if (monsterCount < 40) {
        monstersTab = realloc(monstersTab, sizeof(struct Monster *) * monsterCount);
    }
    for (int i = 0; i < 4; i++) {
        printf("%s\n", levels[i]);
    }
    levels = addPrefix(levels, errorCount, size);
    boardElements->board = board;
    boardElements->monstersTab = monstersTab;
    boardElements->nbMonsters = monsterCount;
    boardElements->aliveMonsters = monsterCount;
    boardElements->otherLevels = levels;

    printf("We got the other levels\n");
    printf("We got the board\n");
    printf("Monsters are setted\n");
    if (levelChain == NULL) {
        levelChain = createLevelChain(copyBoardElement(boardElements));
        return levelChain;
    }
    levelChain->next = createLevelChain(boardElements);
    levelChain->next->previous = levelChain;
    if(boardElements->levelNumber == 1){
        return levelChain;
    }
    levelChain = levelChain->next;
    return levelChain;
}


char **addPrefix(char **levels, int errorCount, int size) {
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
    return levels;
}
