#include "entreeSortieLC.h"

Biblio* charger_n_entrees(char* nomfic, int n){
    Biblio *b = creer_biblio();
    FILE *f = fopen(nomfic, "r");
    if(f == NULL){
        printf("Erreur lors de l'ouverture du fichier %s\n", nomfic);
        return NULL;
    }
    int num, num_ligne = 0;
    char titre[256], auteur[256];
    // On lit le fichier ligne par ligne
    while(fscanf(f, "%d %s %s", &num, titre, auteur) != EOF && num_ligne < n){
        inserer_en_tete(b, num, titre, auteur);
        num_ligne++;
    }
    fclose(f);
    return b;
}

void enregistrer_biblio(Biblio *b, char* nomfic){
    FILE *f = fopen(nomfic, "w");
    if(f == NULL){
        printf("Erreur lors de l'ouverture du fichier %s\n", nomfic);
        return;
    }
    Livre *l = b->L;
    // On parcourt la liste chaînée
    while(l != NULL){
        fprintf(f, "%d %s %s\n", l->num, l->titre, l->auteur);
        l = l->suiv;
    }
    fclose(f);
}