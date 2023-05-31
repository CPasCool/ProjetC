#ifndef PROJETC_COORDONEES_H
#define PROJETC_COORDONEES_H

typedef struct Coordonees {
    int x;
    int y;
} coordonees;

coordonees *createCoordonne(int x, int y);
int getX(coordonees *coordonees);
int getY(coordonees *coordonees);
coordonees *setX(coordonees *coordonees, int x);
coordonees *setY(coordonees *coordonees, int y);
coordonees *setCoordonees(coordonees *coordonees, int x, int y);

#endif //PROJETC_COORDONEES_H
