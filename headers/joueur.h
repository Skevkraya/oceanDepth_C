#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct {
    int points_de_vie;
    int points_de_vie_max;
    int niveau_oxygene;
    int niveau_oxygene_max;
    int niveau_fatigue; // 0 à 5
    int attaque_min;
    int attaque_max;
    int defense;
    int perles; // monnaie du jeu
} Plongeur;

// Constructeur
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
);

void perdre_oxygene(Plongeur* plongeur, int quantite);
void gagner_fatigue(Plongeur* plongeur, int quantite);

void detruire_plongeur(Plongeur* plongeur);
void afficher_plongeur(Plongeur* plongeur);
#endif
