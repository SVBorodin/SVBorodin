#include <iostream>
#include <cstdlib> // для calloc, malloc, realloc, free

using namespace std;

// Функция для ввода положительного числа
int inputPositiveInt(const char* prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (value >= 0) {
            return value;
        } else {
            cout << "Ошибка! Введите неотрицательное число.\n";
        }
    }
}

// Функция для поиска строк с нулевыми элементами
int* findZeroRows(int** matrix, int rows, int cols, int& zeroRowsCount) {
    zeroRowsCount = 0;
    int* zeroRows = (int*)calloc(rows, sizeof(int));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                zeroRows[zeroRowsCount++] = i;
                break; // если в строке есть 0, запоминаем строку и идем дальше
            }
        }
    }

    // Уменьшаем массив до реального количества строк с нулями
    zeroRows = (int*)realloc(zeroRows, zeroRowsCount * sizeof(int));
    return zeroRows;
}

// Функция для удаления строк из матрицы
int** removeRows(int** matrix, int& rows, int cols, int* rowsToRemove, int removeCount) {
    int newRows = rows - removeCount;
    int** newMatrix = (int**)malloc(newRows * sizeof(int*));
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
            newMatrix[newRowIndex] = (int*)malloc(cols * sizeof(int));
            for (int j = 0; j < cols; ++j) {
                newMatrix[newRowIndex][j] = matrix[i][j];
            }
            newRowIndex++;
        }
        free(matrix[i]); // освобождаем строку в любом случае
    }

    free(matrix);
    rows = newRows;
    return newMatrix;
}

// Функция для вывода матрицы
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // 1. Создание и заполнение начальной матрицы 2x2
    int rows = 2;
    int cols = 2;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    cout << "Введите элементы матрицы 2x2:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nИсходная матрица 2x2:\n";
    printMatrix(matrix, rows, cols);

    // 2. Ввод A, B, C, D
    int A = inputPositiveInt("A = ");
    int B = inputPositiveInt("B = ");
    int C = inputPositiveInt("C = ");
    int D = inputPositiveInt("D = ");

    // 3. Преобразование матрицы - добавляем строки сверху и столбцы слева
    int newRows = rows + A;
    int newCols = cols + B;
    int** newMatrix = (int**)malloc(newRows * sizeof(int*));
    
    for (int i = 0; i < newRows; ++i) {
        newMatrix[i] = (int*)malloc(newCols * sizeof(int));
        for (int j = 0; j < newCols; ++j) {
            if (i < A || j < B) {
                // Новые области (добавленные строки сверху и столбцы слева)
                newMatrix[i][j] = i * C + j * D;
            } else {
                // Сохраняем исходную матрицу в правом нижнем углу
                newMatrix[i][j] = matrix[i - A][j - B];
            }
        }
    }

    // Освобождаем старую матрицу
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    
    // Обновляем матрицу и размеры
    matrix = newMatrix;
    rows = newRows;
    cols = newCols;

    cout << "\nПреобразованная матрица (" << rows << "x" << cols << "):\n";
    printMatrix(matrix, rows, cols);

    // 4. Поиск строк с нулевыми элементами
    int zeroRowsCount;
    int* zeroRows = findZeroRows(matrix, rows, cols, zeroRowsCount);

    cout << "\nСтроки с нулевыми элементами: ";
    for (int i = 0; i < zeroRowsCount; ++i) {
        cout << zeroRows[i] << " ";
    }
    cout << endl;

    // 5. Удаление строк с нулевыми элементами
    if (zeroRowsCount > 0) {
        matrix = removeRows(matrix, rows, cols, zeroRows, zeroRowsCount);
        cout << "\nМатрица после удаления строк с нулевыми элементами:\n";
        printMatrix(matrix, rows, cols);
    } else {
        cout << "\nСтрок с нулевыми элементами не найдено.\n";
    }
    free(zeroRows);

    // 6. Работа с указателями
    int a, b;
    cout << "\nВведите a и b: ";
    cin >> a >> b;

    int* ptrA = &a;
    int* ptrB = &b;

    cout << "Исходные значения: a = " << a << ", b = " << b << endl;
    
    *ptrA *= 2;
    cout << "После увеличения a в 2 раза: a = " << a << ", b = " << b << endl;
    
    // Меняем местами через указатели
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    
    cout << "После обмена: a = " << a << ", b = " << b << endl;

    // Освобождение памяти
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}