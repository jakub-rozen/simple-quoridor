
#include <stdio.h>

int main() {
    printf("x");
}
//
//
//int main() {
//
//    char A[5][5] = { {'a', 'f', 'k', 'p', 'v'},
//                     {'b', 'g', 'l', 'r', 'w'},
//                     {'c', 'h', 'm', 's', 'x'},
//                     {'d', 'i', 'n', 't', 'y'},
//                     {'e', 'j', 'o', 'u', 'z'} };
//
//    char *B[25] = {NULL};
//
//    for(int i=0; i<5; i++){
//        for(int j=0; j<5; j++){
//            printf("%c\t", A[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//
//
//    // wczytanie napisu od użytkownika do pomocniczej tablicy
//    char input[25];
//    printf("Podaj napis skladajacy sie z liter z tablicy A: ");
//    scanf("%s", input);
//
//
//    // przeszukiwanie tablicy A w poszukiwaniu każdej litery z napisu
//    int x = 0;
//    while (input[x] != '\0') { //  '\0' = NULL
//        char letter = input[x];
//        for (int i = 0; i < 5; i++) {
//            for (int j = 0; j < 5; j++) {
//                if (A[i][j] == letter) {
//                    B[x] = &A[i][j];
//                    break;
//                }
//            }
//            if (B[x] != NULL) {
//                break;
//            }
//        }
//        x++;
//    }
//
//    // wypisanie zaszyfrowanego napisu za pomocą tablicy B
//    printf("\nSzyfrowany napis: ");
//    for (int i = 0; i < x; i++) {
//            printf("%c", *B[i]);
//    }
//
//
//    // przestawienie wartości w wierszach tablicy A
//    char temp;
//    for(int i = 0; i < 5; i++) {
//        for(int j = i + 1; j < 5; j++) {
//            temp = A[i][j];
//            A[i][j] = A[j][i];
//            A[j][i] = temp;
//        }
//    }
//
//
//
//    // ponowne wypisanie zaszyfrowanego napisu za pomocą tablicy B
//    printf("\n\nSzyfrowany napis po przestawieniu wierszy: ");
//    for (int i = 0; i < x; i++) {
//            printf("%c", *B[i]);
//    }
//
//
//
//    // przywrócenie właściwego porządku wierszy w tablicy A
//    for(int i = 0; i < 5; i++) {
//        for(int j = i + 1; j < 5; j++) {
//            temp = A[i][j];
//            A[i][j] = A[j][i];
//            A[j][i] = temp;
//        }
//    }
//
//
//    // wypisanie odszyfrowanego napisu za pomocą tablicy B
//    printf("\n\nOdszyfrowany napis: ");
//    for (int i = 0; i < x; i++) {
//            printf("%c", *B[i]);
//    }
//
//
//    printf("\n\n");
//    return 0;
//}
