# <div align="center"> 🎮 GAME - UET - 2021 🎮

## **1. About this project 📝**

A small game project, reused and further developed from [my first project back in 11th grade](https://github.com/huynhspm/First-Product), using C++ and the SDL2 library for graphics. The game draws inspiration from classic Nokia mobile games I enjoyed in my childhood, enhanced with creative bosses across various levels.

## **2. How to run 🚀**
- Clone repository:

      git clone https://github.com/huynhspm/GAME-UET.git

- For ubuntu:

      # install
      sudo apt update
      sudo apt install g++ 
      sudo apt install cmake
      sudo apt install libsdl2-dev libsdl2-ttf-dev libsdl2-mixer-dev libsdl2-image-dev

      # verify
      g++ --version
      cmake --version
      sdl2-config --version

      # run
      mkdir build
      cd build
      cmake ..
      make
      ./SDL2_GAME

- For window: 
  - Install C++

        # verify
        g++ --version

  - Run

        cd window
        SDL_game.exe


## **3. How to play 🕹️**
- When you start the program, a menu appears with the following options (click to select):
  - Choose Level: Select a starting level (defaults to Level 1 if no selection is made).
  - About: View instructions on plane controls, along with images of obstacles and items.
  - High Score: Check the highest scores achieved.
  - New Game: Begin a new game and explore!"

- When the game starts, you begin with:
  - Level: The level selected in the Menu
  - Score: 0
  - Lives: 5
  - Mode: Normal Battle
  - On the right side of the screen, there are four buttons:
  	- Pause: Pause the game
  	- Sound Toggle: Turn music on or off
  	- Replay: Return to the Menu
  	- Quit: Exit the Game Console

- Move plane according to the guide in the "About" section. Your goal is to shoot obstacles and bosses while also targeting four types of items falling from the sky:
	- Rock: Shooting it increases your score by 1, and the rock disappears. However, if your plane is hit, you lose 1 life and 1 bullet (if you have more than 2).
	- Shield: Shooting it grants you a protective shield.
	- Heart: Shooting it awards you an extra life.
	- Bullet: Shooting it increases your bullet count by 1.

- For each shot item, you will hear special sound (except rock). When you reach enough score, mode change to Boss Battle and you start to fight with boss:
  - Boss in level 1: boss throws bullets vertically.
  - Boss in level 2: boss throws bullets that bounce when reach the border.  
  - Boss in level 3: boss shoots laser beam (before shooting, its face color change to red for warning)

- If plane is hit by boss bullets or beam, your lives decrease by 1 and number of bullets decreases by 1 if it is greater than 2.


## **4. Demo 🎬**
![Gameplay GIF](demo.gif)