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

    // Wczytanie nazwy pliku od uzytkownika
    char filename[100];
    printf("Podaj nazwe pliku: ");
    scanf_s("%s", filename, 100);

    //Wczytanie wymiarow tablicy od uzytkownika
    int m, n;
    printf("\nPodaj wymiary tablicy (m n): \nm: ");
    scanf_s("%d", &m);
    getchar();
    printf("n: ");
    scanf_s("%d", &n);

    
    char** arr = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) {
        arr[i] = (char*)malloc(n * sizeof(char));
    }


    FILE* file;
    int lines_read = 0;
    if (fopen_s(&file, filename, "r") == 0) {
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
            for (int i = 0; i < m; i++) {
                free(arr[i]);
            }
            free(arr);
            return 1;
        }
    }
    else {
        printf("Nie udalo sie otworzyc pliku \n");
        // Zwalnianie pamieci i wyjscie z programu
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
            if (bin2int(arr[j]) < bin2int(arr[max_idx])) {
                max_idx = j;
            }
        }
        char* temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
    printf("\n");

    // Wypisanie posortowanych liczb calkowitych
    printf("Liczby calkowite (posortowane):\n");
    for (int i = 0; i < m; i++) {
        int temp = bin2int(arr[i]);
        printf("%d\n", temp);
    }

    // Zwalnianie pamieci
    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}






//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct student {
//    int ID;
//    char surname[40];
//    char name[40];
//    double score;
//};
//
//int countLines(FILE* fp) {
//    int count = 0;
//    char buffer[1024];
//    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
//        count++;
//    }
//    rewind(fp);
//    return count;
//}
//
//struct studentList {
//    struct student* list;
//    int size;
//};
//
//struct studentList readStudentsFromFile(char* filename) {
//    FILE* fp;
//    errno_t err = fopen_s(&fp, filename, "r");
//    if (err != 0) {
//        printf("Error opening file.\n");
//        exit(0);
//    }
//
//    int numStudents = countLines(fp);
//    struct studentList students;
//    students.list = (struct student*)malloc(numStudents * sizeof(struct student));
//    students.size = numStudents;
//
//    for (int i = 0; i < numStudents; i++) {
//        struct student s;
//        int numFields = fscanf_s(fp, "%d %s %s %lf", &s.ID, s.surname, 39, s.name, 39, &s.score);
//        if (numFields != 4) {
//            printf("Error reading file.\n");
//            exit(0);
//        }
//        students.list[i] = s;
//    }
//
//    fclose(fp);
//    return students;
//}
//
//void printStudents(struct studentList students) {
//    for (int i = 0; i < students.size; i++) {
//        struct student s = students.list[i];
//        printf("%d %s %s %.2lf\n", s.ID, s.surname, s.name, s.score);
//    }
//}
//
//struct studentList removeStudent(struct studentList students, int id) {
//    int indexToRemove = -1;
//    for (int i = 0; i < students.size; i++) {
//        if (students.list[i].ID == id) {
//            indexToRemove = i;
//            break;
//        }
//    }
//    if (indexToRemove == -1) {
//        printf("Student not found.\n");
//        return students;
//    }
//
//    struct studentList newStudents;
//    newStudents.list = (struct student*)malloc((students.size - 1) * sizeof(struct student));
//    newStudents.size = students.size - 1;
//
//    for (int i = 0, j = 0; i < students.size; i++) {
//        if (i != indexToRemove) {
//            newStudents.list[j++] = students.list[i];
//        }
//    }
//
//    free(students.list);
//    return newStudents;
//}
//
//int main() {
//    struct studentList students = readStudentsFromFile("students.txt");
//
//    printf("Students:\n");
//    printStudents(students);
//
//    int idToRemove;
//    printf("Enter ID of student to remove: ");
//    scanf_s("%d", &idToRemove);
//
//    students = removeStudent(students, idToRemove);
//
//    char outputFilename[256];
//    printf("Enter output filename: ");
//    scanf_s("%s", outputFilename, 255);
//
//    FILE* fp;
//    errno_t err = fopen_s(&fp, outputFilename, "w");
//    if (err != 0) {
//        printf("Error opening file.\n");
//        exit(0);
//    }
//
//    for (int i = 0; i < students.size; i++) {
//        struct student s = students.list[i];
//        fprintf_s(fp, "%d %s %s %.2lf\n", s.ID, s.surname, s.name, s.score);
//    }
//
//    fclose(fp);
//
//
//    return 0;
//}


