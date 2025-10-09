#ifndef COMBINAISON_H
#define COMBINAISON_H
#include "item.h"

typedef struct {
    Item base;
    int defense;
    int perte_oxygene;
    int equipee;
} Combinaison;

Combinaison* creer_combinaison(int id, const char* nom, int defense, int perte_oxy);

#endif
