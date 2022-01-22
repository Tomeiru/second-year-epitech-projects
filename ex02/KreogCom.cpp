/*
** EPITECH PROJECT, 2022
** PM
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial, KreogCom *next_node) : m_serial(serial)
{
    m_x = x;
    m_y = y;
    next = next_node;
    first = false;
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

KreogCom::KreogCom(int x, int y, int serial) : m_serial(serial)
{
    m_x = x;
    m_y = y;
    next = nullptr;
    first = true;
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    if (first == true)
        std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

KreogCom *KreogCom::createNewCom(int x, int y, int serial)
{
    KreogCom *newCom = new KreogCom(x, y, serial, this->next);

    return (newCom);
}

void KreogCom::addCom(int x, int y, int serial)
{
    next = this->createNewCom(x, y, serial);
}

void KreogCom::removeCom(void)
{
    KreogCom *temp;

    if (this->next == nullptr)
        return;
    temp = this->next;
    std::cout << "KreogCom " << this->getCom()->m_serial << " shutting down" << std::endl;
    this->next = this->next->next;
    delete(temp);
}

KreogCom *KreogCom::getCom() const
{
    return (this->next);
}

void KreogCom::ping(void) const
{
    std::cout << "KreogCom " << m_serial << " currently at " << m_x << " " << m_y << std::endl;
}

void KreogCom::locateSquad(void) const
{
    if (first != true)
            this->ping();
    if (this->next != nullptr)
        this->next->locateSquad();
    if (first == true)
        this->ping();
}