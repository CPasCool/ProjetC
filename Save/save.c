#include "save.h"
#include <stdio.h>
#include <stdlib.h>

// La sauvegarde à besoin du board, d'une liste de monstres,d'une liste avec les niveaux et du personnage
// pour une sauvegarde complète
void createSave(char **board,monster* *ListOfMonster,Character* personnage,char **otherLevel)
{
    FILE* saveFile;
    saveFile = fopen("saveFile.txt","w+");

    for (int i=0;i<30; i++)
    {   //on parcours par colonne
        for(int j=0; j<30; j++)
        {   //on parcours par ligne
            fprintf(saveFile,"%c",board[i][j]);
        }
        fprintf(saveFile,"\n");
    }
    //Une fois le board écrit dans la sauvegarde on écrit les données
    fprintf(saveFile,"East : %s\nSud : %s\nOuest : %s\nNord : %s\n\n",otherLevel[0],otherLevel[1]
            ,otherLevel[2],otherLevel[3]);
    //on utilise la liste des montres pour écrire leurs informations
    fprintf(saveFile, "A\nPv : %d\nForce : %d\nArmure : %d\n\n", getMonsterHealth(ListOfMonster[0]),
            getMonsterStrength(ListOfMonster[0]), getMonsterShield(ListOfMonster[0]));
    fprintf(saveFile, "B\nPv : %d\nForce : %d\nArmure : %d\n\n", getMonsterHealth(ListOfMonster[1]),
            getMonsterStrength(ListOfMonster[1]), getMonsterShield(ListOfMonster[1]));
    fprintf(saveFile, "C\nPv : %d\nForce : %d\nArmure : %d\n\n", getMonsterHealth(ListOfMonster[0]),
            getMonsterStrength(ListOfMonster[2]), getMonsterShield(ListOfMonster[2]));
    //on écrit les informations du personnage
    fprintf(saveFile,"Character\nNom : %s.\nMaxPv : %d\nPvActuel : %d\nForce : %d\nArmure : %d\nClé : %d\n"
                     "CoordonnéeX : %d\nCoordonnéesY : %d",getName(personnage),getMaximumLifePoint(personnage)
                     ,getLifePoint(personnage),getStrength(personnage),getDefence(personnage),
                     getKeys(personnage),getCharaX(personnage),getCharaY(personnage));
    fclose(saveFile);
}