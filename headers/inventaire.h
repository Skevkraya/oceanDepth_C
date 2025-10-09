#ifndef INVENTAIRE_H
#define INVENTAIRE_H
#include "items/item.h"
#include "items/arme.h"
#include "items/objet.h"
#include "items/combinaison.h"

#define NB_SLOTS 8

typedef struct {
    Item* slots[NB_SLOTS];
} Inventaire;

void ajouter_item(Inventaire* inv, Item* item);
void afficher_inventaire(Inventaire* inv);
void detruire_inventaire(Inventaire* inv);



// MODÈLES PRÉDÉFINIS
Arme* creer_trident_rouille(void);
Arme* creer_harpon_classique(void);
Arme* creer_harpon_elec(void);
Arme* creer_harpon_laser(void);

Combinaison* creer_neoprene_basique(void);
Combinaison* creer_comb_carbone(void);
Combinaison* creer_armure_titanium(void);

Objet* creer_capsule_oxygene(void);
Objet* creer_trousse_soin(void);
Objet* creer_stimulant_marin(void);
Objet* creer_antidote(void);


#endif

//🧰
