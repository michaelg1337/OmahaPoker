#include "handanalyser.h"
#include "hand.h"
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>

int main() {
	Deck MainDeck;
	Hand p1hand, p2hand;
	p1hand.card1 = MainDeck.draw();
	p1hand.card2 = MainDeck.draw();
	p1hand.card3 = MainDeck.draw();
	p1hand.card4 = MainDeck.draw();
	p2hand.card1 = MainDeck.draw();
	p2hand.card2 = MainDeck.draw();
	p2hand.card3 = MainDeck.draw();
	p2hand.card4 = MainDeck.draw();
}