#include "save.h"
#include <stdio.h>
#include <stdlib.h>

//TODO: mettre en paramètre le board par la suite et faire les changements
void createSave()
{

    char **board = (char**)malloc(sizeof (char*)*30);
    for(int i=0; i<30; i++){
        board[i] = malloc(sizeof(char)*30);
        board[i] = "#";
    }

    FILE* saveFile;
    saveFile = fopen("saveFile.txt","w+");

    for (int i=0;i<30; i++)
    {   //on parcours par colonne
        for(int j=0; j<30; j++)
        {   //on parcours par ligne
            fprintf(saveFile,"%c",j);
        }
        fprintf(saveFile,"/n");
    }
    fclose(saveFile);
}