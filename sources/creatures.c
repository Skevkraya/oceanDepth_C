#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creatures.h"

const CreatureMarine KRAKEN = {1, "Kraken", 180, 180, 25, 40, 10, 5, "aucun", 1};
const CreatureMarine REQUIN = {2, "Requin", 100, 100, 15, 25, 5, 15, "aucun", 1};
const CreatureMarine MEDUSE = {3, "Méduse", 40, 40, 8, 15, 2, 6, "paralysie", 1};
const CreatureMarine POISSON_EPEE = {4, "Poisson-Épée", 90, 90, 18, 28, 7, 10, "aucun", 1};
const CreatureMarine CRABE_GEANT = {5, "Crabe Géant", 120, 120, 12, 20, 20, 4, "aucun", 1};

CreatureMarine* creer_creature(
    int id,
    const char* nom,
    int pv_max,
    int attaque_min,
    int attaque_max,
    int defense,
    int vitesse,
    const char* effet_special
) {
    CreatureMarine* c = malloc(sizeof(CreatureMarine));
    if (!c) {
        fprintf(stderr, "Erreur : impossible d'allouer une CreatureMarine\n");
        exit(EXIT_FAILURE);
    }

    c->id = id;
    strncpy(c->nom, nom, sizeof(c->nom));
    c->nom[sizeof(c->nom) - 1] = '\0'; // sécurité

    c->points_de_vie_max = pv_max;
    c->points_de_vie_actuels = pv_max; // commence full vie
    c->attaque_minimale = attaque_min;
    c->attaque_maximale = attaque_max;
    c->defense = defense;
    c->vitesse = vitesse;

    strncpy(c->effet_special, effet_special, sizeof(c->effet_special));
    c->effet_special[sizeof(c->effet_special) - 1] = '\0';

    c->est_vivant = 1;

    return c;
}

void detruire_creature(CreatureMarine* creature) {
    free(creature);
}

