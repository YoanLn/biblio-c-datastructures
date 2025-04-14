#include "biblioLC.h"

Livre* creer_livre(int num,char* titre,char* auteur){
    Livre *new_livre = (Livre *)malloc(sizeof(Livre));
    new_livre->num = num;
    new_livre->titre = strdup(titre);
    new_livre->auteur = strdup(auteur);
    new_livre->suiv = NULL;
    return new_livre;
}

void liberer_livre(Livre* l){
    while(l != NULL){
        Livre *tmp = l;
        l = l->suiv;
        free(tmp->titre);
        free(tmp->auteur);
        free(tmp);
    }
}

Biblio* creer_biblio(){
    Biblio *new_biblio = (Biblio *)malloc(sizeof(Biblio));
    new_biblio->L = NULL;
    return new_biblio;
}

void liberer_biblio(Biblio* b){
    liberer_livre(b->L);
    free(b);
}

void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur){
    Livre *new_livre = creer_livre(num, titre, auteur);
    new_livre->suiv = b->L;
    b->L = new_livre;
}

void afficher_livre(Livre *l){
    printf("%d %s %s\n", l->num, l->titre, l->auteur);
}

void afficher_biblio(Biblio *b){
    Livre *l = b->L;
    while(l != NULL){
        afficher_livre(l);
        l = l->suiv;
    }
}

Livre* recherche_ouvrage_num(Biblio *b, int num){
    Livre *l = b->L;
    while(l != NULL){
        if(l->num == num){
            return l;
        }
        l = l->suiv;
    }
    return NULL;
}

Livre* recherche_ouvrage_titre(Biblio *b, char *titre){
    Livre *l = b->L;
    while(l != NULL){
        if(strcmp(l->titre, titre) == 0){
            return l;
        }
        l = l->suiv;
    }
    return NULL;
}

Biblio* recherche_ouvrage_auteur(Biblio *b, char *auteur){
    //Création d'une nouvelle bibliothèque pour stocker les ouvrages de l'auteur
    Biblio *new_biblio = creer_biblio();
    Livre *l = b->L;
    while(l != NULL){
        if(strcmp(l->auteur, auteur) == 0){
            inserer_en_tete(new_biblio, l->num, l->titre, l->auteur);
        }
        l = l->suiv;
    }
    return new_biblio;
}

void supprimer_ouvrage_num(Biblio *b, int num){
    Livre *l = b->L;
    //Si le livre à supprimer est le premier
    if(l->num == num){
        b->L = l->suiv;
        free(l->titre);
        free(l->auteur);
        free(l);
        return;
    }
    while(l->suiv != NULL){
        if(l->suiv->num == num){
            Livre *tmp = l->suiv;
            l->suiv = l->suiv->suiv;
            free(tmp->titre);
            free(tmp->auteur);
            free(tmp);
            return;
        }
        l = l->suiv;
    }
}

void supprimer_ouvrage_auteur(Biblio *b, char *auteur){
    Livre *l = b->L;
    //Si le livre à supprimer est le premier
    if(strcmp(l->auteur, auteur) == 0){
        b->L = l->suiv;
        free(l->titre);
        free(l->auteur);
        free(l);
        return;
    }
    while(l->suiv != NULL){
        if(strcmp(l->suiv->auteur, auteur) == 0){
            //Suppression du livre
            Livre *tmp = l->suiv;
            //Le livre suivant devient le suivant du livre à supprimer
            l->suiv = l->suiv->suiv;
            free(tmp->titre);
            free(tmp->auteur);
            free(tmp);
            return;
        }
        l = l->suiv;
    }
}

void supprimer_ouvrage_titre(Biblio *b, char *titre){
    Livre *l = b->L;
    if(strcmp(l->titre, titre) == 0){
        b->L = l->suiv;
        free(l->titre);
        free(l->auteur);
        free(l);
        return;
    }
    while(l->suiv != NULL){
        if(strcmp(l->suiv->titre, titre) == 0){
            Livre *tmp = l->suiv;
            l->suiv = l->suiv->suiv;
            free(tmp->titre);
            free(tmp->auteur);
            free(tmp);
            return;
        }
        l = l->suiv;
    }
}

Biblio* fusion_biblio(Biblio *b1, Biblio *b2){
    //Si une des deux bibliothèques est vide, retourner l'autre
    if(b1->L == NULL){
        return b2;
    }

    if(b2->L == NULL){
        return b1;
    }

    Livre *l2 = b2->L;
    Livre *l1 = b1->L;

    while(l1->suiv != NULL){
        l1 = l1->suiv;
    }

    l1->suiv = l2;
    liberer_biblio(b2);

    return b1;
}

Biblio* recherche_exemplaires(Biblio *b){
    //Création d'une nouvelle bibliothèque pour stocker les ouvrages en double
    Biblio *new_biblio = creer_biblio();
    Livre *l1 = b->L;
    //Parcourir la liste chainée de chaque case de la liste
    while(l1 != NULL){
        Livre *l2 = l1->suiv;
        while(l2 != NULL){
            //Si deux livres ont le même titre et le même auteur, les ajouter à la nouvelle bibliothèque
            if(strcmp(l1->auteur, l2->auteur) == 0 && strcmp(l1->titre, l2->titre) == 0){
                inserer_en_tete(new_biblio, l2->num, l2->titre, l2->auteur);
            }
            l2 = l2->suiv;
        }
        l1 = l1->suiv;
    }
    return new_biblio;
}


