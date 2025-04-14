#!/bin/bash

# Script de démonstration pour le projet de Gestion de Bibliothèque
# LENEVEZ, NGUYEN - Structures de Données

# Couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
RESET='\033[0m'

# Fonction pour afficher les messages
print_header() {
    echo -e "${BLUE}====================================================${RESET}"
    echo -e "${YELLOW}$1${RESET}"
    echo -e "${BLUE}====================================================${RESET}"
}

# Vérifier que GdeBiblio.txt existe
if [ ! -f "GdeBiblio.txt" ]; then
    echo -e "${RED}Erreur: Fichier GdeBiblio.txt non trouvé!${RESET}"
    exit 1
fi

# Compilation des programmes
print_header "Compilation des programmes"
make clean
make all

# Exécution des tests unitaires
print_header "Exécution des tests unitaires"
./jeuDeTest
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Tous les tests ont réussi!${RESET}"
else
    echo -e "${RED}Certains tests ont échoué!${RESET}"
    exit 1
fi

# Démonstration de la version liste chaînée
print_header "Démonstration de la version liste chaînée (10 entrées)"
echo "Chargement de 10 entrées depuis GdeBiblio.txt..."
echo "1" | ./main GdeBiblio.txt 10
echo -e "${GREEN}Appuyez sur Entrée pour continuer...${RESET}"
read

# Démonstration de la version table de hachage
print_header "Démonstration de la version table de hachage (10 entrées)"
echo "Chargement de 10 entrées depuis GdeBiblio.txt..."
echo "1" | ./mainH GdeBiblio.txt 10
echo -e "${GREEN}Appuyez sur Entrée pour continuer...${RESET}"
read

# Comparaison des performances
print_header "Comparaison des performances"
./main_exo3 GdeBiblio.txt sortie_vitesse.txt 100

echo -e "${GREEN}Les résultats de la comparaison ont été enregistrés dans sortie_vitesse.txt${RESET}"
echo -e "${YELLOW}Voici un aperçu des résultats:${RESET}"
head -n 5 sortie_vitesse.txt

# Fin de la démonstration
print_header "Fin de la démonstration"
echo -e "${GREEN}La démonstration est terminée!${RESET}"
echo -e "N'hésitez pas à explorer le code source et la documentation pour en savoir plus sur ce projet." 