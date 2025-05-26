# Pipex

Ce projet consiste à recréer le fonctionnement du pipe (`|`) en C. Il permet d'exécuter une série de commandes en redirigeant la sortie de l'une vers l'entrée de la suivante.

## Description

Le programme `pipex` reproduit le comportement de la commande shell suivante :
```bash
< file1 cmd1 | cmd2 > file2
```
avec la syntaxe :
```bash
./pipex file1 cmd1 cmd2 file2
```

## Fonctionnalités

- Redirection des entrées/sorties
- Exécution de commandes avec leurs arguments
- Gestion des chemins absolus et relatifs
- Gestion des erreurs (fichiers inexistants, commandes invalides)
- Libération propre des ressources

## Compilation

Le projet utilise un Makefile avec les règles suivantes :

```bash
make        # Compile le projet
make clean  # Supprime les fichiers objets
make fclean # Supprime les fichiers objets et l'exécutable
make re     # Recompile le projet
```

## Utilisation

```bash
./pipex file1 "cmd1" "cmd2" file2
```

Exemples :
```bash
./pipex infile.txt "grep hello" "wc -l" outfile.txt
# Équivalent à : < infile.txt grep hello | wc -l > outfile.txt

./pipex infile.txt "/bin/grep hello" "/usr/bin/wc -l" outfile.txt
# Utilisation avec chemins absolus
```

## Tests

Des tests sont fournis dans le fichier `test.md`. Ils couvrent :
- Les commandes simples
- Les chemins absolus
- La gestion des erreurs
- Les redirections

## Gestion des erreurs

Le programme gère les erreurs suivantes :
- Nombre incorrect d'arguments
- Fichiers inexistants ou inaccessibles
- Commandes invalides ou introuvables
- Erreurs d'allocation mémoire
- Erreurs de fork ou de pipe
