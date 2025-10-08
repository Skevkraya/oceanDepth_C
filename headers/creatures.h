#ifndef CREATURES_H
#define CREATURES_H

struct Plongeur;

typedef struct CreatureMarine {
    int id;
    char nom[30];
    int points_de_vie_max;
    int points_de_vie_actuels;
    int attaque_min;
    int attaque_max;
    int defense;
    int vitesse;
    char effet_special[30];
    int est_vivant;
} CreatureMarine;

CreatureMarine* creer_creature(const CreatureMarine* modele);
void detruire_creature(CreatureMarine* creature);
void afficher_creatures(CreatureMarine* creatures[], int nb_creatures);
void attaquer_plongeur(CreatureMarine* creature, struct Plongeur* joueur);
void utiliser_capacite_speciale(CreatureMarine* creature, struct Plongeur* joueur);
void cancelParalized(struct Plongeur* joueur);

extern const CreatureMarine KRAKEN;
extern const CreatureMarine REQUIN;
extern const CreatureMarine MEDUSE;
extern const CreatureMarine POISSON_EPEE;
extern const CreatureMarine CRABE_GEANT;

#endif
