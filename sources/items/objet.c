#include "items/objet.h"

static void afficher_objet(Item* item) {
    Objet* o = (Objet*)item;
    printf("💊 %s (effet : %s +%d)\n", o->base.nom, o->effet, o->valeur);
}

static void utiliser_objet(Item* item) {
    Objet* o = (Objet*)item;
    printf("Vous utilisez %s et gagnez %d %s !\n", o->base.nom, o->valeur, o->effet);
}

static void detruire_objet(Item* item) {
    free(item);
}

Objet* creer_objet(int id, const char* nom, const char* effet, int valeur) {
    Objet* o = malloc(sizeof(Objet));
    if (!o) exit(EXIT_FAILURE);

    o->base.id = id;
    strcpy(o->base.nom, nom);
    o->base.type = ITEM_OBJET;
    o->base.afficher = afficher_objet;
    o->base.utiliser = utiliser_objet;
    o->base.detruire = detruire_objet;

    strcpy(o->effet, effet);
    o->valeur = valeur;
    return o;
}
