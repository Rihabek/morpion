CFLAGS = -O3 -g `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_gfx -lm
CCLINK = -lGL -lGLU -lSDL

INC = data_game.h SDL_render.h parametre.h fichier.h audio.h SDL2_gfxPrimitives.h SDL2_gfxPrimitives_font.h
SRC = main.c SDL_render.c data_game.c audio.c fichier.c SDL2_gfxPrimitives.c

OBJ = main.c SDL_render.o data_game.o audio.o fichier.o SDL2_gfxPrimitives.o


PROG = morpion

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

morpion: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

debug:
	  gcc -DDEBUG -Wall -o main.c data_game.c SDL_render.c -lm

clean:
	rm -f *~ *.o $(PROG)
	rm -rf latex html
