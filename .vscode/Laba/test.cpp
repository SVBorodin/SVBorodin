#include <iostream>
#include <string>
#include <bitset>

int main() {
    short a;
    int i;
    
    std::cout << "Input (a), [-2^15 - 2^15]" << std::endl;
    std::cin >> a;
    std::cout << a << " = " << std::bitset<8>(a) << std::endl;
// Строка для красоты и удобства счёта номера 
    std::cout << "     76543210" << '\n';
    std::cout << "Input (i), [0-7]" << std::endl;
    std::cin >> i;

    if (i > 7 || i < 0) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    // Извлекаем i-й бит
    bool bitValue = (a >> i) & 1;
    std::cout << "Bit " << i << " = " << bitValue << std::endl;

    // Обработка по значению бита
    if (bitValue == 1) {
        // Три сдвига вправо
        for (int shift = 1; shift <= 3; shift++) {
            a = a >> 1;
            std::cout << "Shift " << shift << ": " << a << " = " << std::bitset<8>(a) << std::endl;
        }
    } else {
        // Ввод M и сравнение с 5
        int M;
        std::cout << "Input M: ";
        std::cin >> M;
        
        int difference = M - 5;
        if (difference > 0) {
            std::cout << "M is greater than 5 by " << difference << std::endl;
        } else if (difference < 0) {
            std::cout << "M is less than 5 by " << -difference << std::endl;
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
        default: std::cout << "Error: invalid day number!" << std::endl; break;
    }

    return 0;
}