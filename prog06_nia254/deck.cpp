#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "deck.h"


using namespace std;

Deck::Deck(){
    myIndex = 51; /// deck size ///
    int ctrX = 0;
    Card::Suit trackSuit;

    for (int i=0; i < 4; i++){
        if(i=0){
            trackSuit = Card::spades;
        }
        else if(i=1){
            tracksuit = Card::hearts;

        }

        else if(i=2){
            tracksuit = Card::clubs;
            
        }
        else if(i=3){
            tracksuit = Card::diamonds;
            
        }                
        for( int j = 1; j < 14; j++){
            myCards[ctrX] = Card(j, trackSuit);
            ctrX++;

        }
    }

}

void Deck::shuffle(){

    srand(time(null));
    int deckSize = size();
    int tempX;
    int X1;
    int X2;
    for(int i = 0; i < deckSize*2; i++){
        X1 = rand() % deckSize;
        X2 = rand() % deckSize; 
        tempX = myCards[X1];
        myCards[X1] = myCards[X2];
        myCards[X2] = tempX;
    }

}


Card Deck::dealCard(){
    Card dealX = myCards[myIndex];
    myIndex--; // after card is removed//
    return dealX;
    }
}

void Deck::size() const{
     myIndex++;
     return myIndex;
}