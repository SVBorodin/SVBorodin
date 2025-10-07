#include <iostream>
#include <bitset>
#include <string>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Пункт 1
    short A ;
    int i;
    cout << "Input, A (short): ";
    cin >> A;
    cout << "Input № of a byte, i (0-7): ";
    cin >> i;

    // Проверка корректности i
    if (i < 0 || i > 7) {
        cout << "Error i(0-7)" << endl;
        return 1;
    }

    // Вывод A в 8-битном формате
    cout << A << " = " << bitset<8>(A) << endl;

    // Получение i-го бита
    int bit = (A >> i) & 1;
    cout << "Byte " << i << " = " << bit << endl;

    if (bit == 1) {
        // Три последовательных сдвига вправо
        cout << "Shifts to the right:" << endl;
        for (int shift = 1; shift <= 3; shift++) {
            short shifted = A >> shift;
            cout << "A >> " << shift << ": " << shifted 
                 << " = " << bitset<8>(shifted) << endl;
        }
    } else {
        int M;
        cout << "Input M: ";
        cin >> M;
        
        if (M > 5) {
            cout << "M greater than 5 by " << (M - 5) << endl;
        } else if (M < 5) {
            cout << "M fewer than 5 by " << (5 - M) << endl;
        } else {
            cout << "M is equal to 5" << endl;
        }
    }

    // Пункт 2
    int N;
    cout << "\n" << "Input number of the day of the week (1-7): ";
    cin >> N;

    switch (N) {
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday" << endl; break;
        case 5: cout << "Friday" << endl; break;
        case 6: 
        case 7: 
            cout << (N == 6 ? "Saturday" : "Sunday") << endl;
            break;
        default: 
            cout << "Error 1-7" << endl;
    }

    return 0;
}