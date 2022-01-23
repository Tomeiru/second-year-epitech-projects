/*
** EPITECH PROJECT, 2022
** Day8
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial) : Attack(25), Toughness(15)
{
    Id = serial;
    Status = new std::string("Standing by");
    Energy = 50;
    BattleData = new DroidMemory;
    std::cout << "Droid '" << serial << "' Activated" << std::endl;
}

Droid::Droid(const Droid &other) : Attack(other.Attack), Toughness(other.Toughness)
{
    Id = other.Id;
    Status = new std::string(*other.Status);
    Energy = 50;
    BattleData = new DroidMemory;
    std::cout << "Droid '" << other.Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
    delete Status;
    delete BattleData;
}


std::string Droid::getId() const
{
    return (Id);
}

size_t Droid::getEnergy() const
{
    return (Energy);
}

size_t Droid::getAttack() const
{
    return (Attack);
}

size_t Droid::getToughness() const
{
    return (Toughness);
}

std::string Droid::getStatus() const
{
    return (*Status);
}

void Droid::setId(std::string newId)
{
    Id = newId;
}

void Droid::setEnergy(size_t newEnergy)
{
    Energy = newEnergy;
}

void Droid::setStatus(std::string *newStatus)
{
    delete Status;
    Status = newStatus;
}

bool Droid::operator==(const Droid &other) const
{
    if (this->Status == other.Status)
        return (true);
    return (false);
}

bool Droid::operator!=(const Droid &other) const
{
    if (this->Id == other.Id && this->Energy == other.Energy && this->Attack == other.Attack && this->Toughness == other.Toughness && this->Status == other.Status)
        return (false);
    return (true);
}

void Droid::operator=(const Droid &other)
{
    if (Status)
        delete Status;
    this->Id = other.Id;
    this->Energy = other.Energy;
    this->Status = new std::string(*other.Status);
}

Droid &Droid::operator<<(size_t &value)
{
    if (this->Energy + value > 100) {
        value = value - (100 - this->Energy);
        Energy = 100;
        return (*this);
    }
    if (this->Energy + value < 0) {
        value = value - (0 - this->Energy);
        Energy = 0;
        return (*this);
    }
    this->Energy = this->Energy + value;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Droid &other)
{
    os << "Droid '" << other.getId() << "', " << other.getStatus() << ", " << other.getEnergy();
    return (os);
}