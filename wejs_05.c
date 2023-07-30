#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funkcja konwertujaca binarna liczbe zapisana jako string na int
int bin2int(char* bin) {
    size_t len = strlen(bin);
    int decimal_num = 0, base = 1;

    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '0' || bin[i] == '1') {
            if (bin[i] == '1') {
                decimal_num += base;
            }
            base *= 2;
        }
        else {
            return -1; // w przypadku nie poprawnego znaku
        }
    }


    return decimal_num;
}

int main() {
    // Wczytanie wymiarow tablicy od uzytkownika
    int m, n;
    printf("Podaj wymiary tablicy (m n): \nm: ");
    scanf_s("%d", &m);
    getchar();
    printf("n: ");
    scanf_s("%d", &n);

    // Alokacja pamieci dla tablicy
    char** arr = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) {
        arr[i] = (char*)malloc(n * sizeof(char));
    }


    // Wczytanie danych z pliku
    FILE* file;
    int lines_read = 0;
    if (fopen_s(&file, "liczby.txt", "r") == 0) {
        int i = 0;
        while (fscanf_s(file, "%s", arr[i], n) != EOF) {
            lines_read++;
            i++;
            if (i == m) {
                break;
            }
        }
        fclose(file);
        if (lines_read == 0) {
            printf("Plik jest pusty.\n");
            // Zwalnianie pamięci i wyjście z programu
            for (int i = 0; i < m; i++) {
                free(arr[i]);
            }
            free(arr);
            return 1;
        }
    }
    else {
        printf("Nie udalo sie otworzyc pliku \n");
        // Zwalnianie pamięci i wyjście z programu
        for (int i = 0; i < m; i++) {
            free(arr[i]);
        }
        free(arr);
        return 1;
    }

    // Wypisanie wczytanych danych
    printf("Wczytane dane:\n");
    for (int i = 0; i < m; i++) {
        printf("%.*s\n", n, arr[i]);
    }
    printf("\n");

    // Konwersja ciagow binarnych na liczby calkowite i wypisanie wynikow
    printf("Liczby calkowite:\n");
    for (int i = 0; i < m; i++) {
        int val = bin2int(arr[i]);
        printf("%d\n", val);
    }

    // Sortowanie ciagow binarnych w porzadku malejacym
    for (int i = 0; i < m - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < m; j++) {
            if (bin2int(arr[j]) > bin2int(arr[max_idx])) {
                max_idx = j;
            }
        }
        char* temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
    printf("\n");

    // Wypisanie posortowanych liczb ca?kowitych
    printf("Liczby calkowite (posortowane):\n");
    for (int i = 0; i < m; i++) {
        int val = bin2int(arr[i]);
        printf("%d\n", val);
    }

    // Zwalnianie pamieci
    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}


    
    // Wczytanie nazwy pliku od użytkownika
    //char filename[100];
    //printf("Podaj nazwe pliku: ");
    //scanf_s("%s", filename, 100);
