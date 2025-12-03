#include <iostream>
#include <vector>
#include <array>

void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

// bubble sort по ссылке
void bubbleSort(std::array<int, 10>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмен местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// bubble sort по указателю
void bubbleSortByPointer(std::array<int, 10>* arr) {
    for (size_t i = 0; i < arr->size() - 1; ++i) {
        for (size_t j = 0; j < arr->size() - i - 1; ++j) {
            if ((*arr)[j] > (*arr)[j + 1]) {
                // Обмен местами
                int temp = (*arr)[j];
                (*arr)[j] = (*arr)[j + 1];
                (*arr)[j + 1] = temp;
            }
        }
    }
}

void task2() {
    std::array<int, 10> staticArr;
    std::cout << "Enter 10 elements for the array (from -10 to 10):" << std::endl;
    for (int i = 0; i < 10; ++i) {
        int value;
        while (true) {
            std::cout << "Element " << i + 1 << ": ";
            std::cin >> value;
            if (value < -10 || value > 10) {
                std::cout << "Value must be between -10 and 10. Try again." << std::endl;
            } else {
                staticArr[i] = value;
                break;
            }
        }
    }

    std::cout << "Initial array: ";
    for (int i : staticArr) std::cout << i << " ";
    std::cout << std::endl;

    // Сортировка по значению (сортировка копии)
    {
        std::array<int, 10> arrCopy = staticArr;
        bubbleSort(arrCopy);
        std::cout << "Sort by value: ";
        for (int i : arrCopy) std::cout << i << " ";
        std::cout << std::endl;
    }

    // Сортировка по ссылке
    bubbleSort(staticArr);
    std::cout << "After sorting by reference: ";
    for (int i : staticArr) std::cout << i << " ";
    std::cout << std::endl;

    // Сортировка по указателю
    bubbleSortByPointer(&staticArr);
    std::cout << "After sorting by pointer: ";
    for (int i : staticArr) std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    // Пункт 1 vector
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
        std::cout << "7. Go to Task 2." << std::endl;
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
                std::cout << "Before: ";
                printArray(arr);
                if (arr.size() % 2 == 0) {
                    if (!arr.empty()) {
                        arr.erase(arr.begin());
                        std::cout << "First element removed." << std::endl;
                    }
                } else {
                    size_t n = std::min(static_cast<size_t>(4), arr.size());
                    if (n > 0) {
                        arr.erase(arr.end() - n, arr.end());
                        std::cout << n << " last elements removed." << std::endl;
                    }
                }
                std::cout << "After: ";
                printArray(arr);
                break;
            case 7:
                task2();
                break;
        }
    } while (choice != 0);

    return 0;
}