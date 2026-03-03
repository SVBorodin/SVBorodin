#include "Car.h"
#include "Workshop.hpp"
#include <iostream>

void labOpinion() {
    std::cout << "Lab 3 opinion:\n";
    std::cout << "Interesno, uznal o vidah radio i kak nazivaet'sya avtomoika okolo doma\n";
}

int main() {

    Car car1("BMW", "M5", "123456789",
             "A123BC", 15000,
             {"toolkit", "jack", "pump"});

    Car car2("Audi", "A6", "987654321",
             "B777BB", 20000,
             {"fire extinguisher", "pump"});

    car1.printInfo();
    car2.printInfo();

    Workshop workshop("Sudostroitel'naya 99k1");

    Radio r1 = {"Pioneer"};
    Radio r2 = {"Sony"};

    workshop.addRadio(r1);
    workshop.addRadio(r2);

    workshop.attachCar(&car1);
    workshop.attachCar(&car2);

    workshop.printInfo();

    workshop.installRadio("A123BC", "Pioneer");

    Car sum = car1 + car2;
    sum.printInfo();

    Car unique = car1 - car2;
    unique.printInfo();

    Car common = car1 / car2;
    common.printInfo();

    car1.rollbackMileage(5000);
    car1.printInfo();

    labOpinion();

    return 0;
}