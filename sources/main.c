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
        afficher_actions_disponibles();
        printf("Choisissez une action: ");
        int action;
        scanf("%d", &action);

        switch (action) {
            case 1:
            CreatureMarine* cible = creatures[0];
                if (nb_creatures > 0) {
                    attaquer_creature(joueur, creatures[0]);
                    if (!creatures[0]->est_vivant) {
                        detruire_creature(creatures[0]);
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
    }

    return 0;
}