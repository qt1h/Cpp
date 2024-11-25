#include "trainer_card.h"
#include <iostream>

TrainerCard::TrainerCard(const std::string &cardName, const std::string &trainerEffect)
    : Card(cardName), trainerEffect(trainerEffect) {}

void TrainerCard::displayInfo() const
{
    std::cout << "Trainer Card - Name : " << getName() << ", Effect: " << trainerEffect << "\n";
}

std::string TrainerCard::get_trainerEffect()
{
    return trainerEffect;
}
