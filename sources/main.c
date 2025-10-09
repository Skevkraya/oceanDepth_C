#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "joueur.h"
#include "creatures.h"
#include "combat.h"
#include "inventaire.h"


#define MAX_CREATURES 4


int main(int argc, char const *argv[]) {
    srand(time(NULL));
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    CreatureMarine * creatures[MAX_CREATURES]; 
    int nb_creatures = 0;
          

    Plongeur * joueur = creer_joueur(50, 100, 100, 100, 0, 10, 15, 10, 50);
    afficher_plongeur(joueur);

    if (nb_creatures < MAX_CREATURES) {
        creatures[nb_creatures++] = creer_creature(&REQUIN);
    }
    if (nb_creatures < MAX_CREATURES) {
        creatures[nb_creatures++] = creer_creature(&KRAKEN);
    }

    afficher_creatures(creatures, nb_creatures);

    int running = 0;
    while (running) {
        int nb_attaques = joueur->niveau_fatigue<2?3:(joueur->niveau_fatigue>=2&&joueur->niveau_fatigue<=3?2:1);

        // Tour du joueur 
        while(nb_attaques>0 && nb_creatures>0) {
            afficher_actions_combat_disponibles(nb_attaques);
            printf("Choisissez une action: ");
            int action;
            scanf("%d", &action);
            switch (action) {
                case 1:
                    if (nb_attaques <= 0) {
                        printf("Vous êtes trop fatigué pour attaquer!\n");
                        break;
                    }
                    
                        CreatureMarine* cible = creatures[0];
                        if (nb_creatures > 0) {
                            attaquer_creature(joueur, cible);
                            nb_attaques--;
                            printf("Attaque effectuée! Attaques restantes: %d\n", nb_attaques);
                            afficher_creatures(creatures, nb_creatures);
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
            if(nb_creatures<0) {
                printf("Toutes les créatures ont été vaincues !\n");
            }
        }

        afficher_plongeur(joueur);
        attendre_entree();
        afficher_creatures(creatures, nb_creatures);
        attendre_entree();

        if (joueur->niveau_oxygene <= 10) {
            printf("ALERTE CRITIQUE\n");
        }

        // Vérifier taux oxygène
        verifOxygene(joueur);
        // Vérifier si le joueur est mort
        verifMort(joueur, creatures, nb_creatures);
        // Enlever statuts 
        cancelParalized(joueur);

        // Attaques créatures
        for(int i=0; i<nb_creatures; i++) {
            printf("Au tour du %s\n", creatures[i]->nom);
            utiliser_capacite_speciale(creatures[i], joueur);
            attaquer_plongeur(creatures[i], joueur);
            attendre_entree();
            afficher_plongeur(joueur);
            verifMort(joueur, creatures, nb_creatures);
            attendre_entree();
        }

    }


    // TEST
    Inventaire inv = {0};



    ajouter_item(&inv, (Item*)creer_harpon_laser());
    ajouter_item(&inv, (Item*)creer_trousse_soin());
    ajouter_item(&inv, (Item*)creer_armure_titanium());

    afficher_inventaire(&inv);

    printf("\nUtilisation du slot 0 :\n");
    inv.slots[0]->utiliser(inv.slots[0]);

    detruire_inventaire(&inv);

    return 0;
}