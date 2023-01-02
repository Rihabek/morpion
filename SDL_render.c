#include "SDL_render.h"
#include <math.h>
#include <SDL2/SDL2_gfxPrimitives.h>



/*
const color pour les lignes du jeu
const color rouge pour le player X
const color vert pour le player O
const color white pour le tie game
*/
const SDL_Color LINE_COLOR =
{
  .r = 255,
  .g = 255,
  .b = 255
};
const SDL_Color PLAYER_X_COLOR =
{
  .r = 255,
  .g = 50,
  .b = 50
};

const SDL_Color PLAYER_O_COLOR =
{
  .r = 0,
  .g = 100,
  .b = 0
};

const SDL_Color TIE_COLOR =
{
  .r =100,
  .g = 100,
  .b = 100
};


void render_lines(SDL_Renderer *renderer,const SDL_Color *color)
{
  SDL_SetRenderDrawColor(renderer,color->r,color->g,color->b, 255);

  for (int i = 1; i < N; i++)
  {
    // creation d'un ligne verticale
    SDL_RenderDrawLine(renderer,i * WIDTH, 0, i * WIDTH, SCREEN_HEIGHT);
    // creation des ligne horizontal
    SDL_RenderDrawLine(renderer,0, i * HEIGHT,SCREEN_WIDTH, i * HEIGHT);
  }
}

/*
/pour creer une linge ainsi "/" il faut calculer
/un carre dans la case pour
/ difinir le centre s = min(height,width)/4
**/
void render_xLine(SDL_Renderer *renderer, int row , int col, const SDL_Color *color)
{
    const float inside_case = fmin(WIDTH,HEIGHT) * 0.24; //min(height,width)/4
    const float center_case_x = WIDTH * 0.5 + col * WIDTH;
    const float center_case_y = HEIGHT * 0.5 + row * HEIGHT;
    // draw une ligne comme ca /
    thickLineRGBA(renderer, center_case_x - inside_case,
                            center_case_y - inside_case,
                            center_case_x + inside_case,
                            center_case_y + inside_case,
                            5,
                            color->r,
                            color->g,
                            color->b,
                            255);
    // draw une ligne comme ca "\"
    thickLineRGBA(renderer, center_case_x + inside_case,
                            center_case_y - inside_case,
                            center_case_x - inside_case,
                            center_case_y + inside_case,
                            5,
                            color->r,
                            color->g,
                            color->b,
                            255);
}

void render_oCircle(SDL_Renderer *renderer, int row , int col, const SDL_Color *color)
{
  // calculer le centre de la case
  const float inside_case = fmin(WIDTH,HEIGHT) * 0.24; //min(height,width)/4
  const float center_case_x = WIDTH * 0.5 + col * WIDTH;
  const float center_case_y = HEIGHT * 0.5 + row * HEIGHT;
  // en fait une circle apre une autre circle en noir
  filledCircleRGBA(renderer,
                    center_case_x, center_case_y, inside_case + 5,
                    color->r, color->g, color->b, 255);
  filledCircleRGBA(renderer,
                    center_case_x,center_case_y,inside_case - 5,
                    0, 0, 0, 255);

}

void render_table(SDL_Renderer *renderer,
                  const int *table,
                  const SDL_Color *player_x_color,
                  const SDL_Color *player_o_color)
{
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        switch (table[i * N + j])
        {
          case PLAYER_X:
            render_xLine(renderer, i , j, player_x_color);
            break;
          case PLAYER_O:
            render_oCircle(renderer, i , j, player_o_color);
            break;

          default: {}
        }
      }
    }

  }

  void render_is_running(SDL_Renderer *renderer, const game_t *game)
{
    render_lines(renderer, &LINE_COLOR);
    render_table(renderer, game->table, &PLAYER_X_COLOR, &PLAYER_O_COLOR);

}

void render_game_over(SDL_Renderer *renderer,
                      const game_t *game,
                      const SDL_Color *color)
{
    render_lines(renderer, color);
    render_table(renderer, game->table, color,color);
}



/** on utilise const game psk on veut pas qu'il fait
des changement sur le jeu on veut qu'il render le state de game
*/
void render_game(SDL_Renderer *renderer, const game_t *game)
{
    switch (game->game_state)
    {
      case IS_RUNNING:
          render_is_running(renderer, game);
          break;

      case PLAYER_X_WON_GAME:
          render_game_over(renderer, game, &PLAYER_X_COLOR);
          break;

      case PLAYER_O_WON_GAME:
          render_game_over(renderer, game, &PLAYER_O_COLOR);
          break;

      case TIE_GAME:
          render_game_over(renderer, game, &TIE_COLOR);
          break;

      default: {}
    }
}
