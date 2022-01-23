/*
** EPITECH PROJECT, 2022
** Day8
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    Exp = 0;
    Fingerprint = random();
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerprint() const
{
    return (Fingerprint);
}

size_t DroidMemory::getExp() const
{
    return (Exp);
}

void DroidMemory::setFingerprint(size_t newFingerprint)
{
    Fingerprint = newFingerprint;
}

void DroidMemory::setExp(size_t newExp)
{
    Exp = newExp;
}

DroidMemory DroidMemory::operator<<(const DroidMemory &other)
{
    Exp = Exp + other.getExp();
    Fingerprint = Fingerprint ^ other.getFingerprint();
    return (*this);
}

DroidMemory DroidMemory::operator>>(DroidMemory &other) const
{
    other.setExp(other.getExp() + Exp);
    other.setFingerprint(other.getFingerprint() ^ Fingerprint);
    return (other);
}

DroidMemory DroidMemory::operator+=(const DroidMemory &other)
{
    Exp = Exp + other.getExp();
    Fingerprint = Fingerprint ^ other.getFingerprint();
    return (*this);
}

DroidMemory DroidMemory::operator+=(const size_t value)
{
    Exp = Exp + value;
    Fingerprint = Fingerprint ^ value;
    return (*this);
}

DroidMemory DroidMemory::operator+(const DroidMemory &other) const
{
    DroidMemory ret;

    ret.setExp(Exp + other.getExp());
    ret.setFingerprint(Fingerprint ^ other.getFingerprint());
    return (ret);
}

DroidMemory DroidMemory::operator+(const size_t value) const
{
    DroidMemory ret;

    ret.setExp(Exp + value);
    ret.setFingerprint(Fingerprint ^ value);
    return (ret);
}

std::ostream &operator<<(std::ostream &os, const DroidMemory &other)
{
    os << "DroidMemory '" << other.getFingerprint() << "', " << other.getExp();
    return (os);
}