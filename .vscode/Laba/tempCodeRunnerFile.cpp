#include <iostream>
#include <limits>
#include <cstring>
#include <cmath>
int main()
{
    short h ; //Вмещает от -2^15 до 2^15, что подходит по размеру
    short osn1 ; //Та же ситуация с 2 основаниями
    short osn2 ; 
    int S; //По идее должно вмешать до 255тыс
    std::cout << "Введите высоту (|x| ≤ 255):" << '\n';
    std::cin >> h;
    std::cout << "Введите основание номер 1 (|x| ≤ 1000):" << '\n';
    std::cin >> osn1;
    std::cout << "Введите основание номер 2 (|x| ≤ 1000):" << '\n';
    std::cin >> osn2;
    S = (osn1 + osn2)*h / 2;
    std::cout << S ; 
}