// TODO standard classes to be tested should be defined
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <random>
#include <time.h>

class Card{

public:
Card(void);
~Card();
int getVal();
int getSuit();
bool setVal(int val);
bool setSuit(int val);
Card(const Card &c);


protected:
    int m_suit;
    int m_val;
    //suit is an int val just to keep things simple
    //m_suit can have 4 values, 1 = Spade 2 = Club 3 = Hearts 4 = Diamonds
    //meant to be more of a way to keep track of that data
};

class Deck{

public:
Deck(void);
virtual ~Deck();
Card *removeCard();
bool addCard(Card * cardToBeAdded);
void shuffleDeck();
int deckSize();
Deck(const Deck &d);

protected:
    std::list<Card *> m_Deck;
};
class Player{

public:
    Player(void);
    virtual ~Player();
    Player(const Player &p);
    bool addToHand(Card * newCard);
    Card* removeFromHand(int valToBeRemoved);
    int getHandSize();
    bool isEmpty();
    bool showHand();
    bool showStack();
    bool newHand();
    bool addToStack(Card * cardToBeAdded);
    void setName(std::string nameIn);
    std::string getName();
    Card* nukeHand();

private:
    std::list<Card *> m_Hand;
    std::list<Card *> m_WinStack;
    std::string name;
    int handSize;
};