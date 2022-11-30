#ifndef _PARAMETRE_H_
#define _PARAMETRE_H_


#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>

#define N 3
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define WIDTH (SCREEN_WIDTH / N)
#define HEIGHT (SCREEN_HEIGHT / N)

#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2



#define IS_RUNNING 0
#define QUIT_GAME 1


/*
structure board 3*3 rows and cols
*/
typedef struct
{
  int table[N*N];
  int player;
  int game_state;
}game_t;



#endif
