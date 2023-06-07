#include "../../include/src/save.h"
#include <stdio.h>
#include <stdlib.h>

// La sauvegarde à besoin du board, d'une liste de monstres,d'une liste avec les niveaux et du personnage
// pour une sauvegarde complète
void createSave(boardElements *boardElements) {
    char *levelFile = "./src/Levels/save.level";
    FILE *saveFile;
    fopen_s(&saveFile, levelFile, "w+");
    if (fopen_s(&saveFile, levelFile, "w+") != 0) {
        printf("test");
        char* newLevelFilename = malloc (sizeof (char)*28);
        newLevelFilename[27] = '\0';
        char *prefixFile = ".";
        for (int j = 0; j < 27; j++) {
            if (j < 1) {
                newLevelFilename[j] = prefixFile[j];
            } else {
                newLevelFilename[j] = levelFile[j - 1];
            }
        }
        fopen_s(&saveFile, newLevelFilename, "w+");
        if (fopen_s(&saveFile, newLevelFilename, "w+") != 0) {
            printf("Error opening the file.\n");
            return;
        }
    }
    for (int i = 0; i < 30; i++) {   //on parcours par colonne
        for (int j = 0; j < 30; j++) {   //on parcours par ligne
            fprintf(saveFile, "%c", boardElements->board[i][j]);
        }
        fprintf(saveFile, "\n");
    }
    //Une fois le board écrit dans la sauvegarde on écrit les données
    fprintf(saveFile, "East : %s\nSud : %s\nOuest : %s\nNord : %s\n\n", boardElements->otherLevels[0],
            boardElements->otherLevels[1], boardElements->otherLevels[2], boardElements->otherLevels[3]);
    //on utilise la liste des montres pour écrire leurs informations*
    for (int i = 0; i < boardElements->nbMonsters; i++) {
        fprintf(saveFile, "%c\nPv : %d\nForce : %d\nArmure : %d\n\n", boardElements->monstersTab[i]->type,
                boardElements->monstersTab[i]->hp, boardElements->monstersTab[i]->strength,
                boardElements->monstersTab[i]->shield);

    }
    //on écrit les informations du personnage
    fprintf(saveFile, "Character\nNom : %s.\nMaxPv : %d\nPvActuel : %d\nForce : %d\nArmure : %d\nClé : %d\n"
                      "CoordonnéeX : %d\nCoordonnéesY : %d", getName(boardElements->character),
            getMaximumLifePoint(boardElements->character), getLifePoint(boardElements->character),
            getStrength(boardElements->character), getDefence(boardElements->character),
            getKeys(boardElements->character), getCharaX(boardElements->character),
            getCharaY(boardElements->character));
    fclose(saveFile);
    printf("game has been saved");
}