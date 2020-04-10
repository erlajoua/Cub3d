/*
1. stocker dans la structure
2.








FICHIER .cub

1. Le 1er caractere est l'id (1 ou 2 char)
2. Le reste sont des params
Ex :
- R (resolution) 1920 (x) 1080 (y)
- NO (texture nord) ./path_to_nord_texture (image)
...

MAP :
La map sera toujours en dernier dans le parsing
Les infos peuvent etre separes par 1 ou plusieurs espaces

VALIDE :
4 caractères : 0 pour les espaces vides, 1 pour les murs, 2 pour un objet, N,S,E ou W qui représentent la
position de départ du joueur et son orientation.

INVALIDE :
Une map qui n'est pas entoure de mur est invalide

GESTION ERREUR :
Si un problème de configuration de n’importe quel type est rencontré dans
le fichier, le programme doit quitter et renvoyer "Error\n" suivi d’un message
d’erreur explicite de votre choix.
---

Step 1. Parsing
	- Utiliser GNL pour parser la map et les autres infos, lire ligne par ligne et stocker toute les infos dans un tableau et des structures
	- Si le ficher est invalide -> "Error\n" + message explicite
	- Si le ficher est valide





gestion de la texture des murs NSWE
gestion des sprite
gestion du sol et du plafond

gestion des touches gauche et droite
gestion de W, A, S et D

ESC ou cliquer sur la croix rouge doit fermer la fenetre et quitter le prog

Si la taille de fenêtre demandée dans la map est plus grande que celle de l’écran, la taille de fenêtre doit être celle de l’écran.


RAYCASTING :

L'idee globale : Pour chaque x de l'écran (c'est-à-dire pour chaque bande verticale de l'écran), on envoie un rayon qui commence à l'endroit où se trouve le joueur et dont la direction dépend à la fois de la direction de visée du joueur et de la coordonnée x de l'écran. Ensuite, laissez ce rayon avancer sur la carte 2D, jusqu'à ce qu'il touche une case de la carte qui est un mur. S'il touche un mur, calculez la distance entre ce point de frappe et le joueur, et utilisez cette distance pour calculer la hauteur de ce mur à l'écran : plus le mur est éloigné, plus il est petit à l'écran, et plus il est proche, plus il semble être haut.

Pour checker si y a un mur ou non, l'idée est de vérifier de chaque côté d'un mur que le rayon va rencontrer. Nous donnons à chaque carré une largeur de 1, donc chaque côté d'un mur est une valeur entière et les endroits entre les deux ont une valeur après le point. Algo pour faire ca : Digital Differential Analysis.

Travailler avec des vecteurs : la position du joueur est toujours un vecteur (une coordonnée x et une coordonnée y), mais maintenant, nous faisons aussi de la direction un vecteur : la direction est donc maintenant déterminée par deux valeurs : les coordonnées x et y de la direction. Un vecteur de direction peut être vu comme suit : si vous tracez une ligne dans la direction où le joueur regarde, à travers la position du joueur, alors chaque point de la ligne est la somme de la position du joueur, et un multiple du vecteur de direction. La longueur d'un vecteur de direction n'a pas vraiment d'importance, seule sa direction compte. Multiplier x et y par la même valeur change la longueur mais garde la même direction.
*/
