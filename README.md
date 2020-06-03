# Cub3d

J'ai recodé le jeu Cub3d en C.

Ce projet est issu de l'école 42
[gist](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2) et utilise la minilibx.

## Sommaire

  - [Bibliothèques utilisées](#bibliothèqes-utilisées)
  - [Deployment](#deployment)
  - [Built With](#built-with)
  - [Contributing](#contributing)
  - [Versioning](#versioning)
  - [Authors](#authors)
  - [License](#license)
  - [Acknowledgments](#acknowledgments)

## Bibliothèques utilisées

<unistd.h>
<stdlib.h>
<math.h>
<fcntl.h>
<mlx.h> (installée localement)

### Prérequis

Si vous ne disposez pas de la minilibx, vous devez l'installer afin de compiler le projet.
Vous devez remplir le fichier parsing.cub des informations ci dessous :

R     "X, Y résolution" 

NO   "texture north path"
SO   "texture south path"
WE   "texture west path"
EA   "texture east path"
S    "texture sprite path"

F    "R, G, B color of the floor"
C    "R, G, B color of the ceiling"

1111111111111111111111
1100000000000000000111
11111000000000N1111
110000000000001
111200200100111
110000000000111111111
1111110000000000000001
111111111111111111111

(The map, with N,W,E or S spawn direction)

0      sont le floor,
1      sont les walls,
2      sont les sprites,
spaces ne sont rien mais sont valides

### Compilation

Une fois la minilibx installée localement, ou sur votre pc.
Lancez la commande make.

## Lancement

Pour lancer le projet lancez la commande : ./Cub3D parsing.cub

### Alternative de lancement

En lançant la commande : ./Cub3D --save
Le jeu ne se lance pas, mais effectue un screen de la première image du jeu en lancement et est stockée dans le fichier screen du repos.

## Authors

  - **Tsarafian** - *42 school's student* -
  - **Elajouan** -

## Sources

- [https://lodev.org/cgtutor/raycasting.html]
