//Tablice statyczne
#include <iostream>
using namespace std;

int fun1(int n) {
    if (n == 1) return 0;
    return fun1(n - 1) + 10;
}
#define ROZMIAR 10 //deklaracja stałej poprzez dyrektywę prepocesora - przed właściwą kompilacją
const int rozmiar = 10;
int sumaliczb1(int tab[4], int);
void zwieksz(int tab[], int);

int main()
{
    //tablice statyczne - zmienna, która potrafi przechowywać więcej niż 1 wartość
    //Rozmiar tablicy musi być znany na etapie kompilacji
    int a = 12;
    //int tablica3[a];//błąd!!!
    int tablica3[ROZMIAR];//takie coś jest prawidłowe
    int tablica4[rozmiar];//takie coś jest prawidłowe
    int tablica1[10];
    int tablica2[4] = { 1,2,3,4 };
    //tablice indeksowane są od 0
    //tablica1[10] -> błąd, bo ostatni element to tablica1[9]
    cout << tablica2[2] << endl;
    tablica2[2] = 10;//{1,2,10,4}
    cout << tablica2[2] << endl;
    cout << tablica2 << endl; //nazwa tablicy to adres jej zerowego elementu - to wskaźnik to zerowego elementu
    cout << *tablica2 << endl; //taki zapis oznacza odwołanie się do zawartości komórki pamieci pod wskazanym adresem
    //zawartość całej tablicy możemy zrealizować poprzez pętlę
    for (int i = 0; i < 4; i++) {
        cout << tablica2[i] << ",";
    }
    cout << endl;
    for (int i = 0; i < sizeof(tablica2)/sizeof(tablica2[0]); i++) {
        cout << tablica2[i] << ",";
    }
    cout << endl;

    //wywołanie funkcji z parametrem w postaci tablicy
    //cout << sumaliczb1(tablica2, 4) << endl;
    zwieksz(tablica2, 4);
    for (int i = 0; i < sizeof(tablica2) / sizeof(tablica2[0]); i++) {
        cout << tablica2[i] << ",";
    }
    cout << endl;
    return 0;
}
//Przekazywanie tablic jako parametrów do funkcji
int sumaliczb1(int tab[4], int r) {
    int suma = 0;
    //int rozmiar = sizeof(tab) / sizeof(tab[0]);
    for (int i = 0; i< r; i++) {
        suma += tab[i];
    }
    return suma;
}

int sumaliczb2(int tab[]) {
    return 0;
}

int sumaliczb3(int *tab) {
    return 0;
}
//tablice przekazywane do funkcji nigdy nie są kopiowane! Są przekazywane przez referencję/wskaźnik
void zwieksz(int tab[], int r) {
    for (int i = 0; i < r; i++) {
        tab[i] += 10;
    }
    for (int i = 0; i < r; i++) {
        cout << tab[i] << ",";
    }
    cout << endl;
}