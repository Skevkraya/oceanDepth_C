#ifndef COMBAT_H
#define COMBAT_H


struct Plongeur;
struct CreatureMarine;


void afficher_actions_combat_disponibles(int nb_attaques);
void attaquer_creature(struct Plongeur* joueur, struct CreatureMarine* creature);
void attaquer_plongeur(struct CreatureMarine* creature, struct Plongeur* joueur);
void afficher_attaque_joueur(struct CreatureMarine* creature, struct Plongeur* joueur, int degats);
void afficher_attaque_creature(struct CreatureMarine* creature, struct Plongeur* joueur, int degats);

#endif
