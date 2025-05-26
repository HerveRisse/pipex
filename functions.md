# Description des fonctions par fichier

## pipex.c
- `init_pipex(t_pipex *pipex, int argc, char **argv)` : Initialise la structure pipex avec les arguments du programme
- `main(int argc, char **argv, char **envp)` : Point d'entrée du programme, vérifie les arguments et gère l'exécution des commandes

## pipex_init.c
- `init_files(t_pipex *pipex, char **argv)` : Ouvre les fichiers d'entrée et de sortie
- `init_commands(t_pipex *pipex, char **argv)` : Initialise les commandes à exécuter
- `wait_for_children(t_pipex *pipex)` : Attend la fin de l'exécution des processus enfants

## pipex_cmd.c
- `get_cmd_path(char *cmd)` : Recherche le chemin complet d'une commande dans les variables d'environnement
- `execute_cmd1(t_pipex *pipex, char **envp)` : Exécute la première commande
- `execute_cmd2(t_pipex *pipex, char **envp)` : Exécute la deuxième commande

## pipex_cmd_utils.c
- `try_direct_path(char **cmd_args)` : Vérifie si la commande est un chemin direct (absolu ou relatif)
- `try_path_dir(char *dir, char *cmd)` : Teste si la commande existe dans un répertoire donné
- `free_search_resources(char *path, char **cmd_args)` : Libère la mémoire allouée pendant la recherche de commande

## pipex_exec.c
- `setup_io(t_pipex *pipex, int cmd_num)` : Configure les redirections d'entrée/sortie pour une commande

## pipex_utils.c
- `error_exit(char *msg)` : Affiche un message d'erreur et quitte le programme
- `cleanup(t_pipex *pipex)` : Nettoie les ressources allouées
- `free_array(char **arr)` : Libère un tableau de chaînes de caractères

## pipex_split_utils.c
- `split_cmd(char *cmd)` : Découpe une commande en tableau d'arguments

## pipex_str_utils1.c
- `ft_strlen(const char *s)` : Calcule la longueur d'une chaîne
- `ft_strdup(const char *s)` : Duplique une chaîne de caractères
- `ft_strchr(const char *s, int c)` : Recherche un caractère dans une chaîne
- `ft_strjoin(char const *s1, char const *s2)` : Concatène deux chaînes

## pipex_str_utils2.c
- `ft_strncpy(char *dst, const char *src, size_t n)` : Copie n caractères d'une chaîne dans une autre
- `ft_strtok(char *str, char sep)` : Découpe une chaîne en utilisant un séparateur (version thread-safe)

## Structures de données

### t_pipex
```c
typedef struct s_pipex
{
    int     infile;         // Descripteur du fichier d'entrée
    int     outfile;        // Descripteur du fichier de sortie
    char    *cmd1;          // Première commande
    char    *cmd2;          // Deuxième commande
    char    **cmd1_args;    // Arguments de la première commande
    char    **cmd2_args;    // Arguments de la deuxième commande
    int     pipe_fd[2];     // Descripteurs du pipe
    pid_t   pid1;           // PID du premier processus enfant
    pid_t   pid2;           // PID du deuxième processus enfant
} t_pipex;
```

### t_split
```c
typedef struct s_split
{
    char    *str;           // Chaîne à découper
    int     pos;            // Position actuelle
    char    sep;           // Caractère séparateur
} t_split;
```

## Flux d'exécution

1. Le programme commence dans `main`
2. `init_pipex` initialise la structure principale
3. `init_files` ouvre les fichiers
4. `init_commands` prépare les commandes
5. Création du pipe
6. `execute_cmd1` exécute la première commande dans un processus fils
7. `execute_cmd2` exécute la deuxième commande dans un autre processus fils
8. `wait_for_children` attend la fin des processus
9. `cleanup` libère les ressources

Chaque commande est exécutée dans un processus séparé, connectés par un pipe. Les entrées/sorties sont redirigées selon les besoins.
