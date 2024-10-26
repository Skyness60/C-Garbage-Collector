# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                          :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: sperron <sperron@student>                  +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2024/10/26 20:00:00 by sperron           #+#    #+#             #
#   Updated: 2024/10/26 20:40:00 by sperron          ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

# Variables
NAME = garbage_collector
CC = cc -g3
CFLAGS = -Wall -Wextra -Werror

SRC = src/gc_add.c src/gc_check.c src/gc_debug.c src/gc_free.c \
      src/gc_init.c src/gc_remove.c src/gc_utils.c main.c

OBJECTS = $(SRC:.c=.o)

#################################################################################

# Couleurs pour l'affichage
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CYAN = \033[0;36m
NC = \033[0m

#################################################################################

OBJ = $(SRC:.c=.o)

# Règle par défaut
all: $(NAME)

# Animation de chargement
loading_animation:
	@echo "$(CYAN)🚀 Initializing garbage collector...$(NC)"
	@sleep 1; echo -n "$(YELLOW)🗑️  Collecting garbage"; sleep 0.5
	@for i in $(shell seq 1 5); do \
		echo -n ". "; sleep 0.5; \
	done; \
	echo "\n$(GREEN)✅ Garbage collected!$(NC)$(NL)"
	@sleep 1; echo -n "$(CYAN)♻️  Optimizing memory"; sleep 0.5
	@for i in $(shell seq 1 5); do \
		echo -n ". "; sleep 0.5; \
	done; \
	echo "\n$(GREEN)✅ Memory optimized!$(NC)"

# Compilation des fichiers objets
%.o: %.c
	@echo "$(YELLOW)🔨 Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)✅ $< compiled!$(NC)"

# Création de l'exécutable
$(NAME): $(OBJ)
	@$(MAKE) -s loading_animation
	@echo "$(BLUE)🔗 Linking...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ $@ built!$(NC)"

# Nettoyage des fichiers objets avec animation de poubelle
clean:
	@echo "$(YELLOW)🗑️ Cleaning up object files...$(NC)"
	@$(MAKE) -s trash_animation
	@rm -f $(OBJECTS)
	@echo "$(YELLOW)🗑️ $(OBJECTS) deleted!$(NC)"

# Animation de la poubelle
# Animation de la poubelle
trash_animation:
	@echo "$(YELLOW)🗑️  Starting garbage collection...$(NC)"
	@sleep 1
	@echo -n "$(CYAN)🔄 Collecting garbage"
	@for i in $(shell seq 1 5); do \
		echo -n ". "; sleep 0.5; \
	done; \
	echo -n "\n$(GREEN)✅ Garbage collected! $(NC)"
	@echo
	@sleep 1
	@echo "$(GREEN)♻️  Optimizing memory...$(NC)"
	@for i in $(shell seq 1 5); do \
		echo -n "🌱 "; sleep 0.5; \
	done; \
	echo "\n$(GREEN)✅ Memory optimized!$(NC)"

# Nettoyage complet
fclean: clean
	@echo "$(RED)🗑️ Removing executable...$(NC)"
	@rm -rf $(NAME)
	@echo "$(GREEN)🗑️ $(NAME) deleted!$(NC)"

# Recompile tout
re: fclean all

.PHONY: re all clean fclean trash_animation loading_animation
