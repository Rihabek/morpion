#include "parametre.h"
#ifndef SDL_RENDER_H_
#define SDL_RENDER_H_




void render_lines(SDL_Renderer *renderer,const SDL_Color *color);




void render_table(SDL_Renderer *renderer,
                  const int *table,
                  const SDL_Color *PLAYER_X_COLOR,
                  const SDL_Color *PLAYER_O_COLOR);

void render_is_running(SDL_Renderer *renderer, const game_t *game);

void render_game_over(SDL_Renderer *renderer,
                      const game_t *game,
                      const SDL_Color *color);

void render_game(SDL_Renderer *renderer, const game_t *game);

#endif
