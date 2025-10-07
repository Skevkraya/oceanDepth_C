#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "joueur.h"
#include "creatures.h"
#include "combat.h"

#define MAX_CREATURES 4


int main(int argc, char const *argv[]) {
    srand(time(NULL));
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    CreatureMarine * creatures[MAX_CREATURES]; 
    int nb_creatures = 0;
          

    Plongeur * joueur = creer_joueur(50, 100, 100, 100, 5, 10, 15, 10, 50);
    afficher_plongeur(joueur);

    if (nb_creatures < MAX_CREATURES) {
        creatures[nb_creatures++] = creer_creature(&REQUIN);
    }
    if (nb_creatures < MAX_CREATURES) {
        creatures[nb_creatures++] = creer_creature(&KRAKEN);
    }

    afficher_creatures(creatures, nb_creatures);

    int running = 1;
    while (running) {
        // actions joueur
        afficher_actions_disponibles();
        printf("Choisissez une action: ");
        int nb_attaques = joueur->niveau_fatigue<2?3:(joueur->niveau_fatigue>=2&&joueur->niveau_fatigue<=3?2:1);
        int action;
        scanf("%d", &action);

        switch (action) {
            case 1:
                if (nb_attaques <= 0) {
                    printf("Vous êtes trop fatigué pour attaquer!\n");
                    break;
                }
                nb_attaques--;
                printf("Attaque effectuée! Attaques restantes: %d\n", nb_attaques);
                CreatureMarine* cible = creatures[0];
                if (nb_creatures > 0) {
                    attaquer_creature(joueur, cible);
                    if (!cible->est_vivant) {
                        detruire_creature(cible);
                        for (int i = 1; i < nb_creatures; i++) {
                            creatures[i - 1] = creatures[i];
                        }
                        nb_creatures--;
                    }
                } else {
                    printf("Aucune créature à attaquer.\n");
                }
                break;
            case 2:
                printf("Compétence marine utilisée!\n");
                break;
            case 3:
                printf("Objet consommé!\n");
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Action invalide. Veuillez réessayer.\n");
        }

        afficher_plongeur(joueur);
        afficher_creatures(creatures, nb_creatures);

        if (joueur->niveau_oxygene <= 10) {
            printf("ALERTE CRITIQUE\n");
        }
        if (joueur->niveau_oxygene <= 0) {
            printf("Manque d'oxygène ! Vous perdez 5 PV ...\n");
            joueur->points_de_vie -= 5;
        }
        
        if(joueur->points_de_vie <= 0) {
            printf("Vous avez perdu !\n");
            running = 0;
        }

        for(int i=0; i<nb_creatures; i++) {
            printf("Au tour du %s", creatures[i]->nom);
            utiliser_capacite_speciale(CreatureMarine* creatures[i], Plongeur* joueur);
            attaquer_plongeur(CreatureMarine* creatures[i], Plongeur* joueur);

        }
    }

    return 0;
}