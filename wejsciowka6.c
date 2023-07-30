#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pomiar {
    unsigned int nr_pomiaru;
    unsigned int nr_czujnika;
    char data_i_czas[20];
    double temp;
    struct pomiar* nast;
};

typedef struct pomiar Pomiar;

int main() {

    FILE* plik;
    if (fopen_s(&plik, "temp-na-zewn.txt", "r") != 0) {
        printf("Nie mozna otworzyc pliku.\n");
        return 1;
    }

    Pomiar* glowa1 = NULL;
    Pomiar* glowa2 = NULL;
    Pomiar* glowa3 = NULL;
    Pomiar* glowa4 = NULL;

    Pomiar* obecny;
    char buf[100];
    while (fgets(buf, sizeof(buf), plik)) {
        obecny = (Pomiar*)malloc(sizeof(Pomiar));
        sscanf_s(buf, "%u %u %s %lf", &obecny->nr_pomiaru, &obecny->nr_czujnika, obecny->data_i_czas, (unsigned)_countof(obecny->data_i_czas), &obecny->temp);

        switch (obecny->nr_czujnika) {
        case 1:
            obecny->nast = glowa1;
            glowa1 = obecny;
            break;
        case 2:
            obecny->nast = glowa2;
            glowa2 = obecny;
            break;
        case 3:
            obecny->nast = glowa3;
            glowa3 = obecny;
            break;
        case 4:
            obecny->nast = glowa4;
            glowa4 = obecny;
            break;
        default:
            free(obecny);
            printf("Niepoprawny numer czujnika.\n");
            break;
        }
    }

    fclose(plik);

    // zapis czterech list do plikow
    char nazwa_pliku[50];
    printf("Podaj poczatek nazwy plikow do zapisu: ");
    scanf_s("%s", nazwa_pliku, (unsigned)_countof(nazwa_pliku));

    Pomiar* p;
    FILE* fp;
    for (int i = 1; i <= 4; i++) {
        sprintf_s(nazwa_pliku + strlen(nazwa_pliku), 3, "%d.txt", i);
        if (fopen_s(&fp, nazwa_pliku, "w") != 0) {
            printf("Nie mozna otworzyc pliku %s.\n", nazwa_pliku);
            return 1;
        }
        switch (i) {
        case 1:
            p = glowa1;
            break;
        case 2:
            p = glowa2;
            break;
        case 3:
            p = glowa3;
            break;
        case 4:
            p = glowa4;
            break;
        }
        while (p) {
            fprintf(fp, "%u %u %s %lf\n", p->nr_pomiaru, p->nr_czujnika, p->data_i_czas, p->temp);
            p = p->nast;
        }
    }

    // zwolnienie pami?ci
    while (obecny = glowa1) {
        glowa1 = glowa1->nast;
        free(obecny);
    }
    while (obecny = glowa2) {
        glowa2 = glowa2->nast;
        free(obecny);
    }
    while (obecny = glowa3) {
        glowa3 = glowa3->nast;
        free(obecny);
    }
    while (obecny = glowa4) {
        glowa4 = glowa4->nast;
        free(obecny);
    }

    return 0;
}
