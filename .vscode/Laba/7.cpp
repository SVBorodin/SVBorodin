#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>
#include <algorithm>

/*
Пункт 3:
Для П.1 используем std::vector, т.к. там требуется добавлять и удалять элементы, а в П.2 массив фиксированный, подойдёт и std::array.
Здесь представлен выбор без выбора,
т.к. у std::array отсутствует возможность динамически расширять массив (что необходимо для выполнения П.1), в отличие от std::vector.
std::array и std::vector играют одну и ту же роль, если массив должен быть фиксированным
*/

// Функция для вывода массива
void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

// Функция для сортировки по значению
void sortByValue(std::array<int, 10> arr) {
    std::sort(arr.begin(), arr.end());
    std::cout << "Sort by value: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;
}

// Функция для сортировки по ссылке
void sortByReference(std::array<int, 10>& arr) {
    std::sort(arr.begin(), arr.end());
    std::cout << "Sort by reference: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;
}

// Функция для сортировки по указателю
void sortByPointer(std::array<int, 10>* arr) {
    std::sort(arr->begin(), arr->end());
    std::cout << "Sort by pointer: ";
    for (int i : *arr) std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    // Пункт 1
    std::vector<int> arr;
    int choice;
    do {
        std::cout << "0. Exit." << std::endl;
        std::cout << "1. View array." << std::endl;
        std::cout << "2. Add element to the beginning." << std::endl;
        std::cout << "3. Add element to the end." << std::endl;
        std::cout << "4. Clear the entire array." << std::endl;
        std::cout << "5. Search for an element in the array." << std::endl;
        std::cout << "6. Task variant." << std::endl;
        std::cout << "Choose an action: ";
        std::cin >> choice;
        switch(choice) {
            case 1:
                printArray(arr);
                break;
            case 2: {
                int element;
                std::cout << "Enter the element to add to the beginning: ";
                std::cin >> element;
                arr.insert(arr.begin(), element);
                break;
            }
            case 3: {
                int element;
                std::cout << "Enter the element to add to the end: ";
                std::cin >> element;
                arr.push_back(element);
                break;
            }
            case 4:
                arr.clear();
                std::cout << "Array is cleared." << std::endl;
                break;
            case 5: {
                int element;
                std::cout << "Enter the element to search for: ";
                std::cin >> element;
                std::vector<size_t> indices;
                for (size_t i = 0; i < arr.size(); ++i) {
                    if (arr[i] == element) {
                        indices.push_back(i);
                    }
                }
                std::cout << "[";
                for (size_t i = 0; i < indices.size(); ++i) {
                    std::cout << indices[i];
                    if (i != indices.size() - 1) std::cout << ", ";
                }
                std::cout << "]" << std::endl;
                break;
            }
            case 6:
                if (arr.size() % 2 == 0) {
                    if (!arr.empty()) {
                        arr.erase(arr.begin());
                        std::cout << "First element removed." << std::endl;
                    }
                } else {
                    size_t n = std::min(size_t(4), arr.size());
                    if (n > 0) {
                        arr.erase(arr.end() - n, arr.end());
                        std::cout << n << " last elements removed." << std::endl;
                    }
                }
                break;
        }
    } while (choice != 0);

    // Пункт 2
    std::srand(std::time(0));
    std::array<int, 10> staticArr;
    for (int& i : staticArr) {
        i = std::rand() % 21 - 10; // [-10, 10]
    }
    std::cout << "Initial array: ";
    for (int i : staticArr) std::cout << i << " ";
    std::cout << std::endl;

    sortByValue(staticArr);
    std::cout << "After sorting by value: ";
    for (int i : staticArr) std::cout << i << " ";
    std::cout << std::endl;

    sortByReference(staticArr);
    std::cout << "After sorting by reference: ";
    for (int i : staticArr) std::cout << i << " ";
    std::cout << std::endl;

    sortByPointer(&staticArr);
    std::cout << "After sorting by pointer: ";
    for (int i : staticArr) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
