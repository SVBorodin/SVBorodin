#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <algorithm>

using namespace std;

// Пункт 1 - используем vector для динамических операций
vector<int> items;

void print_vector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
    }
    cout << "]";
}

void print_vector_with_comma(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

void add_beginning() {
    int element;
    cout << "Введите значение элемента: ";
    cin >> element;
    items.insert(items.begin(), element);
    cout << "Элемент со значением " << element << " был добавлен в начало массива." << endl;
}

void add_end() {
    int element;
    cout << "Введите значение элемента: ";
    cin >> element;
    items.push_back(element);
    cout << "Элемент со значением " << element << " был добавлен в конец массива." << endl;
}

void clear_vector() {
    cout << "Массив ";
    print_vector(items);
    items.clear();
    cout << " был успешно очищен" << endl;
}

void search_element() {
    int seekfor;
    cout << "Введите значение искомого элемента: ";
    cin >> seekfor;
    vector<int> indices;
    
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i] == seekfor) {
            indices.push_back(i);
        }
    }
    
    cout << "Соответствующие поиску индексы: ";
    if (indices.empty()) {
        cout << "[]";
    } else {
        print_vector_with_comma(indices);
    }
    cout << endl;
}

void variant_task() {
    if (items.empty()) {
        cout << "В массиве нет элементов!" << endl;
        return;
    }
    
    cout << "Массив до обработки: ";
    print_vector(items);
    cout << endl;
    
    if (items.size() % 2 == 0) {
        // Четное количество - удалить первый элемент
        if (!items.empty()) {
            items.erase(items.begin());
        }
    } else {
        // Нечетное количество - удалить до 4 последних элементов
        if (items.size() > 4) {
            items.erase(items.begin(), items.end() - 4);
        } else {
            items.clear();
        }
    }
    
    cout << "Массив после обработки: ";
    print_vector(items);
    cout << endl;
}

void show_menu() {
    cout << "\n========== Меню ==========" << endl;
    cout << "0. Выход" << endl;
    cout << "1. Просмотр массива" << endl;
    cout << "2. Добавить элемент в начало" << endl;
    cout << "3. Добавить элемент в конец" << endl;
    cout << "4. Очистка всего массива" << endl;
    cout << "5. Поиск элемента в массиве" << endl;
    cout << "6. Задание варианта" << endl;
    cout << "Выбор: ";
}

// Пункт 2 - используем array для фиксированного размера

// Передача по значению - создается копия массива
void sort_by_value(array<int, 10> arr) {
    cout << "В sort_by_value (до сортировки): ";
    for (const auto& elem : arr) cout << elem << " ";
    cout << endl;
    
    sort(arr.begin(), arr.end());
    
    cout << "В sort_by_value (после сортировки): ";
    for (const auto& elem : arr) cout << elem << " ";
    cout << endl;
}

// Передача по ссылке - работаем с оригинальным массивом
void sort_by_reference(array<int, 10>& arr) {
    sort(arr.begin(), arr.end());
}

// Передача по указателю - работаем с оригинальным массивом через указатель
void sort_by_pointer(array<int, 10>* arr) {
    sort(arr->begin(), arr->end());
}

