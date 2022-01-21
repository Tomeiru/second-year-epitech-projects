/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int new_id)
{
    id = new_id;
    working = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string report)
{
    std::ifstream file(report);
    auto drug = std::ostringstream{};
    std::string patient = report;

    if (patient.find(".report") == std::string::npos || !file.is_open())
        return("");
    patient.resize(report.size() - 7);
    drug << file.rdbuf();
    std::cout << "Nurse " << id << ": Kreog! Mr." << patient << " needs a " << drug.str() << "!" << std::endl;
    return (drug.str());
}

void KoalaNurse::timeCheck(void)
{
    if (working == false) {
        working = true;
        std::cout << "Nurse " << id << ": Time to get to work!" << std::endl;
        return;
    }
    working = false;
    std::cout << "Nurse " << id << ": Time to go home to my eucalyptus forest!" << std::endl;
}

int KoalaNurse::getID(void)
{
    return (id);
}
