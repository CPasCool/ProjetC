//
// Created by benfa on 17/05/2023.
//

#include "Keyboard.h"
#include <conio.h>
#include <stdarg.h>

/**
 *  catch input and use on player or menu
 * @param count : number of parameter
 * @param ... optional parameter for character
 * @return
 */
int catchInput(int count, ...) {
    va_list ap;
    Character *character;
    va_start(ap, count);
    character = va_arg(ap, Character*);
    va_end(ap);
    int letter = getch();
    if (character != NULL) {
        if (letter == 'Z' || letter == 'z') {
            moveUp(character);
        }
        if (letter == 'S' || letter == 's') {
            moveDown(character);
        }
        if (letter == 'Q' || letter == 'q') {
            moveLeft(character);
        }
        if (letter == 'D' || letter == 'd') {
            moveRight(character);
        }
        return letter;
    } else {
        // TODO : use menu
        return letter;
    }
}