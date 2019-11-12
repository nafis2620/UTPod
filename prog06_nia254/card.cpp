#include <cstdlib>
#include <iostream>
#include "card.h"
#include <string>

using namespace std;

//Default Constructor//

Card::Card(){
    mySuit = spades;
    myRank = 13;

}


//Card Constructor//

Card::Card(int rank, Suit s){
     mySuit = s;
     myRank = rank;
    
}

bool Card::sameSuitAs(const Card &c) {
    if (mySuit == c.mySuit){
        return true;
    }

    else {
        return false;
    }
}



int Card::getRank() const{

    return myRank;
}


string Card::suitString(Card::Suit s) const {

    string cardSuit;
//spades//
    if (s == spades){
        return cardSuit = 's';
    }
//hearts//
    else if (s == hearts){
        return cardSuit = 'h';
    }
//clubs//    
    else if (s == clubs){
        return cardSuit = 'c';
    }
 //diamonds//
    else {
        return cardSuit = 'd'
    }
}

string Card::rankString(int r) const
{
	string cardRank[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

	return cardRank[r - 1];
}



string Card::toString() const
{
	return (rankString(mySuit) + suitString(myRank));
}

bool Card::operator == (const Card &rhs) const{
    if ((myRank == rhs.myRank) && (mySuit == rhs.mySuit)){
        return true;
    }
    else{
        return false;
    }
}

bool Card::operator != (const Card &rhs) const{
    if ((myRank != rhs.myRank) || (mySuit != rhs.mySuit)){
        return true;
    }
    else{
        return false;
    }
}

ostream& operator << (ostream& out, const Card& c)
{
	out << c.toString();
	return out;
}