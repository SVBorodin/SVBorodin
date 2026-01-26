#include <iostream>
#include <string>

class Car {
private:
    std::string mark;
    std::string model;
    std::string bodyNumber;
    std::string govNumber;
    unsigned int mileage;

    // check format A999AA
    bool isGovNumberValid(const std::string& s) const {
        if (s.length() != 6) return false;

        if (!((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z')))
            return false;

        for (int i = 1; i <= 3; i++) {
            if (!(s[i] >= '0' && s[i] <= '9'))
                return false;
        }

        for (int i = 4; i <= 5; i++) {
            if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
                return false;
        }

        return true;
    }

protected:
    bool isBodyNumberValid(const std::string& s) const {
        if (s.length() < 9 || s.length() > 12)
            return false;

        for (char c : s) {
            bool isDigit = (c >= '0' && c <= '9');
            bool isLetter =
                (c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z');

            if (!(isDigit || isLetter))
                return false;
        }
        return true;
    }

public:
    static const std::string DEFAULT_MARK;
    static const std::string DEFAULT_MODEL;
    static const std::string DEFAULT_GOV;
    static const std::string DEFAULT_BODY;

    Car() {
        std::cerr << "Default constructor started\n";
        mark = DEFAULT_MARK;
        model = DEFAULT_MODEL;
        govNumber = DEFAULT_GOV;
        bodyNumber = DEFAULT_BODY;
        mileage = 0;
    }

    Car(const Car& other) {
        std::cerr << "Copy constructor started\n";
        mark = other.mark;
        model = other.model;
        govNumber = other.govNumber;
        bodyNumber = other.bodyNumber;
        mileage = other.mileage;
    }

    Car(std::string m, std::string mo,
        std::string gov, std::string body,
        unsigned int mil) {

        std::cerr << "Full constructor started\n";

        mark = m.empty() ? DEFAULT_MARK : m;
        model = mo.empty() ? DEFAULT_MODEL : mo;

        govNumber = isGovNumberValid(gov) ? gov : DEFAULT_GOV;
        bodyNumber = isBodyNumberValid(body) ? body : DEFAULT_BODY;
        mileage = mil;
    }

    ~Car() {
        std::cerr << "Destructor started\n";
    }

    std::string getMark() const { return mark; }
    std::string getModel() const { return model; }
    std::string getGovNumber() const { return govNumber; }
    std::string getBodyNumber() const { return bodyNumber; }
    unsigned int getMileage() const { return mileage; }

    void setGovNumber(const std::string& gov) {
        if (isGovNumberValid(gov)) {
            govNumber = gov;
        } else {
            std::cerr << "Invalid government number format\n";
        }
    }

    void setBodyNumber(const std::string& body) {
        if (isBodyNumberValid(body)) {
            bodyNumber = body;
        } else {
            std::cerr << "Invalid body number format\n";
        }
    }

    void printInfo() const {
        std::cout << "Mark: " << mark << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "Government number: " << govNumber << "\n";
        std::cout << "Body number: " << bodyNumber << "\n";
        std::cout << "Mileage: " << mileage << " km\n";
    }

    void rollbackMileage(unsigned int x) {
        std::cout << "Mileage rollback\n";
        if (x >= mileage)
            mileage = 0;
        else
            mileage -= x;
    }
};

const std::string Car::DEFAULT_MARK  = "Unknown";
const std::string Car::DEFAULT_MODEL = "Unknown";
const std::string Car::DEFAULT_GOV   = "A000AA";
const std::string Car::DEFAULT_BODY  = "000000000";

int main() {
    Car a;
    a.printInfo();

    std::cout << "----\n";

    Car b("Toyota", "Camry", "A123BC", "123456789ABC", 10000);
    b.printInfo();

    std::cout << "----\n";

    Car c(b);
    c.rollbackMileage(2000);
    c.setGovNumber("A333AA");
    c.setBodyNumber("12332332155");
    c.printInfo();

    return 0;
}