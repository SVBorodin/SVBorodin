#include "Car.h"
#include <algorithm>

bool Car::isGovValid(const std::string& s) const {
    if (s.length() != 6) return false;
    return true;
}

Car::Car()
 : mark("Unknown"), model("Unknown"),
   bodyNumber("000000000"),
   govNumber("A000AA"),
   mileage(0) {
    std::cout << "Default constructor\n";
}

Car::Car(const Car& other)
 : mark(other.mark), model(other.model),
   bodyNumber(other.bodyNumber),
   govNumber(other.govNumber),
   mileage(other.mileage),
   trunk(other.trunk) {
    std::cout << "Copy constructor\n";
}

Car::Car(std::string m, std::string mo,
         std::string body, std::string gov,
         int mil, std::vector<std::string> items)
 : mark(m), model(mo), mileage(mil), trunk(items) {
    if (body.length() > 0) bodyNumber = body;
    else bodyNumber = "000000000";
    if (isGovValid(gov)) govNumber = gov;
    else govNumber = "A000AA";
    std::cout << "Full constructor\n";
}

Car::~Car() {
    trunk.clear();
    std::cout << "Destructor called\n";
}

std::string Car::getMark() const       { return mark; }
std::string Car::getModel() const      { return model; }
std::string Car::getBodyNumber() const { return bodyNumber; }
std::string Car::getGovNumber() const  { return govNumber; }
int Car::getMileage() const            { return mileage; }

void Car::setBodyNumber(const std::string& body) {
    if (body.length() >= 8) bodyNumber = body;
}

void Car::setGovNumber(const std::string& gov) {
    if (isGovValid(gov)) govNumber = gov;
}

Car Car::operator+(const Car& other) const {
    Car result = *this;
    for (auto item : other.trunk) {
        result.trunk.push_back(item);
    }
    return result;
}

Car Car::operator-(const Car& other) const {
    Car result = *this;
    for (auto item : other.trunk) {
        bool found = false;
        for (auto exist : result.trunk) {
            if (exist == item) found = true;
        }
        if (!found) result.trunk.push_back(item);
    }
    return result;
}

Car Car::operator/(const Car& other) const {
    Car result;
    for (auto item : trunk) {
        for (auto oitem : other.trunk) {
            if (item == oitem) {
                result.trunk.push_back(item);
            }
        }
    }
    return result;
}

void Car::printInfo() const {
    std::cout << "Mark: " << mark << "\n";
    std::cout << "Model: " << model << "\n";
    std::cout << "Gov: " << govNumber << "\n";
    std::cout << "Trunk: ";
    for (auto item : trunk) std::cout << item << " ";
    std::cout << "\n";
}