#include "knopkodav.h"

int kbhit (void) {
  /* checks if key has been hit or not */
  struct timeval tv;
  fd_set read_fd;

  tv.tv_sec=0;
  tv.tv_usec=0;
  FD_ZERO(&read_fd);
  FD_SET(0,&read_fd);

  if(select(1, &read_fd, NULL, NULL, &tv) == -1)
    return 0;

  if(FD_ISSET(0,&read_fd))
    return 1;

  return 0;
}

int colliding(int *snakeArray, float snakeLength) {
  /* checks if snake is colliding with walls */
  int x = *snakeArray;
  int y = *(snakeArray+1);
  int parent_x, parent_y;
  getmaxyx(stdscr, parent_y, parent_x);

  if (x < 1 || x > parent_x-2) {
    return 1;
  }
  else if (y < 2 || y > parent_y-2) {
    return 1;
  }

  for (size_t i = 2; i < snakeLength*2+2; i+=2) {
    if (x == *(snakeArray+i) && y == *(snakeArray+i+1)) {
      return 1;
    }
  }
  return 0;
}

void moveSnake(int *snakeArray, int dirX, int dirY, int speed, float snakeLength) {
  /* moves snake one position to the direction provided also controls the speed
     of the game using usleep function */
  int oldX = 0;
  int oldY = 0;
  int curX = *snakeArray;
  int curY = *(snakeArray+1);
  int newX = curX + dirX;
  int newY = curY + dirY;

  *(snakeArray) = newX;
  *(snakeArray+1) = newY;
  mvprintw(newY, newX, "+");

  for (size_t i = 2; i < snakeLength*2; i += 2) {
    oldX = curX;
    oldY = curY;
    curX = *(snakeArray+i);
    curY = *(snakeArray+i+1);
    newX = oldX;
    newY = oldY;
    *(snakeArray+i) = newX;
    *(snakeArray+i+1) = newY;

    mvprintw(newY, newX, "x");
    }

  usleep(500000/speed);
}

void letThereBeApple(int* appleX, int* appleY, int *appleEaten) {
  int parent_x, parent_y;
  getmaxyx(stdscr, parent_y, parent_x);
  parent_y= parent_y - 4;
  parent_x= parent_x -3;
  /* new random apple location if apple is eaten, if not then prints apple at
     previous location */
  if (*appleEaten) {
    srand(time(0)); //use current time as seed for random generator
    *appleX = (rand() % parent_x ) +2;
    *appleY = (rand() % parent_y) +3;
    *appleEaten = 0;
  }
  start_color();
  init_pair(2,COLOR_GREEN,COLOR_BLACK);
  attron(COLOR_PAIR(2));
  mvprintw(*appleY, *appleX,"");//A
  attroff(COLOR_PAIR(2));
}

void eatApple(int *snakeArray, int appleX, int appleY, int *appleEaten, float *snakeLength) {
  /* if snake find apple get one point, also sets appleEaten to true and
  prints snakeLength and debug info */
  int x = *snakeArray;
  int y = *(snakeArray+1);
  if (x == appleX && y == appleY) {
    *appleEaten = 1;
    *snakeLength += 1;
    int snakeLen = *snakeLength;
    int lastX = *(snakeArray + snakeLen*2-2);
    int lastY = *(snakeArray + snakeLen*2-2+1);
    *(snakeArray + snakeLen*2) = lastX;
    *(snakeArray + snakeLen*2+1) = lastY;
  }
  mvprintw(0,0,"snakeLength: %.0f", *snakeLength);
}

int snake() {

  int snakeArray[100][2];
  for (size_t i = 0; i < 100; i++) {
    for (size_t j = 0; j < 2; j++) {
      snakeArray[i][j] = 0;
    }
  }
  snakeArray[0][0] = 3;
  snakeArray[0][1] = 3;
  int keyPressed = 0;   /* which key user pressed */
  int dirX = 1;        /* direction xy */
  int dirY = 0;
  int speed = 4;       /* controls speed of the snake */
  int appleX = 0;       /* current apple xy position */
  int appleY = 0;
  int appleEaten = 1;   /* is apple eaten? */
  float snakeLength = 20;  /* player snakeLength */

  int start_time=0;
  int plus=0;

  initscr();			/* Start cursesq mode */
  curs_set(false);
  noecho();
  /* MAIN LOOP */
  while (!colliding(&snakeArray[0][0], snakeLength)) {
    erase();
  
  int parent_x, parent_y;
  getmaxyx(stdscr, parent_y, parent_x);
	mvhline(1, 0, '#', parent_x);//drawing a border
	mvhline(parent_y-1, 0, '#', parent_x);//drawing a border
	mvvline(1, parent_x -1, '#', parent_y-2);//drawing a border
	mvvline(1, 0, '#', parent_y-2);//drawing a border
  
  start_time++;
  if (start_time==9){
    start_time=0;
    plus++;
  }
   
 mvprintw(0,20,"Timer: %d", plus);

    letThereBeApple(&appleX, &appleY, &appleEaten);
    moveSnake(&snakeArray[0][0], dirX, dirY, speed, snakeLength);
    eatApple(&snakeArray[0][0], appleX, appleY, &appleEaten, &snakeLength);
    refresh();

    /* change direction with wasd */
    if (kbhit()) {
      keyPressed = getch();

      if (keyPressed == 'w' && !(dirY == 1 && dirX == 0)) {
        dirY = -1;
        dirX = 0;
      }
      if (keyPressed == 's' && !(dirY == -1 && dirX == 0)) {
        dirY = 1;
        dirX = 0;
      }
      if (keyPressed == 'a' && !(dirY == 0 && dirX == 1)) {
        dirY = 0;
        dirX = -1;
      }
      if (keyPressed == 'd' && !(dirY == 0 && dirX == -1)) {
        dirY = 0;
        dirX = 1;
      }
    }


  }
  erase();
  int p_x, p_y;
  getmaxyx(stdscr, p_y, p_x);
  mvprintw((p_y/2),(p_x/2) -8,"Time wasted: %d", plus);
  mvprintw((p_y/2) - 3,(p_x/2) -16,"Game Over! - Your score was: %d", snakeLength);
  mvprintw((p_y/2) +3,(p_x/2) -8,"PRESS R TO RETRY");
  mvprintw((p_y/2) + 6,(p_x/2) -13,"PRESS B TO RETURN TO MENU");
  refresh();
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}
