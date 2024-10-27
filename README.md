# Garbage Collector en C

Ce projet implémente un garbage collector (GC) en C. Ce garbage collector est conçu pour gérer la mémoire dynamique en ajoutant, supprimant et libérant des pointeurs, ce qui aide à prévenir les fuites de mémoire.


## Fonctionnalités

- **Ajout de Pointeurs** : 
  - La fonction `add_ptr` permet d'ajouter un pointeur à la collection. Si le tableau de pointeurs est plein, il est redimensionné automatiquement.
  - `add_ptr_tab` permet d'ajouter un tableau de pointeurs.

- **Vérification de Pointeurs** : 
  - La fonction `is_ptr_in_trash` vérifie si un pointeur est déjà dans le collecteur de déchets.

- **Libération de Mémoire** : 
  - `free_all` libère tous les pointeurs actuellement stockés dans le garbage collector, réinitialisant ainsi sa capacité et son compte.

- **Initialisation** : 
  - `init_garbage_collector` initialise le collecteur avec une capacité initiale.

- **Suppression de Pointeurs** : 
  - `remove_ptr` permet de supprimer un pointeur spécifique du collecteur. Si le nombre de pointeurs descend en dessous d'un certain seuil, le tableau est redimensionné.

- **Debugging** : 
  - `debug_gc` affiche l'état actuel du garbage collector, y compris la capacité et le nombre de pointeurs.

Mention spécial [jlebard07](https://github.com/jlebard07)

## Init Makefile for your project

```M̀akefile
LINKLIBS = -L./garbage_collector -lgarbage_collector
```
```M̀akefile
$(NAME) : $(OBJ)
	@make -C ./garbage_collector --no-print-directory
 ```
```M̀akefile
fclean:	clean
@make fclean -C ./garbage_collector --no-print-directory
```
