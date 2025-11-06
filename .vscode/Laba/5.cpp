#include <iostream>
#include <cmath>
#include <limits>

int sumDigits(int n) {
    int sum = 0;
    n = std::abs(n);
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Перегрузка функций номер 1
int processNumbers(int a, int b) {
    std::cout << "Function of digit sum of 2 numbers (2 non zero)" << std::endl;
    
    return sumDigits(a) + sumDigits(b);
}

// номер 2
int processNumbers(int a, int b, int c) {
    std::cout << "Function of searching maximum of max out of 3 numbers and 25 (3 non zero)" << std::endl;
    
    int max_val = a;
    if (b > max_val) max_val = b;
    if (c > max_val) max_val = c;
    if (25 > max_val) max_val = 25;
    
    return max_val;
}

// Задача с трапецией через void, лаба 1 переписаная
void trapezoid(short h, short b1, short b2) {
    std::cout << "Function to calculate trapezoid area" << std::endl;
    
    float s = ((std::abs(b1) + std::abs(b2)) * std::abs(h)) / 2.0;
    
    std::cout << "S=" << s << std::endl;
    std::cout << "h-" << sizeof(h) * 8 << " bit, min = " 
              << std::numeric_limits<short>::min() << ", max = " 
              << std::numeric_limits<short>::max() << std::endl;
    std::cout << "b1-" << sizeof(b1) * 8 << " bit, min = " 
              << std::numeric_limits<short>::min() << ", max = " 
              << std::numeric_limits<short>::max() << std::endl;
    std::cout << "b2-" << sizeof(b2) * 8 << " bit, min = " 
              << std::numeric_limits<short>::min() << ", max = " 
              << std::numeric_limits<short>::max() << std::endl;
    std::cout << "S-" << sizeof(s) * 8 << " bit, min = " 
              << std::numeric_limits<float>::lowest() << ", max = " 
              << std::numeric_limits<float>::max() << std::endl;
}

int main() {
    int choice;
    std::cout << "Enter code number (1 or 2): ";
    std::cin >> choice;
    
    if (choice == 1) {
        int a, b, c;
        std::cout << "Enter three integers: ";
        std::cin >> a >> b >> c;
        
        // Колилчество не нулевых значений
        int nonZeroCount = 0;
        if (a != 0) nonZeroCount++;
        if (b != 0) nonZeroCount++;
        if (c != 0) nonZeroCount++;
        
        int result;
        if (nonZeroCount == 2) {
            int x = 0, y = 0;
            if (a != 0) { x = a; if (b != 0) y = b; else y = c; }
            else { x = b; y = c; }
            result = processNumbers(x, y);
        }
        else if (nonZeroCount == 3) {
            result = processNumbers(a, b, c);
        }
        else {
            std::cout << "Not enough non zero numbers" << std::endl;
            return 1;
        }
        
        std::cout << "Result: " << result << std::endl;
    }
    else if (choice == 2) {
        short h, b1, b2;
        
        std::cout << "Input height (|h| <= 255):" << std::endl;
        std::cin >> h;
        std::cout << "Input base 1 (|x| <= 1000):" << std::endl;
        std::cin >> b1;
        std::cout << "Input base 2 (|x| <= 1000):" << std::endl;
        std::cin >> b2;
        
        trapezoid(h, b1, b2);
    }
    else {
        std::cout << "Invalid code choice" << std::endl;
        return 1;
    }
    
    return 0;
}
/*Лабораторная работа 1.
Лабораторная работа 1.
Типы данных и математические операции

Выбрать максимально подходящий тип данных (согласно заданию) и объяснить в комментариях. 
Для каждого использованного типа данных вывести на экран название, размер в битах, 
минимальное и максимальное значение (значение необходимо посчитать формулой, получить константой, 
вывести можно в экспоненциальном формате). Результат вычислить в новую переменную и вывести на экран с указанием типа. 
Входные данные вводить с клавиатуры (корректно).

Вариант 2
Из целых введенных данных высоты ( |x| не более 255) и двух оснований (|x| не более 1000) вычислить площадь трапеции.

Лабораторная работа №5
Функции

В начале каждой функции выводить текст с информацией какая именно функция используется например "исп. функция суммы 2х чисел", числа вводятся целые, для выбора какая функция должна вызываться в п. 1 использовать правило "если число = 0, считаем что его нет" т.е. ввод (1;0;2) считать как два числа, (1;5;3) как три числа, а (0;0;7) как одно число. Функции в п. 1 должны вернуть численное значение.
Реализовать возможность для пользователя ввести номер  пункта который будет выполняться (1 или 2).
Задание п.2 написано после всех вариантов и является обобщенным упрощение, вместо него все желающие могут сделать дополнительное усложненное задание.
Разбиение на файлы не обязательно.
Пункт 1 – перегрузка функций. (Лекция 27.10)

Вариант 2
Для двух чисел вычислить сумму всех цифр.
Для трёх чисел – наибольшее значение из них и 25.


Пункт 2 – void функция.

Переделать л1 в void функцию. Числа ввести в основной программе, и передать в функцию, которая выводит результат на экран.
 Кто л1 не сдал – возможность получить по ней дополнительную половину балла.
*/