#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct livreh {
    int clef ;
    int num ;
    char *titre ;
    char *auteur ;
    struct livreh *suivant ;
} LivreH ;

typedef struct table {
    int nE ; /*nombre d’elements contenus dans la table de hachage */
    int m ; /*taille de la table de hachage */
    LivreH **T ; /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;


int fonctionClef(char* auteur);
LivreH* creer_livreH(int num,char* titre,char* auteur);
void liberer_livreH(LivreH* l);
BiblioH* creer_biblioH(int m);
void liberer_biblioH(BiblioH* b);
int fonctionHachage(int cle,int m);
void insererH(BiblioH* b,int num,char* titre,char* auteur);

void afficher_livreH(LivreH *l);
void afficher_biblioH(BiblioH *b);
LivreH* recherche_ouvrage_numH(BiblioH *b, int num);
LivreH* recherche_ouvrage_titreH(BiblioH *b, char *titre);
BiblioH* recherche_ouvrage_auteurH(BiblioH *b, char *auteur);
void supprimer_ouvrage_numH(BiblioH *b, int num);
void supprimer_ouvrage_auteurH(BiblioH *b, char *auteur);
void supprimer_ouvrage_titreH(BiblioH *b, char *titre);
BiblioH* fusion_biblioH(BiblioH *b1, BiblioH *b2);
BiblioH* recherche_exemplairesH(BiblioH *b);
