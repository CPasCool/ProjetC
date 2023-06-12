#include "../../include/src/save.h"
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

// La sauvegarde à besoin du board, d'une liste de monstres,d'une liste avec les niveaux et du personnage
// pour une sauvegarde complète
int createSave(levelChain *levelChain) {
    char *levelFile = "../src/Levels/save1.txt";
    FILE *levelPointer;
    int errorCount = 0;

    levelPointer = fopen(levelFile, "w+");
    // Send an error if the file does not exist
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
    //on utilise la liste des montres pour écrire leurs informations*
    for (int i = 0; i < levelChain->current->nbMonsters; i++) {

        fprintf(levelPointer, "%c\nPv : %d\nForce : %d\nArmure : %d\n", levelChain->current->monstersTab[i]->type,
                levelChain->current->monstersTab[i]->hp, levelChain->current->monstersTab[i]->strength,
                levelChain->current->monstersTab[i]->shield);

    }
    //on écrit les informations du personnage

    fclose(levelPointer);
    printf("game saved successfully");
    return 1;
}

//comme il n'y a que un seul fichier de sauvegarde pas besoin de paramètre
void getCharacterSave(boardElements *boardElements) {
    Character *personnage = createCharacter("");
    char *name;
    int countLine = 0;
    int savePos = 0;
    int coordX = 0;
    int coordY = 0;
    char *value = malloc(sizeof(char) * 4);
    char *levelFile = "../src/Levels/save.txt";
    FILE *saveFile;

    if (fopen(levelFile, "r") == 0) {
        printf("impossible d'ouvrir le fichier");
        return;
    } else {
        saveFile = fopen(levelFile, "r");
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
    boardElements->character = personnage;
}

void getLevelBoardSave(boardElements *boardElements) {
    // Initialize board with 0 values except \0 for end of line
    char **board = (char **) malloc(sizeof(char *) * 30);
    for (int i = 0; i < 30; i++) {
        board[i] = malloc(sizeof(char) * 31);
        board[i][30] = '\0';
    }
    char *levelFile = "../src/Levels/save.txt";
    FILE *saveFile;

    if (fopen(levelFile, "r") == 0) {
        printf("impossible d'ouvrir le fichier");
        return;
    } else {
        saveFile = fopen(levelFile, "r");
    }
    char letter = (char) fgetc(saveFile);
    int counterLine = 0;
    int counterLetter = 0;

    //read the file util the board ended so until we see the E of East(Est)
    while (counterLine <= 30 && letter != 'E') {

        //Print the § character --> -62 = special character ascii then skip the ° symbol because the § is split in UTF-8
        if (letter == (char) -62 || letter == 'P') {
            if (letter != 'P') {
                letter = (char) fgetc(saveFile);
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
        letter = (char) fgetc(saveFile);
    }
    printf("We got the board\n");
    fclose(saveFile);
    boardElements->board = board;
}

void getOtherLevelsSave(boardElements *boardElements) {

    // Initialize the levels array with empty strings
    int errorCount = 0;
    char *levelFile = "../src/Levels/save.txt";
    FILE *saveFile;

    if (fopen(levelFile, "r") == 0) {
        printf("impossible d'ouvrir le fichier");
        return;
    } else {
        saveFile = fopen(levelFile, "r");
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
    fgets(line, 32, saveFile);

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
        line = fgets(line, 32, saveFile);
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
            strcpy(levels[i], prefixedLevelName);
        }
        if (errorCount > 0) {
            prefix = "../src/Levels/";
        } else {
            prefix = "./src/Levels/";
        }
    }
    printf("We got the other levels\n");
    fclose(saveFile);
    boardElements->otherLevels = levels;
}

void getMonsterSave(boardElements *boardElements) {

}