#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creatures.h"
#include "joueur.h"

#define MAX_CREATURES 4

const CreatureMarine KRAKEN = {1, "🐙 Kraken", 180, 180, 25, 40, 10, 5, "Etreinte tentaculaire", 1};
const CreatureMarine REQUIN = {2, "🦈 Requin", 100, 100, 15, 25, 5, 15, "Piqûre paralysante", 1};
const CreatureMarine MEDUSE = {3, "🪼 Méduse", 40, 40, 8, 15, 2, 6, "Frénésie sanguinaire", 1};
const CreatureMarine POISSON_EPEE = {4, "🐠 Poisson-Épée", 90, 90, 18, 28, 7, 10, "Charge perforante", 1};
const CreatureMarine CRABE_GEANT = {5, "🦀 Crabe Géant", 120, 120, 12, 20, 20, 4, "Carapace durcie", 1};

CreatureMarine* creer_creature(const CreatureMarine* modele) {
    CreatureMarine* c = malloc(sizeof(CreatureMarine));
    if (!c) {
        fprintf(stderr, "Erreur : impossible d'allouer une CreatureMarine\n");
        exit(EXIT_FAILURE);
    }

    *c = *modele; 
    c->points_de_vie_actuels = c->points_de_vie_max;
    c->est_vivant = 1;

    return c;
}

void detruire_creature(CreatureMarine* creature) {
    free(creature);
}

void afficher_creatures(CreatureMarine* creatures[], int nb_creatures) {
    if (nb_creatures == 0) {
        printf("Aucune créature.\n");
        return;
    }

    int largeur = 20;

    for (int i = 0; i < nb_creatures; i++) {
        printf("%-*s", largeur, creatures[i]->nom);
    }
    printf("\n");

    for (int i = 0; i < nb_creatures; i++) {
        char texte[32];
        snprintf(texte, sizeof(texte), "%d/%d",
                 creatures[i]->points_de_vie_actuels,
                 creatures[i]->points_de_vie_max);
        printf("%-*s", largeur, texte);
    }
    printf("\n");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

void attaquer_plongeur(CreatureMarine* creature, Plongeur* joueur) {
    int degats_base = rand() % (creature->attaque_max - creature->attaque_min + 1) + creature->attaque_min;
    int degats = degats_base - joueur->defense;
    if (degats < 1) degats = 1;
    joueur->points_de_vie_actuels -= degats;
    joueur->niveau_oxygene -= (rand() % 2)+1;
}

void utiliser_capacite_speciale(CreatureMarine* creature, Plongeur* joueur) {
    if (strcmp(creature->effet_special, "Etreinte tentaculaire") == 0) {
        printf("%s ! Le %s attaque deux fois !\n", creature->effet_special, creature->nom);
        attaquer_plongeur(CreatureMarine* creature, Plongeur* joueur);

    } else if (strcmp(creature->effet_special, "Piqûre paralysante") == 0) {
        printf("%s ! Le joueur sera paralysé au prochain tour!\n", creature->effet_special);
        joueur->isParalyzed=1;

    } else if (strcmp(creature->effet_special, "Frénésie sanguinaire") == 0) {
        printf("%s ! Le %s entre en frénésie !\n", creature->effet_special, creature->nom);


    } else if (strcmp(creature->effet_special, "Charge perforante") == 0) {
        printf("%s ! Le %s ignore la défense du plongeur !\n", creature->effet_special, creature->nom);

    } else if (strcmp(creature->effet_special, "Carapace durcie") == 0) {
        printf("%s ! Le %s durcit sa carapace !\n", creature->effet_special, creature->nom);


    } else {
        printf("Capacité spéciale '%s' inconnue.\n", creature->effet_special);
    }
}