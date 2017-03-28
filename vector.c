#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

static int vector_rozmiar = 1;

void alokuj_vector(struct vector *wsk) {
	wsk->tab = malloc(sizeof(int));
	vector_rozmiar++;
}

void dodaj_element(struct vector *wsk, const int wartosc) {
	wsk->tab = realloc(wsk->tab, vector_rozmiar * sizeof(int));
	vector_rozmiar++;

	wsk->tab[vector_rozmiar - 3] = wartosc;
}

void usun_element(struct vector *wsk) {
	wsk->tab[vector_rozmiar - 3] = 0;
	free(wsk->tab[vector_rozmiar - 3]);
	vector_rozmiar--;
}

void wyswietl_vector(const struct vector *wsk) {
	for (int i = 0; i < vector_rozmiar - 2; ++i)
		printf("%d ", wsk->tab[i]);
}

size_t zwroc_rozmiar(const struct vector *wsk) {
	return vector_rozmiar - 2;
}

void sortuj_2(struct vector *wsk, int lewy, int prawy) {
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
		sortuj_2(wsk, lewy, j);
	if (i < prawy)
		sortuj_2(wsk, i, prawy);
}
void sortuj(struct vector *wsk) {
	int lewy = 0;
	int prawy = vector_rozmiar - 3;
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
		sortuj_2(wsk, lewy, j);
	if (i < prawy)
		sortuj_2(wsk, i, prawy);
}

void wyczysc_vector(struct vector *wsk) {
	free(wsk->tab);
}
