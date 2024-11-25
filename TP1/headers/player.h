#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "pokemon_card.h"
#include "trainer_card.h"
#include "energy_card.h"
#include <string.h>
#include <tuple>
#include <vector>

class PokemonCard; // Forward declaration (because of circular inclusion)

class Player
{
private:
    std::string playerName;
    std::vector<Card *> benchCards;
    std::vector<PokemonCard *> actionCards;

public:
    Player(const std::string &playerName);
    ~Player() = default;
    const std::vector<Card *> &getBenchCards() const;

    void addCardToBench(Card *card);
    void activatePokemonCard(unsigned int card);
    void attachEnergyCard(int benchIndex, int actionIndex);
    void displayBench() const;
    void displayAction() const;
    void attack(int pokemonIndex, int attackIndex, Player &opponent, int opponentPokemonIndex);
    void useTrainer(int actionIndex);
    std::string getPlayerName() const;
};

#endif
