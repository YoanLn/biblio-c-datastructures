#include <stdio.h>
#include "biblioLC.h"
#include "biblioH.h"
#include <assert.h>

int main(){

    //Création de la bibliothèque et des livres
    Biblio* library = creer_biblio();
    Livre* book = creer_livre(1, "Book 1", "Author 1");
    BiblioH* libraryH = creer_biblioH(1);
    LivreH* bookH = creer_livreH(1, "Book 1", "Author 1");

    //Insertion des livres dans la bibliothèque
    inserer_en_tete(library, book->num, book->titre, book->auteur);
    assert(library->L->num == book->num);
    insererH(libraryH, bookH->num, bookH->titre, bookH->auteur);

    //Test si les livres ont bien été créés
    assert(book!=NULL);
    assert(bookH!=NULL);

    //Test si les livres ont bien été insérés dans la bibliothèque et les fonctions de recherche fonctionnent
    assert(strcmp(recherche_ouvrage_titre(library, "Book 1")->titre, book->titre) == 0);    
    assert(strcmp(recherche_ouvrage_titreH(libraryH, "Book 1")->titre, bookH->titre) == 0);
    assert(recherche_ouvrage_auteur(library, "Author 1")!= NULL);
    assert(recherche_ouvrage_auteurH(libraryH, "Author 1")!= NULL);
    assert(recherche_ouvrage_num(library, 1)->num==book->num);
    assert(recherche_ouvrage_numH(libraryH, 1)->num==bookH->num);

    
    //Test de la fonction de suppression
    supprimer_ouvrage_num(library, 1);
    supprimer_ouvrage_numH(libraryH, 1);
    assert(recherche_ouvrage_num(library, 1)==NULL);
    assert(recherche_ouvrage_numH(libraryH, 1)==NULL);

    inserer_en_tete(library, book->num, book->titre, book->auteur);
    insererH(libraryH, bookH->num, bookH->titre, bookH->auteur);

    supprimer_ouvrage_titre(library, "Book 1");
    supprimer_ouvrage_titreH(libraryH, "Book 1");
    assert(recherche_ouvrage_titre(library, "Book 1")==NULL);
    assert(recherche_ouvrage_titreH(libraryH, "Book 1")==NULL);

    inserer_en_tete(library, book->num, book->titre, book->auteur);
    insererH(libraryH, bookH->num, bookH->titre, bookH->auteur);

    supprimer_ouvrage_auteur(library, "Author 1");
    supprimer_ouvrage_auteurH(libraryH, "Author 1");
    assert(recherche_ouvrage_auteur(library, "Author 1")->L==NULL);
    assert(recherche_ouvrage_auteurH(libraryH, "Author 1")->T[0]==NULL);


    //Test de la fonction de recherche d'exemplaires
    
    inserer_en_tete(library, 2, "Book 2", "Author 2");
    inserer_en_tete(library, 3, "Book 2", "Author 2");
    insererH(libraryH, 2, "Book 2", "Author 2");
    insererH(libraryH, 3, "Book 2", "Author 2");

    assert(strcmp(recherche_exemplaires(library)->L->titre,"Book 2")==0);
    assert(strcmp(recherche_exemplaires(library)->L->auteur,"Author 2")==0);
    assert(strcmp(recherche_exemplairesH(libraryH)->T[0]->titre,"Book 2")==0);
    assert(strcmp(recherche_exemplairesH(libraryH)->T[0]->auteur,"Author 2")==0);

    liberer_livre(book);
    liberer_livreH(bookH);
    liberer_biblio(library);
    liberer_biblioH(libraryH);
    
    return 0;
}
