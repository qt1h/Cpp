#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H
#include "card.h"
#include <string.h>
#include <tuple>
#include <vector>

class TrainerCard : public Card {
    private :
        std::string trainerEffect; //heal all your action pokemon

    public :
        TrainerCard(const std::string& cardName, const std::string& trainerEffect);
        ~TrainerCard() = default;
        void displayInfo() const override;
        std::string get_trainerEffect();
};

#endif

