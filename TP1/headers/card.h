#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

class Card{
    protected : 
        std::string cardName;

    public :
        Card(const std::string& name);
        virtual ~Card() = default;
        
        std::string getName() const;
        virtual void displayInfo() const = 0;

};

#endif