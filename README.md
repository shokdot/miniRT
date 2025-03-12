# miniRT

## Description

`miniRT` is a minimalistic implementation of a ray tracing engine, developed as part of a collaborative project with my teammate Tigran Yavroyan. The project demonstrates the fundamentals of ray tracing, where we focus on rendering simple scenes with basic shapes like spheres, planes, cylinders and light sources.

The engine supports rendering a scene from a text file that defines objects and their properties, including light positions, camera setup, and object specifications. The output is a basic image rendered using ray tracing principles.

## Features

- **Ray Tracing Engine**: Renders 3D scenes using ray tracing techniques.
- **Basic Geometries**: Supports spheres, planes, and basic transformations (scaling, rotating).
- **Lighting**: Basic lighting with ambient and point light sources.
- **Scene File Parsing**: Input scene description from a `.rt` text file.
- **Image Output**: Renders the scene as an image in MiniLibX window.

## Installation (For Mac OS)

1. Clone the repository:
   ```bash
   git clone https://github.com/shokdot/miniRT
   cd miniRT
   ```
2. Compile:
    ```bash
    make
    ```
3. Run:
    ```bash
    ./miniRT maps/snowman.rt
    ```

## Installation (For Linux)

1. Clone the repository:
   ```bash
   git clone https://github.com/shokdot/miniRT
   cd miniRT
   ```
2. Clone MLX for Linux
    ```bash
    git clone https://github.com/42Paris/minilibx-linux libs/mlx_linux
    ```
3. Compile
    ```bash
    make
    ```
4. Run:
    ```bash
    ./miniRT maps/snowman.rt
    ```
## Resources

-   [C Documentation](https://en.cppreference.com/w/c)
-   [42 Norminette](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf)
-   [Subject](https://cdn.intra.42.fr/pdf/pdf/147734/en.subject.pdf)
-   [Tigran's profile](https://github.com/TigranYavroyan)

## License

This project is part of the 42 School curriculum and should be used for educational purposes only.