void demonstrate_array_operations() {
    cout << "\n========== Пункт 2 ==========" << endl;
    
    // Заполнение массива случайными числами от -10 до 10
    array<int, 10> fixed_array;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-10, 10);
    
    cout << "Исходный массив: ";
    for (size_t i = 0; i < fixed_array.size(); ++i) {
        fixed_array[i] = dist(gen);
        cout << fixed_array[i] << " ";
    }
    cout << endl;
    
    // Демонстрация передачи по значению
    cout << "\n1. Передача по ЗНАЧЕНИЮ:" << endl;
    cout << "Создается копия массива, оригинал не изменяется" << endl;
    cout << "Оригинальный массив до sort_by_value: ";
    for (const auto& elem : fixed_array) cout << elem << " ";
    cout << endl;
    
    sort_by_value(fixed_array);
    
    cout << "Оригинальный массив после sort_by_value: ";
    for (const auto& elem : fixed_array) cout << elem << " ";
    cout << endl;
    
    // Демонстрация передачи по ссылке
    cout << "\n2. Передача по ССЫЛКЕ:" << endl;
    cout << "Работаем с оригинальным массивом, изменения сохраняются" << endl;
    array<int, 10> array_ref = fixed_array;
    cout << "Массив до sort_by_reference: ";
    for (const auto& elem : array_ref) cout << elem << " ";
    cout << endl;
    
    sort_by_reference(array_ref);
    
    cout << "Массив после sort_by_reference: ";
    for (const auto& elem : array_ref) cout << elem << " ";
    cout << endl;
    
    // Демонстрация передачи по указателю
    cout << "\n3. Передача по УКАЗАТЕЛЮ:" << endl;
    cout << "Работаем с оригинальным массивом через указатель" << endl;
    array<int, 10> array_ptr = fixed_array;
    cout << "Массив до sort_by_pointer: ";
    for (const auto& elem : array_ptr) cout << elem << " ";
    cout << endl;
    
    sort_by_pointer(&array_ptr);
    
    cout << "Массив после sort_by_pointer: ";
    for (const auto& elem : array_ptr) cout << elem << " ";
    cout << endl;
    
    // Объяснение различий
    cout << "\n=== Объяснение различий ===" << endl;
    cout << "ПЕРЕДАЧА ПО ЗНАЧЕНИЮ:" << endl;
    cout << "- Создается полная копия массива" << endl;
    cout << "- Изменения не влияют на оригинал" << endl;
    cout << "- Может быть затратной по памяти для больших массивов" << endl;
    
    cout << "\nПЕРЕДАЧА ПО ССЫЛКЕ:" << endl;
    cout << "- Работаем напрямую с оригинальным массивом" << endl;
    cout << "- Изменения сохраняются" << endl;
    cout << "- Эффективно по памяти" << endl;
    
    cout << "\nПЕРЕДАЧА ПО УКАЗАТЕЛЮ:" << endl;
    cout << "- Аналогично передаче по ссылке" << endl;
    cout << "- Требуется разыменование (* или ->)" << endl;
    cout << "- Может быть nullptr" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    // Пункт 1 - работа с динамическим массивом
    while (true) {
        setlocale(LC_ALL, "Russian");
        show_menu();
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 0:
                cout << "Выход из программы." << endl;
                break;
            case 1:
                cout << "Текущий массив: ";
                print_vector(items);
                cout << endl;
                continue;
            case 2:
                add_beginning();
                continue;
            case 3:
                add_end();
                continue;
            case 4:
                clear_vector();
                continue;
            case 5:
                search_element();
                continue;
            case 6:
                variant_task();
                continue;
            default:
                cout << "Неизвестная команда!" << endl;
                continue;
        }
        break;
    }
    
    // Пункт 2 - демонстрация работы с фиксированным массивом
    demonstrate_array_operations();
    
    // Пункт 3 - объяснение выбора
    cout << "\n========== Пункт 3 ==========" << endl;
    cout << "Объяснение выбора контейнеров:" << endl;
    cout << "1. В Пункте 1 использован std::vector, потому что:" << endl;
    cout << "   - Требуется динамическое изменение размера (добавление/удаление)" << endl;
    cout << "   - Нужны операции insert, push_back, erase" << endl;
    cout << "   - Размер массива неизвестен заранее" << endl;
    
    cout << "\n2. В Пункте 2 использован std::array, потому что:" << endl;
    cout << "   - Размер фиксирован (10 элементов)" << endl;
    cout << "   - Не требуется изменение размера" << endl;
    cout << "   - Более эффективен для массивов фиксированного размера" << endl;
    
    cout << "\n3. 'Выбора нет' потому что:" << endl;
    cout << "   - std::vector оптимален для динамических операций" << endl;
    cout << "   - std::array оптимален для статических данных" << endl;
    cout << "   - Они выполняют одинаковую роль только при фиксированном размере" << endl;
    
    return 0;
}