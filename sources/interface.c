#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void afficher_jauge(int valeur, int max, int longueur) {
    if (max <= 0 || longueur <= 0) return; // sécurité

    // proportion de "plein"
    float ratio = (float)valeur / max;
    if (ratio > 1.0f) ratio = 1.0f;   // clamp max
    if (ratio < 0.0f) ratio = 0.0f;   // clamp min

    int nb_plein = (int)(ratio * longueur);    // nombre de █
    int nb_vide  = longueur - nb_plein;        // nombre de ▒

    // affichage
    printf("[");
    for (int i = 0; i < nb_plein; i++) printf("█");
    for (int i = 0; i < nb_vide; i++) printf("▒");
    printf("]");

    // afficher les valeurs numériques à côté
    printf(" %d/%d\n", valeur, max);
}

void attendre_entree() {
    printf("\nAppuyez sur ENTRÉE pour continuer...\n");

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    getchar();
}

