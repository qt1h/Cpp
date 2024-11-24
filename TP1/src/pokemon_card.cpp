#include "pokemon_card.h"
#include "energy_card.h"

#include <iostream>
#include <stdexcept>

PokemonCard::PokemonCard(const std::string& pokemonName, const std::string& pokemonType, const std::string& familyName,
                         unsigned int evolutionLevel, unsigned int maxHP, int cout1, const std::string& desc1, int dmg1,
                         int cout2, const std::string& desc2, int dmg2)
    : Card(pokemonName), pokemonType(pokemonType), familyName(familyName), evolutionLevel(evolutionLevel), maxHP(maxHP),
      hp(maxHP), energyActualCost(0) {
    if (cout1 < 0 || dmg1 < 0 || cout2 < 0 || dmg2 < 0) {
        throw std::invalid_argument("Costs and damage values cannot be negative.");
    }

    attacks.emplace_back(cout1, dmg1, desc1, 0);
    attacks.emplace_back(cout2, dmg2, desc2, 0);
}

bool PokemonCard::attachEnergy(const EnergyCard* energyCard) {
    if (energyCard && energyCard->getEnergyType() == pokemonType) {
        energyActualCost++;
        return true;
    }
    return false;
}

bool PokemonCard::attack(unsigned int attackNumber, PokemonCard* target, Player* player, Player* opponent) {
    if (attackNumber >= attacks.size() || !target) {
        std::cout << "Only 2 attacks exist.\n";
        return false; // Invalid attack number or target
    }

    auto& attack = attacks[attackNumber];
    int cost = std::get<0>(attack);
    int damage = std::get<1>(attack);

    if (energyActualCost < cost) {
        std::cout << "Not enough energy to perform the attack.\n";
        return false;
    }

    std::cout << player->getPlayerName() << " attacking " << opponent->getPlayerName() 
              << "'s Pokemon " << target->getName()
              << " with the Pokemon " << getName() 
              << " with its attack: " << std::get<2>(attack) << "\n";

    target->damage(damage,opponent);
    return true;
}

void PokemonCard::damage(int damage,Player* opponent) {
    if (damage < 0) return; // Damage can't be negative
    hp -= damage;

    if (hp < 0) {
        std::cout << getName() << " has fainted.\n";
    } else {
        std::cout << "Reducing " <<  damage << " from " << opponent->getPlayerName() << "'s Pokemon's HP\n";
        std::cout << "Pokemon " << getName() << " is still alive \n";
    }
}

void PokemonCard::heal() {
    hp = maxHP;
    //std::cout << getName() << " has been fully healed.\n";
}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << getName() << ", Type: " << pokemonType << ", Evolution Level: " \
    << evolutionLevel << " of the family \""<< familyName<< ", HP: "<<hp<<"\"\n";

    std::cout << "Attacks:\n";
    for (size_t i = 0; i < attacks.size(); ++i) {
        const auto& attack = attacks[i];
       
        std::cout << "Attack #" << i << ":\n" \
                  << "Attack Cost: " << std::get<0>(attack) << "\n" \
                  << "Attack current energy storage: " << energyActualCost << "\n" \
                  << "Attack description: " << std::get<2>(attack) << "\n" \
                  << "Attack damage: "<< std::get<1>(attack) << "\n";
                  
    }
}


//TODO CLEAN
// void PokemonCard::get_pokemonType()
// {
//     //return pokemonType
// }

void PokemonCard::get_familyName()
{
}

void PokemonCard::get_attackDescription()
{
}
