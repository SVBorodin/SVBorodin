#include "Workshop.hpp"

Workshop::Workshop() : address("Unknown") {
    std::cout << "Workshop default constructor\n";
}

Workshop::Workshop(const Workshop& other)
    : address(other.address),
      radios(other.radios),
      cars(other.cars) {
    std::cout << "Workshop copy constructor\n";
}

Workshop::Workshop(std::string addr)
    : address(addr) {
    std::cout << "Workshop full constructor\n";
}

Workshop::~Workshop() {
    cars.clear();
    radios.clear();
    std::cout << "Workshop destructor\n";
}

void Workshop::addRadio(Radio r) {
    radios.push_back(r);
}

void Workshop::attachCar(Car* car) {
    cars.push_back(car);
}

void Workshop::installRadio(const std::string& govNumber,
                            const std::string& radioName) {
    for (auto car : cars) {
        if (car->getGovNumber() == govNumber) {
            std::cout << "Radio " << radioName
                      << " installed in car "
                      << govNumber << "\n";
            return;
        }
    }
    std::cout << "Car not found\n";
}

void Workshop::printInfo() const {
    std::cout << "Workshop address: " << address << "\n";
    std::cout << "Cars attached: " << cars.size() << "\n";
    std::cout << "Radios available: " << radios.size() << "\n\n";
}