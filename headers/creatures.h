#ifndef CREATURES_H
#define CREATURES_H

typedef struct {
    int id;  // identifiant unique pour cibler
    char nom[30];
    int points_de_vie_max;
    int points_de_vie_actuels;
    int attaque_minimale;
    int attaque_maximale;
    int defense;
    int vitesse;
    char effet_special[20]; // "paralysie", "poison", "aucun"
    int est_vivant;
} CreatureMarine;

// Constructeur
CreatureMarine* creer_creature(const CreatureMarine* modele);
void detruire_creature(CreatureMarine* creature);
void afficher_creatures(CreatureMarine* creatures[], int nb_creatures);

extern const CreatureMarine KRAKEN;
extern const CreatureMarine REQUIN;
extern const CreatureMarine MEDUSE;
extern const CreatureMarine POISSON_EPEE;
extern const CreatureMarine CRABE_GEANT;

#endif
