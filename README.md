# Fdf

A repository containing the fdf project of 42 Malaga. The aim of this project is to parse the files included in tests maps so that the program can read them and create a isometric projection of those coordinates, thus creating 3D looking images.

For example, passing the pikachu.fdf file as an argument to the program will create the following image.

<img width="452" alt="Screen Shot 2024-03-19 at 4 43 05 PM" src="https://github.com/juan-est145/Fdf/assets/128648875/6988b207-910d-4da7-b95d-b69ca6ddb708">

This project is only supposed to work on MacOS. In order to compile it first make sure that you have installed the neccesary dependencies needed for the graphical library to work. You can find them here:
(https://github.com/codam-coding-college/MLX42).

You can find all of the project details inside the subject pdf. Also, you can use your own maps if you want, just make sure to stick to the requirements listed in the subject pdf, that the rows of the map have the same lenght and that the file has a .fdf extension.

If you are a fellow student at 42, DO NOT COPY ANYTHING FROM THIS REPOSITORY THAT 
YOU DO NOT UNDERSTAND, use it to learn instead.

## Dependencies

For this project to compile you will need a C compiler, Cmake and the Make command. Also, you will need to install the necessary dependencies for the MLX42 graphic libray to function according to your operating system (POSIX system's are recommended). You can find said dependencies and how to install them here: (https://github.com/codam-coding-college/MLX42).


## Run Locally

Clone the project

```bash
  git clone https://github.com/juan-est145/Fdf.git
```
Install dependencies (MacOs)

```bash
  brew install glfw
  brew install cmake
```

Install dependencies (Debian distributions)
```bash
  sudo apt update
  sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
```

Go to the project directory

```bash
  cd fdf
```

Compile the program
```bash
  make
```

Run the executable
```bash
  ./fdf test_maps/*Whatever map you want*
```

To delete the .o files and the executable
```bash
  make fclean
```
