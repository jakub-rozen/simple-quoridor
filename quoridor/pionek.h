#ifndef PIONEK_H
#define PIONEK_H

class Plansza; // Deklaracja wsteczna klasy Plansza

class Pionek {
public:
    Pionek(int x, int y, Plansza* plansza); // Dodajemy wskaźnik do planszy
    int getX() const;
    int getY() const;
    void przesun(int x, int y);
private:
    int pozycjaX;
    int pozycjaY;
    Plansza* plansza; // Wskaźnik do planszy
};

#endif
