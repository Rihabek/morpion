#include "parametre.h"
#include "fichier.h"

char** fichier_txt(FILE* fichier)
{
  char mode = 0;
  fichier = fopen("morpion.txt","r");

  if (fichier == NULL)
  {
    printf("Error impossible de lire le fichier: %s\n", SDL_GetError());
  }

  while ( mode != EOF)
  {
    mode = fgetc(fichier);
    printf("%c",mode);
  }

  fclose(fichier);

}
