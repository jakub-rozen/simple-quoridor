#include "pionek.h"
#include "plansza.h"

Pionek::Pionek(int x, int y, Plansza* plansza) : pozycjaX(x), pozycjaY(y), plansza(plansza) {}

int Pionek::getX() const {
    return pozycjaX;
}

int Pionek::getY() const {
    return pozycjaY;
}

void Pionek::przesun(int x, int y) {
    plansza->ustawPionek(pozycjaX, pozycjaY, 0);  // Usunięcie starej pozycji pionka z planszy
    pozycjaX = x;
    pozycjaY = y;
    plansza->ustawPionek(pozycjaX, pozycjaY, 1);  // Ustawienie pionka na nowej pozycji na planszy
}
