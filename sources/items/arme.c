#include "items/arme.h"

static void afficher_arme(Item* item) {
    Arme* a = (Arme*)item;
    printf("%s [%d-%d] (oxy -%d, pen %d)\n",
           a->base.nom, a->attaque_min, a->attaque_max,
           a->perte_oxygene, a->penetration_armure);
}

static void utiliser_arme(Item* item) {
    Arme* a = (Arme*)item;
    printf("Vous attaquez avec %s !\n", a->base.nom);
}

static void detruire_arme(Item* item) {
    free(item);
}

Arme* creer_arme(int id, const char* nom, const char* qualite, int min, int max, int oxy, int pen) {
    Arme* a = malloc(sizeof(Arme));
    if (!a) {
        fprintf(stderr, "Erreur : impossible d’allouer une Arme\n");
        exit(EXIT_FAILURE);
    }

    a->base.id = id;
    strcpy(a->base.nom, nom);
    a->base.type = ITEM_ARME;

    a->base.afficher = afficher_arme;
    a->base.utiliser = utiliser_arme;
    a->base.detruire = detruire_arme;

    strcpy(a->qualite, qualite); 
    a->attaque_min = min;
    a->attaque_max = max;
    a->perte_oxygene = oxy;
    a->penetration_armure = pen;
    a->equipee = 0;

    return a;
}

