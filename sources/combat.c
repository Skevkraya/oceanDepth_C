#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combat.h"
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
    if(strcmp(creature->effet_special, "Carapace durcie") == 0) degats -= degats * 0.2;
    if (degats < 1) degats = 1;
    creature->points_de_vie_actuels -= degats;

    int oxygene_perdu = 3;
    int fatigue_gagnee = 1;

    perdre_oxygene(joueur, oxygene_perdu);
    gagner_fatigue(joueur, fatigue_gagnee);

    afficher_attaque_joueur(creature, joueur, degats);
    printf("Oxygène consommé: -%d (action de combat)\n", oxygene_perdu);
    printf("Fatigue augmentée: +%d (effort physique)\n", fatigue_gagnee);
    
    if (creature->points_de_vie_actuels <= 0) {
        creature->points_de_vie_actuels = 0;
        creature->est_vivant = 0;
    } 
};
void afficher_attaque_joueur(CreatureMarine* creature, Plongeur* joueur, int degats) {
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
}

void afficher_attaque_creature(CreatureMarine* creature, Plongeur* joueur, int degats) {
    printf("╔════════════════════ COMBAT SOUS-MARIN ════════════════════╗\n");
    printf("║ Le %s vous attaque                                        ║\n", creature -> nom);
    printf("║                                                           ║\n");
    printf("║                   %s VS PLONGEUR                     ║\n", creature -> nom);
    printf("║                        ♠     🦈                           ║\n");
    printf("║                  ════════►   ◄════════                   ║\n");
    printf("║                                                           ║\n");
    printf("║ Dégâts infligés: %d points                                ║\n", degats);
    printf("╚═══════════════════════════════════════════════════════════╝\n");
}


