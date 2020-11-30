#include "SomeThing.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <random>
#include <time.h>



int main(){
    std::cout<<"The rules are:"<<
    std::endl<<"1.	Each player must end their turn with 5 or fewer cards in their hand."<<
    std::endl<<"2.	At the start of their turn, they must draw a card from the top of the community pile of cards"<<
    std::endl<<"3.	The player then tries to make a stack from their hand in order from 1 to 13 during their turn."<<
    std::endl<<"4.	During their turn, the player may draw additional cards from the top of the pile so long as the total cards in their hand don’t exceed 6."<<
    std::endl<<"5.	When the player cannot place any more cards in their stack and they have 6 cards in their hand, they must discard 1 card to the bottom of the community pile and then player  goes."<<
    std::endl<<"6.	A player may choose to discard all of their cards to the bottom of the community pile and start with 5 new cards at the beginning of their turn.  This action ends their turn without them getting a chance to draw a 6th card or discard any cards to their stack."<<
    std::endl<<"7.	The game is played with a standard playing card deck (Ace = 1, Jack = 11, Queen =12, King = 13).  The suits are not important for the purposes of determining rule 3 (i.e. a 4 of any suit can go on top of a 3 of any suit)."<<
    std::endl<<"8.  Moves: P=Play Card, N=New Set";
    Deck New_deck;
    int DEBUGVAL = 0;
    if(DEBUGVAL == 0){
        New_deck.shuffleDeck(); 
    }
    
    Player player1;
    Player player2;
    Player player3;
    int player_to_start = 1;
    int coin= 0;
    char move;
    int c;
    int sizeOfHand;
    char draw;
    std::string name;
    Card* card;

    for( int i=0; i<5; i++){
        player1.addToHand(New_deck.removeCard());
    }
    for( int i=0; i<5; i++){
        player2.addToHand(New_deck.removeCard());
    }
    for( int i=0; i<5; i++){
        player3.addToHand(New_deck.removeCard());
    }
    while (coin == 0){
        std::cout<<"Player : "<<player_to_start<<" : Your turn begins..."<<std::endl;
        //Uses switching and cases to sort through the different players (1->3)
        switch (player_to_start){
            case 1:
                std::cout << "Player 1, START!" << std::endl << std::endl;
                player1.showHand();
                player1.showStack();
                std::cout << std::endl;
                while(move != 'D'){
                    std::cout<<"What is your move (P / N): "<<std::endl;
                    std::cin>>move;
                    //play
                    if(move == 'P'){
                        while((player1.getHandSize()>5)||(move!='N')){
                            if(player1.getHandSize() <= 5){
                                std::cout<<"Would you like to draw a card? Y/N?"<<std::endl;
                                std::cin>>draw;
                                if(draw == 'Y'){
                                    std::cout<<"Picking up card"<<std::endl;
                                    player1.addToHand(New_deck.removeCard());
                                }
                            }
                            player1.showHand();
                            std::cout<<"What card do you want to play? "<<std::endl;
                            std::cin >> c;
                            card = player1.removeFromHand(c);
                            if(player1.addToStack(card)==true){//Added a true statement, not sure if it already checks for it or not
                                std::cout << "Nice Play!" << std::endl;
                                if(c==13){
                                    coin=1;
                                }
                            }else{
                                std::cout << "Oof! Not quite! Try again!" << std::endl;
                                player1.addToHand(card);
                            }
                            std::cout<<"Do you have more cards to play? (Y/N)"<<std::endl;
                            std::cin>>move;
                            if(move == 'N'){
                                if(player1.getHandSize() == 6){
                                player1.showHand();
                                std::cout << "Your hand is at 6 cards, please choose a card to discard back to the community pile:" << std::endl;
                                std::cin>>c;
                                New_deck.addCard(player1.removeFromHand(c));
                                }    
                            break;
                            }
                        }
                        break; //break as it shoudl end the player's turn
                    }
                    //New hand
                    if(move == 'N'){
                        sizeOfHand = player1.getHandSize();
                        for(int i = 0; i < sizeOfHand; i++){
                            New_deck.addCard(player1.nukeHand());
                        }
                        for(int i=0; i<5; i++){
                            player1.addToHand(New_deck.removeCard());
                        }
                        std::cout<<"Player 1 Turn Ended."<<std::endl;
                        break;
                    }
                }
            case 2:
            std::cout << "Player 2, START!" << std::endl << std::endl;
                player2.showHand();
                player2.showStack();
                std::cout << std::endl;
                while(move != 'D'){
                    std::cout<<"What is your move (P / N): "<<std::endl;
                    std::cin>>move;
                    //play
                    if(move == 'P'){
                        while((player2.getHandSize()>5)||(move!='N')){
                            if(player2.getHandSize() <= 5){
                                std::cout<<"Would you like to draw a card? Y/N?"<<std::endl;
                                std::cin>>draw;
                                if(draw == 'Y'){
                                    std::cout<<"Picking up card"<<std::endl;
                                    player2.addToHand(New_deck.removeCard());
                                }
                            }
                            player2.showHand();
                            player2.showStack();
                            std::cout << std::endl;
                            std::cout<<"What card do you want to play? "<<std::endl;
                            std::cin >> c;
                            card = player2.removeFromHand(c);
                            if(player2.addToStack(card)){
                                std::cout << "Nice Play!" << std::endl;
                                if(c==13){
                                    coin=2;
                                }
                            }else{
                                std::cout << "Oof! Not quite! Try again!" << std::endl;
                                player2.addToHand(card);
                            }
                            std::cout<<"Do you have more cards to play? (Y/N)"<<std::endl;
                            std::cin>>move;
                            if(move == 'N'){
                                if(player2.getHandSize() == 6){
                                player2.showHand();
                                std::cout << "Your hand is at 6 cards, please choose a card to discard back to the community pile:" << std::endl;
                                std::cin>>c;
                                New_deck.addCard(player2.removeFromHand(c));

                                }
                            break;
                            }
                        }
                        break; //break as it shoudl end the player's turn
                    }
                    //New hand
                    if(move == 'N'){
                        sizeOfHand = player2.getHandSize();
                        for(int i = 0; i < sizeOfHand; i++){
                            New_deck.addCard(player2.nukeHand());
                        }
                        for(int i=0; i<5; i++){
                            player2.addToHand(New_deck.removeCard());
                        }
                        std::cout<<"Player 2 Turn Ended."<<std::endl;
                        break;
                    }
                }
            case 3:
                std::cout << "Player 3, START!" << std::endl << std::endl;
                player3.showHand();
                player3.showStack();
                std::cout << std::endl;
                while(move != 'D'){
                    std::cout<<"What is your move (P / N): "<<std::endl;
                    std::cin>>move;
                    //play
                    if(move == 'P'){
                        while((player3.getHandSize()>5)||(move!='N')){
                            if(player3.getHandSize() <= 5){
                                std::cout<<"Would you like to draw a card? Y/N?"<<std::endl;
                                std::cin>>draw;
                                if(draw == 'Y'){
                                    std::cout<<"Picking up card"<<std::endl;
                                    player3.addToHand(New_deck.removeCard());
                                }
                            }
                            player3.showHand();
                            player3.showStack();
                            std::cout << std::endl;
                            std::cout<<"What card do you want to play? "<<std::endl;
                            std::cin >> c;
                            card = player3.removeFromHand(c);
                            if(player3.addToStack(card)){
                                std::cout << "Nice Play!" << std::endl;
                                if(c==13){
                                    coin=3;
                                }
                            }
                            else{
                                std::cout << "Oof! Not quite! Try again!" << std::endl;
                                player3.addToHand(card);
                            }
                            std::cout<<"Do you have more cards to play? (Y/N)"<<std::endl;
                            std::cin>>move;
                        }
                        if(move == 'N'){
                            if(player3.getHandSize() == 6){
                            player3.showHand();
                            std::cout << "Your hand is at 6 cards, please choose a card to discard back to the community pile:" << std::endl;
                            std::cin>>c;
                            New_deck.addCard(player3.removeFromHand(c));

                            }
                            break;
                        }
                        break; //break as it shoudl end the player's turn
                    }
                    
                    //New hand
                    if(move == 'N'){
                        sizeOfHand = player3.getHandSize();
                        for(int i = 0; i < sizeOfHand; i++){
                            New_deck.addCard(player3.nukeHand());
                        }
                        for(int i=0; i<5; i++){
                            player3.addToHand(New_deck.removeCard());
                        }
                        std::cout<<"Player 3 Turn Ended."<<std::endl;
                        break;
                    }
                }
        }
    }
    player_to_start++;
    if(player_to_start>3){
        player_to_start=1;
    }
    

    if(coin == 1){
        std::cout<<"CONGRATS PLAYER 1 ON WINNING!"<<std::endl;
    }
    if(coin == 2){
        std::cout<<"CONGRATS PLAYER 2 ON WINNING!!"<<std::endl;
    }
    if(coin == 3){
        std::cout<<"CONGRATS PLAYER 3 ON WINNING!!!"<<std::endl;
    }
    
return 0;
}
