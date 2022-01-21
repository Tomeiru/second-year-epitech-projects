/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *new_patient)
{
    patient = new_patient;
    next = nullptr;
    prev = nullptr;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd(void)
{
    if (next == nullptr) {
        return (true);
    }
    return (false);
}

void KoalaNurseList::append(KoalaNurseList *node)
{
    KoalaNurseList *temp = this;

    for ( ; temp->isEnd() == false; temp = temp->next);
    node->prev = temp;
    temp->next = node;
}

KoalaNurse *KoalaNurseList::getFromID(int ID)
{
    KoalaNurseList *temp = this;

    if (ID == temp->patient->getID())
        return (temp->patient);
    while (temp != nullptr) {
        if (ID == temp->patient->getID()) {
            return (temp->patient);
        }
        temp = temp->next;
    }
    return (nullptr);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *node_to_remove)
{
    KoalaNurseList *temp;

    if (node_to_remove == nullptr)
        return (nullptr);
    if (node_to_remove->prev == nullptr) {
        node_to_remove = node_to_remove->next;
        node_to_remove->prev = nullptr;
        return (node_to_remove);
    }
    temp = node_to_remove->prev;
    if (node_to_remove->next == nullptr)
        temp->next = nullptr;
    else {
        temp->next = node_to_remove->next;
        node_to_remove->next->prev = temp;
    }
    while (temp->prev != nullptr)
        temp = temp->prev;
    return (temp);
}

KoalaNurseList *KoalaNurseList::removeFromID(int ID)
{
    KoalaNurseList *temp = this;
    KoalaNurseList *temp_second;

    if (ID == temp->patient->getID()) {
        temp = temp->next;
        temp->prev = nullptr;
        return (temp);
    }
    while (temp != nullptr) {
        if (ID == temp->patient->getID())
            break;
        temp = temp->next;
    }
    temp_second = temp->prev;
    if (temp->next == nullptr)
        temp_second->next = nullptr;
    else {
        temp_second->next = temp->next;
        temp->next->prev = temp_second;
    }
    while (temp_second->prev != nullptr)
        temp_second = temp_second->prev;
    return (temp_second);
}

void KoalaNurseList::dump(void)
{
    KoalaNurseList *temp = this;
    if (this == nullptr)
        return;
    std::cout << "Nurses: ";
    while (temp->next != nullptr) {
        if (temp->patient == nullptr)
            std::cout << "[nullptr]";
        else
            std::cout << temp->patient->getID();
        std::cout << ", ";
        temp = temp->next;
    }
    if (temp->patient == nullptr)
        std::cout << "[nullptr]";
    else
        std::cout << temp->patient->getID();
    std::cout << "." << std::endl;
}