#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "joueur.h"
#include "creatures.h"


void afficher_actions_disponibles() {
    puts("Actions disponibles:");
    puts(" 1 - Attaquer avec harpon (2 attaques restantes)");
    puts(" 2 - Utiliser compétence marine");
    puts(" 3 - Consommer objet");
    puts(" 4 - Terminer le tour");
}

void attaquer_creature(Plongeur* joueur, CreatureMarine* creature) {
    int degats_base = rand() % (joueur->attaque_max - joueur->attaque_min + 1) + joueur->attaque_min;
    int degats = degats_base - creature->defense;
    if (degats < 1) degats = 1;
    creature->points_de_vie_actuels -= degats;
    printf("╔════════════════════ COMBAT SOUS-MARIN ════════════════════╗\n");
    printf("║ Vous attaquez le %s avec votre Harpon Rouillé   ║\n", creature -> nom);
    printf("║                                                           ║\n");
    printf("║                   PLONGEUR VS %s                     ║\n", creature -> nom);
    printf("║                        ♠     🦈                           ║\n");
    printf("║                  ════════►   ◄════════                   ║\n");
    printf("║                                                           ║\n");
    printf("║ Dégâts infligés: %d points                                ║\n", degats);
    // printf("║ Le %s riposte! Vous perdez 18 points de vie     ║\n", creature -> nom);
    printf("╚═══════════════════════════════════════════════════════════╝\n");
    printf("Oxygène consommé: -3 (action de combat)\n");
    printf("Fatigue augmentée: +1 (effort physique)\n");
    
    if (creature->points_de_vie_actuels <= 0) {
        creature->points_de_vie_actuels = 0;
        creature->est_vivant = 0;
    } 
};

void attaquer_plongeur(CreatureMarine* creature, Plongeur* joueur) {

};