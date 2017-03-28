# Szablon-vector-typu-int
Moja własna interpretacja szablonu vector z języka C++ napisana w języku C. Na chwilę obecną obsługuje on tylko typ int.
Operacje możliwe do wykonania na szablonie vector:
-dodanie nowego elementu na koniec vectora
-usunięcie ostatniego elementu vectora
-wyświetla wszystkie elementy vectora
-zwraca rozmiar vectora
-sortuje vector
-usuwa vector

Przykład użycia:
(Obowiązkową metodą jest punkt nr 2, w którym alokujemy pamięć dla vectora oraz punkt nr 8 w którym czyścimy pamięć vectora, która została przydzielona dynamicznie).

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
