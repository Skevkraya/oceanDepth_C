#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

#include "interface.h"
#include "creatures.h"

Plongeur* creer_joueur(
    int points_de_vie,
    int points_de_vie_max,
    int niveau_oxygene,
    int niveau_oxygene_max,
    int niveau_fatigue,
    int attaque_min,
    int attaque_max,
    int defense,
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
    p->attaque_min = attaque_min;
    p->attaque_max = attaque_max;
    p->defense     = defense;
    p->perles = perles;
    p->isParalyzed = 0;

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

void perdre_oxygene(Plongeur* plongeur, int quantite){
    if (!plongeur) return;
    plongeur->niveau_oxygene -= quantite;
    if (plongeur->niveau_oxygene < 0) {
        plongeur->niveau_oxygene = 0;
    }
};

void gagner_fatigue(Plongeur* plongeur, int quantite)  {
    if (!plongeur) return;
    plongeur->niveau_fatigue += quantite;
    if (plongeur->niveau_fatigue > 5) {
        plongeur->niveau_fatigue = 5;
    }
};

void verifOxygene(Plongeur* plongeur) {
    if (!plongeur) return;
    if (plongeur->niveau_oxygene <= 0) {
        printf("Manque d'oxygène ! Vous perdez 5 PV ...\n");
        plongeur->points_de_vie -= 5;
    }
};

void verifMort(Plongeur* plongeur, CreatureMarine* creatures[], int nb_creatures) {
    if (!plongeur) return;
    if (plongeur->points_de_vie <= 0) {
        printf("Vous êtes mort ! Game Over.\n");
        detruire_plongeur(plongeur);
        if(nb_creatures > 0) {
            for(int i=0; i<nb_creatures; i++) {
                detruire_creature(creatures[i]);
            }
            free(creatures);
        } 
        exit(EXIT_SUCCESS);
    }
};