/**
 *  \file data_game.h
 * \brief la logique du jeu
 * \@author Belkhadiri rihab 
  * \game_state
 */
#include "parametre.h"

#ifndef DATA_GAME_H_
#define DATA_GAME_H_

void player_turn(game_t *game, int row, int column);

int won_game(game_t *game,  int player);

void game_over_condition(game_t *game);

int count_cases(const int *table, int cell);

void switch_player(game_t *game);

void reset(game_t *game);

void clicked_cell(game_t *game, int row, int column);


#endif
