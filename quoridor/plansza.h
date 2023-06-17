#ifndef PLANSZA_H
#define PLANSZA_H

#include "pionek.h"

class Plansza {
public:
    Plansza();
    void wyswietl() const;
    void wyswietlWspolrzedne() const;
    bool postawScianke(int x, int y);
    
    char getSymbolGracza1() const;
    char getSymbolGracza2() const;
    void ustawPionek(int x, int y, int symbol); // Nowa metoda do aktualizacji planszy
private:
    char plansza[9][11];
    char symbolGracza1;
    char symbolGracza2;
};

#endif
