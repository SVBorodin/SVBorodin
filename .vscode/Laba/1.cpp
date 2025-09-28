#include <iostream>
#include <limits>
#include <cstring>
#include <cmath>

int main() {
    short h;  // Char не подойдет, т.к нужно от -255 до 255 из за модуля
    short b1; 
    short b2; 
    int s;  //Используем int т.к 

    std::cout << "Input height (|x| <= 255):" << '\n';
    std::cin >> h;
    
    // Проверка по модулю
    if (std::abs(h) > 255) {
        std::cout << "Error: |height| must be <= 255  !" << '\n';
        return 1;
    }
    
    std::cout << "Input base 1 (|x| <= 1000):" << '\n';
    std::cin >> b1;
    if (std::abs(b1) > 1000) {
        std::cout << "Error: |base 1| must be <= 1000  !" << '\n';
        return 1;
    }
    
    std::cout << "Input base 2 (|x| <= 1000):" << '\n';
    std::cin >> b2;
    if (std::abs(b2) > 1000) {
        std::cout << "Error: |base 2| must be <= 1000  !" << '\n';
        return 1;
    }
    
    // Вычисление площади,  я использовал abs (т.е по модюлю) т.к по идее площадбь не должна быть отрицательной ( могу быть не прав)
    s = ((std::abs(b1) + std::abs(b2)) * std::abs(h)) / 2;
    
    // Результаты
    std::cout << "S=" << s << '\n';
    //                               Допустим для unsigned char             тут был бы 0                                    тут было бы 255
    //         Размер в байтах \/                Возвращает лимит по типу |  тут минимум \/                      Тут тоже но макс значение \/
    std::cout << "h-" << sizeof(h) * 8 << " bit, min = " << std::numeric_limits<short>::min() << ", max = " << std::numeric_limits<short>::max() << '\n';
    std::cout << "b1-" << sizeof(b1) * 8 << " bit, min = " << std::numeric_limits<short>::min() << ", max = " << std::numeric_limits<short>::max() << '\n';
    std::cout << "b2-" << sizeof(b2) * 8 << " bit, min = " << std::numeric_limits<short>::min() << ", max = " << std::numeric_limits<short>::max() << '\n';
    std::cout << "S-" << sizeof(s) * 8 << " bit, min = " << std::numeric_limits<int>::min() << ", max = " << std::numeric_limits<int>::max() << '\n';

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