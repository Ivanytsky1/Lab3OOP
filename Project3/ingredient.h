#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>
using namespace std;

class Medicine {
private:
    string name;    // Назва ліків
    int quantity;   // Кількість
    double cost;    // Вартість за одиницю

public:
    // Конструктор класу
    Medicine(const string& name, int quantity, double cost);

    // Метод для обчислення вартості ліків за рецептом
    double calculateTotalCost() const;

    // Перевантаження операції +=
    Medicine& operator+=(int addedQuantity);

    // Перевантаження операції -=
    Medicine& operator-=(int removedQuantity);

    // Перевантаження операції +
    Medicine& operator+(double addedCost);

    // Перевантаження операції -
    Medicine& operator-(double removedCost);

    // Перевантаження оператора << для виводу в потік
    friend ostream& operator<<(ostream& os, const Medicine& medicine);

    // Метод для пошуку ліків за різними критеріями
    bool searchByName(const string& query) const;
};

#endif // MEDICINE_H
