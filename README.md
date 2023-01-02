# Morpion

@author Belkhadiri rihab

Les @fichier:
main.c
data_game.c
data_game.h
SDL_render.c
SDL_render.h
parametre.h


compiler @Morpion:
  make

executer @Morpion:
  ./Morpion

clean @Morpion:
  make clean

debug @Morpion:
  make debug


-creation SDL window main.c


-define les parametre qu'on va utiliser dans le programme
-data_game.c
-creation de makefile
  qui contient:
    debugging
    clean
    doxygen
    les fichier src
    les fichier bibleotheque
    les fichier object



- SDL_render.c creation des function pour rendre le jeu
- ajout du sons pendant le jeu
- Mise en place d'une function clicked case qui prends 3 parametre game et row et col. qui prends en charge l'état du jeu, si le jeu IS_RUNNING alors player_turn() sinon reset() tout les cases devient EMPTY et le jeu redemare  


- cretaation d'un circle avec la bibleotheque SDL2_gfxPrimitives en utilisant la function filledCircleRGBA() et apres et cree une autre circle en utilisant la meme function pour avoir une ligne circle car apparmant il n'y a pas une function qui nous permets de creer une ligne circle.

-creation da la logique du jeu en utilisant les fonction suivant :
	void player_turn()
	int won_game()
	void game_over_condition()
	int count_cases()
	void switch_player()
	void reset()
	void clicked_cell()
