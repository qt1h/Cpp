#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H
#include "card.h"
#include <string.h>
#include <tuple>
#include <vector>

class EnergyCard : public Card
{
private:
    std::string energyType;

public:
    EnergyCard(const std::string &energyType);
    ~EnergyCard() = default;

    std::string getEnergyType() const;
    void displayInfo() const override;
};

#endif
