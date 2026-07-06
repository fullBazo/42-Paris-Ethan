*This project has been created as part of the 42 curriculum by rdupoix and ehuet.*

# cub3D

> My first RayCaster with miniLibX.

---

## Description

**cub3D** is a first-person 3D maze renderer inspired by the legendary
*Wolfenstein 3D*. It is built in C with the **miniLibX** graphics library and
recreates a "realistic" 3D view of the inside of a maze using the
**ray-casting** technique — the same trick that powered early 90s pseudo-3D
games on machines that could not yet do real 3D.

The program reads a scene description file (`*.cub`), validates it, then opens a
window and lets the player walk and look around the maze in real time. Walls are
textured according to the direction they face (North, South, East, West), while
the floor and ceiling are filled with two distinct solid colors.

Under the hood the renderer relies on the **DDA** (Digital Differential
Analysis) algorithm to find wall intersections efficiently and corrects the
classic *fish-eye* distortion so that straight walls stay straight.

### Features

- Strict parsing and validation of `.cub` scene files.
- Closed-map detection (the map must be fully surrounded by walls).
- Textured walls, with a different texture per orientation (NO / SO / EA / WE).
- Configurable floor and ceiling colors.
- Smooth ray-casting rendering with fish-eye correction.
- Movement (`W` `A` `S` `D`) and camera rotation (left / right arrows).
- Clean exit via the `ESC` key or the window's red cross.
- No memory leaks; every error case exits cleanly with an explicit message.

---

## Instructions

### Requirements

- A Linux environment (the project uses the X11-based miniLibX).
- `cc` and `make`.
- The math library (`-lm`) and X11 development libraries (`-lXext`, `-lX11`).

The `libft` and `minilibx` sources are bundled in the repository and are
compiled automatically by the project's `Makefile`.

### Compilation

```bash
make        # builds the libft, the minilibX, then the cub3D binary
make run    # rebuild the project with "re" rule and run the program after that
make debug  # rebuild the project with "re" rule and run the program with gdb
make vg     # rebuild the project with "re" rule and run the program with valgrind
make norm   # run the norminette command on all our .c files without mlx ones
make clean  # removes object files
make fclean # removes object files and the binary
make re     # full rebuild
```

We add a Makefile variable call "MAP" that you can add in the prompt line to select the argument .cub you need. 
It works with *run*, *debug* and *vg* Makefile rules. For exemple :

```bash
 make run MAP=map/....
```

The Makefile compiles with the `-Wall -Wextra -Werror` flags and performs no
unnecessary relinking.

### Execution

The program takes exactly **one** argument: a scene file with the `.cub`
extension.

```bash
./cub3D <map.cub>
```

For example:

```bash
./cub3D map/good_map.cub
```

If the file is missing, malformed, or contains any misconfiguration, the program
exits cleanly and prints `Error` followed by an explicit message.

### Controls

| Key            | Action                       |
|----------------|------------------------------|
| `W` / `S`      | Move forward / backward      |
| `A` / `D`      | Strafe left / right          |
| `←` / `→`      | Rotate the camera left/right |
| `ESC`          | Quit the program             |
| Red cross      | Quit the program             |

---

## The `.cub` scene file

A scene file describes the textures, the colors, and the map. Apart from the
map (which must always come last), elements can appear in any order and be
separated by one or more empty lines.

| Identifier | Meaning                          | Example                       |
|------------|----------------------------------|-------------------------------|
| `NO`       | North wall texture path          | `NO ./assets/NO_texture.xpm`  |
| `SO`       | South wall texture path          | `SO ./assets/SO_texture.xpm`  |
| `WE`       | West wall texture path           | `WE ./assets/WE_texture.xpm`  |
| `EA`       | East wall texture path           | `EA ./assets/EA_texture.xpm`  |
| `F`        | Floor color, `R,G,B` in `[0,255]`| `F 220,100,0`                 |
| `C`        | Ceiling color, `R,G,B` in `[0,255]`| `C 225,30,0`                |

The map uses only six characters:

- `0` — empty walkable space
- `1` — wall
- `N`, `S`, `E`, `W` — player's start position and facing direction

The map must be closed/surrounded by walls. Spaces are a valid part of the map.

Minimal valid example:

```
NO ./assets/NO_texture.xpm
SO ./assets/SO_texture.xpm
WE ./assets/WE_texture.xpm
EA ./assets/EA_texture.xpm
F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

---

## Project structure

```
.
├── includes/        # cub3d.h, struct.h (shared headers, structures, enums)
├── libft/           # custom C library (incl. get_next_line, ft_printf)
├── minilibx/        # bundled miniLibX sources
├── assets/          # wall textures (.xpm)
├── map/             # valid and invalid test scenes
└── srcs/
    ├── main.c
    ├── parsing/     # scene reading, element & color parsing, map validation,
    │                #   flood-fill closure check
    ├── cleaning/    # memory cleanup (parsing + mlx)
    └── game/
        ├── init/        # window, image and texture initialization
        ├── moovement/   # key hooks, player movement & rotation
        └── raycasting/  # DDA, wall projection, texture mapping, drawing
```

---

## Resources

Classic references used while studying ray-casting and the miniLibX:

- **Lode Vandevenne — Lode's Computer Graphics Tutorial: Raycasting**
  (the reference walkthrough of the DDA-based raycaster):
  https://lodev.org/cgtutor/raycasting.html
- **42 miniLibX documentation** and the bundled man pages
  (`mlx`, `mlx_loop`, `mlx_new_image`, `mlx_new_window`, `mlx_pixel_put`).
- **Permadi — Ray-Casting Tutorial**, for the geometry and the fish-eye
  correction explanation: https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
- The original *Wolfenstein 3D* (playable online) for reference and motivation:
  http://users.atw.hu/wolf3d/

### Use of AI

AI tools were used as a learning and productivity aid, never as a substitute for
understanding. Specifically:

- **Explanations and intuition:** to clarify the math behind the DDA algorithm,
  the fish-eye correction, and how miniLibX images and addresses work.
- **Debugging support:** to reason about segmentation faults, memory leaks
  (cross-checked with `valgrind`), and edge cases in the `.cub` parser.
- **Norm and refactoring:** to spot functions exceeding the 42 Norm limits and
  to suggest ways to split them into smaller helpers.
- **README.md generating**
