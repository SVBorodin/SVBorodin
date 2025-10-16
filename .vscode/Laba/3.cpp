#include <iostream>
#include <climits>
#include <cmath>

int main(){
    int n;
    std::cout << "Input n: " << '\n' ;
    std::cin >> n ;

    int result = 1; 
    int minValue = std::numeric_limits<int>::max();
    int minNomer = -1;
    bool found = false;
    
     for (int i = 1; i <= n; ++i) {
        int num;
        std::cout << "Enter number: " << i << " ";
        std::cin >> num;
        
           int lastDigit = std::abs(num % 10); 
        if (lastDigit != 3) {
            // Пропуск если не оканчивается на 3
            continue; 
        }
        // Эта тема работает только для того что внутри большого ифа, т.е если число не подходят о нем забывают и пропускают по циклу следующие числа
        // Ток подходящие
        found = true;
        // Произведение всех оканчивающихся на 3
        result *= num; 

        // Проверяем на минимум
        if (num < minValue) {
            minValue = num;
            minNomer = i;
        }
    }

    
    if (found) {
        std::cout << "Product of numbers ending with 3: " << result << '\n';
        std::cout << "Minimal number: " << minValue << " at position: " << minNomer << '\n';
    } else {
        std::cout << "No numbers ending with 3 found." << '\n';
    }


    
    int x;
    std::cout << "Input |x| < 1000: ";
    std::cin >> x;

    if (abs(x) >= 1000) {
        std::cout << "Error: |x| <1000" << '\n';
        return 1;
    }

    int sum = 0;
    int absx = abs(x); 

    // Сумма цифр 
    do {
        sum += absx % 10;
        absx = absx / 10;
    } while (absx > 0);

    std::cout << "Sum of  " << x << " = " << sum << '\n';



    return 0;
}
/*
Для пункта 1 последовательность целых чисел {A1, A2, …, AN} вводим с клавиатуры. Числа последовательности хранить не нужно. Количество чисел в последовательности вводится с клавиатуры (корректно). Если в последовательности нет чисел, удовлетворяющих условию, вывести сообщение о состоянии.

Для пункта 2 ввести целое  |X| <1.000 и для него посчитать по заданию. Подсказка в конце файла.

Вариант 2
Найти произведение всех чисел, оканчивающихся на 3, из таких чисел определить минимальное и его номер в последовательности.
Найти сумму цифр числа.

Подсказка:
Для пункта 1 цикл for, операторы continue и break.
Для пункта 2 цикл while / do..while.


*/