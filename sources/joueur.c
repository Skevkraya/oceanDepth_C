// OceanDepths - Profondeur: -247m Perles: 42
// Vie [█████████████████████████████████████████████
// ███████▒▒▒▒] 87/100
// Oxygène [██████████████████████████████████▒▒▒▒▒▒▒▒▒
// ▒▒▒▒▒▒▒▒▒] 58/100
// Fatigue [███▒▒▒▒▒] 3/5
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"
#include "interface.h"

Plongeur* creer_joueur(
    int points_de_vie,
    int points_de_vie_max,
    int niveau_oxygene,
    int niveau_oxygene_max,
    int niveau_fatigue,
    int perles
) {
    Plongeur* p = malloc(sizeof(Plongeur));
    if (!p) {
        fprintf(stderr, "Erreur : impossible d'allouer un Plongeur\n");
        exit(EXIT_FAILURE);
    }

    p->points_de_vie = points_de_vie;
    p->points_de_vie_max = points_de_vie_max;
    p->niveau_oxygene = niveau_oxygene;
    p->niveau_oxygene_max = niveau_oxygene_max;
    p->niveau_fatigue = niveau_fatigue;
    p->perles = perles;

    return p;
}

void detruire_plongeur(Plongeur* plongeur) {
    free(plongeur);
}

void afficher_plongeur(Plongeur* plongeur) {
    if (!plongeur) return;

    printf("OceanDepths - Profondeur: -247m             Perles: %d\n", plongeur->perles);
    printf("Vie ");
    afficher_jauge(plongeur->points_de_vie, plongeur->points_de_vie_max,30);
    printf("\n");
    printf("Oxygène ");
    afficher_jauge(plongeur->niveau_oxygene, plongeur->niveau_oxygene_max,30);
    printf("\n");
    printf("Fatigue ");
    afficher_jauge(plongeur->niveau_fatigue, 5,30);
    puts("");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

}
