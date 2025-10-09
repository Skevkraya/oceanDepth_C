#ifndef OBJET_H
#define OBJET_H
#include "item.h"

typedef struct {
    Item base;
    char effet[20];
    int valeur;
} Objet;

Objet* creer_objet(int id, const char* nom, const char* effet, int valeur);
#endif
