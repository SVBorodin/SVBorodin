#include <iostream>
#include <limits>
#include <cstring>
#include <cmath>
int main()
{
    unsigned char h ; //Вмещает от 0 до 255, что подходит по размеру и предотвращает использования отрицательных значений
    unsigned short b1 ; //
    unsigned short b2 ; //
    unsigned int s; //Вмещает явно более 255 тыс
    std::cout << "Input height (|x| <= 255):" << '\n';
    std::cin >> h;
    std::cout << "Input base 1 (|x| <= 1000):" << '\n';
    std::cin >> b1;
    std::cout << "Input base 2 (|x| <= 1000):" << '\n';
    std::cin >> b2;
    s = ((b1 + b2) * h) / 2;
    std::cout << s << '\n'; 
    std::cout << "h-" << sizeof(h) * 8 << " bit, min =" << 0 << ", max = " << static_cast<int>(std::numeric_limits<unsigned char>::max()) << '\n';
    std::cout << "b1-" << sizeof(b1) * 8 << " bit, min = " << 0 << ", max =  " << std::numeric_limits<unsigned short>::max() << '\n';
    std::cout << "b2-" << sizeof(b2) * 8 << " bit, min = " << 0 << ", max =  " << std::numeric_limits<unsigned short>::max() << '\n';
    std::cout << "S-" << sizeof(s) * 8 << " bit, min = " << 0 << ", max =  " << std::numeric_limits<unsigned int>::max() << '\n';
    
}
/* Лабораторная работа 1.

Типы данных и математические операции


Выбрать максимально подходящий тип данных (согласно заданию) и объяснить в комментариях.
Для каждого использованного типа данных вывести на экран название, размер в битах, минимальное и максимальное значение (значение необходимо посчитать формулой,
вывести можно в экспоненциальном формате). Результат вычислить в новую переменную и вывести на экран с указанием типа. 
Входные данные вводить с клавиатуры (корректно).

Вариант 2

Из целых введенных данных высоты ( |x| не более 255) и двух оснований (|x| не более 1000) вычислить площадь трапеции. */