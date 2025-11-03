#include <iostream>
#include <limits>
#include <cstring>
#include <cmath>

int main() {
    short h;  // Char не подойдет, т.к нужно от -255 до 255 из за модуля
    short b1; 
    short b2; 
    float s;  

    std::cout << "Input height (|h| <= 255):" << '\n';
    std::cin >> h;
    

    
    std::cout << "Input base 1 (|x| <= 1000):" << '\n';
    std::cin >> b1;
    
    std::cout << "Input base 2 (|x| <= 1000):" << '\n';
    std::cin >> b2;

    
    // Вычисление площади,  я использовал abs (т.е по модюлю) т.к по идее площадбь не должна быть отрицательной ( могу быть не прав )
    s = ((std::abs(b1) + std::abs(b2)) * std::abs(h)) / 2.0;
    
    // Результаты
    std::cout << "S=" << s << '\n';
    //                               Допустим для unsigned char             тут был бы 0                                    тут было бы 255
    //         Размер в байтах \/                Возвращает лимит по типу |  тут минимум \/                      Тут тоже но макс значение \/
    std::cout << "h-" << sizeof(h) * 8 << " bit, min = " << std::numeric_limits<short>::min() << ", max = " << std::numeric_limits<short>::max() << '\n';
    std::cout << "b1-" << sizeof(b1) * 8 << " bit, min = " << std::numeric_limits<short>::min() << ", max = " << std::numeric_limits<short>::max() << '\n';
    std::cout << "b2-" << sizeof(b2) * 8 << " bit, min = " << std::numeric_limits<short>::min() << ", max = " << std::numeric_limits<short>::max() << '\n';
    std::cout << "S-" << sizeof(s) * 8 << " bit, min = " << std::numeric_limits<float>::lowest() << ", max = " << std::numeric_limits<float>::max() << '\n';

    return 0;
}
/* Лабораторная работа 1.

Типы данных и математические операции


Выбрать максимально подходящий тип данных (согласно заданию) и объяснить в комментариях.
Для каждого использованного типа данных вывести на экран название, размер в битах, минимальное и максимальное значение (значение необходимо посчитать формулой,
вывести можно в экспоненциальном формате). Результат вычислить в новую переменную и вывести на экран с указанием типа. 
Входные данные вводить с клавиатуры (корректно).

Вариант 2

Из целых введенных данных высоты ( |x| не более 255) и двух оснований (|x| не более 1000) вычислить площадь трапеции. */