#include "data_game.h"
#include "parametre.h"



void switch_player(game_t *game)
{
    if (game->player == PLAYER_X)
    {
        game->player = PLAYER_O;
    } else if (game->player == PLAYER_O)
    {
        game->player = PLAYER_X;
    }
}

int won_game(game_t *game,  int player)
{
  int counter_coll = 0;
  int counter_row = 0;
  int dia1 = 0;
  int dia2 = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (game->table[i*N+j] == player)
      {
        counter_row++;
      }
      if (game->table[j*N+i] == player)
      {
        counter_coll++;
      }
    }
    if (counter_row >= N || counter_coll >= N)
    {
      return 1;
    }
    
    // if the counter row and col didnt reset at 0 it cant works
    // correctly it will continue aat counting without reset at 0

    counter_row = 0;
    counter_coll = 0;

    if (game->table[i * N + i] == player)
    {
      dia1++;
    }

    if (game->table[i * N + N - i -1] == player)
    {
      dia2++;
    }
  }

  return dia1 >= N || dia2 >= N;
}

int count_cases(const int *table, int cell)
{
  int counter = 0;
  for (int i = 0; i < N * N; i++)
  {
    if (table[i] == cell)
    {
      counter++;
    }
  }
  return counter;
}

void game_over_condition(game_t *game)
{
  if (won_game(game,PLAYER_X))
  {
    game->game_state= PLAYER_X_WON_GAME;
  }else if (count_cases(game->table,EMPTY) ==0)
  {
    game->game_state = TIE_GAME;
  }else if (won_game(game, PLAYER_O))
  {
    game->game_state = PLAYER_O_WON_GAME;
  }

}

void player_turn(game_t *game, int row, int col)
{
    if (game->table[row * N + col] == EMPTY)
    {
        game->table[row * N + col] = game->player;
        switch_player(game);
        game_over_condition(game);
    }
}

void reset(game_t *game)
{
    game->player = PLAYER_X;
    game->game_state = IS_RUNNING;
    for (int i = 0; i < N * N; ++i)
    {
        game->table[i] = EMPTY;
    }
}

void clicked_cell(game_t *game, int row, int col)
{
    if (game->game_state == IS_RUNNING) {
        player_turn(game, row, col);
    } else {
        reset(game);
    }
}
