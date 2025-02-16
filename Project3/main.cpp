#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Medicine {
private:
    string name;
    int quantity;
    double cost;

public:
    // Конструктор класу
    Medicine(const string& name, int quantity, double cost)
    {
        this->name = name;
        this->quantity = quantity;
        this->cost = cost;
    }

    // Метод для обчислення вартості ліків за рецептом
    double calculateTotalCost() const {
        return quantity * cost;
    }

    // Перевантаження операції +=
    Medicine& operator+=(int addedQuantity) {
        if (addedQuantity >= 0) {
            quantity += addedQuantity;
        }
        return *this;
    }

    // Перевантаження операції -=
    Medicine& operator-=(int removedQuantity) {
        if (removedQuantity >= 0 && removedQuantity <= quantity) {
            quantity -= removedQuantity;
        }
        return *this;
    }

    // Перевантаження операції +
    Medicine& operator+(double addedCost) {
        if (addedCost >= 0) {
            cost += addedCost;
        }
        return *this;
    }

    // Перевантаження операції -
    Medicine& operator-(double removedCost) {
        if (removedCost >= 0 && removedCost <= cost) {
            cost -= removedCost;
        }
        return *this;
    }

    // Перевантаження операції *
    Medicine operator*(double multiplier) const {
        return Medicine(name, quantity, cost * multiplier);
    }

    // Перевантаження методу виводу в потік
    friend ostream& operator<<(ostream& os, const Medicine& medicine) {
        cout << "Назва: " << medicine.name << "\n";
        cout << "Кількість: " << medicine.quantity << "\n";
        cout << "Вартість за одиницю: " << medicine.cost << "\n";
        cout << "Загальна вартість: " << medicine.calculateTotalCost() << "\n";
        return os;
    }

    // Метод для пошуку ліків за різними критеріями (приклад)
    bool searchByName(const string& query) const {
        return name.find(query) != string::npos;
    }
};

int main() {
    try {
        Medicine medicine("Аспірин", 100, 0.5);

        cout << "Початкові дані про ліки:\n";
        cout << medicine;

        medicine += 50;
        cout << "Після додавання кількості:\n";
        cout << medicine;

        medicine -= 30;
        cout << "Після видалення кількості:\n";
        cout << medicine;

        medicine + 0.2;
        cout << "Після збільшення вартості:\n";
        cout << medicine;

        medicine - 0.1;
        cout << "Після зменшення вартості:\n";
        cout << medicine;

        // Використання перевантаженого оператора *
        Medicine newMedicine = medicine * 2;
        cout << "Після множення вартості на 2:\n";
        cout << newMedicine;

        bool found = medicine.searchByName("Аспірин");
        if (found) {
            cout << "Ліки знайдено за назвою 'Аспірин'.\n";
        } else {
            cout << "Ліки не знайдено за назвою 'Аспірин'.\n";
        }
    } catch (const invalid_argument& e) {
        cout << "Помилка: " << e.what() << "\n";
    }

    return 0;
}
