#include "Car.h"
#include <algorithm>
#include <random>
#include <cctype>

bool Car::isGovValid(const std::string& s) const {
    if (s.size() != 6) return false;
    if (!isalpha(s[0])) return false;
    for (int i = 1; i <= 3; ++i)
        if (!isdigit(s[i])) return false;
    if (!isalpha(s[4]) || !isalpha(s[5])) return false;
    return true;
}

std::string Car::generateGov(const std::string& a,
                             const std::string& b) {
    static int counter = 100;
    return "A" + std::to_string(counter++) + "AA";
}

Car::Car()
    : mark("Unknown"),
      model("Unknown"),
      bodyNumber("000000000"),
      govNumber("A000AA"),
      mileage(0) {
    std::cout << "Default constructor\n";
}

Car::Car(const Car& other)
    : mark(other.mark),
      model(other.model),
      bodyNumber(other.bodyNumber),
      govNumber(other.govNumber),
      mileage(other.mileage),
      trunk(other.trunk) {
    std::cout << "Copy constructor\n";
}

Car::Car(std::string m, std::string mo,
         std::string body,
         std::string gov,
         int mil,
         std::vector<std::string> items)
    : mark(m),
      model(mo),
      bodyNumber(body),
      mileage(mil),
      trunk(items) {

    if (isGovValid(gov)) govNumber = gov;
    else govNumber = "A000AA";

    std::cout << "Full constructor\n";
}

Car::~Car() {
    trunk.clear();
    std::cout << "Destructor called\n";
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        mark = other.mark;
        model = other.model;
        bodyNumber = other.bodyNumber;
        govNumber = other.govNumber;
        mileage = other.mileage;
        trunk = other.trunk;
    }
    return *this;
}

Car Car::operator+(const Car& other) const {
    Car result = *this;
    result.govNumber = generateGov(govNumber, other.govNumber);

    for (auto item : other.trunk)
        result.trunk.push_back(item);

    return result;
}

Car Car::operator-(const Car& other) const {
    Car result = *this;
    result.govNumber = generateGov(govNumber, other.govNumber);

    for (auto item : other.trunk) {
        bool found = false;
        for (auto exist : result.trunk)
            if (exist == item)
                found = true;

        if (!found)
            result.trunk.push_back(item);
    }

    return result;
}

Car Car::operator/(const Car& other) const {
    Car result;
    result.mark = mark;
    result.model = model;
    result.bodyNumber = bodyNumber;
    result.mileage = mileage;
    result.govNumber = generateGov(govNumber, other.govNumber);

    for (auto item : trunk)
        for (auto o : other.trunk)
            if (item == o)
                result.trunk.push_back(item);

    return result;
}

std::string Car::getGovNumber() const {
    return govNumber;
}

void Car::rollbackMileage(int x) {
    if (x >= mileage)
        mileage = 0;
    else
        mileage -= x;
}

void Car::printInfo() const {
    std::cout << "Mark: " << mark << "\n";
    std::cout << "Model: " << model << "\n";
    std::cout << "Body: " << bodyNumber << "\n";
    std::cout << "Gov: " << govNumber << "\n";
    std::cout << "Mileage: " << mileage << "\n";
    std::cout << "Trunk: ";
    for (auto item : trunk)
        std::cout << item << " ";
    std::cout << "\n";
}