#include "biblioH.h"


int fonctionClef(char* auteur){
    int clef = 0;
    //Parcourir le nom de l'auteur et ajouter la valeur ASCII de chaque caractère à la clé
    for (size_t i = 0; i < strlen(auteur); i++){
        clef += auteur[i];
    }
    return clef;
}

LivreH* creer_livreH(int num,char* titre,char* auteur){
    LivreH *l = (LivreH *)malloc(sizeof(LivreH));
    l->clef = fonctionClef(auteur);
    l->num = num;
    l->titre = strdup(titre);
    l->auteur = strdup(auteur);
    l->suivant = NULL;
    return l;
}

void liberer_livreH(LivreH* l){
    free(l->titre);
    free(l->auteur);
    free(l);
}

BiblioH* creer_biblioH(int m){
    BiblioH *b = (BiblioH *)malloc(sizeof(BiblioH));
    b->nE = 0;
    b->m = m;
    b->T = (LivreH **)malloc(m * sizeof(LivreH *));
    for (int i = 0; i < m; i++){
        b->T[i] = NULL;
    }
    return b;
}

void liberer_biblioH(BiblioH* b){
    for (int i = 0; i < b->m; i++){
        LivreH *l = b->T[i];
        while (l != NULL){
            LivreH *tmp = l;
            l = l->suivant;
            liberer_livreH(tmp);
        }
    }
    free(b->T);
    free(b);
}

int fonctionHachage(int cle,int m){
    return (int)(m*(cle*((sqrt(5)-1)/2)-floor(cle*((sqrt(5)-1)/2))));
}

void insererH(BiblioH *b, int num, char *titre, char *auteur)
{
    int clef = fonctionClef(auteur);
    int h = fonctionHachage(clef, b->m);
    LivreH *l = creer_livreH(num, titre, auteur);
    l->suivant = b->T[h];
    b->T[h] = l;
    b->nE++;
}

void afficher_livreH(LivreH *l){
    printf("%d %s %s\n", l->num, l->titre, l->auteur);
}
void afficher_biblioH(BiblioH *b){
    for (int i = 0; i < b->m; i++){
        LivreH *l = b->T[i];
        while (l != NULL){
            afficher_livreH(l);
            l = l->suivant;
        }
    }
}
LivreH* recherche_ouvrage_numH(BiblioH *b, int num){
    for (int i = 0; i < b->m; i++){
        LivreH *l = b->T[i];
        while (l != NULL){
            if (l->num == num){
                return l;
            }
            l = l->suivant;
        }
    }
    return NULL;
}
LivreH* recherche_ouvrage_titreH(BiblioH *b, char *titre){
    for (int i = 0; i < b->m; i++){
        LivreH *l = b->T[i];
        while (l != NULL){
            if (strcmp(l->titre, titre) == 0){
                return l;
            }
            l = l->suivant;
        }
    }
    return NULL;
}
BiblioH* recherche_ouvrage_auteurH(BiblioH *b, char *auteur){
    //Créer une bibliothèque vide pour stocker les livres de l'auteur
    BiblioH *b2 = creer_biblioH(b->m);
    int clef = fonctionClef(auteur);
    int h = fonctionHachage(clef, b->m);
    LivreH *l = b->T[h];
    while (l != NULL){
        if (strcmp(l->auteur, auteur) == 0){
            //Inserer le livre dans la nouvelle bibliothèque
            insererH(b2, l->num, l->titre, l->auteur);
        }
        l = l->suivant;
    }
    return b2;
}
void supprimer_ouvrage_numH(BiblioH *b, int num){
    for (int i = 0; i < b->m; i++){
        LivreH *l = b->T[i];
        //Si la case est vide, passer à la suivante
        if (l == NULL){
            continue;
        }
        //Si le livre à supprimer est le premier de la liste
        if (l->num == num){
            b->T[i] = l->suivant;
            liberer_livreH(l);
            b->nE--;
            return;
        }
        //Sinon, parcourir la liste pour trouver le livre à supprimer
        while (l->suivant != NULL){
            if (l->suivant->num == num){
                LivreH *tmp = l->suivant;
                l->suivant = l->suivant->suivant;
                liberer_livreH(tmp);
                b->nE--;
                return;
            }
            l = l->suivant;
        }
    }
}
void supprimer_ouvrage_auteurH(BiblioH *b, char *auteur){
    int clef = fonctionClef(auteur);
    int h = fonctionHachage(clef, b->m);
    //Parcourir la liste chainée de la case h de la table de hachage
    LivreH *l = b->T[h];
    while (l != NULL){
        //Si le livre est de l'auteur à supprimer, le supprimer
        if (strcmp(l->auteur, auteur) == 0){
            LivreH *tmp = l;
            l = l->suivant;
            supprimer_ouvrage_numH(b, tmp->num);
        }
        else{
            l = l->suivant;
        }
    }
}
void supprimer_ouvrage_titreH(BiblioH *b, char *titre){
    for (int i = 0; i < b->m; i++){
        LivreH *l = b->T[i];
        while (l != NULL){
            if (strcmp(l->titre, titre) == 0){
                LivreH *tmp = l;
                l = l->suivant;
                supprimer_ouvrage_numH(b, tmp->num);
            }
            else{
                l = l->suivant;
            }
        }
    }
}
BiblioH* fusion_biblioH(BiblioH *b1, BiblioH *b2){
    //Créer une bibliothèque vide pour stocker les livres de la fusion
    BiblioH *b3 = creer_biblioH(b1->m);
    for (int i = 0; i < b1->m; i++){
        //Parcourir la liste chainée de chaque case de la table de hachage
        LivreH *l = b1->T[i];
        while (l != NULL){
            //Inserer chaque livre dans la nouvelle bibliothèque
            insererH(b3, l->num, l->titre, l->auteur);
            l = l->suivant;
        }
    }
    //Faire la même chose avec la deuxième bibliothèque
    for (int i = 0; i < b2->m; i++){
        LivreH *l = b2->T[i];
        while (l != NULL){
            insererH(b3, l->num, l->titre, l->auteur);
            l = l->suivant;
        }
    }
    return b3;
}
BiblioH* recherche_exemplairesH(BiblioH *b){
    //Créer une bibliothèque vide pour stocker les livres en double
    BiblioH *new_biblio = creer_biblioH(b->m);
    for (int i = 0; i < b->m; i++){
        //Parcourir la liste chainée de chaque case de la table de hachage
        LivreH *l1 = b->T[i];
        while (l1 != NULL){
            LivreH *l2 = l1->suivant;
            while (l2 != NULL){
                //Si deux livres ont le même titre et le même auteur, les insérer dans la nouvelle bibliothèque
                if (strcmp(l1->auteur, l2->auteur) == 0 && strcmp(l1->titre, l2->titre) == 0){
                    insererH(new_biblio, l2->num, l2->titre, l2->auteur);
                }
                //Passer au livre suivant pour comparer avec le premier l1
                l2 = l2->suivant;
            }
            //Passer au livre suivant
            l1 = l1->suivant;
        }
    }
    return new_biblio;
}