# Tests pour pipex

## Préparation

Création du fichier de test :
```bash
echo "Hello World
This is a test file
With multiple lines
For testing pipex" > infile.txt
```

## Test 1 : Commande simple (grep + wc)

Commande :
```bash
./pipex infile.txt "grep test" "wc -l" outfile1.txt
```

Résultat attendu (contenu de outfile1.txt) :
```
2
```

## Test 2 : Commande avec chemin absolu

Commande :
```bash
./pipex infile.txt "/usr/bin/grep World" "/usr/bin/wc -l" outfile2.txt
```

Résultat attendu (contenu de outfile2.txt) :
```
1
```

## Test 3 : Gestion des erreurs - Fichier inexistant

Commande :
```bash
./pipex nonexistent.txt "grep test" "wc -l" outfile3.txt
```

Résultat attendu (sortie d'erreur) :
```
Error: Cannot open input file: No such file or directory
```

## Test 4 : Gestion des erreurs - Commande invalide

Commande :
```bash
./pipex infile.txt "invalidcmd" "wc -l" outfile4.txt
```

Résultat attendu (sortie d'erreur) :
```
Error: Command not found: No such file or directory
```

## Équivalences shell

Les commandes ci-dessus sont équivalentes aux commandes shell suivantes :

Test 1 :
```bash
< infile.txt grep test | wc -l > outfile1.txt
```

Test 2 :
```bash
< infile.txt /usr/bin/grep World | /usr/bin/wc -l > outfile2.txt
```

## Notes

- Tous les tests ont été effectués avec les flags de compilation : `-Wall -Wextra -Werror`
- Le programme gère correctement :
  - Les chemins relatifs et absolus pour les commandes
  - Les erreurs de fichiers et de commandes
  - La redirection des entrées/sorties
  - Les pipes entre les commandes

## Nettoyage des fichiers de test

Pour nettoyer tous les fichiers générés pendant les tests :

```bash
# Suppression des fichiers de sortie
rm -f outfile*.txt

# Suppression du fichier d'entrée de test
rm -f infile.txt

# Nettoyage des fichiers de compilation
make fclean
```
