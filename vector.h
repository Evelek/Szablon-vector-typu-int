#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct vector {
	int *tab;
} Vector;

//funkcja alokuje pamiec dla jednego elementu
void alokuj_vector(struct vector *wsk);

//funkcja alokuje pamiec dla nastepnego elementu i dodaje nowy element na koniec vectora
void dodaj_element(struct vector *wsk, const int wartosc);

//funkcja czysci pamiec ostatniego elementu vectora i usuwa ostatni element vectora
void usun_element(struct vector *wsk);

//wyswietla wszystkie elementy vectora
void wyswietl_vector(const struct vector *wsk);

//zwraca rozmiar vectora
size_t zwroc_rozmiar(const struct vector *wsk);

//sortuje vector
void sortuj_2(struct vector *wsk, int lewy, int prawy);
void sortuj(struct vector *wsk);

//funkcja czysci pamiec vectora, vector jest usuwany
void wyczysc_vector(struct vector *wsk);

#endif // !VECTOR_H_