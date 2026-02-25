#pragma once
#include <iostream>
#include <string>
#include <vector>

class Car {
private:
    std::string mark;
    std::string model;
    std::string govNumber;
    std::vector<std::string> trunk;

    bool isGovValid(const std::string& s) const;
    static std::string generateGov(const std::string& a, const std::string& b);

public:
    Car();
    Car(const Car& other);
    Car(std::string m, std::string mo,
        std::string gov,
        std::vector<std::string> items);
    ~Car();

    Car& operator=(const Car& other);

    Car operator+(const Car& other) const;
    Car operator-(const Car& other) const;
    Car operator/(const Car& other) const;

    void printInfo() const;
};