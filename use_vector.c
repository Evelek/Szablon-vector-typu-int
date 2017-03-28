#include <stdio.h>
#include "vector.h"

int main(void)
{
	Vector tablica;
	alokuj_vector(&tablica);

	dodaj_element(&tablica, 2);
	dodaj_element(&tablica, 1);
	dodaj_element(&tablica, 4);
	dodaj_element(&tablica, 5);
	dodaj_element(&tablica, 7);
	dodaj_element(&tablica, 6);
	dodaj_element(&tablica, 10);
	dodaj_element(&tablica, 8);
	dodaj_element(&tablica, 9);
	dodaj_element(&tablica, 11);
	dodaj_element(&tablica, -2);

	printf("Rozmiar vectora wynosi: %u\n", zwroc_rozmiar(&tablica));

	wyswietl_vector(&tablica);
	putchar('\n');

	sortuj(&tablica);

	wyswietl_vector(&tablica);
	putchar('\n');

	usun_element(&tablica);

	wyswietl_vector(&tablica);
	putchar('\n');

	printf("Rozmiar vectora wynosi: %u\n", zwroc_rozmiar(&tablica));

	wyczysc_vector(&tablica);

	return 0;
}
