#include <stdio.h>
#include <stdlib.h>

#include "joueur.h"

// gcc main.c joueur.c creatures.c interface.c -o drone3D.exe -lmingw32

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001); // 65001 = CP_UTF8
    // SetConsoleCP(65001);
    
    Plongeur * joueur = creer_joueur(50, 100, 100, 100, 5, 50);
    afficher_plongeur(joueur);

    return 0;
}
