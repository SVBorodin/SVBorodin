








#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Функция для отображения вектора
void displayVector(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}

// Функция для добавления элемента в начало вектора
void addToBeginning(std::vector<int>& arr, int element) {
    arr.insert(arr.begin(), element);
}

// Функция для добавления элемента в конец вектора
void addToEnd(std::vector<int>& arr, int element) {
    arr.push_back(element);
}

// Функция для очистки вектора
void clearVector(std::vector<int>& arr) {
    arr.clear();
}

// Функция для поиска элемента в векторе
std::vector<size_t> findElement(const std::vector<int>& arr, int element) {
    std::vector<size_t> indices;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == element) {
            indices.push_back(i);
        }
    }
    return indices;
}

// Функция для выполнения задания варианта
void taskVariant(std::vector<int>& arr) {
    std::cout << "Before: ";
    displayVector(arr);
    if (arr.size() % 2 == 0) {
        if (!arr.empty()) {
            arr.erase(arr.begin());
        }
    } else {
        if (arr.size() >= 4) {
            arr.erase(arr.end() - 4, arr.end());
        } else {
            arr.clear();
        }
    }
    std::cout << "After: ";
    displayVector(arr);
}

// Функция для заполнения массива случайными значениями
void fillArray(std::array<int, 10>& arr) {
    std::srand(std::time(0));
    for (int& element : arr) {
        element = std::rand() % 21 - 10; // Random number between -10 and 10
    }
}

// Функция для отображения массива
void displayArray(const std::array<int, 10>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}

// Функция сортировки по значению
void sortByValue(std::array<int, 10> arr) {
    std::sort(arr.begin(), arr.end());
    std::cout << "Sorted by value: ";
    displayArray(arr);
}

// Функция сортировки по ссылке
void sortByReference(std::array<int, 10>& arr) {
    std::sort(arr.begin(), arr.end());
    std::cout << "Sorted by reference: ";
    displayArray(arr);
}

// Функция сортировки по указателю
void sortByPointer(std::array<int, 10>* arr) {
    std::sort(arr->begin(), arr->end());
    std::cout << "Sorted by pointer: ";
    displayArray(*arr);
}

int main() {
    std::vector<int> vec;
    int choice;
    int element;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Display vector" << std::endl;
        std::cout << "2. Add element to beginning" << std::endl;
        std::cout << "3. Add element to end" << std::endl;
        std::cout << "4. Clear vector" << std::endl;
        std::cout << "5. Find element" << std::endl;
        std::cout << "6. Task variant" << std::endl;
        std::cout << "7. Demonstrate array sorting" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            case 1:
                displayVector(vec);
                break;
            case 2:
                std::cout << "Enter element to add to beginning: ";
                std::cin >> element;
                addToBeginning(vec, element);
                break;
            case 3:
                std::cout << "Enter element to add to end: ";
                std::cin >> element;
                addToEnd(vec, element);
                break;
            case 4:
                clearVector(vec);
                std::cout << "Vector cleared." << std::endl;
                break;
            case 5:
                std::cout << "Enter element to find: ";
                std::cin >> element;
                {
                    std::vector<size_t> indices = findElement(vec, element);
                    std::cout << "[";
                    for (size_t i = 0; i < indices.size(); ++i) {
                        std::cout << indices[i];
                        if (i != indices.size() - 1) {
                            std::cout << ", ";
                        }
                    }
                    std::cout << "]" << std::endl;
                }
                break;
            case 6:
                taskVariant(vec);
                break;
            case 7: {
                std::array<int, 10> arr;
                fillArray(arr);
                std::cout << "Original array: ";
                displayArray(arr);
                sortByValue(arr);
                sortByReference(arr);
                sortByPointer(&arr);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}