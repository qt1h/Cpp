#include "card.h"

Card::Card(const std::string& name) : cardName(name) {}

std::string Card::getName() const {
    return cardName;
}

