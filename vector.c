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
	wsk->tab[wsk->rozmiar-1] = 0; //przypisanie ostatniemu elementowi liczby 0
	wsk->rozmiar--;
	int *tablica_tymczasowa = (int*)malloc(wsk->rozmiar * sizeof(int)); //utworzenie tymczasowej tablicy dynamicznej
	for (size_t i = 0; i < wsk->rozmiar; ++i)
		tablica_tymczasowa[i] = wsk->tab[i]; //skopiowanie wartosci z glownej tablicy do tymczasowej bez ostatniego elementu
	free(wsk->tab); //dealokacja pamieci glownej tablicy
	wsk->tab = (int*)malloc(wsk->rozmiar * sizeof(int)); //alokacja pamieci dla nowej pomniejszonej glownej tablicy 
	for (size_t i = 0; i < wsk->rozmiar; ++i)
		wsk->tab[i] = tablica_tymczasowa[i]; //skopiowanie wartosci z tablicy tymczasowej do glownej 
	free(tablica_tymczasowa); //dealokacja pamieci tablicy tymczasowej
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
