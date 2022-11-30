#include "parametre.h"




int main()
{

  SDL_Window *window;

  //initialisation SDL window
  if (SDL_Init(SDL_INIT_VIDEO| SDL_INIT_AUDIO) < 0)
  {
    fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());

    return EXIT_FAILURE;
  }

  window = SDL_CreateWindow("morpion",200, 200,SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_OPENGL);


  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL)
  {
    SDL_DestroyWindow(window);
    fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }


  game_t game = {
      .table = { EMPTY, EMPTY, EMPTY,
                 EMPTY, EMPTY, EMPTY,
                 EMPTY, EMPTY, EMPTY },
      .player = PLAYER_X,
      .game_state = IS_RUNNING
  };

// boucle du jeu

  SDL_Event a;
  while (game.game_state != QUIT_GAME)
  {

    while (SDL_PollEvent(&a))
    {
      switch (a.type)
      {
        case SDL_QUIT:
            game.game_state = QUIT_GAME;
            break;

        default: {}
      }
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }


    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

    
}
