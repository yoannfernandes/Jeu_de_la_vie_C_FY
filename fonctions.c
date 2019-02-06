#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init_tab(int tableau[TAILLE][TAILLE]){
/*-----------------------------------
 Descriptions : fonction pour initialiser le tableau
 Entrées : le tableau d'entier
 Sorties :tableau initialisé
-----------------------------------*/
    int i=0;
    int j=0;

    int CoordAleaX=0;
    int CoordAleaY=0;

    for(i=0; i<TAILLE; i++)
    {
        for(j=0; j<TAILLE; j++)
        {
            CoordAleaX=(rand()%TAILLE);
            CoordAleaY=(rand()%TAILLE);
            tableau[i][j]=0;
            tableau[CoordAleaX][CoordAleaY]= 1;

        }
    }

}

void affichage(int tableau[TAILLE][TAILLE]){
/*-----------------------------------
 Descriptions : fonction pour afficher le tableau
 Entrées :le tableau d'entier
 Sorties :le tableau affiché
-----------------------------------*/
    int i=0;
    int j=0;

    for(i=0; i<TAILLE; i++)
    {
        for(j=0; j<TAILLE; j++)
        {
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }

}


void gestion_cellule(int tableau[TAILLE][TAILLE]){
/*-----------------------------------
 Descriptions :fonction qui va calculer les voisins et gerer les differentes cellules (mort ou vivante)
 Entrées :le tableau d'entier
 Sorties :le tableau d'entier "actualisé"
-----------------------------------*/
                                                //0=mort;1=vivant;2=naissance;3=mourante
    int i=0;
    int j=0;
    int cptVoisins=0;

    for(i=0; i<TAILLE; i++){

        for(j=0; j<TAILLE; j++){

            if(tableau[i][j]==1)
            {
                                                                //je compte les voisins
                if(tableau[i+1][j]==1||tableau[i][j]==3){
                    cptVoisins += 1;
                }
                 if(tableau[i][j+1]==1||tableau[i][j]==3){
                    cptVoisins += 1;
                }
                 if(tableau[i-1][j]==1||tableau[i][j]==3){
                    cptVoisins += 1;
                }
                 if(tableau[i][j-1]==1||tableau[i][j]==3){
                    cptVoisins += 1;
                }
                 if(tableau[i+1][j+1]==1||tableau[i][j]==3){
                    cptVoisins += 1;
                }
                 if(tableau[i+1][j-1]==1||tableau[i][j]==3){
                    cptVoisins += 1;
                }
                 if(tableau[i-1][j+1]==1||tableau[i][j]==3){
                    cptVoisins += 1;
                }
                 if(tableau[i-1][j-1]==1||tableau[i][j]==3){
                    cptVoisins += 1;
                }
            }

                                                //je change les etats des cellules en mourrante ou naissante
        if(tableau[i][j]==1)
        {
            if((cptVoisins==2)||(tableau[i][j]==3)){
            tableau[i][j]=1;
            }
        }
        else
        {
            tableau[i][j]=3;
        }

        if(tableau[i][j]==0)
        {
            if((cptVoisins==3)&&(tableau[i][j]==0)){
            tableau[i][j]=2;
            }
        }
        else
        {
            tableau[i][j]=0;
        }
//0=mort;1=vivant;2=naissance;3=mourante


    for(i=0; i<TAILLE; i++){            //je change les etats en mort ou vivante
        for(j=0; j<TAILLE; j++){

            if(tableau[i][j]==2){
                tableau[i][j]=1;
            }
            if(tableau[i][j]==3){
                tableau[i][j]=0;
            }

        }
    }
}
}
}

void sauvegarde(int tableau[TAILLE][TAILLE]){
/*-----------------------------------
 Descriptions :fonction pour les sauvegardes dans un fichier texte
 Entrées :le tableau d'entier
 Sorties :un fichier .txt
-----------------------------------*/
    int i = 0;
    int j = 0;
    int nbVivant = 0;
    int nbMort = 0;

    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)           //je compte les cellules vivantes et mortes
        {
            if(tableau[i][j]==1)
            {
                nbVivant+=1;
            }
            if(tableau[i][j]==0)
            {
                nbMort+=1;
            }

        }
    }

    FILE *pFile;                            //je stock dans mon fichier .txt
    pFile= fopen("jeu_de_la_vie_sauvegarde.txt", "w");
    fclose(pFile);
    pFile = fopen("jeu_de_la_vie_sauvegarde.txt", "a");
    fputs("Nombre de cellules mortes : ", pFile);
    fprintf(pFile, "%d", nbMort);
    fputs("\n", pFile);
    fputs("Nombre de cellules vivantes : ", pFile);
    fprintf(pFile, "%d", nbVivant);
    fputs("\n", pFile);
    fclose(pFile);

}
