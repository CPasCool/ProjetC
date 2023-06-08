#include "../../include/src/Keyboard.h"
#include <conio.h>
#include <stdarg.h>

/**
 *  catch input and use on player or menu
 * @param count : number of parameter
 * @param ... optional parameter for character
 * @return
 */
char catchInput() {
    int letter = getch();
    if (letter == 'Z' || letter == 'z') {
        return 'z';
    } else if (letter == 'S' || letter == 's') {
        return 's';
    } else if (letter == 'Q' || letter == 'q') {
        return 'q';
    } else if (letter == 'D' || letter == 'd') {
        return 'd';
    } else if (letter == 'E' || letter == 'e') {
        return 'e';
    }else if (letter == 'P' || letter == 'p') {
        return 'p';
    }else if (letter == 'M' || letter == 'm') {
        return 'm';
    } else {
        return ' ';
    }
}