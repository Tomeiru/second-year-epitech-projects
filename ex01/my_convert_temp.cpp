/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** my_convert_temp
*/

#include <iostream>
#include <iomanip>

int main(void)
{
    double temp;
    std::string unit;
    std::cin >> temp;
    std::cin >> unit;

    if (unit == "Fahrenheit") {
        temp = 5.0 / 9.0 * (temp - 32);
        unit = " Celsius";
    }
    if (unit == "Celsius") {
        temp = temp / (5.0 / 9.0) + 32;
        unit = " Fahrenheit";
    }
    std::cout << std::setw(16) << std::fixed <<
    std::setprecision(3) << temp << std::setw(16) << unit << std::endl;
    return (0);
}
