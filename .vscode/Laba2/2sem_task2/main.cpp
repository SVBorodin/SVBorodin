#include "Car.h"
#include <vector>

int main() {
    Car c1("A", "M1", "123456789", "ABC123", 100, {"a", "b", "c"});
    Car c2("B", "M2", "987654321", "DEF456", 200, {"b", "d", "c"});

    Car c3 = c1 + c2;
    c3.printInfo();
    std::cout << "----\n";

    Car c4 = c1 - c2;
    c4.printInfo();
    std::cout << "----\n";

    Car c5 = c1 / c2;
    c5.printInfo();

    return 0;
}