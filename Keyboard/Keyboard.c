//
// Created by benfa on 17/05/2023.
//

#include "Keyboard.h"
#include <conio.h>
#include "stdio.h"

char catchInput(){
    int letter = getch();
    printf("%c",letter);
    return 'a';
}