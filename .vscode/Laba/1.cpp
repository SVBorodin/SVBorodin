#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    short h, a, b;
    
    // Ввод данных с проверкой корректности
    cout << "Введите высоту трапеции (|h| <= 255): ";
    cin >> h;
    while (abs(h) > 255) {
        cout << "Ошибка! Введите высоту снова (|h| <= 255): ";
        cin >> h;
    }

    cout << "Введите первое основание (|a| <= 1000): ";
    cin >> a;
    while (abs(a) > 1000) {
        cout << "Ошибка! Введите первое основание снова (|a| <= 1000): ";
        cin >> a;
    }

    cout << "Введите второе основание (|b| <= 1000): ";
    cin >> b;
    while (abs(b) > 1000) {
        cout << "Ошибка! Введите второе основание снова (|b| <= 1000): ";
        cin >> b;
    }

    // Вычисление площади трапеции
    int area = (a + b) * h / 2;

    // Вывод информации о типе short
    short short_min = -pow(2, 15); // -32768
    short short_max = pow(2, 15) - 1; // 32767
    cout << "short, занимает 16 бит(а), мин. значение = " << short_min 
         << ", макс. значение = " << short_max << endl;

    // Вывод информации о типе int
    long long int_min = -pow(2, 31); // -2147483648
    long long int_max = pow(2, 31) - 1; // 2147483647
    cout << "int, занимает 32 бит(а), мин. значение = " << scientific << int_min 
         << ", макс. значение = " << int_max << endl;

    // Вывод результата
    cout << "Площадь трапеции: " << area << " (тип: int)" << endl;

    return 0;
}