//struct para {
//    char napis[50];
//    int liczba;
//};
//
//int wiersz(FILE* f, struct para *p) {
//    int nr;
//    char nazwisko[50];
//    int ocena;
//    if (fscanf_s(f, "%d %s %d", &nr, nazwisko, 50, &ocena) != 3) {
//        // nie udało się odczytać kolejnej porcji danych
//        return 1;
//    }
//    // ignorujemy numer i wpisujemy do tablicy nazwisko i ocenę
//    strcpy_s(p->napis, 50, nazwisko);
//    p->liczba = ocena;
//    return 0;
//}
//
//int main() {
//    char nazwa_wej[50];
//    char nazwa_wyj[50];
//    printf("Podaj nazwe pliku z danymi: ");
//    scanf_s("%s", nazwa_wej, 50);
//    printf("Podaj nazwe pliku wyjsciowego: ");
//    scanf_s("%s", nazwa_wyj, 50);
//
//    // otwieramy plik z danymi w trybie do odczytu
//    FILE* f_wej;
//    if (fopen_s(&f_wej, nazwa_wej, "r") != 0) {
//        printf("Nie udalo sie otworzyc pliku %s.\n", nazwa_wej);
//        return 1;
//    }
//
//    // otwieramy plik wynikowy w trybie do zapisu
//    FILE* f_wyj;
//    if (fopen_s(&f_wyj, nazwa_wyj, "w") != 0) {
//        printf("Nie udalo sie otworzyc pliku %s.\n", nazwa_wyj);
//        fclose(f_wej);
//        return 1;
//    }
//
//    // deklarujemy lokalną tablicę o długości 5
//    struct para tab[5];
//    int i = 0;
//    while (i < 5 && !feof(f_wej)) {
//        // odczytujemy kolejny wiersz z pliku
//        if (wiersz(f_wej, &tab[i]) == 0) {
//            // odczytano dane poprawnie, zapisujemy do pliku wynikowego
//            char zaszyfrowane[50];
//            strcpy_s(zaszyfrowane, 50, tab[i].napis);
//            for (int j = 0; j < strlen(zaszyfrowane); j++) {
//                if (zaszyfrowane[j] == 'a' || zaszyfrowane[j] == 'e' || zaszyfrowane[j] == 'i' || zaszyfrowane[j] == 'o' || zaszyfrowane[j] == 'u') {
//                    zaszyfrowane[j] = '*';
//                }
//            }
//            fprintf_s(f_wyj, "%s %d\n", zaszyfrowane, tab[i].liczba);
//            i++;
//        }
//    }
//
//    // zamykamy pliki
//    fclose(f_wej);
//    fclose(f_wyj);





