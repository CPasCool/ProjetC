#include "../../include/src/save.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

// La sauvegarde à besoin du board, d'une liste de monstres,d'une liste avec les niveaux et du personnage
// pour une sauvegarde complète
int createSave(boardElements *boardElements) {
    char *levelFile = "../src/Levels/save.txt";
    FILE* saveFile;

    if (fopen(levelFile, "w+") == 0) {
        printf("impossible d'ouvrir le fichier");
        return 1;
    }
    else
    {
        saveFile=fopen( levelFile, "w+");
    }
    for (int i = 0; i < 30; i++) {//on parcours par colonne
        for (int j = 0; j < 30; j++) {
            //on parcours par ligne
            fprintf(saveFile,"%c", boardElements->board[i][j]);
        }
        fprintf(saveFile, "\n");
    }
    //Une fois le board écrit dans la sauvegarde on écrit les données
    fprintf(saveFile, "East : %s\nSud : %s\nOuest : %s\nNord : %s\n\n", boardElements->otherLevels[0],
              boardElements->otherLevels[1], boardElements->otherLevels[2], boardElements->otherLevels[3]);
    fprintf(saveFile, "Character\nNom : %s.\nMaxPv : %d\nPvActuel : %d\nForce : %d\nArmure : %d\nClé : %d\n"
                      "CoordonnéeX : %d\nCoordonnéesY : %d\n\n", getName(boardElements->character),
            getMaximumLifePoint(boardElements->character), getLifePoint(boardElements->character),
            getStrength(boardElements->character), getDefence(boardElements->character),
            getKeys(boardElements->character), getCharaX(boardElements->character),
            getCharaY(boardElements->character));
    //on utilise la liste des montres pour écrire leurs informations*
    for (int i = 0; i < boardElements->nbMonsters; i++) {

        fprintf(saveFile, "%c\nPv : %d\nForce : %d\nArmure : %d\n", boardElements->monstersTab[i]->type,
                  boardElements->monstersTab[i]->hp, boardElements->monstersTab[i]->strength,
                  boardElements->monstersTab[i]->shield);

    }
    //on écrit les informations du personnage

    fclose(saveFile);
    printf("game has been saved");
    return 0;
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
    FILE* saveFile;

    if (fopen(levelFile, "r") == 0) {
        printf("impossible d'ouvrir le fichier");
        return;
    }
    else
    {
        saveFile=fopen( levelFile, "r");
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
    boardElements->character=personnage;
}

void getLevelBoardSave(boardElements *boardElements) {
    // Initialize board with 0 values except \0 for end of line
    char **board = (char **) malloc(sizeof(char *) * 30);
    for (int i = 0; i < 30; i++) {
        board[i] = malloc(sizeof(char) * 31);
        board[i][30] = '\0';
    }
    char *levelFile = "../src/Levels/save.txt";
    FILE* saveFile;

    if (fopen(levelFile, "r") == 0) {
        printf("impossible d'ouvrir le fichier");
        return;
    }
    else
    {
        saveFile=fopen( levelFile, "r");
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
    FILE* saveFile;

    if (fopen(levelFile, "r") == 0) {
        printf("impossible d'ouvrir le fichier");
        return;
    }
    else
    {
        saveFile=fopen( levelFile, "r");
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

void getMonsterSave(boardElements *boardElements)
{

}