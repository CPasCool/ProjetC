#include "save.h"
#include <stdio.h>
#include <stdlib.h>

//TODO: mettre en paramètre le board par la suite et faire les changements
//TODO: pouvoir sauvegarder les monstres et le personnage
void createSave(char **board)
{
    FILE* saveFile;
    saveFile = fopen("saveFile.txt","w+");

    for (int i=0;i<30; i++)
    {   //on parcours par colonne
        for(int j=0; j<30; j++)
        {   //on parcours par ligne
            fprintf(saveFile,"%s",board[j]);
        }
        fprintf(saveFile,"%s","/n");
    }

    fclose(saveFile);
    //TODO: faire ressembler au fichier de level
}