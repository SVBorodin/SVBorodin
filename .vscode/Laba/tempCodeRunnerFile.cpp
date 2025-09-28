#include <iostream>
#include <limits>
#include <cstring>
#include <cmath>

int main() {
    // Объявление переменных
    unsigned char height; // Высота трапеции, от 0 до 255
    unsigned short base1; // Первое основание, от 0 до 1000
    unsigned short base2; // Второе основание, от 0 до 1000
    unsigned int area; // Площадь трапеции

    // Ввод высоты
    std::cout << "Input height (|x| <= 255): " << '\n';
    std::cin >> height;

    // Ввод первого основания
    std::cout << "Input base 1 (|x| <= 1000):" << '\n';
    std::cin >> base1;

    // Ввод второго основания
    std::cout << "Input base 2 (|x| <= 1000):" << '\n';
    std::cin >> base2;

    // Вычисление площади трапеции
    area = (base1 + base2) * height / 2;

    // Вывод информации о типах данных
    std::cout << "unsigned char " << sizeof(height) * 8 << " bit, min =" << 0 << ", max = " << static_cast<int>(std::numeric_limits<unsigned char>::max()) << '\n';
    std::cout << "unsigned short " << sizeof(base1) * 8 << " bit, min = " << 0 << ", max =  " << std::numeric_limits<unsigned short>::max() << '\n';
    std::cout << "unsigned int " << sizeof(area) * 8 << " bit, min = " << 0 << ", max =  " << std::numeric_limits<unsigned int>::max() << '\n';

    // Вывод площади
    std::cout << "S: " << area << " (unsigned int)" << '\n';

    return 0;
}