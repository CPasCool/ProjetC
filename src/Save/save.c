#include "../../include/src/save.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/**
 * We create write in a file to save the current level
 * */
int createSave(levelChain *levelChain) {
    char *levelFile = "../src/Levels/save.txt";
    FILE *levelPointer;
    int errorCount = 0;

    levelPointer = fopen(levelFile, "w+");
    // Test an onther path and send an error if the file does not exist
    if (fopen(levelFile, "w+") != 0) {
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
        levelPointer = fopen(levelFile, "w+");
        if (fopen(levelFile, "w+") != 0) {
            printf("Error opening the file.\n");
            printf("Fail to save the game");
            return 0;
        }
    } else {
        levelPointer = fopen(levelFile, "w+");
    }
    for (int i = 0; i < 30; i++) {//on parcours par colonne
        for (int j = 0; j < 30; j++) {
            //on parcours par ligne
            fprintf(levelPointer, "%c", levelChain->current->board[i][j]);
        }
        fprintf(levelPointer, "\n");
    }
    //Une fois le board écrit dans la sauvegarde on écrit les données
    fprintf(levelPointer, "East : %s\nSud : %s\nOuest : %s\nNord : %s\n\n", levelChain->current->otherLevels[0],
            levelChain->current->otherLevels[1], levelChain->current->otherLevels[2],
            levelChain->current->otherLevels[3]);
    fprintf(levelPointer, "Character\nNom : %s.\nMaxPv : %d\nPvActuel : %d\nForce : %d\nArmure : %d\nClé : %d\n"
                          "CoordonnéeX : %d\nCoordonnéesY : %d\n\n", getName(levelChain->current->character),
            getMaximumLifePoint(levelChain->current->character), getLifePoint(levelChain->current->character),
            getStrength(levelChain->current->character), getDefence(levelChain->current->character),
            getKeys(levelChain->current->character), getCharaX(levelChain->current->character),
            getCharaY(levelChain->current->character));
    //on utilise la liste des montres pour écrire leurs informations
    for (int i = 0; i < levelChain->current->nbMonsters; i++) {

        fprintf(levelPointer, "%c\nPv : %d\nForce : %d\nArmure : %d\n", levelChain->current->monstersTab[i]->type,
                getMonsterHealth(levelChain->current->monstersTab[i]),
                getMonsterStrength(levelChain->current->monstersTab[i]),
                getMonsterShield(levelChain->current->monstersTab[i]));
    }
    //on écrit les informations du personnage

    fclose(levelPointer);
    printf("game saved successfully");
    return 1;
}

//Get the Save Character
levelChain *getCharacterSave(levelChain *levelChain) {
    Character *personnage = createCharacter("");
    char *name;
    int errorCount = 0;
    int countLine = 0;
    int savePos = 0;
    int coordX = 0;
    int coordY = 0;
    char *value = malloc(sizeof(char) * 4);
    char *levelFile = "./src/Levels/save.txt";
    FILE *saveFile;

    saveFile = fopen(levelFile, "r");
    // Test an onther path and send an error if the file does not exist
    if (fopen(levelFile, "r") != 0) {
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
        saveFile = fopen(levelFile, "r");
        if (fopen(levelFile, "r") != 0) {
            printf("Error opening the file.\n");
            return levelChain;
        }
    }
    char *line = malloc(sizeof(char) * 32);
    while (fgets(line, 32, saveFile)) {
        countLine += 1;
        if (countLine == 36) {
            for (int i = 0; i < 32; i++) {
                if (line[i] == ':') {
                    i += 2;
                    savePos = i;
                    break;
                }
            }
            while (line[savePos] != '.') {
                name = strcat(name, &line[savePos]);
                savePos += 1;
            }
            setName(personnage, name);
        }
        if (countLine > 36 && countLine < 44) {
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
        }
        if (countLine == 38) {
            setMaximumLifePoint(personnage, atoi(value));
        }
        if (countLine == 39) {
            setLifePoint(personnage, atoi(value));
        }
        if (countLine == 40) {
            setStrength(personnage, atoi(value));
        }
        if (countLine == 41) {
            setDefence(personnage, atoi(value));
        }
        if (countLine == 42) {
            setKeys(personnage, atoi(value));
        }
        if (countLine == 43) {
            coordX = atoi(value);
        }
        if (countLine == 44) {
            coordY = atoi(value);
        }
        changeCoordonnes(personnage, coordX, coordY);
    }
    levelChain->current->character = personnage;
    return levelChain;
}

levelChain *getCompliteSave(levelChain *levelChain) {
    levelChain = getLevelBoardSave(levelChain);
    levelChain = getCharacterSave(levelChain);
    return levelChain;
};

// This function is the same as the one in level.c (so non correctly commented) except the monsters part
levelChain *getLevelBoardSave(levelChain *levelChain) {
    char *levelFile = "./src/Levels/save.txt";
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
        (levelChain->next->current->levelNumber == boardElements->levelNumber || boardElements->levelNumber == 1 ||
         boardElements->levelNumber == -1) &&
        levelChain->current->aliveMonsters != -1 && levelChain->current->nbMonsters != -1 &&
        levelChain->current->monstersTab != NULL && levelChain->current->otherLevels != NULL) {

        if (boardElements->levelNumber == 1) {
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
        if (counterLine >= 30) {
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
    if (boardElements->levelNumber == 1) {
        return levelChain;
    }
    levelChain = levelChain->next;
    return levelChain;
}

