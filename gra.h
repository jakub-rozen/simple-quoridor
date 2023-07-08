#ifndef GRA_H
#define GRA_H

#include "plansza.h"

class Gra {
public:
    Gra();
    void rozpocznijGre();
    // Dodaj inne metody, jeśli są potrzebne
private:
    Plansza plansza;
    Pionek pionekGracza;
    Pionek pionekPrzeciwnika;
    bool sprawdzWygrana() const;
};

#endif
