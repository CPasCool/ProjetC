#include "../../include/src/save.h"
#include <stdio.h>
#include <stdlib.h>

// La sauvegarde à besoin du board, d'une liste de monstres,d'une liste avec les niveaux et du personnage
// pour une sauvegarde complète
void createSave(boardElements *boardElements)
{
    FILE* saveFile;
    saveFile = fopen("saveFile.txt","w+");

    for (int i=0;i<30; i++)
    {   //on parcours par colonne
        for(int j=0; j<30; j++)
        {   //on parcours par ligne
            fprintf(saveFile,"%c",boardElements->board[i][j]);
        }
        fprintf(saveFile,"\n");
    }
    //Une fois le board écrit dans la sauvegarde on écrit les données
    fprintf(saveFile,"East : %s\nSud : %s\nOuest : %s\nNord : %s\n\n",boardElements->otherLevels[0],boardElements->otherLevels[1]
            ,boardElements->otherLevels[2],boardElements->otherLevels[3]);
    //on utilise la liste des montres pour écrire leurs informations*
    for(int i=0;i<boardElements->nbMonsters;i++)
    {
        fprintf(saveFile, "%c\nPv : %d\nForce : %d\nArmure : %d\n\n", boardElements->monstersTab[i]->type,
                boardElements->monstersTab[i]->hp,boardElements->monstersTab[i]->strength,
                boardElements->monstersTab[i]->shield);

    }
    //on écrit les informations du personnage
    fprintf(saveFile,"Character\nNom : %s.\nMaxPv : %d\nPvActuel : %d\nForce : %d\nArmure : %d\nClé : %d\n"
                     "CoordonnéeX : %d\nCoordonnéesY : %d",getName(boardElements->character),
                     getMaximumLifePoint(boardElements->character),getLifePoint(boardElements->character),
                     getStrength(boardElements->character),getDefence(boardElements->character),
                     getKeys(boardElements->character),getCharaX(boardElements->character),
                     getCharaY(boardElements->character));
    fclose(saveFile);
}