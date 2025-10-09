#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ITEM_ARME,
    ITEM_COMBINAISON,
    ITEM_OBJET
} ItemType;

// Prototype avant définition (pointeurs de fonction)
typedef struct Item Item;

struct Item {
    int id;
    char nom[30];
    ItemType type;

    // “Méthodes” (pointeurs de fonction)
    void (*afficher)(Item*);
    void (*utiliser)(Item*);
    void (*detruire)(Item*);
};

#endif
