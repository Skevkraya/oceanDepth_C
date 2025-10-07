#ifndef COMBAT_H
#define COMBAT_H

#include "joueur.h"
#include "creatures.h"

void afficher_actions_disponibles();
int attaquer_creature(Plongeur* joueur, CreatureMarine* creature);
void attaquer_plongeur(CreatureMarine* creature, Plongeur* joueur);
void afficher_attaque_joueur(CreatureMarine* creature, Plongeur* joueur, int degats);
void afficher_attaque_creature(CreatureMarine* creature, Plongeur* joueur, int degats);

#endif

//Actions disponibles:
// 1 - Attaquer avec harpon (2 attaques restantes)
// 2 - Utiliser compétence marine
// 3 - Consommer objet
// 4 - Terminer le tour