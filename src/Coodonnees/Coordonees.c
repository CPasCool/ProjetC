# include <stdlib.h>
#include "Coordonees.h"

coordonees *createCoordonne(int x, int y){
    coordonees *coo = (coordonees*)malloc(sizeof (struct Coordonees));
    coo->x = x;
    coo->y = y;
    return coo;
}

int getX(coordonees *coordonees) {
    return coordonees->x;
}

int getY(coordonees *coordonees) {
    return coordonees->y;
}

coordonees *setCoordonees(coordonees *coo, int x, int y){
    coo->x = x;
    coo->y = y;
    return coo;
}

coordonees *setX(coordonees *coo, int x){
    coo->x = x;
    return coo;
}

coordonees *setY(coordonees *coo, int y){
    coo->y = y;
    return coo;
}

