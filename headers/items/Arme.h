#ifndef ARME_H
#define ARME_H
#include "item.h"

typedef struct {
    Item base; 
    char qualite[30];
    int attaque_min;
    int attaque_max;
    int perte_oxygene;
    int penetration_armure;
    int equipee;
} Arme;

Arme* creer_arme(int id, const char* nom, const char* qualite, int min, int max, int oxy, int pen);
#endif
