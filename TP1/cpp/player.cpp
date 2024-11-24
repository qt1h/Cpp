#include <iostream>
#include "player.h"

Player::Player(const std::string &playerName) :  playerName(playerName)
{
}

const std::vector<Card*>& Player::getBenchCards() const {
    return benchCards;
}

void Player::addCardToBench(Card* card) {
   benchCards.push_back(card); // Add the card to the bench (limit can be added if necessary)
}

void Player::activatePokemonCard(unsigned int card) {
    if (card < benchCards.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(benchCards[card]);
        if (pokemonCard) {
            actionCards.push_back(pokemonCard);
            benchCards.erase(benchCards.begin() + card);
            std::cout << playerName << " is activating a Pokemon Card: "<< pokemonCard->getName() << "\n";
        } else {
            std::cout << "The selected card is not a Pokemon card.\n";
        }
    } else {
        std::cout << "Invalid card index.\n";
    }
}

void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    if (benchIndex >= 0 && benchIndex < static_cast<int>(benchCards.size()) &&
        actionIndex >= 0 && actionIndex < static_cast<int>(actionCards.size())) {
        
        // Check if the card is an EnergyCard
        Card* card = benchCards[benchIndex];
        if (EnergyCard* energyCard = dynamic_cast<EnergyCard*>(card)) {
            actionCards[actionIndex]->attachEnergy(energyCard);
            benchCards.erase(benchCards.begin() + benchIndex);
            std::cout << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType() << " to the Pokemon " << actionCards[actionIndex]->getName() << "\n";
        } else {
            std::cout << "The selected card is not an Energy card.\n";
        }
    } else {
        std::cout << "Invalid index for attaching the Energy card.\n";
    }
}

void Player::displayBench() const {
    std::cout << "Bench cards " << "\033[34mfor\033[0m" << " Player " << playerName << " :\n"; //color to check the output faster
    for (size_t i = 0; i < benchCards.size(); ++i) {
        
        // Identify the type of card
        if (PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(benchCards[i])) {
            pokemonCard->displayInfo();
        } else if (TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[i])) {
            trainerCard->displayInfo();
        } else { // Energy card
            dynamic_cast<EnergyCard*>(benchCards[i])->displayInfo();
        }
    }
}

void Player::displayAction() const {
    std::cout << "Action cards \033[34mfor\033[0m Player " << playerName << ":\n";
    for (size_t i = 0; i < actionCards.size(); ++i) {
        // Identify the type of card
        if (PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(actionCards[i])) {
            pokemonCard->displayInfo();
        } else if (TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(actionCards[i])) {     
            trainerCard->displayInfo();
        } else { // Energy card
            dynamic_cast<EnergyCard*>(actionCards[i])->displayInfo();
        }
    }
}

void Player::attack(int pokemonIndex, int attackIndex, Player& opponent, int opponentPokemonIndex) {
    if (pokemonIndex >= 0 && pokemonIndex < static_cast<int>(actionCards.size()) &&
        opponentPokemonIndex >= 0 && opponentPokemonIndex < static_cast<int>(opponent.actionCards.size())) {
        
        PokemonCard* attacker = dynamic_cast<PokemonCard*>(actionCards[pokemonIndex]);
        PokemonCard* target = dynamic_cast<PokemonCard*>(opponent.actionCards[opponentPokemonIndex]);
        
        if (attacker && target) {
            attacker->attack(attackIndex, target, this, &opponent);
        } else {
            std::cout << "The attack requires two valid Pokemon cards.\n";
        }
    } else {
        std::cout << "Invalid index for the attack.\n";
    }
}

void Player::useTrainer(int benchIndex) {
    if (benchIndex >= 0 && benchIndex < static_cast<int>(benchCards.size())) {
        Card* card = benchCards[benchIndex];
        
        if (TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(card)) {
            std::cout << playerName << " is using the Trainer card to \"" <<
            trainerCard->get_trainerEffect() << "\"\n"; //that way we can have other effects if needed

            // Heal all Pokémon in action cards
            for (PokemonCard* pokemon : actionCards) {
                if (pokemon) {
                    pokemon->heal();
                }
            }
            benchCards.erase(benchCards.begin() + benchIndex); //deletes the trainer after being used

        } else {
            std::cout << "This is not a trainer card.\n";
        }
    } else {
        std::cout << "Invalid index to use a trainer card.\n";
    }
}

std::string Player::getPlayerName() const {
    return playerName;
}
