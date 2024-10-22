#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "etudiant.h"

// Prototypes des fonctions
void afficher_menu();
void gerer_menu(TNOF *tnof,int);

int main()
{
    TNOF *tnof = NULL;
    char path[100];
    char mode;
    int choix;
    
    printf("Entrez le chemin du fichier : ");
    scanf("%s", path);

    printf("Mode d'ouverture (A: Ouvrir un fichier existant, N: Nouveau fichier) : ");
    scanf(" %c", &mode);

    tnof = open_file(path, mode);
    
    if (tnof == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return -1;
    }

    do
    {
        afficher_menu();
        printf("Choix : ");
        scanf("%d", &choix);

        gerer_menu(tnof, choix);

    } while (choix != 0);

    printf("Fermeture du programme.\n");
    return 0;
}

void afficher_menu()
{
    printf("\n---- Menu ----\n");
    printf("1. Inserer un etudiant\n");
    printf("2. Lire un bloc\n");
    printf("3. Afficher l'entete\n");
    printf("4. Afficher un etudiant (recherche par matricule)\n");
    printf("0. Quitter\n");
    printf("----------------\n");
}

void gerer_menu(TNOF *tnof, int choix)
{
    Etudiant etudiant;
    int mat, position;
    Bloc bloc;

    switch (choix)
    {
    case 1:
        printf("Insertion d'un etudiant.\n");
        printf("Matricule : ");
        scanf("%d", &etudiant.mat);
        printf("Nom : ");
        scanf("%s", etudiant.nom);
        printf("Prenom : ");
        scanf("%s", etudiant.prenom);
        insert_etudiant(tnof, etudiant);
        break;

    case 2:
        printf("Lecture d'un bloc.\n");
        printf("Entrez la position du bloc à lire : ");
        scanf("%d", &position);
        if (read_bloc(tnof, &bloc, position) == 1)
        {
            int i;
            printf("Bloc %d lu avec succes.\n", position);
            for (i = 0; i < bloc.nb; i++)
            {
                printetudiant(bloc.tab_enreg[i]);
            }
        }
        else
        {
            printf("Erreur de lecture du bloc.\n");
        }
        break;

    case 3:
        printf("Affichage de l'entete.\n");
        printf("Nombre de blocs : %d\n", tnof->ent.nb_bloc);
        break;

    case 4:
        printf("Recherche d'un etudiant.\n");
        printf("Entrez le matricule de l'etudiant : ");
        scanf("%d", &mat);
        if (rechercher_etudiant(tnof, mat, &etudiant) != -1)
        {
            printf("etudiant trouve :\n");
            printetudiant(etudiant);
        }
        else
        {
            printf("etudiant non trouve.\n");
        }
        break;

    case 0:
        printf("Quitter.\n");
        break;

    default:
        printf("Choix non valide.\n");
        break;
    }
}
