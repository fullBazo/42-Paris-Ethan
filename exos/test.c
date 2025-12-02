
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
	int nombre;
	Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
	Element *premier;
};

Liste *initialisation()
{
	Liste *liste = malloc(sizeof(*liste));
	Element *element = malloc(sizeof(*element));

	if (liste == NULL || element == NULL)
		exit(EXIT_FAILURE);
	
	element->nombre = 0;
	element->suivant = NULL;
	// Le champ premier de liste doit contenir l'adresse memoire du 1er element
	liste->premier = element;

	return liste;
}

void insertion(Liste *liste, int nvNombre)
{
	/* Creation d'un nouvel element */
	Element *nouveau = malloc(sizeof(*nouveau));
	if (!liste || !nouveau)
		exit(EXIT_FAILURE);
	
	nouveau->nombre = nvNombre;

	/* Insertion de l'element au debut de la liste */

	nouveau->suivant = liste->premier; // nouveau->suivant pointe mtn vers l'adresse de l'ancien premier bloc
	liste->premier = nouveau; // le premier bloc devient le nouveau Element
	
}