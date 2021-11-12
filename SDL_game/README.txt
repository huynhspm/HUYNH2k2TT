a small project by c++ and sdl

Introduce:
When you run program, Menu is showed (click mouse to pick):
	+) Choose Level: you can choose level(if you do not choose, it is level 1)
	+) About: way to move plane, image of obstacles and items  
	+) High Score:
	+) New Game to play and discover.

Start game, you have:
	+) Level:	Level that you choose in Menu
 	+) Score:	0
	+) Lives:	5
	+) Mode:		Battle normal.

In right screen, there are 4 buttons:
	+) Pause:		to pause game
	+) Sound toggle:		turn on or off the music
	+) Replay:		to back to Menu
	+) Quit:			Close Game Console

Plane: you move according to the guide in "About"
You will shoot obstacles and bosses.
You move plane to shoot 4 types of items falling from sky:
	+) rock:	if you shoot, your score increases by 1 and they will disappear, 
		if your plane is hit, your number of lives decreases by 1 and number of bullets
		decreases by 1 if it is greater than 2. 
 	+) shield:	if you shoot, you receive a shield.
	+) heart:	if you shoot, you receive an extra life.
	+) bullet:	if you shoot, number of bullets increases by 1.

For each shot item, you will hear special sound (except rock).

When you reach enough score, mode change to Boss Battle and you start to fight with boss:

Boss in level 1: boss throws bullets vertically.
Boss in level 2: boss throws bullets that bounce when reach the border.  
Boss in level 3: boss shoots laser beam (before shooting, its face color change to red for warning)

If plane is hit by boss bullets or beam, your lives decrease by 1 and number of bullets decreases by 1 if it is greater than 2.

Setting:
*	Method 1:
	-	Copy all files and folders to bin/debug except folders: bin and obj
	-	Then run SDL_game.ext in bin/debug.
*	Method 2:
	-	Open project in your IDE and compile a new program (not recommend).