#include "plansza.h"
#include <iostream>

Plansza::Plansza() : symbolGracza1('X'), symbolGracza2('O') {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            plansza[i][j] = 0;
        }
    }
    plansza[4][0] = 1;
    plansza[4][8] = 2;
}

void Plansza::wyswietl() const {
    wyswietlWspolrzedne();
    for (int i = 0; i < 9; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 9; j++) {
            if (plansza[i][j] == 1) {
                std::cout << symbolGracza1 << " ";
            } else if (plansza[i][j] == 2) {
                std::cout << symbolGracza2 << " ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

void Plansza::wyswietlWspolrzedne() const {
    std::cout << "  0 1 2 3 4 5 6 7 8" << std::endl;
}

char Plansza::getSymbolGracza1() const {
    return symbolGracza1;
}

char Plansza::getSymbolGracza2() const {
    return symbolGracza2;
}

void Plansza::ustawPionek(int x, int y, int symbol) {
    plansza[x][y] = symbol;
}


