#include "items/combinaison.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 🧥 Fonction d'affichage
static void afficher_combinaison(Item* item) {
    Combinaison* c = (Combinaison*)item;
    printf("🧥 %s (def: %d, oxy: -%d)%s\n",
           c->base.nom,
           c->defense,
           c->perte_oxygene,
           c->equipee ? " [Équipée]" : "");
}

// 👕 Fonction d'utilisation (équiper / retirer)
static void utiliser_combinaison(Item* item) {
    Combinaison* c = (Combinaison*)item;
    if (c->equipee) {
        c->equipee = 0;
        printf("Vous retirez la combinaison %s.\n", c->base.nom);
    } else {
        c->equipee = 1;
        printf("Vous enfilez la combinaison %s.\n", c->base.nom);
    }
}

// 🧹 Destructeur
static void detruire_combinaison(Item* item) {
    free(item);
}

// 🏗️ Constructeur
Combinaison* creer_combinaison(int id, const char* nom, int defense, int perte_oxy) {
    Combinaison* c = malloc(sizeof(Combinaison));
    if (!c) {
        fprintf(stderr, "Erreur : impossible d’allouer une Combinaison\n");
        exit(EXIT_FAILURE);
    }

    // Remplissage du champ parent `Item`
    c->base.id = id;
    strcpy(c->base.nom, nom);
    c->base.type = ITEM_COMBINAISON;

    // Assignation des méthodes “virtuelles”
    c->base.afficher = afficher_combinaison;
    c->base.utiliser = utiliser_combinaison;
    c->base.detruire = detruire_combinaison;

    // Champs spécifiques
    c->defense = defense;
    c->perte_oxygene = perte_oxy;
    c->equipee = 0;

    return c;
}
