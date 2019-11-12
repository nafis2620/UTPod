#include <istream>
#include <time.h>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;


void Player::addCard(Card c){

    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){

    myBook.push_back(c1);
    myBook.push_back(c2);
}