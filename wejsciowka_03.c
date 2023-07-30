#include <stdio.h>
#include <string.h>

struct Data {
    char text[100];
    int number;
};

int shorten_words(struct Data tab[], int length){
    int count=0;
    
    for(int i=0; i<length; i++){
        
        int string_length = 0;
        while(tab[i].text[string_length] != '\0'){
            string_length++;
        }
        
        if(tab[i].number<string_length){
            tab[i].text[tab[i].number] = '\0';
            count++;
        }
    }
    return count;
}

int main() {
    struct Data tab[5];
    printf("Podaj 5 slow oraz liczbe:\n");
    for (int i = 0; i < 5; i++) {
        printf("Slowo %d : ", i+1);
        scanf_s("%s", tab[i].text, 99);
        printf("Liczba %d : ", i+1);
        scanf_s("%d", &tab[i].number);
    }
    
    int count = shorten_words(tab, 5);
    printf("\nWynik:\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2d %.8s\n", tab[i].number, tab[i].text);
    }
    printf("Liczba skrocen: %d\n", count);
    return 0;
}


#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struktura przechowująca wynik funkcji
struct Result {
    int value;           // Obliczona wartość liczby w systemie dziesiętnym
    char decimal[MAX_SIZE]; // Liczba w systemie dziesiętnym zapisana jako napis
};

// Funkcja sprawdza, czy tablica zawiera tylko cyfry w systemie ósemkowym
int isOctal(char *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (!isdigit(arr[i]) || arr[i] < '0' || arr[i] > '7') {
            return 0;
        }
    }
    return 1;
}

// Funkcja zamienia napis z cyframi w systemie ósemkowym na liczbę w systemie dziesiętnym
int octalToDecimal(char *arr, int n) {
    int decimal = 0;
    for (int i = 0; i < n; i++) {
        decimal += (arr[i] - '0') * pow(8, n-i-1);
    }
    return decimal;
}

// Funkcja oblicza wartość liczby w systemie dziesiętnym i zwraca wynik w strukturze Result
struct Result octalToDecimalResult(char *arr, int n) {
    struct Result result;
    if (!isOctal(arr, n)) {  // Sprawdzenie, czy tablica zawiera tylko cyfry w systemie ósemkowym
        result.value = -1;
        strcpy(result.decimal, "Nieprawidlowy napis"); // Informacja o błędzie
    } else {
        result.value = octalToDecimal(arr, n); // Obliczenie wartości liczby w systemie dziesiętnym
        _itoa(result.value, result.decimal, 10); // Konwersja liczby na napis w systemie dziesiętnym
    }
    return result;
}

int main() {
    char arr[MAX_SIZE];
    int n;
    printf("Podaj liczbe w systemie osemkowym: ");
    scanf("%s", arr); // Wczytanie napisu reprezentującego liczbę
    n = strlen(arr);
   










