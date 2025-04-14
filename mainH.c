#include "entreeSortieH.h"
#include <time.h>

void menu(){
    printf("0 - Sortie du programme\n");
    printf("1 - Affichage\n");
    printf("2 - Insérer un ouvrage\n");
    printf("3 - Recherche par numéro\n");
    printf("4 - Recherche par titre\n");
    printf("5 - Recherche par auteur\n");
    printf("6 - Suppression par numéro\n");
    printf("7 - Suppression par titre\n");
    printf("8 - Suppression par auteur\n");
    printf("9 - Fusion de deux bibliothèques\n");
    printf("10 - Recherche des exemplaires\n");
}

int main(int argc, char **argv){
    if(argc != 3){
        printf("Usage: %s <fichier_biblio> <n>\n", argv[0]);
        return 1;
    }
    BiblioH *B = charger_n_entrees(argv[1], atoi(argv[2]));
    if(B == NULL){
        return 1;
    }

    int choix;

    do {
        menu();
        char choix_str[256];
        BiblioH *new_biblio = NULL;
        fgets(choix_str, sizeof(choix_str), stdin);
        choix = atoi(choix_str);
        switch (choix) {
        case 1: // Affichage
            printf("Affichage:\n");
            afficher_biblioH(B);
            break;
        case 2: // Insérer un ouvrage
            printf("Insérer un ouvrage:\n");
            printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage.\n");
            int num;
            char titre[256], auteur[256];
            fgets(choix_str, sizeof(choix_str), stdin);
            if (sscanf(choix_str, "%d %s %s", &num, titre, auteur) == 3) {
                inserer(B, num, titre, auteur);
            } else {
                printf("Erreur format.\n");
            }
            break;
        case 3: // Recherche par numéro
            printf("Recherche par numéro:\n");
            printf("Veuillez écrire le numéro de l'ouvrage.\n");
            fgets(choix_str, sizeof(choix_str), stdin);
            if (sscanf(choix_str, "%d", &num) == 1) {
                LivreH *l = recherche_ouvrage_numH(B, num);
                if (l != NULL) {
                    afficher_livreH(l);
                } else {
                    printf("Ouvrage non trouvé.\n");
                }
            } else {
                printf("Erreur format.\n");
            }
            break;
        case 4: // Recherche par titre
            printf("Recherche par titre:\n");
            printf("Veuillez écrire le titre de l'ouvrage.\n");
            fgets(titre, sizeof(titre), stdin);
            titre[strlen(titre) - 1] = '\0';
            LivreH *l = recherche_ouvrage_titreH(B, titre);
            if (l != NULL) {
                afficher_livreH(l);
            } else {
                printf("Ouvrage non trouvé.\n");
            }
            break;
        case 5: // Recherche par auteur
            printf("Recherche par auteur:\n");
            printf("Veuillez écrire l'auteur de l'ouvrage.\n");
            fgets(auteur, sizeof(auteur), stdin);
            auteur[strlen(auteur) - 1] = '\0';
            new_biblio = recherche_ouvrage_auteurH(B, auteur);
            if (new_biblio != NULL) {
                afficher_biblioH(new_biblio);
            } else {
                printf("Ouvrage non trouvé.\n");
            }
            break;
        case 6: // Suppression par numéro
            printf("Suppression par numéro:\n");
            printf("Veuillez écrire le numéro de l'ouvrage.\n");
            fgets(choix_str, sizeof(choix_str), stdin);
            if (sscanf(choix_str, "%d", &num) == 1) {
                supprimer_ouvrage_numH(B, num);
            } else {
                printf("Erreur format.\n");
            }
            break;
        case 7: // Suppression par titre
            printf("Suppression par titre:\n");
            printf("Veuillez écrire le titre de l'ouvrage.\n");
            fgets(titre, sizeof(titre), stdin);
            titre[strlen(titre) - 1] = '\0';
            supprimer_ouvrage_titreH(B, titre);
            break;
        case 8: // Suppression par auteur
            printf("Suppression par auteur:\n");
            printf("Veuillez écrire l'auteur de l'ouvrage.\n");
            fgets(auteur, sizeof(auteur), stdin);
            auteur[strlen(auteur) - 1] = '\0';
            supprimer_ouvrage_auteurH(B, auteur);
            break;
        case 9: // Fusion de deux bibliothèques
            printf("Fusion de deux bibliothèques:\n");
            printf("Veuillez écrire le nom du fichier de la deuxième bibliothèque.\n");
            char nomfic[256];
            fgets(nomfic, sizeof(nomfic), stdin);
            nomfic[strlen(nomfic) - 1] = '\0';
            BiblioH *B2 = charger_n_entrees(nomfic, 100);
            if (B2 != NULL) {
                new_biblio = fusion_biblioH(B, B2);
                afficher_biblioH(new_biblio);
            } else {
                printf("Erreur lors de la lecture du fichier.\n");
            }
            break;
        case 10: // Recherche des exemplaires
            printf("Recherche des exemplaires:\n");
            new_biblio = recherche_exemplairesH(B);
            if (new_biblio != NULL) {
                afficher_biblioH(new_biblio);
            } else {
                printf("Erreur lors de la recherche des exemplaires.\n");
            }
            break;
        }
    } while (choix != 0);
    printf("Merci, et au revoir.\n");
    liberer_biblio(B);
    return 0;
}

//Problème de supprimage
//Probleme de rechcerche case 10 et affichage