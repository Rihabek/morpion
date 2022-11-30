CFLAGS = -O3 -g `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_gfx -lm
CCLINK = -lGL -lGLU -lSDL

INC = parametre.h
SRC = main.c

OBJ = main.c


PROG = morpion

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

morpion: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

debug:
	  gcc -DDEBUG -Wall -o main.c -lm

clean:
	rm -f *~ *.o $(PROG)
	rm -rf latex html
