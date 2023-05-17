#include <stdio.h>
#include "menu.h"

void afficheCredit(){
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#       Jeu réalisé par      #\n"
            "#      Korentin KOLACZEK     #\n"
            "#       Benoit Fardoux       #\n"
            "#        Edouard Hoest       #\n"
            "#      Baptiste Lemattre     #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#     1 - retour au menu     #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################");
}
void afficheMenu(){
    printf(
            "##############################\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#    1 -   lancer le jeu     #\n"
            "#    2 -    credit           #\n"
            "#    3 -    quitter          #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#        Bon chance :)       #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "#                            #\n"
            "##############################"
    );
}

int menu(){
    int choix;
    afficheMenu();
    printf("Entrer votre choix");
    scanf("%d", &choix);
    if (choix == 1)
    {
        printf("jeu lancer");
    }else if (choix == 2)
    {
        credit();
    } else {
        return 1;
    }   
}

void credit() {
    int choix;
    afficheCredit();
    printf("Entrer votre choix : ");
    scanf("%d", &choix);
    menu();
}