// Funkcja konwertuj?ca C-napis zgodnie z wymaganiami zadania
//void convert(char str[]) {
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (isalpha(str[i])) {
//            str[i] = toupper(str[i]); // Zamiana litery na du??
//            if (str[i] == 'Z') { // Ostatnia litera alfabetu
//                str[i] = 'A';
//            }
//            else {
//                str[i]++;
//            }
//        }
//    }
//}
//
//
//int main() {
//    char word[100];
//    char fileInName[100];
//    printf("Podaj nazwe pliku wejsciowego: ");
//    scanf_s("%s", fileInName, 99);
//
//    // pobiera nazwe pliku wejsciowego
//    char fileOutName[100];
//    printf("Podaj nazwe pliku wyjsciowego: ");
//    scanf_s("%s", fileOutName, 99);
//
//    FILE* fileIn;
//    FILE* fileOut;
//
//    if (fopen_s(&fileIn, fileInName, "r") != 0) {
//        printf("Nie udalo sie otworzyc pliku.");
//        return 1;
//    }
//
//    if (fopen_s(&fileOut, fileOutName, "w") != 0) {
//        printf("Nie udalo sie otworzyc pliku.");
//        return 1;
//    }
//
//    // P?tla przetwarzaj?ca kolejne s?owa
//    while (fscanf_s(fileIn, "%99s", word, 100) != EOF) {
//        convert(word); // Konwersja s?owa
//        fprintf_s(fileOut, "%s\n", word); // Zapisanie wyniku do pliku wyj?ciowego
//    }
//
//    // Zamkni?cie plików
//    fclose(fileIn);
//    fclose(fileOut);
//
//    printf("Konwersja zako?czona pomy?lnie.\n");
//
//    return 0;
//    return 0;
//





// Funkcja sprawdza czy 3 liczby spelniaja wlasnosci trojkata

//struct Triangles {
//    char canBuild;
//    int smallestTriangleIndex;
//    int area;
//};
//
//struct Triangles checkTriangles(int arr[][3], int n) {
//
//    char canBuild = 'n';
//    double area = -1;
//    int smallestTriangleIndex = -1;
//
//    for (int i = 0; i < n; i++) {
//        int a = arr[i][0];
//        int b = arr[i][1];
//        int c = arr[i][2];
//
//        if (a + b > c && a + c > b && b + c > a) {
//            double p = (a + b + c) / 2;
//            double temp_area = sqrt(p * (p - a) * (p - b) * (p - c));
//
//            if (canBuild == 'n' || temp_area < area) {
//                canBuild = 't';
//                area = temp_area;
//                smallestTriangleIndex = i;
//
//
//            }
//        }
//    }
//
//    struct Triangles result = { canBuild, smallestTriangleIndex, area };
//
//    return result;
//}
//int main() {
//    int n = 3; // zmień na dowolną liczbę trójek
//    double arr[n][3] = {
//        {3, 4, 5},
//        {2, 2, 5},
//        {1, 2, 3}
//    };
//
//    struct TriangleInfo info = checkTriangles(arr, n);
//
//    if (info.canBuild == 't') {
//        printf("Triangle %d: sides %f, %f, %f, area %f\n", info.smallestTriangleIndex, arr[info.smallestTriangleIndex][0], arr[info.smallestTriangleIndex][1], arr[info.smallestTriangleIndex][2], info.area);
//    } else {
//        printf("No valid triangles.\n");
//    }
//
//    return 0;
//}





//
//    FILE* inFile, * outFile;
//    char id[10], lastName[50], firstName[50];
//    int points;
//
//    if (fopen_s(&inFile, "input.txt", "r") != 0) {
//        printf("Failed to open input file.\n");
//        return 1;
//    }
//
//    if (fopen_s(&outFile, "output.txt", "w") != 0) {
//        printf("Failed to create output file.\n");
//        return 1;
//    }
//
//    while (fscanf_s(inFile, "%s %s %s %d", id, sizeof(id), lastName, sizeof(lastName), firstName, sizeof(firstName), &points) == 4) {
//        for (int i = 0; lastName[i] != '\0'; i++) {
//            if (isalpha(lastName[i]) && (lastName[i] == 'a' || lastName[i] == 'e' || lastName[i] == 'i' || lastName[i] == 'o' || lastName[i] == 'u' ||
//                lastName[i] == 'A' || lastName[i] == 'E' || lastName[i] == 'I' || lastName[i] == 'O' || lastName[i] == 'U')) {
//                lastName[i] = '*';
//            }
//        }
//
//        for (int i = 0; firstName[i] != '\0'; i++) {
//            if (isalpha(firstName[i]) && (firstName[i] == 'a' || firstName[i] == 'e' || firstName[i] == 'i' || firstName[i] == 'o' || firstName[i] == 'u' ||
//                firstName[i] == 'A' || firstName[i] == 'E' || firstName[i] == 'I' || firstName[i] == 'O' || firstName[i] == 'U')) {
//                firstName[i] = '*';
//            }
//        }
//
//        fprintf_s(outFile, "%s %s %s %d\n", id, lastName, firstName, points);
//    }
//
//    fclose(inFile);
//    fclose(outFile);
//
//    return 0;
//}






//#include <stdio.h>
//#include <string.h>
//
//struct Data {
//    char text[100];
//    int number;
//};
//
//int shorten_strings(struct Data tab[], int length){
//    int count=0;
//
//    for(int i=0; i<length; i++){
//
//        int string_length = 0;
//        while(tab[i].text[string_length] != '\0'){
//            string_length++;
//        }
//
//        if(tab[i].number<string_length){
//            tab[i].text[tab[i].number] = '\0';
//            count++;
//        }
//    }
//    return count;
//}
//
//int main() {
//    struct Data tab[5];
//    printf("Podaj 5 slow oraz liczb:\n");
//    for (int i = 0; i < 5; i++) {
//        printf("Slowo %d : ", i+1);
//        scanf_s("%s", tab[i].text, 99);
//        printf("Liczba %d : ", i+1);
//        scanf_s("%d", &tab[i].number);
//    }
//
//    int count = shorten_strings(tab, 5);
//    printf("\nWynik:\n");
//    for (int i = 0; i < 5; i++) {
//        printf("%.2d %.8s\n", tab[i].number, tab[i].text);
//    }
//    printf("Liczba skrocen: %d\n", count);
//    return 0;
//}

// Funkcja sortujaca rosnaco kolumny dwywumiarowej tablicy

//void sort_columns(int arr[][MAX], int row, int col) {
//
//    for(int column=0; column<col; column++) {
//        for(int i=0; i<row-1; i++) {
//            for(int j=i+1; j<row; j++) {
//                if (arr[i][column] > arr[j][column]) {
//                    int temp = arr[i][column];
//                    arr[i][column] = arr[j][column];
//                    arr[j][column] = temp;
//                }
//            }
//        }
//    }
//}
