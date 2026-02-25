#include "Car.h"

int main() {
    Car c1("A", "M1", "A123BC", {"first aid kit", "wheel", "pump"});
    Car c2("B", "M2", "B777BB", {"wheel", "fire extinguisher", "pump"});

    Car c3 = c1 + c2;
    c3.printInfo();

    Car c4 = c1 - c2;
    c4.printInfo();

    Car c5 = c1 / c2;
    c5.printInfo();

    Car c6;
    c6 = c1;
    c6.printInfo();

    return 0;
}