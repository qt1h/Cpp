#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H
#include "card.h"
#include "energy_card.h"
#include <string.h>
#include <tuple>
#include <vector>
#include <string>
#include "player.h"

class Player; // Forward declaration

class PokemonCard : public Card
{
private:
    std::string pokemonType, familyName, attackDescription;
    unsigned int evolutionLevel, maxHP, energyCost, energyActualCost, damages;
    int hp;                                                      // if <0 the pokemon dies
    std::vector<std::tuple<int, int, std::string, int>> attacks; // 2 attacks

public:
    PokemonCard(const std::string &pokemonName, const std::string &pokemonType, const std::string &familyName,
                unsigned int evolutionLevel, unsigned int maxHP, int cout1, const std::string &desc1, int dmg1,
                int cout2, const std::string &desc2, int dmg2);

    bool attachEnergy(const EnergyCard *energyCard);
    bool attack(unsigned int attackNumber, PokemonCard *target, Player *player, Player *opponent);
    void damage(int damage, Player *opponent);
    void heal();
    void displayInfo() const override;
    // string& get_pokemonType(); can be useful for future implementations
};

#endif
