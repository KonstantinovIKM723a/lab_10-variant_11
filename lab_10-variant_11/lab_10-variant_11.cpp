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
        cout << "¬вед≥ть назву " << (i + 1) << "-го товару: ";
        //¬икористаЇмо функц≥ю getline дл€ п≥дтримки р€дк≥в с проб≥лом ≥ цикл, щоб виключити пуст≥ р€дки
        do {getline(cin, products[i].name);} while (products[i].name == "");
        cout << "¬вед≥ть код " << "товару \"" << products[i].name << "\": ";
        cin >> products[i].code;
        cout << "¬вед≥ть к≥льк≥сть " << "товару \"" << products[i].name << "\": ";
        cin >> products[i].count;
        cout << "¬вед≥ть ц≥ну " << "товару \"" << products[i].name << "\": ";
        cin >> products[i].price;
        cout << endl;
    }

    //¬иводимо весь асортимент товар≥в на екран
    cout << "јсортимент товар≥в:" << endl;
    for (int i = 0; i < n; i++) {
        cout << products[i].name << ": код: " << products[i].code << "; к≥льк≥сть: " << products[i].count << "; ц≥на: " << products[i].price << "." << endl;
    }

    //¬≥дсортуЇмо товари за ц≥ною ≥ виведемо на екран
    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (products[j + 1].price < products[j].price) {
                product p = products[j + 1];
                products[j + 1] = products[j];
                products[j] = p;
            }
        }
    }

    cout << "јсортимент товар≥в, в≥дсортований за ц≥ною:" << endl;
    for (int i = 0; i < n; i++) {
        cout << products[i].name << ": код: " << products[i].code << "; к≥льк≥сть: " << products[i].count << "; ц≥на: " << products[i].price << "." << endl;
    }
}