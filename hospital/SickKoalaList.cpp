/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"


SickKoalaList::SickKoalaList(SickKoala *new_patient)
{
    patient = new_patient;
    next = nullptr;
    prev = nullptr;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd(void)
{
    if (next == nullptr) {
        return (true);
    }
    return (false);
}

void SickKoalaList::append(SickKoalaList *node)
{
    SickKoalaList *temp = this;

    for ( ; temp->isEnd() == false; temp = temp->next);
    node->prev = temp;
    temp->next = node;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *temp = this;

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

SickKoalaList *SickKoalaList::remove(SickKoalaList *node_to_remove)
{
    SickKoalaList *temp;

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

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList *temp = this;
    SickKoalaList *temp_second;

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

SickKoala *SickKoalaList::getContent(void)
{
    return (this->patient);
}

SickKoalaList *SickKoalaList::getNext(void)
{
    if (this->next == nullptr)
        return (nullptr);
    return (this->next);
}

void SickKoalaList::dump(void)
{
    SickKoalaList *temp = this;
    if (this == nullptr)
        return;
    std::cout << "Patients: ";
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

int main(void)
{
    SickKoala Josh("Josh");
    SickKoala shoJ("hsoJ");
    SickKoala a("a");
    SickKoala b("b");
    SickKoala c("c");
    SickKoala d("d");

    SickKoalaList list(&Josh);
    SickKoalaList node(&shoJ);
    SickKoalaList B(nullptr);
    SickKoalaList A(&b);
    SickKoalaList C(&c);
    SickKoalaList D(&d);
    SickKoalaList *listo;
    list.append(&node);
    list.append(&A);
    list.append(&B);
    list.append(&C);
    list.append(&D);
    listo = list.remove(&A);

    listo->dump();
}