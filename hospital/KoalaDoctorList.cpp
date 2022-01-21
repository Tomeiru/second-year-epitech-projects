/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** KoalaDoctorList
*/

#include "KoalaDoctorList.hpp"


KoalaDoctorList::KoalaDoctorList(KoalaDoctor *new_patient)
{
    patient = new_patient;
    next = nullptr;
    prev = nullptr;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd(void)
{
    if (next == nullptr) {
        return (true);
    }
    return (false);
}

void KoalaDoctorList::append(KoalaDoctorList *node)
{
    KoalaDoctorList *temp = this;

    for ( ; temp->isEnd() == false; temp = temp->next);
    node->prev = temp;
    temp->next = node;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *temp = this;

    if (name.compare(temp->patient->getName()) == 0)
        return (temp->patient);
    while (temp != nullptr) {
        if (name.compare(temp->patient->getName()) == 0) {
            return (temp->patient);
        }
        temp = temp->next;
    }
    return (nullptr);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *node_to_remove)
{
    KoalaDoctorList *temp;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    KoalaDoctorList *temp = this;
    KoalaDoctorList *temp_second;

    if (name.compare(temp->patient->getName()) == 0) {
        temp = temp->next;
        temp->prev = nullptr;
        return (temp);
    }
    while (temp != nullptr) {
        if (name.compare(temp->patient->getName()) == 0)
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

void KoalaDoctorList::dump(void)
{
    KoalaDoctorList *temp = this;
    if (this == nullptr)
        return;
    std::cout << "Doctors: ";
    while (temp->next != nullptr) {
        if (temp->patient == nullptr)
            std::cout << "[nullptr]";
        else
            std::cout << temp->patient->getName();
        std::cout << ", ";
        temp = temp->next;
    }
    if (temp->patient == nullptr)
        std::cout << "[nullptr]";
    else
        std::cout << temp->patient->getName();
    std::cout << "." << std::endl;
}