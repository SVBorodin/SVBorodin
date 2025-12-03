#include <iostream>
#include <vector>
#include <array>

/*
Пункт 3
Для пункта 1 используется vector т.к надо добавлять и удалять в отличие от 2 пункта куда вписывается array
т.к с ним такие махинации не возможны, если не добавлять и удалять элементы то они выполняют одинаковую задачу (т.е массив фиксированный).
Очевидно что для 1 пункта не подойдет array, но для 2 пункта подойдет как array так и vector (по заданию требуется использовать оба)
*/

void printVect(const std::vector<int>& vect) {
    std::cout << "[";
    for (size_t i = 0; i < vect.size(); ++i) {
        std::cout << vect[i];
        if (i != vect.size() - 1) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

// bubble sort по ссылке
void bubbleSort(std::array<int, 10>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
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
                int temp = (*arr)[j];
                (*arr)[j] = (*arr)[j + 1];
                (*arr)[j + 1] = temp;
            }
        }
    }
}

void part2() {
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
    std::vector<int> vect;
    int choice;
    do {
        std::cout << "0. Exit." << std::endl;
        std::cout << "1. View array." << std::endl;
        std::cout << "2. Add element to the beginning." << std::endl;
        std::cout << "3. Add element to the end." << std::endl;
        std::cout << "4. Clear the entire array." << std::endl;
        std::cout << "5. Search for an element in the array." << std::endl;
        std::cout << "6. Task variant." << std::endl;
        std::cout << "7. Go to Part 2." << std::endl;
        std::cout << "Choose an action: ";
        std::cin >> choice;
        switch(choice) {
            case 1:
                printVect(vect);
                break;
            case 2: {
                int element;
                std::cout << "Enter the element to add to the beginning: ";
                std::cin >> element;
                vect.insert(vect.begin(), element);
                break;
            }
            case 3: {
                int element;
                std::cout << "Enter the element to add to the end: ";
                std::cin >> element;
                vect.push_back(element);
                break;
            }
            case 4:
                vect.clear();
                std::cout << "Array is cleared." << std::endl;
                break;
            case 5: {
                int element;
                std::cout << "Enter the element to search for: ";
                std::cin >> element;
                std::vector<size_t> indices;
                for (size_t i = 0; i < vect.size(); ++i) {
                    if (vect[i] == element) {
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
                printVect(vect);
                if (vect.size() % 2 == 0) {
                    if (!vect.empty()) {
                        vect.erase(vect.begin());
                        std::cout << "First element removed." << std::endl;
                    }
                } else {
                    size_t n = std::min(static_cast<size_t>(4), vect.size());
                    if (n > 0) {
                        vect.erase(vect.end() - n, vect.end());
                        std::cout << n << " last elements removed." << std::endl;
                    }
                }
                std::cout << "After: ";
                printVect(vect);
                break;
            case 7:
                part2();
                break;
        }
    } while (choice != 0);

    return 0;
}