#include "inventaire.h"
#include <stdio.h>
#include <stdlib.h>

void ajouter_item(Inventaire* inv, Item* item) {
    for (int i = 0; i < NB_SLOTS; i++) {
        if (!inv->slots[i]) {
            inv->slots[i] = item;
            return;
        }
    }
    printf("Inventaire plein !\n");
}

void afficher_inventaire(Inventaire* inv) {
    printf("=== INVENTAIRE ===\n");
    for (int i = 0; i < NB_SLOTS; i++) {
        if (inv->slots[i])
            inv->slots[i]->afficher(inv->slots[i]);
        else
            printf("[%d] (vide)\n", i);
    }
}

void detruire_inventaire(Inventaire* inv) {
    for (int i = 0; i < NB_SLOTS; i++) {
        if (inv->slots[i]) {
            inv->slots[i]->detruire(inv->slots[i]);
            inv->slots[i] = NULL;
        }
    }
}

// MODÈLES PRÉDÉFINIS

// Armes
Arme* creer_trident_rouille(void)   { return creer_arme(1, "🔱 Trident Rouillé", "Commun", 10, 15, 3, 1); }
Arme* creer_harpon_classique(void)  { return creer_arme(2, "🔱 Harpon Classique", "Peu Commun", 18, 25, 4, 2); }
Arme* creer_harpon_elec(void)       { return creer_arme(3, "🔱 Harpon Électrique", "Rare", 28, 42, 4, 3); }
Arme* creer_harpon_laser(void)      { return creer_arme(4, "🔱 Harpon Laser", "Épique", 35, 50, 5, 4); }

// Combinaisons
Combinaison* creer_neoprene_basique(void) { return creer_combinaison(1, "🧥 Combinaison Néoprène", 5, 2); }
Combinaison* creer_comb_carbone(void)     { return creer_combinaison(2, "🧥 Combinaison Carbone", 15, 3); }
Combinaison* creer_armure_titanium(void)  { return creer_combinaison(3, "🧥 Armure Titanium", 25, 4); }

// Objets
Objet* creer_capsule_oxygene(void) { return creer_objet(1, "💊 Capsule d'Oxygène", "oxygene", 40); }
Objet* creer_trousse_soin(void)    { return creer_objet(2, "🩹 Trousse de Soin", "soin", 25); }
Objet* creer_stimulant_marin(void) { return creer_objet(3, "💉 Stimulant Marin", "fatigue", 2); }
Objet* creer_antidote(void)        { return creer_objet(4, "🧪 Antidote", "antidote", 0); }