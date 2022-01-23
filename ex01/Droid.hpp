/*
** EPITECH PROJECT, 2022
** Day8
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include "DroidMemory.hpp"

class Droid {
    public:
        Droid(std::string);
        Droid(const Droid &other);
        ~Droid();
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string getStatus() const;
        void setId(std::string);
        void setEnergy(size_t);
        void setStatus(std::string *);
        bool operator==(const Droid &other) const;
        bool operator!=(const Droid &other) const;
        void operator=(const Droid &other);
        Droid &operator<<(size_t &value);
    private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
        DroidMemory *BattleData;
};

std::ostream &operator<<(std::ostream &os, const Droid &other);


#endif /* !DROID_HPP_ */
