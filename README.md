*This project has been created as part of the 42 curriculum by malavaud.*

# So Long

## Description

**So Long** is a graphical mini-game project from the 42 curriculum. Its objective is to introduce students to 2D game development using the **MiniLibX** graphics library. The project consists in creating a small top-down game in which the player must collect all collectibles on the map and reach the exit while avoiding enemies (depending on the bonus implementation).

The map is provided as a `.ber` file and must follow strict formatting rules. The program loads the map, displays it graphically, and handles player movements using keyboard inputs.

This project focuses on:

* Basic **game loop logic**
* **Window management** and **image rendering** with MiniLibX
* **Event handling** (keyboard inputs, window closing)
* **Map parsing** and error management
* (Bonus) Animations, enemy movement, improved textures, etc.

## Instructions

### Requirements

* macOS or Linux
* **MiniLibX** installed (provided by 42 or included in the project directory)
* A C compiler (gcc)

### Compilation

Run the following command at the root of the repository:

```bash
make
```

To recompile from scratch:

```bash
make fclean && make
```

### Execution

Run the game with:

```bash
./so_long <map.ber>
```

Example:

```bash
./so_long map/level.ber
```

### Example Error Output

If the map is invalid, the program must display an error message.

Example:

```
Error
Map is not rectangular
```

## Resources

### Documentation & References

* MiniLibX documentation (official 42 docs)
* To understand the so_long project https://42-cursus.gitbook.io/guide/2-rank-02/so_long 
* 42 subject PDF for **so_long**
* Articles on handling key events and rendering loops

### How AI Was Used

AI (ChatGPT) was used to:

* Rephrase and structure the README
* Provide examples of wording and organization
* Suggest conventional sections and descriptions

AI **was not used** to write core code logic, algorithms, map parsing, or game mechanics. All implementation decisions and coding were done manually.
