## Cub3d

### Description ✨
Cub3d is a 42 project, written in C, which consisted in recoding a game using raycasting.
A config file is provided at the execution, example with `parsing.cub`

The graphic library used is the [minilibx](https://github.com/42Paris/minilibx-linux)

#### _Example of config file_

```
R 1280 720
SO ./textures/jungle-1.xpm 
NO ./textures/jungle-2.xpm
EA ./textures/jungle-3.xpm
WE ./textures/jungle-4.xpm
S ./textures/banana.xpm
C 31,14,28    
F 100, 125, 52

11111
12001
100N1
11111
```

- `R` is the resolution of the screen
- `SO`, `NO`, `EA`, `WE` and `S` are the xpm file used to represent the wall of the respectives directions: `South, North, East, West` (the **1** on the map) and the `Sprite` (the **2** on the map)
- `C` and `F` are respectively `Ceiling` and `Floor`, representing an RGB color.
- The map that follows the rules: **1** for wall, **0** for the ceiling, **2** for the sprite, **N**, **E**, **W** or **S** for the spawn and its direction.

### Main purpose :page_facing_up:
The goal of this project using the minilibx, was to be able to code a FPS 3D game, using [raycasting](https://en.wikipedia.org/wiki/Ray_casting). Parsing the config file to get all the textures, the map, the RGB colors. The map follows some rules such as:
- The map must be surrounded by walls
- There must be one and only one spawn

The creation of a bitmap file representing the screenshot of the first image of the game, without launching it, if the argument `--save` is given.

Handle movement and collision with walls, handle hooks for keyboard keys:
- ZQSD to move (_azerty_)
- Arrow left and right for the camera view
- Escape to leave the game

### How to use :rocket:
First, run ``make``
Then run:


You can edit `parsing.cub` before to change the configuration of the game as explained above.
```
./Cub3D parsing.cub
```
Controls are **ZQSD** (_azerty_), **Arrow Left/Right** 🎮


If you want to create a screenshot of the game without launching it, you can use `--save` as:
```
./Cub3D parsing.cub --save
```


Enjoy the game!
