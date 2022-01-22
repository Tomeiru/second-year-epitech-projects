/*
** EPITECH PROJECT, 2022
** Day7
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    _serial = serial;
}

KoalaBot::KoalaBot()
{
    _serial = "Bob-01";
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms& part)
{
   _arm = part;
}

void KoalaBot::setParts(const Legs& part)
{
    _leg = part;
}

void KoalaBot::setParts(const Head& part)
{
   _head = part;
}

void KoalaBot::swapParts(Arms& part)
{
    Arms copy =_arm;

   _arm = part;
    part =_arm;
}

void KoalaBot::swapParts(Legs& part)
{
    Legs copy = _leg;

    _leg = part;
    part = _leg;
}

void KoalaBot::swapParts(Head& part)
{
    Head copy = _head;

    _head = part;
    part = _head;
}

void KoalaBot::informations(void) const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arm.informations();
    _leg.informations();
    _head.informations();
}

bool KoalaBot::status(void) const
{
    if (_arm.isFunctional() == true && _leg.isFunctional() == true && _head.isFunctional() == true)
        return (true);
    return (false);
}