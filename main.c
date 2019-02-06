#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "windows.h"

int main(){

    int tableau[TAILLE][TAILLE];
    int cycle=0;
    int NbCycle=0;

    srand(time(NULL));
    init_tab(tableau);
    affichage(tableau);
    printf("Veuillez saisir le nombre de cycle\n");
    scanf("%d", &cycle);

    for(NbCycle=0; NbCycle<cycle; NbCycle++)
    {
        gestion_cellule(tableau);
        Sleep(500);
        system("cls");
        affichage(tableau);
        Sleep(500);
    }
    sauvegarde(tableau);

    return 0;
}
