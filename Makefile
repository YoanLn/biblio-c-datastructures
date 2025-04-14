# Makefile pour le projet de Gestion de Bibliothèque
# LENEVEZ, NGUYEN - Structures de Données

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g -O2

# Libraries
LIBS = -lm

# Source directories
SRC_DIR = .

# Object directory
OBJ_DIR = ./obj

# Binary directory
BIN_DIR = ./bin

# Source files for each target
SRCS_LC = main.c biblioLC.c entreeSortieLC.c
SRCS_H = mainH.c biblioH.c entreeSortieH.c
SRCS_EX3 = main_exo3.c biblioLC.c biblioH.c entreeSortieLC.c entreeSortieH.c
SRCS_TEST = jeu_de_test.c biblioLC.c biblioH.c

# Object files
OBJS_LC = $(SRCS_LC:.c=.o)
OBJS_H = $(SRCS_H:.c=.o)
OBJS_EX3 = $(SRCS_EX3:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)

# Executable names
EXEC_LC = main
EXEC_H = mainH
EXEC_EX3 = main_exo3
EXEC_TEST = jeuDeTest

# Default target
all: $(EXEC_LC) $(EXEC_H) $(EXEC_EX3) $(EXEC_TEST)

# Rules for each target
$(EXEC_LC): $(OBJS_LC)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(EXEC_H): $(OBJS_H)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(EXEC_EX3): $(OBJS_EX3)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(EXEC_TEST): $(OBJS_TEST)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Generic rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Clean generated files
clean:
	rm -f *.o $(EXEC_LC) $(EXEC_H) $(EXEC_EX3) $(EXEC_TEST)

# Clean all generated files including test outputs
cleanall: clean
	rm -f sortie_vitesse.txt

# Help message
help:
	@echo "Makefile pour le projet de Gestion de Bibliothèque"
	@echo "Cibles disponibles:"
	@echo "  all       : Compile tous les exécutables"
	@echo "  main      : Compile l'implémentation par liste chaînée"
	@echo "  mainH     : Compile l'implémentation par table de hachage"
	@echo "  main_exo3 : Compile le programme de comparaison de performances"
	@echo "  jeuDeTest : Compile les tests unitaires"
	@echo "  clean     : Supprime les fichiers objets et exécutables"
	@echo "  cleanall  : Supprime tous les fichiers générés y compris les sorties"
	@echo "  help      : Affiche ce message d'aide"

# Phony targets
.PHONY: all clean cleanall help main mainH main_exo3 jeuDeTest

# Additional targets for convenience
main: $(EXEC_LC)
mainH: $(EXEC_H)
main_exo3: $(EXEC_EX3)
jeuDeTest: $(EXEC_TEST)