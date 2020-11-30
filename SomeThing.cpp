#include "SomeThing.h"

Card::Card(){
    m_suit = 0;
    m_val = 0;
}
Card::~Card(){}

Card::Card(const Card &c){
    std::cout<<"    BAD!!!! Copy Coonstructor being called.  I shouldn't really be callled!!!"<<std::endl;
}

bool Card::setSuit(int val){
    m_suit = val;
    return true;
}
bool Card::setVal(int val){
    m_val = val;
    return true;
}
int Card::getVal(){
    return m_val;
}
int Card::getSuit(){
    return m_suit;
}

Deck::Deck(){
    Card * tempCard;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            tempCard = new Card;
            tempCard->setSuit(i);
            tempCard->setVal(j);
            m_Deck.push_front(tempCard);
        }
    }
}
Deck::~Deck(){
    m_Deck.clear();

}
Deck::Deck(const Deck &d){
    std::cout<<"    BAD!!!! Copy Coonstructor being called.  I shouldn't really be callled!!!"<<std::endl;
}
void Deck::shuffleDeck(){
    Card * holdingArray[52] = {NULL};
    Card * newArray[52] = {NULL};
    int locationArray[52];
    int randVal = 0;
    for(int i=0; i < 52; i++){
        holdingArray[i] = m_Deck.front();
        m_Deck.pop_front();
    }
    for(int i=0; i < 52; i++){
        locationArray[i] = i;
    }
    srand(time(NULL));
    std::random_shuffle(std::begin(locationArray),std::end(locationArray));
    for(int i=0; i < 52; i++){
        newArray[i] = holdingArray[locationArray[i]];
    }
    for(int k=0; k < 52; k++){
        m_Deck.push_front(newArray[k]);
    }
}

Card * Deck::removeCard(){
    Card * tempCard;
    tempCard = m_Deck.front();
    m_Deck.pop_front();
    return tempCard;
}
bool Deck::addCard(Card * cardToBeAdded){
    m_Deck.push_back(cardToBeAdded);
    return true;
}
int Deck::deckSize(){
    return m_Deck.size();
}


Player::Player(){};
Player::~Player(){
    std::cout << "Deleting player: " << name << std::endl;
}
Player::Player(const Player &p){
    std::cout<<"    BAD!!!! Copy Coonstructor being called.  I shouldn't really be callled!!!"<<std::endl;
}
int Player::getHandSize(){
    return m_Hand.size();
}
bool Player::addToHand(Card * newCard){
    m_Hand.push_back(newCard);
    return true;
}


bool Player::isEmpty(){
    if(m_Hand.size() == 0){
        return true;
    }else{
        return false;
    }
}


bool Player::showHand(){
    Card * array[6];
    int handSize = m_Hand.size();
    if(isEmpty()==true){
        return false;
    }
    else{
        std::cout<<"Hand: ";
        for(int i=0 ; i< handSize; i++){
            array[i] = m_Hand.front();
            m_Hand.pop_front();
            std::cout << array[i]->getVal() << " ";
        }
        for(int i=0 ; i< handSize; i++){
            m_Hand.push_back(array[i]);
        }
    }
}
bool Player::showStack(){
    Card * array[6];
    int winSize = m_WinStack.size();
    if(isEmpty()==true){
        return false;
    }
    else{
        std::cout<<"Stack: ";
        for(int i=0 ; i< winSize; i++){
            array[i] = m_WinStack.front();
            m_WinStack.pop_front();
            std::cout << array[i]->getVal() << " ";
        }
        for(int i=0 ; i< winSize; i++){
            m_WinStack.push_back(array[i]);
        }
    }
}
//Ill Just solve it in the main program.
//https://www.geeksforgeeks.org/print-stack-elements-from-bottom-to-top/ <found some code to recurssively go through a stack while preserving its stack>

Card * Player::removeFromHand(int valToBeRemoved){
    Card * tempCard = new Card;
    Card * array[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
    int cardPos = 0;
    bool foundCard = false;
    int sizeOfHand = m_Hand.size();
    for(int i = 0; i < sizeOfHand-1; i++){
        array[i] = m_Hand.front();
        m_Hand.pop_front();
    }
    while(true){
        if(valToBeRemoved == array[cardPos]->getVal()){
            break;
        }
        cardPos++;
        if(cardPos == 6){
            break;
        }
    }
    tempCard = array[cardPos];
    for(int i = 0; i <= sizeOfHand - 1; i++){
        if((tempCard != array[i]) && (array[i] != NULL)){
            m_Hand.push_front(array[i]);
        }
    }
    return tempCard;
}
Card * Player::nukeHand(){
    Card * tempCard;
    tempCard = m_Hand.front();
    m_Hand.pop_front();
    return tempCard;
}
bool Player::addToStack(Card * cardToBeAdded){
    Card * StackCardPtr = m_WinStack.front();
    int valOfCard = cardToBeAdded->getVal();
    int valOfTopOfStack = 0;
    if((m_WinStack.empty()) && (valOfCard == 1)){
        valOfTopOfStack = 0;
    }else if(StackCardPtr == NULL){
        valOfTopOfStack = -1;
    }else{
        valOfTopOfStack = StackCardPtr->getVal();
    }
    if((valOfTopOfStack+1) != valOfCard){
        return false;
    }else{
        m_WinStack.push_front(cardToBeAdded);
        return true;
    }
}
void Player::setName(std::string nameIn){
    name = nameIn;
}
std::string Player::getName(){
    return name; //streching for a sec
}
