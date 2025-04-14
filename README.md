# Gestion de Bibliothèque en C - Structures de Données

Ce projet est une implémentation d'un système de gestion de bibliothèque en C, développé dans le cadre d'un cours de Structures de Données. Il utilise deux approches différentes pour la gestion des données : une implémentation par liste chaînée et une autre par table de hachage.

## Fonctionnalités

- **Stockage de livres** avec leurs attributs (numéro, titre, auteur)
- **Recherche d'ouvrages** par numéro, titre ou auteur
- **Insertion et suppression** d'ouvrages dans la bibliothèque
- **Fusion** de deux bibliothèques
- **Détection des exemplaires** (livres avec même titre et auteur)
- **Analyse comparative** des performances entre les deux implémentations

## Structure du projet

Le projet est divisé en deux implémentations principales :

### Implémentation par Liste Chaînée
- `biblioLC.h` et `biblioLC.c` : Définition des structures et fonctions pour la gestion de la bibliothèque par liste chaînée
- `entreeSortieLC.h` et `entreeSortieLC.c` : Fonctions de chargement/sauvegarde des données
- `main.c` : Programme principal pour l'implémentation par liste chaînée

### Implémentation par Table de Hachage
- `biblioH.h` et `biblioH.c` : Définition des structures et fonctions pour la gestion de la bibliothèque par table de hachage
- `entreeSortieH.h` et `entreeSortieH.c` : Fonctions de chargement/sauvegarde des données
- `mainH.c` : Programme principal pour l'implémentation par table de hachage

### Comparaison et Tests
- `main_exo3.c` : Programme de comparaison des performances entre les deux implémentations
- `jeu_de_test.c` : Tests unitaires des fonctionnalités principales
- `courbes_vitesse.ps` : Visualisation graphique des performances

## Compilation et Exécution

Le projet utilise un Makefile pour faciliter la compilation. Pour compiler et exécuter le programme :

```bash
# Compiler l'implémentation par liste chaînée
make main
./main GdeBiblio.txt <nombre_entrees>

# Compiler l'implémentation par table de hachage
make mainH
./mainH GdeBiblio.txt <nombre_entrees>

# Compiler et exécuter les tests de performance
make main_exo3
./main_exo3 GdeBiblio.txt sortie_vitesse.txt <nombre_entrees>

# Compiler et exécuter les tests unitaires
make jeuDeTest
./jeuDeTest
```

## Analyse des Performances

Le projet inclut une analyse comparative des performances entre les deux implémentations. Les résultats montrent que :

- La table de hachage est généralement plus efficace pour la recherche d'éléments, avec une complexité moyenne O(1) contre O(n) pour la liste chaînée
- La liste chaînée est plus simple à implémenter et utilise moins de mémoire
- Les performances relatives varient selon la taille de la bibliothèque et la distribution des données

## Améliorations Possibles

- Implémentation d'une interface graphique
- Ajout de fonctionnalités de tri et de filtrage avancées
- Optimisation de la fonction de hachage pour réduire les collisions
- Utilisation de structures de données alternatives (arbres binaires de recherche, tables de hachage à double hachage, etc.)
- Persistance des données via une base de données

## Licence

Ce projet est disponible sous licence libre pour usage éducatif.

---

© LENEVEZ, NGUYEN - Projet de Structures de Données 