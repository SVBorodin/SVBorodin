#pragma once
#include <iostream>
#include <string>
#include <vector>

class Car {
private:
    std::string mark;
    std::string model;
    std::string bodyNumber;
    std::string govNumber;
    int mileage;
    std::vector<std::string> trunk;

    bool isGovValid(const std::string& s) const;

public:
    Car();
    Car(const Car& other);
    Car(std::string m, std::string mo,
        std::string body, std::string gov,
        int mil, std::vector<std::string> items);
    ~Car();

    std::string getMark() const;
    std::string getModel() const;
    std::string getBodyNumber() const;
    std::string getGovNumber() const;
    int getMileage() const;

    void setBodyNumber(const std::string& body);
    void setGovNumber(const std::string& gov);

    Car operator+(const Car& other) const;
    Car operator-(const Car& other) const;
    Car operator/(const Car& other) const;

    void printInfo() const;
};