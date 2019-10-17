/* $cat faux.c */

void main(void)
{
	int *p; /* Réservation de place pour le pointeur uniquement */
	*p = 120; /* Pas de réservation de place pour l'entier */
}
