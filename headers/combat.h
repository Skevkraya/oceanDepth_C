#ifndef COMBAT_H
#define COMBAT_H

#include "joueur.h"
#include "creatures.h"

void afficher_actions_disponibles();
void attaquer_creature(Plongeur* joueur, CreatureMarine* creature);
void attaquer_plongeur(CreatureMarine* creature, Plongeur* joueur);

#endif

//Actions disponibles:
// 1 - Attaquer avec harpon (2 attaques restantes)
// 2 - Utiliser compétence marine
// 3 - Consommer objet
// 4 - Terminer le tour