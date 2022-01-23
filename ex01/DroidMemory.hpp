/*
** EPITECH PROJECT, 2022
** Day8
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();
        size_t getFingerprint() const;
        size_t getExp() const;
        void setFingerprint(size_t Fingerprint);
        void setExp(size_t Exp);
        DroidMemory operator<<(const DroidMemory &other);
        DroidMemory operator>>(DroidMemory &other) const;
        DroidMemory operator+=(const DroidMemory &other);
        DroidMemory operator+=(const size_t value);
        DroidMemory operator+(const DroidMemory &other) const;
        DroidMemory operator+(const size_t value) const;
    private:
        size_t Fingerprint;
        size_t Exp;
};

std::ostream &operator<<(std::ostream &os, const DroidMemory &other);


#endif /* !DROIDMEMORY_HPP_ */
