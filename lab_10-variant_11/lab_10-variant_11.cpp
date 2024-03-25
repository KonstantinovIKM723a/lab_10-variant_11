#include <iostream>;
#include "windows.h";
#include <string>;
using namespace std;

struct product {
    string name;
    unsigned int code;
    unsigned int count;
    float price;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 4;
    product products[n];

    for (int i = 0; i < n; i++) {
        cout << "Введіть назву " << (i + 1) << "-го товару: ";
        //Використаємо функцію getline для підтримки рядків с пробілом і цикл, щоб виключити пусті рядки
        do {getline(cin, products[i].name);} while (products[i].name == "");
        cout << "Введіть код " << "товару \"" << products[i].name << "\": ";
        cin >> products[i].code;
        cout << "Введіть кількість " << "товару \"" << products[i].name << "\": ";
        cin >> products[i].count;
        cout << "Введіть ціну " << "товару \"" << products[i].name << "\": ";
        cin >> products[i].price;
        cout << endl;
    }

    //Виводимо весь асортимент товарів на екран
    cout << "Асортимент товарів:" << endl;
    for (int i = 0; i < n; i++) {
        cout << products[i].name << ": код: " << products[i].code << "; кількість: " << products[i].count << "; ціна: " << products[i].price << "." << endl;
    }

    //Відсортуємо товари за ціною і виведемо на екран
    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (products[j + 1].price < products[j].price) {
                product p = products[j + 1];
                products[j + 1] = products[j];
                products[j] = p;
            }
        }
    }

    cout << "Асортимент товарів, відсортований за ціною:" << endl;
    for (int i = 0; i < n; i++) {
        cout << products[i].name << ": код: " << products[i].code << "; кількість: " << products[i].count << "; ціна: " << products[i].price << "." << endl;
    }
}