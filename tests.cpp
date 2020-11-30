// tests.cpp
#include "SomeThing.h"
#include <gtest/gtest.h>


		
 		TEST(Card, ConstructionOfClass)
		{
			Card * randCard;
			randCard = new Card;
			ASSERT_EQ(0,randCard->getSuit());
			ASSERT_EQ(0,randCard->getVal());
		}
		TEST(Card,BasicSettingsTest)
		{	
			Card randCard;
			ASSERT_TRUE(randCard.setSuit(1));
			ASSERT_TRUE(randCard.setVal(1));
			ASSERT_EQ(1, randCard.getVal());
			ASSERT_EQ(1, randCard.getSuit());
		}
		TEST(Card, DeletionOfCards)
		{
			Card * randCard;
			randCard = new Card;
			ASSERT_EQ(0, randCard->getSuit());
			ASSERT_EQ(0, randCard->getVal());
			randCard = NULL;
			delete randCard;
			ASSERT_EQ(NULL, randCard);
		}
		TEST(Deck, BasicDeckConstruction)
		{
			Deck playingDeck;
			ASSERT_EQ(52, playingDeck.deckSize());

		}
		TEST(Deck, DeckRemovalAndAddition)
		{
			Deck playingDeck;
			Card * tempCard;
			
			ASSERT_EQ(52, playingDeck.deckSize()); //construction
			tempCard = playingDeck.removeCard(); //card removal
			ASSERT_EQ(4, tempCard->getSuit()); //checking to see if it was top card
			ASSERT_EQ(13, tempCard->getVal());
			ASSERT_EQ(51, playingDeck.deckSize()); //return size
			playingDeck.addCard(tempCard); //card addition
			ASSERT_EQ(52, playingDeck.deckSize()); //returns size after addtion
			//now we need to see if the card was placed ontop or not, which can be done by popping again
			tempCard = playingDeck.removeCard();
			ASSERT_EQ(4, tempCard->getSuit());
			ASSERT_EQ(12, tempCard->getVal());
		}
		TEST(Deck, ShufflingOfTheDeck)
		{
			Deck playingDeck;
			Deck randomDeck;
			randomDeck.shuffleDeck();
			Card * card1;
			Card * card2;
			bool testVal = true;
			ASSERT_EQ(52, playingDeck.deckSize());
			ASSERT_EQ(52, randomDeck.deckSize());
			card1 = playingDeck.removeCard();
			card2 = randomDeck.removeCard();
			if(card1 != card2){
				testVal = false;
			}
			ASSERT_FALSE(testVal);

		}
		TEST(Player, StackAdditions){
			Player p1;
			Card *card1 = new Card;
			Card *card2 = new Card;
			Card *card3 = new Card;
			Card *card4 = new Card;
			card1->setSuit(1);
			card2->setSuit(1);
			card3->setSuit(1);
			card4->setSuit(1);
			card1->setVal(1);
			card2->setVal(2);
			card3->setVal(4);
			card4->setVal(3);
			ASSERT_TRUE(p1.addToStack(card1));
			ASSERT_TRUE(p1.addToStack(card2));
			ASSERT_FALSE(p1.addToStack(card3));
			ASSERT_TRUE(p1.addToStack(card4));
		}
		TEST(Player, HandAdditionAndRemoval){
			Player p1;
			Card *card1 = new Card;
			Card *card2 = new Card;
			card1->setVal(1);
			card2->setVal(2);
			ASSERT_TRUE(p1.addToHand(card1));
			ASSERT_TRUE(p1.addToHand(card2));
			ASSERT_EQ(card1,p1.removeFromHand(1));
			ASSERT_EQ(card2,p1.removeFromHand(2));

		}
		TEST(Player, WinCondition){
			Player p1;
			Card * card1 = new Card;
			Card * card2 = new Card;
			Card * card3 = new Card;
			Card * card4 = new Card;
			Card * card5 = new Card;
			Card * card6 = new Card;
			Card * card7 = new Card;
			Card * card8 = new Card;
			Card * card9 = new Card;
			Card * card10 = new Card;
			Card * card11 = new Card;
			Card * card12 = new Card;
			Card * card13 = new Card;
			card1->setVal(1);
			card2->setVal(2);
			card3->setVal(3);
			card4->setVal(4);
			card5->setVal(5);
			card6->setVal(6);
			card7->setVal(7);
			card8->setVal(8);
			card9->setVal(9);
			card10->setVal(10);
			card11->setVal(11);
			card12->setVal(12);
			card13->setVal(13);
			ASSERT_TRUE(p1.addToStack(card1));
			ASSERT_TRUE(p1.addToStack(card2));
			ASSERT_TRUE(p1.addToStack(card3));
			ASSERT_TRUE(p1.addToStack(card4));
			ASSERT_TRUE(p1.addToStack(card5));
			ASSERT_TRUE(p1.addToStack(card6));
			ASSERT_TRUE(p1.addToStack(card7));
			ASSERT_TRUE(p1.addToStack(card8));
			ASSERT_TRUE(p1.addToStack(card9));
			ASSERT_TRUE(p1.addToStack(card10));
			ASSERT_TRUE(p1.addToStack(card11));
			ASSERT_TRUE(p1.addToStack(card12));
			ASSERT_TRUE(p1.addToStack(card13));
		}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
