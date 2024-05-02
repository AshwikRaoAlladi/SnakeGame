# SnakeGame
Certainly! Let's break down the algorithm step by step:

Initialization (setup()):
The game initializes by setting the gameOver flag to false.
The direction (dir) of the snake is set to STOP, indicating that it is not moving initially.
The initial position of the snake (x and y) is set to the center of the game board.
The position of the fruit (fruitx and fruity) is randomly generated within the game board.
Rendering (Draw()):
The game board is cleared (system("CLS")) to refresh the screen.
Walls of the game board are drawn using '#' characters.
The snake's head is drawn at its current position (x and y) using the 'O' character.
The fruit is drawn at its current position (fruitx and fruity) using the 'F' character.
The snake's tail is drawn using 'o' characters, based on the positions stored in the tailx and taily arrays.
The player's score is displayed on the screen.
Input Handling (Input()):
The function checks if a key has been pressed using _kbhit().
If a key has been pressed, it reads the key using _getch() and updates the direction of the snake (dir) accordingly.
The possible directions are: UP, DOWN, LEFT, and RIGHT.
Game Logic (Logic()):
The previous position of the snake's head is stored.
The snake's head is moved in the direction determined by the dir variable.
If the snake goes out of bounds (hits the walls), the game ends (gameOver becomes true).
If the snake collides with its own tail, the game ends.
If the snake's head overlaps with the fruit, the player's score is increased by 10 points, a new fruit is randomly placed on the board, and the length of the snake's tail (nTail) is incremented.
Main Loop (main()):
The game loop continues until gameOver becomes true.
In each iteration of the loop, the game board is drawn (Draw()), user input is handled (Input()), and game logic is updated (Logic()).
The Sleep(40) function is used to pause execution for 40 milliseconds, controlling the speed of the game.
