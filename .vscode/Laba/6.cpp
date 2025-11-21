#include <iostream>
#include <cstdlib>

int inputPositiveInt(const char* prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (value >= 0) {
            return value;
        } else {
            std::cout << "Error! Please enter a non negative number." << "\n";
        }
    }
}

// Поиск нулевых строк матрицы
int* findZeroRows(int** matrix, int rows, int cols, int& zeroRowsCount) {
    zeroRowsCount = 0;
    int* zeroRows = (int*)std::calloc(rows, sizeof(int));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                zeroRows[zeroRowsCount++] = i;
                break;
            }
        }
    }
    zeroRows = (int*)std::realloc(zeroRows, zeroRowsCount * sizeof(int));
    return zeroRows;
}

// Удаление строк
int** removeRows(int** matrix, int& rows, int cols, int* rowsToRemove, int removeCount) {
    int newRows = rows - removeCount;
    int** newMatrix = (int**)std::malloc(newRows * sizeof(int*));
    int newRowIndex = 0;
    for (int i = 0; i < rows; ++i) {
        bool shouldRemove = false;
        for (int j = 0; j < removeCount; ++j) {
            if (i == rowsToRemove[j]) {
                shouldRemove = true;
                break;
            }
        }
        if (!shouldRemove) {
            newMatrix[newRowIndex] = (int*)std::malloc(cols * sizeof(int));
            for (int j = 0; j < cols; ++j) {
                newMatrix[newRowIndex][j] = matrix[i][j];
            }
            newRowIndex++;
        }
        std::free(matrix[i]);
    }
    std::free(matrix);
    rows = newRows;
    return newMatrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Начальная матрица 2 на 2
int main() {
    int rows = 2;
    int cols = 2;
    int** matrix = (int**)std::malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)std::malloc(cols * sizeof(int));
    }

    std::cout << "Enter elements of 2x2 matrix:" << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "\n"<< "Original 2x2 matrix:" << "\n";
    printMatrix(matrix, rows, cols);
    int A = inputPositiveInt("A = "); //сколько строк нужно добавить сверху.
    int B = inputPositiveInt("B = "); //сколько столбцов добавить слева.
    int C = inputPositiveInt("C = "); //коэф. для заполнения (целые числа)
    int D = inputPositiveInt("D = "); //коэф. для заполнения (целые числа)
    int newRows = rows + A;
    int newCols = cols + B;
    int** newMatrix = (int**)std::malloc(newRows * sizeof(int*));
    
    for (int i = 0; i < newRows; ++i) {
        newMatrix[i] = (int*)std::malloc(newCols * sizeof(int));
        for (int j = 0; j < newCols; ++j) {
            if (i < A || j < B) {
                //Добавление новых строк столбцов
                newMatrix[i][j] = i * C + j * D;
            } else {
                newMatrix[i][j] = matrix[i - A][j - B]; //По примеру, т.е правый нижний угол
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        std::free(matrix[i]);
    }

    std::free(matrix);
    
    // Обновление матрицы и ее размеров
    matrix = newMatrix;
    rows = newRows;
    cols = newCols;
    std::cout << "Transformed matrix (" << rows << "x" << cols << "):" << "\n";
    printMatrix(matrix, rows, cols);
    int zeroRowsCount;
    int* zeroRows = findZeroRows(matrix, rows, cols, zeroRowsCount);
    std::cout << "Rows with zero elements: ";
    for (int i = 0; i < zeroRowsCount; ++i) {
        std::cout << zeroRows[i] << " ";
    }

    // Строки с 0 элем
    std::cout << std::endl;
    if (zeroRowsCount > 0) {
        matrix = removeRows(matrix, rows, cols, zeroRows, zeroRowsCount);
        std::cout << "Matrix after removing rows with zero elements:" << "\n";
        printMatrix(matrix, rows, cols);
    
    } else {

        std::cout << "No rows with zero elements found." << "\n";
    }

    std::free(zeroRows);
    // Пункт 2
    int a, b;
    std::cout << "Enter a and b: " << "\n";
    std::cin >> a >> b;
    int* ptrA = &a;
    int* ptrB = &b;
    std::cout << "Initial values: a = " << a << ", b = " << b << std::endl;
    
    *ptrA *= 2;
    std::cout << "After doubling a: a = " << a << ", b = " << b << std::endl;
    
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    
    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;
    for (int i = 0; i < rows; ++i) {
        std::free(matrix[i]);
    }

    std::free(matrix);
    return 0;
}

/*
Вариант 2

Лабораторная работа 6.
Динамические массивы и указате

Четные варианты
Создать двумерный динамический массив 2х2. Заполнить его числами с клавиатуры. При отрицательных А, В говорить что ошибка и ждать ввода корректного числа.
А
В
С   
Д

А – сколько строк нужно добавить сверху.
В – сколько столбцов добавить слева.
С, Д – коэф. для заполнения (целые числа)
Преобразовать начальную матрицу по примеру:
0С+0Д
0С+1Д
0С+2Д
0С+3Д
0С+4Д
1С+0Д
…
…
…
…
2С+0Д
…
2С+2Д
А=2
В=3
3С+0Д
…
…
С=1
Д=5


1. Передать эту матрицу в функцию.
2. Найти все ячейки, значение в которых равно 0 и вернуть из функции одномерный массив с индексами строк(не vector).
3. Удалить в увеличенном массиве соответствующие строки.
4. Вывести полученную матрицу.
Использовать calloc/malloc/realloc/free.

Пункт 2 – Указатели и адреса

Четные варианты
Ввести значение 2-х целых переменных а и b. Направить два указателя на эти переменные. С помощью указателя увеличить значение переменной а в 2 раза. Затем поменять местами значения переменных а и b через их указатели.
new/delete.
*/