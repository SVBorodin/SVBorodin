#include <iostream>
#include <string>
#include <bitset>

int main() {
    short a;
    int i;
    int shift;
    shift = 1;
    std::cout << shift;
    std::cout << "Input (a), [-2^15 - 2^15]" << std::endl;
    std::cin >> a;
    std::cout << a << " = " << std::bitset<8>(a) << std::endl;
// Строка для красоты и удобства счёта номера 
    std::cout << "     76543210" << '\n';
    std::cout << "Input (i), [0-7]" << std::endl;
    std::cin >> i;
//         \/ Типо должно работать оба условия
    if (i > 7 || i < 0) {
        std::cout << "Error" << std::endl;
        return 1;
    }

   // Извлекает i-тый бит <- (ну сдвигает на i, делая его 0 номером( последним) и выводит его)
    bool bitValue = (a >> i) & 1;
    std::cout << "Bit " << i << " = " << bitValue << std::endl;

    // Обработка по значению бита
    if (bitValue == 1) {
        //  Задана переменная, пока не станет <= 3 то не перестанет, добавляться +1 следовательно перемесчаться на 1
        for (int shift = 1; shift <= 3; shift++) {
             // сдвиг вправо на 1 цифру
            a = a >> 1;
            //                  вывод номера сдвига, значение "a" в 10-чной системе и вывод "a" в 2-ичной системе
            std::cout << "Shift " << shift << ": " << a << " = " << std::bitset<8>(a) << std::endl;
        }
    } else {
        // Ввод M и сравнение с 5
        int M;
        std::cout << "Input M: ";
        std::cin >> M;
        
        int diff = M - 5;
        if (diff > 0) {
            std::cout << "M is greater than 5 by " << diff << std::endl;
        } else if (diff < 0) {
            std::cout << "M is less than 5 by " << -diff << std::endl;
        } else {
            std::cout << "M equals 5" << std::endl;
        }
    }

    // Дни недели
    int N;
    std::cout << "Input day of week number (1-7): ";
    std::cin >> N;

    switch (N) {
        case 1: std::cout << "Monday" << std::endl; break;
        case 2: std::cout << "Tuesday" << std::endl; break;
        case 3: std::cout << "Wednesday" << std::endl; break;
        case 4: std::cout << "Thursday" << std::endl; break;
        case 5: std::cout << "Friday" << std::endl; break;
        case 6: std::cout << "Saturday" << std::endl; break;
        case 7: std::cout << "Sunday" << std::endl; break;
        default: std::cout << "Error (0-7)" << std::endl; break;
    }

    return 0;
}