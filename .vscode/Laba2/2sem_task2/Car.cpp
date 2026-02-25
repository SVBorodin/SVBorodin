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

std::string Car::generateGov(const std::string& a, const std::string& b) {
    static std::mt19937 gen(std::random_device{}());
    static const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::uniform_int_distribution<int> L(0, 25);
    std::uniform_int_distribution<int> D(0, 9);

    std::string s;
    do {
        s.clear();
        s += letters[L(gen)];
        s += char('0' + D(gen));
        s += char('0' + D(gen));
        s += char('0' + D(gen));
        s += letters[L(gen)];
        s += letters[L(gen)];
    } while (s == a || s == b);

    return s;
}

Car::Car() : mark("Unknown"), model("Unknown"), govNumber("A000AA") {
    std::cout << "Default constructor\n";
}

Car::Car(const Car& other)
    : mark(other.mark), model(other.model),
      govNumber(other.govNumber), trunk(other.trunk) {
    std::cout << "Copy constructor\n";
}

Car::Car(std::string m, std::string mo,
         std::string gov,
         std::vector<std::string> items)
    : mark(m), model(mo), trunk(items) {
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
        govNumber = other.govNumber;
        trunk = other.trunk;
    }
    return *this;
}

Car Car::operator+(const Car& other) const {
    Car result;
    result.mark = mark;
    result.model = model;
    result.govNumber = generateGov(govNumber, other.govNumber);

    result.trunk = trunk;
    result.trunk.insert(result.trunk.end(),
                        other.trunk.begin(),
                        other.trunk.end());

    std::sort(result.trunk.begin(), result.trunk.end());
    return result;
}

Car Car::operator-(const Car& other) const {
    Car result;
    result.mark = mark;
    result.model = model;
    result.govNumber = generateGov(govNumber, other.govNumber);

    result.trunk = trunk;
    result.trunk.insert(result.trunk.end(),
                        other.trunk.begin(),
                        other.trunk.end());

    std::sort(result.trunk.begin(), result.trunk.end());
    result.trunk.erase(std::unique(result.trunk.begin(),
                                   result.trunk.end()),
                       result.trunk.end());

    return result;
}

Car Car::operator/(const Car& other) const {
    Car result;
    result.mark = other.mark;
    result.model = other.model;
    result.govNumber = generateGov(govNumber, other.govNumber);

    for (auto& item : trunk) {
        for (auto& o : other.trunk) {
            if (item == o)
                result.trunk.push_back(item);
        }
    }

    std::sort(result.trunk.begin(), result.trunk.end());
    result.trunk.erase(std::unique(result.trunk.begin(),
                                   result.trunk.end()),
                       result.trunk.end());

    return result;
}

void Car::printInfo() const {
    std::cout << "Mark: " << mark << "\n";
    std::cout << "Model: " << model << "\n";
    std::cout << "Gov: " << govNumber << "\n";
    std::cout << "Trunk: ";
    for (auto& item : trunk)
        std::cout << item << " ";
    std::cout << "\n";
}