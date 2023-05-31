//
// Created by benfa on 24/05/2023.
//

#include <stdbool.h>
#include "stdio.h"
#include "Game.h"
#include "../menu/menu.h"
#include "../Keyboard/Keyboard.h"

const int MAXIMUM_CHOICE_MENU = 5;
const int MINIMUM_CHOICE_MENU = 1;



int LaunchGame() {
    printf("Z -> move up\n"
           "S -> move down\n"
           "E -> validate choice\n");

    choiceMenu* menu = createChoiceMenu();
    bool isChoiced = false;
    do {
        int choice = getChoice(menu);

        displayMenu(menu);

        char result = catchInput();
        if (result == 'z'){
            if (choice != MINIMUM_CHOICE_MENU){
                setChoice(menu,choice-1);
            }
        }else if (result == 's'){
            if (choice != MAXIMUM_CHOICE_MENU){
                setChoice(menu,choice+1);
            }
        }else if (result == 'e'){
            isChoiced = true;
            if (choice == 1){
                play();
            }
        }
    } while (!isChoiced);
    return 0;
}

int play() {
    printf("Z -> move up\n"
                  "S -> move down\n"
                  "Q -> move left\n"
                  "D -> move right\n"
                  "P -> pause game");
    return 0;
}