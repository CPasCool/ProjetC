#include <stdio.h>
#include <stdbool.h>
#include "Board/CreateBoard.h"
#include "Tests/Character/TestCharacter.h"
#include "Tests/Monsters/MonstersTests.h"
#include "menu/menu.h"

int main() {
    /*testCharacter();
    testMonster();
    generateBoard();*/
    choixMenu* choixMenu = createChoixMenu();
    bool choixFait = false;
    /*TestCharacter();
    generateBoard();*/
    lancementMenu(choixMenu); 
    int choix;
    while (choixFait == false)
    {
        printf("entrer votre choix");
        scanf("%d",choix);
        setChoixMenu(choixMenu,choix);
        afficheMenu(getChoix(choixMenu));
    }
    return 0;
}
