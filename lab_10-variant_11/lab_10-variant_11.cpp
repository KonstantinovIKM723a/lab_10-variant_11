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
        cout << "������ ����� " << (i + 1) << "-�� ������: ";
        //����������� ������� getline ��� �������� ����� � ������� � ����, ��� ��������� ���� �����
        do {getline(cin, products[i].name);} while (products[i].name == "");
        cout << "������ ��� " << "������ \"" << products[i].name << "\": ";
        cin >> products[i].code;
        cout << "������ ������� " << "������ \"" << products[i].name << "\": ";
        cin >> products[i].count;
        cout << "������ ���� " << "������ \"" << products[i].name << "\": ";
        cin >> products[i].price;
        cout << endl;
    }

    //�������� ���� ���������� ������ �� �����
    cout << "���������� ������:" << endl;
    for (int i = 0; i < n; i++) {
        cout << products[i].name << ": ���: " << products[i].code << "; �������: " << products[i].count << "; ����: " << products[i].price << "." << endl;
    }

    //³�������� ������ �� ����� � �������� �� �����
    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (products[j + 1].price < products[j].price) {
                product p = products[j + 1];
                products[j + 1] = products[j];
                products[j] = p;
            }
        }
    }

    cout << "���������� ������, ������������ �� �����:" << endl;
    for (int i = 0; i < n; i++) {
        cout << products[i].name << ": ���: " << products[i].code << "; �������: " << products[i].count << "; ����: " << products[i].price << "." << endl;
    }
}