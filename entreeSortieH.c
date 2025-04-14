#include "entreeSortieH.h"

BiblioH* charger_n_entreesH(char* nomfic, int n){
    FILE *f = fopen(nomfic, "r");
    if (f == NULL){
        printf("Erreur lors de l'ouverture du fichier %s\n", nomfic);
        return NULL;
    }
    BiblioH *b = creer_biblioH(n);
    int num, num_ligne = 0;
    char titre[256];
    char auteur[256];
    // On lit le fichier ligne par ligne
    while(fscanf(f, "%d %s %s", &num, titre, auteur) != EOF && num_ligne < n){
        insererH(b, num, titre, auteur);
        num_ligne++;
    }
    fclose(f);
    return b;
}

void enregistrer_biblioH(BiblioH *b, char* nomfic){
    FILE *f = fopen(nomfic, "w");
    if (f == NULL){
        printf("Erreur lors de l'ouverture du fichier %s\n", nomfic);
        return;
    }
    // On parcourt la table de hachage
    for (int i = 0; i < b->m; i++){
        LivreH *l = b->T[i];
        while (l != NULL){
            fprintf(f, "%d %s %s\n", l->num, l->titre, l->auteur);
            l = l->suivant;
        }
    }
    fclose(f);
}