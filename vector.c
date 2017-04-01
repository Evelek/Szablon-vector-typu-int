#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void alokuj_vector(struct vector *wsk) {
	wsk->tab = malloc(sizeof(int));
	wsk->rozmiar = 0;
}

void dodaj_element(struct vector *wsk, const int wartosc) {
	wsk->tab = realloc(wsk->tab, (wsk->rozmiar + 1) * sizeof(int));
	wsk->tab[wsk->rozmiar] = wartosc;
	wsk->rozmiar++;
}

void usun_element(struct vector *wsk) {
	wsk->tab[wsk->rozmiar-1] = 0;
	free(wsk->tab[(wsk->rozmiar)-1]);
	wsk->rozmiar--;
}

void wyswietl_vector(const struct vector *wsk) {
	for (size_t i = 0; i < wsk->rozmiar; ++i)
		printf("%d ", wsk->tab[i]);
}

size_t zwroc_rozmiar(const struct vector *wsk) {
	return wsk->rozmiar;
}

void wyczysc_vector(struct vector *wsk) {
	free(wsk->tab);
	wsk->rozmiar = 0;
}

void sortuj(struct vector *wsk) {
	sortuj_algorytm(wsk, 0, wsk->rozmiar-1);
}

void sortuj_algorytm(struct vector *wsk, int lewy, int prawy) {
	if (prawy <= lewy) return;
	int i = lewy - 1, j = prawy + 1,
		pivot = wsk->tab[(lewy + prawy) / 2];
	while (1)
	{
		while (pivot>wsk->tab[++i]);
		while (pivot<wsk->tab[--j]);
		if (i <= j) {
			int temp = wsk->tab[i];
			wsk->tab[i] = wsk->tab[j];
			wsk->tab[j] = temp;
		}
		else
			break;
	}
	if (j > lewy)
		sortuj_algorytm(wsk, lewy, j);
	if (i < prawy)
		sortuj_algorytm(wsk, i, prawy);
}
