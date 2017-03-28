# Szablon-vector-typu-int
Moja własna interpretacja szablonu vector z języka C++ napisana w języku C. Na chwilę obecną obsługuje on tylko typ int.
Operacje możliwe do wykonania na szablonie vector:
1) dodanie nowego elementu na koniec vectora
2) usunięcie ostatniego elementu vectora
3) wyświetlenie wszystkich elementów vectora
4) zwrócenie rozmiaru vectora
5) posortowanie vectora
6) usunięcie vectora


Obowiązkową metodą jest punkt nr 2, w którym alokujemy pamięć dla vectora oraz punkt nr 8 w którym czyścimy pamięć vectora, która została przydzielona dynamicznie).
Przykład użycia:

1. Utworzenie nowej zmiennej typu Vector:

Vector tablica;

2. Alokujemy pamięć dla vectora:

alokuj_vector(&tablica);

3. Dodawanie elementu do vectora (w nawiasie podajemy liczbę typu int):

dodaj_element(&tablica, 2);

4. Wyświetlenie vectora:

wyswietl_vector(&tablica);

5. Sortowanie vectora:

sortuj(&tablica);

6. Usunięcie ostatniego elementu vectora:

usun_element(&tablica);

7. Zwrócenie rozmiaru vectora:

printf("Rozmiar vectora: %u", zwroc_rozmiar(&tablica));

8. Usuniecie vectora:

wyczysc_vector(&tablica);
