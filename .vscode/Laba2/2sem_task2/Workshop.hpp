#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Car.h"

struct Radio {
    std::string name;
};

class Workshop {
private:
    std::string address;
    std::vector<Radio> radios;
    std::vector<Car*> cars;

public:
    Workshop();
    Workshop(const Workshop& other);
    Workshop(std::string addr);
    ~Workshop();

    void addRadio(Radio r);
    void attachCar(Car* car);
    void installRadio(const std::string& govNumber,
                      const std::string& radioName);

    void printInfo() const;
};