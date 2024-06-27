# SO_LONG
<p align="center">
  <img width="668" alt="so_long_img" src="https://github.com/Gl1tsh/42_so_long/assets/69108289/71519126-8633-4144-aff3-bd73004331e0">
</p>


The So_Long project at 42 school is an introductory project that focuses on creating a simple 2D game using the MinilibX graphic library. The objective of the game is to collect all required items and reach the exit while avoiding obstacles.

This project introduces students to several key concepts in game development and graphics programming, including:

- *Graphics Rendering*: Students learn how to use the MinilibX library to render graphics on the screen, including drawing images, shapes, and text.

- *Game Loop*: The project involves implementing a game loop, which continuously updates the game state and renders the graphics to provide a seamless gameplay experience.

- *Collision Detection*: Students must implement collision detection algorithms to detect collisions between the player character and various game objects, such as walls and items.

- *Event Handling*: The project requires handling user input events, such as keyboard and mouse events, to control the player character and interact with the game environment.

- *Map Parsing*: Students parse a map file to generate the game environment dynamically, including the layout of walls, items, and the player's starting position.

- *Memory Management*: Proper memory allocation and deallocation are crucial to avoid memory leaks and ensure the efficient use of system resources.

In summary, the So_Long project provides students with hands-on experience in game development and graphics programming using the MinilibX library. It allows them to apply their knowledge of C programming and learn fundamental concepts in game design while creating a simple 2D game.

# How to launch the game :

## First step
- You need to clone the repository with the following command in the terminal: 

```git clone https://github.com/Gl1tsh/42_so_long.git```

- Now you need to enter the folder of the clone you've made

## Start the game

- Run the command: ```make```
- Once compiled, launch the game with a valid map: ```./so_long map/<map of your choice>```
- Exemple, you can copy past this : ```./so_long map/map1.ber```
- You have to collect all the pieces to be able to exit.

## Mouvement
| Commands                  | Move                            |
|---------------------------|---------------------------------|
| `W`/`A`/`S`/`D`           | front/left/down/right           |

## Enjoy
