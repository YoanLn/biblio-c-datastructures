#include "entreeSortieH.h"
#include "entreeSortieLC.h"
#include <time.h>
#include <math.h>  

//Question 3.1/3.2

/*
int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Usage: %s <fichier_biblio.txt> <n>\n", argv[0]);
        return 1;
    }

    clock_t temps_initial ;
    clock_t temps_final ;
    double temps_cpu ;
    Biblio *b = charger_n_entrees(argv[1], atoi(argv[2]));
    BiblioH *bH = charger_n_entreesH(argv[1], atoi(argv[2]));
    int num;
    char titre[256], auteur[256], choix_str[256];
;

                    //RECHERCHE OUVRAGE PAR NUMERO

    printf("Recherche d'un ouvrage par son numéro\n");
    printf("Veuillez écrire le numéro de l'ouvrage.\n");
    fgets(choix_str, sizeof(choix_str), stdin);
    sscanf(choix_str, "%d", &num);
    printf("Avec Liste : \n");
    temps_initial = clock ();
    Livre *l = recherche_ouvrage_num(b, num);
    
    temps_final = clock ();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
    
    if(l != NULL){
        printf("Ouvrage trouvé : ");
        afficher_livre(l);
    }else{
        printf("Ouvrage non trouvé\n");
    }
    printf("Temps d'execution : %f\n", temps_cpu);

    printf("Avec Table de hachage : \n");
    temps_initial = clock ();
    LivreH *lh = recherche_ouvrage_numH(bH, num);
    temps_final = clock ();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    if(lh != NULL){
        printf("Ouvrage trouvé : ");
        afficher_livreH(lh);
    }else{
        printf("Ouvrage non trouvé\n");
    }
    printf("Temps d'execution : %f\n", temps_cpu);

                    //RECHERCHE OUVRAGE PAR TITRE 

    printf("Recherche d'un ouvrage par son titre\n");
    printf("Veuillez écrire le titre de l'ouvrage.\n");
    fgets(titre, sizeof(titre), stdin);
    titre[strlen(titre) - 1] = '\0';
    printf("Avec Liste : \n");
    temps_initial = clock ();
    l = recherche_ouvrage_titre(b, titre);
    temps_final = clock ();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    if(l != NULL){
        printf("Ouvrage trouvé : ");
        afficher_livre(l);
    }else{
        printf("Ouvrage non trouvé\n");
    }
    printf("Temps d'execution : %f\n", temps_cpu);

    printf("Avec Table de hachage : \n");
    temps_initial = clock ();
    lh = recherche_ouvrage_titreH(bH, titre);
    temps_final = clock ();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
    
    if(lh != NULL){
        printf("Ouvrage trouvé : ");
        afficher_livreH(lh);
    }else{
        printf("Ouvrage non trouvé\n");
    }
    printf("Temps d'execution : %f\n", temps_cpu);

                    //RECHERCHE OUVRAGE PAR AUTEUR 

    printf("Recherche d'un ouvrage par son auteur\n");
    printf("Veuillez écrire l'auteur de l'ouvrage.\n");
    fgets(auteur, sizeof(auteur), stdin);
    auteur[strlen(auteur) - 1] = '\0';
    printf("Avec Liste : \n");
    temps_initial = clock ();
    Biblio *b2 = recherche_ouvrage_auteur(b, auteur);
    temps_final = clock ();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
    
    if(b2 != NULL){
        printf("Ouvrages trouvés : \n");
        afficher_biblio(b2);
    }else{
        printf("Ouvrage non trouvé\n");
    }
    printf("Temps d'execution : %f\n", temps_cpu);

    printf("Avec Table de hachage : \n");
    temps_initial = clock ();
    BiblioH *b3 = recherche_ouvrage_auteurH(bH, auteur);
    temps_final = clock ();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    if(b3 != NULL){
        printf("Ouvrages trouvés : \n");
        afficher_biblioH(b3);
    }else{
        printf("Ouvrage non trouvé\n");
    }
    printf("Temps d'execution : %f\n", temps_cpu);

    liberer_biblio(b);
    liberer_biblio(b2);
    liberer_biblioH(b3);
    liberer_biblioH(bH);

    return 0;
}
*/


//Question 3.3

int main(int argc, char *argv[]){

    if(argc != 4){
        printf("Usage: %s <fichier_biblio.txt> <fichier_sortie.txt> <n>\n", argv[0]);
        return 1;
    }

    clock_t temps_initial ;
    clock_t temps_final ;
    double temps_cpu ;

    int n = atoi(argv[3]);

    FILE *f = fopen(argv[2], "w");


    for (int i = n; i < 50000; i+=1000)
    {
        // Pour Liste Chainée
        temps_initial = clock ();
        Biblio *b = charger_n_entrees(argv[1], i);
        recherche_exemplaires(b);
        temps_final = clock ();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        
        fprintf(f, "%d %f\t", i, temps_cpu);

        // Pour Table de Hachage

        temps_initial = clock ();
        BiblioH *bH = charger_n_entreesH(argv[1], i);
        recherche_exemplairesH(bH);
        temps_final = clock ();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        fprintf(f, "%f\n", temps_cpu);
    }
}
    