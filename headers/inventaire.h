#ifndef INVENTAIRE_H
#define INVENTAIRE_H

typedef struct {
    int id;  // identifiant unique pour cibler
    char nom[30];
    int equiped; // 1 si équipé, 0 sinon
    int attaque_min;
    int attaque_max;
    int perte_oxygene; // oxygene perdu par attaque
} Arme;

typedef struct {
    int id;  // identifiant unique pour cibler
    char nom[30];
    int equiped; // 1 si équipé, 0 sinon
    int defense;
    int perte_oxygene; 
} Combinaison;

typedef struct {
    int id;  // identifiant unique pour cibler
    char nom[30];
    int quantite;
    char effet_texte[20]; // "soin", "oxygene", "fatigue"
    int effet_soin; // points de vie rendus
    int effet_oxygene; // points d'oxygene rendus
    int effet_fatigue; // points de fatigue retirés
} Objet;

#endif

//🧰
