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

DroidMemory Droid::getBattleData() const
{
    return (*BattleData);
}

void Droid::setId(std::string newId)
{
    Id = newId;
}

void Droid::setEnergy(size_t newEnergy)
{
    if (newEnergy > 100) {
        Energy = 100;
        return;
    }
    Energy = newEnergy;
}

void Droid::setStatus(std::string *newStatus)
{
    delete Status;
    Status = newStatus;
}

void Droid::setBattleData(DroidMemory *newBattleData)
{
    delete BattleData;
    BattleData = newBattleData;
}

bool Droid::operator==(const Droid &other) const
{
    if (this->getStatus().compare(other.getStatus()) == 0)
        return (true);
    return (false);
}

bool Droid::operator!=(const Droid &other) const
{
    if (this->getStatus().compare(other.getStatus()) == 0)
        return (false);
    return (true);
}

void Droid::operator=(const Droid &other)
{
    if (Status)
        delete Status;
    this->Id = other.Id;
    this->Status = new std::string(*other.Status);
    this->BattleData = other.BattleData;
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

bool Droid::operator()(const std::string *task, size_t experience)
{
    std::string status;

    if (Energy < 10) {
        this->setStatus(new std::string("Battery Low"));
        this->Energy = 0;
        delete(task);
        return (false);
    }
    this->Energy = Energy - 10;
    if (BattleData->getExp() >= experience) {
        BattleData->setExp(BattleData->getExp() + (experience / 2));
        this->setStatus(new std::string(status.append(*task).append(" - Completed!")));
        delete(task);
        return (true);
    }
    BattleData->setExp(BattleData->getExp() + experience);
    this->setStatus(new std::string(status.append(*task).append(" - Failed!")));
    delete(task);
    return (false);
}