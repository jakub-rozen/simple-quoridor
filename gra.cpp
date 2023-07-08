#include "gra.h"
#include <iostream>

Gra::Gra() : plansza(), pionekGracza(4, 0, &plansza), pionekPrzeciwnika(4, 8, &plansza) {}

void Gra::rozpocznijGre() {
    plansza.wyswietl();

    while (!sprawdzWygrana()) {
        // Ruch gracza 1
        int x1 = 0, y1;
        bool poprawnyRuch1 = false;

        while (!poprawnyRuch1) {
            std::cout << "Gracz 1 (" << plansza.getSymbolGracza1() << "): Podaj ruch (x y): ";
            std::cin >> x1 >> y1;

            // Sprawdzenie poprawności ruchu
            if (x1 >= 0 && x1 < 9 && y1 >= 0 && y1 < 9) {
                int ruchX = abs(x1 - pionekGracza.getX());
                int ruchY = abs(y1 - pionekGracza.getY());

                if ((ruchX == 1 && ruchY == 0) || (ruchX == 0 && ruchY == 1)) {
                    poprawnyRuch1 = true;
                } else {
                    std::cout << "Nieprawidłowy ruch. Spróbuj ponownie." << std::endl;
                }
            } else {
                std::cout << "Nieprawidłowe współrzędne. Spróbuj ponownie." << std::endl;
            }
        }

        pionekGracza.przesun(x1, y1);
        plansza.wyswietl();

        if (sprawdzWygrana()) {
            std::cout << "Gracz 1 wygrywa!" << std::endl;
            break;
        }

        // Ruch gracza 2
        int x2, y2;
        bool poprawnyRuch2 = false;

        while (!poprawnyRuch2) {
            std::cout << "Gracz 2 (" << plansza.getSymbolGracza2() << "): Podaj ruch (x y): ";
            std::cin >> x2 >> y2;

            // Sprawdzenie poprawności ruchu
            if (x2 >= 0 && x2 < 9 && y2 >= 0 && y2 < 9) {
                int ruchX = abs(x2 - pionekPrzeciwnika.getX());
                int ruchY = abs(y2 - pionekPrzeciwnika.getY());

                if ((ruchX == 1 && ruchY == 0) || (ruchX == 0 && ruchY == 1)) {
                    poprawnyRuch2 = true;
                } else {
                    std::cout << "Nieprawidłowy ruch. Spróbuj ponownie." << std::endl;
                }
            } else {
                std::cout << "Nieprawidłowe współrzędne. Spróbuj ponownie." << std::endl;
            }
        }

        pionekPrzeciwnika.przesun(x2, y2);
        plansza.wyswietl();
    }

    std::cout << "Koniec gry!" << std::endl;
}

bool Gra::sprawdzWygrana() const {
    if (pionekGracza.getY() == 8 && pionekPrzeciwnika.getY() == 0) {
        return true;
    }
    return false;
}
