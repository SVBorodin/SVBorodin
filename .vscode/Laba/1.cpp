#include <iostream>
#include <limits>
#include <cstring>
#include <cmath>

int main() {
    // Объявление переменных
    unsigned char h; // Высота трапеции, от 0 до 255
    unsigned short b1; // Первое основание, от 0 до 1000
    unsigned short b2; // Второе основание, от 0 до 1000
    unsigned int s; // Площадь трапеции

    // Ввод высоты
    std::cout << "Input height (|x| <= 255): " << std::endl;
    std::cin >> h;

    std::cout << "Input base 1 (|x| <= 1000):" << '\n';
    std::cin >> b1;
    std::cout << "Input base 2 (|x| <= 1000):" << '\n';
    std::cin >> b2;
    // Вычисление площади трапеции
    s = ((b1+b2)*h)/2;

    // Вывод информации о типах данных
    std::cout << "unsigned char " << sizeof(h) * 8 << " bit, min =" << 0 << ", max = " << static_cast<int>(std::numeric_limits<unsigned char>::max()) << '\n';
    std::cout << "unsigned short " << sizeof(b1) * 8 << " bit, min = " << 0 << ", max =  " << std::numeric_limits<unsigned short>::max() << '\n';
    std::cout << "unsigned int " << sizeof(s) * 8 << " bit, min = " << 0 << ", max =  " << std::numeric_limits<unsigned int>::max() << '\n';

    // Вывод площади
    std::cout << "S: " << s << " (unsigned int)" << '\n';

    return 0;
}