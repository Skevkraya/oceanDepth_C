#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct {
    int points_de_vie;
    int points_de_vie_max;
    int niveau_oxygene;
    int niveau_oxygene_max;
    int niveau_fatigue; // 0 à 5
    int perles; // monnaie du jeu
} Plongeur;

// Constructeur
Plongeur* creer_joueur(
    int points_de_vie,
    int points_de_vie_max,
    int niveau_oxygene,
    int niveau_oxygene_max,
    int niveau_fatigue,
    int perles
);

void detruire_plongeur(Plongeur* plongeur);
void afficher_plongeur(Plongeur* plongeur);
#endif
