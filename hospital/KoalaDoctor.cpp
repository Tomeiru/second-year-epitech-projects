/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    doc_name = name;
    std::cout << "Dr." << name << ": I'm Dr." << name << "! How do you kreog?" << std::endl;
    working = false;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string filename;
    std::string drug_list[5] = {
        "Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"
    };
    auto drug_num = random() % 5;

    filename.append(patient->getName());
    filename.append(".report");
    std::cout << "Dr." << doc_name << ": So what's goerking you Mr." << patient->getName() << "?" << std::endl;
    patient->poke();
    std::ofstream outfile (filename);
    outfile << drug_list[drug_num];
    outfile.close();
}

void KoalaDoctor::timeCheck(void)
{
    if (working == false) {
        working = true;
        std::cout << "Dr." << doc_name << ": Time to get to work!" << std::endl;
        return;
    }
    working = false;
    std::cout << "Dr." << doc_name << ": Time to go home to my eucalyptus forest!" << std::endl;
}