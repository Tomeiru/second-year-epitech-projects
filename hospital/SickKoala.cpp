/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string new_name)
{
    name = new_name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars") {
        std::cout << "Mr." << name << ": Mars, and it kreogs!" << std::endl;
        return (true);
    }if (drug == "Kinder") {
        std::cout << "Mr." << name << ": There is a toy inside!" << std::endl;
        return (true);
    }std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string sentence)
{
    std::string kreog = "Kreog!";

    while (sentence.find(kreog) != std::string::npos)
        sentence.replace(sentence.find(kreog), kreog.length(), "1337!");
    std::cout << "Mr." << name << ": " << sentence << std::endl;
}

std::string SickKoala::getName(void)
{
    return (name);
}
