#ifndef KNOPKA_H
#define KNOPKA_H

#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <sys/ioctl.h>

typedef struct s_display {
    int length;
    int start;
    int finish;
    wchar_t *arr;
} t_display;

typedef struct t_player
{
    int points;
    double limit;
} t_player;

void printOutLetter(WINDOW*, char, int, int, int);
//adding snake
int kbhit (void);
int colliding(int *, float);
void moveSnake(int *, int, int, int, float);
void letThereBeApple(int *, int *, int *);
void eatApple(int *, int, int, int *, float *);
int snake();


#endif
