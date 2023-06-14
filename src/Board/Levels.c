#include "../../include/src/Levels.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"


/**
 *  get the fileName's digit(s) return
 * @param levelFile : the file we want the digit(s)
 * @param board : the board elements of the level
 * @return -1 if it does not exist max = 99
 */
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
    board->levelNumber = -1;
}


/**
 *  get all present elements in a file and create the level
 * @param levelFile : the level file we want to play
 * @param levelChain : the chain which contain every levels
 * @return : the updated levelChain
 */
levelChain *getLevelBoard(char *levelFile, levelChain *levelChain) {
    boardElements *boardElements = createBoardElement();
    getLevelNumber(levelFile, boardElements);
    // go to first element
    while (levelChain != NULL && levelChain->previous != NULL) {
        levelChain = levelChain->previous;
    }
    // go to correct element -1
    while (levelChain != NULL && levelChain->next != NULL && levelChain->current != NULL &&
           levelChain->current->levelNumber != boardElements->levelNumber) {

        levelChain = levelChain->next;
    }
    // skip opening the file if level already played and
    if (levelChain != NULL && levelChain->next != NULL && levelChain->current != NULL &&
        (levelChain->next->current->levelNumber == boardElements->levelNumber || boardElements->levelNumber == 1) &&
        levelChain->current->aliveMonsters != -1 && levelChain->current->nbMonsters != -1 &&
        levelChain->current->monstersTab != NULL && levelChain->current->otherLevels != NULL) {

        return levelChain;
    }
    FILE *levelpointer;
    // Initialize board with 0 values except \0 for end of line
    int errorCount = 0;

    levelpointer = fopen(levelFile, "r");
    // Test an onther path and send an error if the file does not exist
    if (fopen(levelFile, "r") == 0) {
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
        levelpointer = fopen(levelFile, "r");
        if (fopen(levelFile, "r") == 0) {
            printf("Error opening the file.\n");
            return levelChain;
        }
    }
    // initialize empty board/monstersStats array/levels array/monstersStats stats array
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

    monster **monstersStats = malloc(sizeof(struct Monster) * 3);
    for (int i = 0; i < 3; i++) {
        monstersStats[i] = createNewMonster("A", 0, 0, 0, 'a', createCoordonne(0, 0));
    }
    // initialize variable needed to set everything correctly
    char *letter = malloc(sizeof(char));
    char *line = malloc(sizeof(char) * 32);
    int counterLine = 0;
    int counterLetter = 0;
    int monsterCount = 0;
    int counterLevel = 0;

    //read the file util the file ended or the line 51(last monster line) is read
    while (line != NULL && counterLine < 51) {
        int savePos = 0;
        // Set board and monstersStats with type and coordinates
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
            // Get the possible other level we can play at
        } else if (counterLine > 31 && counterLine < 36) {
            for (int i = 0; i < 32; i++) {
                if (line[i] == ':') {
                    i += 2;
                    savePos = i;
                    break;
                }
            }
            // get the fileName of the level if he exists
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
            // Set the monstersStats stats in the stats array and skip the type line, we use the exact line because we know them
        } else if (counterLine > 37 && counterLine != 42 && counterLine != 47) {
            char *value = malloc(sizeof(char) * 4);
            value[3] = '\0';

            // Get the stat value max is 999 to be easier
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
                    setMonsterHealth(monstersStats[0], atoi(value));
                    break;
                case 39:
                    setMonsterStrength(monstersStats[0], atoi(value));
                    break;
                case 40:
                    setMonsterShield(monstersStats[0], atoi(value));
                    break;
                case 43:
                    setMonsterHealth(monstersStats[1], atoi(value));
                    break;
                case 44:
                    setMonsterStrength(monstersStats[1], atoi(value));
                    break;
                case 45:
                    setMonsterShield(monstersStats[1], atoi(value));
                    break;
                case 48:
                    setMonsterHealth(monstersStats[2], atoi(value));
                    break;
                case 49:
                    setMonsterStrength(monstersStats[2], atoi(value));
                    break;
                case 50:
                    setMonsterShield(monstersStats[2], atoi(value));
                    break;
                default:
                    break;
            }
        }
        // continue line increment, starting there we do not use letters anymore
        if (counterLine >= 30) {
            line = fgets(line, 32, levelpointer);
            counterLine++;
        }
        // Reset column
        if (counterLine < 30 && counterLetter - 30 == 0) {
            counterLine++;
            counterLetter = 0;
        }
    }
    // Set every monster's stats which theses we have in the stats array
    for (int i = 0; i < monsterCount; i++) {
        if (monstersTab[i]->type == 'A') {
            monstersTab[i] = setMonsterHealth(monstersTab[i], monstersStats[0]->hp);
            monstersTab[i] = setMonsterStrength(monstersTab[i], monstersStats[0]->strength);
            monstersTab[i] = setMonsterShield(monstersTab[i], monstersStats[0]->shield);

        } else if (monstersTab[i]->type == 'B') {
            monstersTab[i] = setMonsterHealth(monstersTab[i], monstersStats[1]->hp);
            monstersTab[i] = setMonsterStrength(monstersTab[i], monstersStats[1]->strength);
            monstersTab[i] = setMonsterShield(monstersTab[i], monstersStats[1]->shield);
        } else {
            monstersTab[i] = setMonsterHealth(monstersTab[i], monstersStats[2]->hp);
            monstersTab[i] = setMonsterStrength(monstersTab[i], monstersStats[2]->strength);
            monstersTab[i] = setMonsterShield(monstersTab[i], monstersStats[2]->shield);
        }
    }
    fclose(levelpointer);
    // We stats the monsters to 40 max, we don't expect a level to have more
    if (monsterCount < 40) {
        monstersTab = realloc(monstersTab, sizeof(struct Monster *) * monsterCount);
    }
    // Set every element in the boardElement var
    levels = addPrefix(levels, errorCount, size);
    boardElements->board = board;
    boardElements->monstersTab = monstersTab;
    boardElements->nbMonsters = monsterCount;
    boardElements->aliveMonsters = monsterCount;
    boardElements->otherLevels = levels;

    printf("We got the other levels\n");
    printf("We got the board\n");
    printf("Monsters are set\n");

    // create a chain with the board we just created
    if (levelChain == NULL) {
        levelChain = createLevelChain(copyBoardElement(boardElements));
        return levelChain;
    }
    levelChain->next = createLevelChain(boardElements);
    levelChain->next->previous = levelChain;
    if (boardElements->levelNumber == 1) {
        return levelChain;
    }
    levelChain = levelChain->next;
    return levelChain;
}


// Add prefix to get the correct level path later
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
