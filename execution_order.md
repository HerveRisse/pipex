# Ordre d'exécution des fonctions

## 1. Initialisation
1. `main` (pipex.c)
   - Vérifie le nombre d'arguments
   - Initialise la structure pipex

2. `init_pipex` (pipex.c)
   - Appelle les fonctions d'initialisation
   - Vérifie les erreurs

3. `init_files` (pipex_init.c)
   - Ouvre le fichier d'entrée (infile)
   - Ouvre le fichier de sortie (outfile)
   - Gère les erreurs d'ouverture

4. `init_commands` (pipex_init.c)
   - Stocke les commandes dans la structure
   - Utilise `split_cmd` pour parser les arguments

5. `split_cmd` (pipex_split_utils.c)
   - Découpe la commande en arguments
   - Utilise `ft_strtok` pour le parsing

## 2. Exécution de la première commande
1. `execute_cmd1` (pipex_cmd.c)
   - Fork pour créer le premier processus fils
   - Configure les redirections
   - Exécute la commande

2. `get_cmd_path` (pipex_cmd.c)
   - Recherche le chemin complet de la commande
   - Utilise `try_direct_path` et `try_path_dir`

3. `try_direct_path` (pipex_cmd_utils.c)
   - Vérifie si la commande est un chemin absolu/relatif
   - Teste l'accessibilité

4. `try_path_dir` (pipex_cmd_utils.c)
   - Cherche la commande dans un répertoire du PATH
   - Construit le chemin complet

5. `setup_io` (pipex_exec.c)
   - Configure les descripteurs de fichiers
   - Redirige stdin/stdout

## 3. Exécution de la deuxième commande
1. `execute_cmd2` (pipex_cmd.c)
   - Fork pour créer le second processus fils
   - Configure les redirections
   - Exécute la commande

2. `get_cmd_path` (pipex_cmd.c)
   - (même processus que pour cmd1)

3. `setup_io` (pipex_exec.c)
   - Configure les descripteurs pour cmd2

## 4. Finalisation
1. `wait_for_children` (pipex_init.c)
   - Attend la fin des deux processus fils
   - Récupère les statuts de sortie

2. `cleanup` (pipex_utils.c)
   - Ferme les descripteurs de fichiers
   - Libère la mémoire allouée

## Fonctions utilitaires (appelées selon les besoins)
- `error_exit` (pipex_utils.c)
  - Affiche les messages d'erreur
  - Termine le programme

- `free_array` (pipex_utils.c)
  - Libère les tableaux de chaînes

- `free_search_resources` (pipex_cmd_utils.c)
  - Libère les ressources de recherche de commandes

### Fonctions de manipulation de chaînes
- `ft_strlen` (pipex_str_utils1.c)
- `ft_strdup` (pipex_str_utils1.c)
- `ft_strchr` (pipex_str_utils1.c)
- `ft_strjoin` (pipex_str_utils1.c)
- `ft_strncpy` (pipex_str_utils2.c)
- `ft_strtok` (pipex_str_utils2.c)

## Notes sur le flux d'exécution
- Les fonctions de gestion d'erreur peuvent être appelées à n'importe quel moment
- Les fonctions de manipulation de chaînes sont utilisées tout au long de l'exécution
- Le programme maintient une structure de données cohérente grâce à `cleanup`
- Les processus fils sont exécutés en parallèle, mais le processus parent attend leur terminaison
