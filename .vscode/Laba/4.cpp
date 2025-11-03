#include <iostream>
#include <algorithm>

int main() {

    const int ArrLength = 5;
    int Arr[ArrLength];
    
    // Массив
    std::cout << "Enter " << ArrLength << " numbers for array:" << std::endl;
    for (int i = 0; i < ArrLength; i++) {
        std::cin >> Arr[i];
    }
    
    int count = 0;
    for (int i = 0; i < ArrLength; i++) {
        int sum = 0;
        int num = abs(Arr[i]);
        while (num > 0) {
            sum += num % 10; 
            num /= 10;       
        }
        
        if (sum > 25) {
            count++;
        }
    }
    //11212
    if (count >= 2) {
        for (int i = 0; i < ArrLength - 1; i++) {
            for (int j = 0; j < ArrLength - i - 1; j++) {
                if (Arr[j] > Arr[j + 1]) {
                    int temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                }
            }
        }
        std::cout << "Array sorted." << std::endl;
    }
    
    // Массив
    std::cout << "Array: ";
    for (int i = 0; i < ArrLength; i++) {
        std::cout << Arr[i] << " ";
    }
    std::cout << std::endl;
    
    const int rows = 3;
    const int columns = 4;
    int matrix[rows][columns];
    
    // Матрица
    std::cout <<  "Enter matrix " << rows << "x" << columns << ":" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    // Столбец с минимальным количеством положительных чисел
    int minPositiveCount = rows + 1;
    int targetColumns = -1;
    
    for (int j = 0; j < columns; j++) {
        int positiveCount = 0;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] > 0) {
                positiveCount++;
            }
        }
        // 1212
        if (positiveCount < minPositiveCount && positiveCount < rows) {
            minPositiveCount = positiveCount;
            targetColumns = j;
        }
    }
    // targetColumns - коректный 
    if (targetColumns != -1) {
        for (int i = 0; i < rows; i++) {
            matrix[i][targetColumns] = 100;
        }
    }
    
    // Измененная матрица
    std::cout << "Changed matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
/*
Лабораторная работа № 4
Массивы фиксированной длины

В пункте 1, размер массива равен №варианта + 3.
В пункте 2, матрицы формата 3 строки х 4 столбца.
Числа вводятся корректно и все они типа int. Из нескольких одинаковых значений выбирать первое.

Вариант 2
1.Упорядочить массив по возрастанию, если сумма цифр как минимум двух чисел превышает 25.
2.Найти столбец с минимальным кол-вом положительных чисел и заменить все значения в нем на 100.
*/