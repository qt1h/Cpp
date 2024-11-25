#include "energy_card.h"
#include <iostream>

EnergyCard::EnergyCard(const std::string &energyType) : Card("Energy"), energyType(energyType) {}

std::string EnergyCard::getEnergyType() const
{
    return energyType;
}

void EnergyCard::displayInfo() const
{
    std::cout << "Energy Card: " << getName() << ", Type: " << energyType << std::endl;
}