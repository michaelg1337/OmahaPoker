#include "handanalyser.h"
#include "hand.h"
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

map<string, value_t> svalues;
map<value_t, string> evalues;
map<string, suit_t> ssuits;
map<suit_t, string> esuits;

void initSymbols() {
	svalues["two"] = two;
	svalues["three"] = three;
	svalues["four"] = four;
	svalues["five"] = five;
	svalues["six"] = six;
	svalues["seven"] = seven;
	svalues["eight"] = eight;
	svalues["nine"] = nine;
	svalues["ten"] = ten;
	svalues["jack"] = jack;
	svalues["queen"] = queen;
	svalues["king"] = king;
	svalues["ace"] = ace;
	evalues[two] = "two";
	evalues[three] = "three";
	evalues[four] = "four";
	evalues[five] = "five";
	evalues[six] = "six";
	evalues[seven] = "seven";
	evalues[eight] = "eight";
	evalues[nine] = "nine";
	evalues[ten] = "ten";
	evalues[jack] = "jack";
	evalues[queen] = "queen";
	evalues[king] = "king";
	evalues[ace] = "ace";
	ssuits["diamonds"] = diamonds;
	ssuits["spades"] = spades;
	ssuits["clubs"] = clubs;
	ssuits["hearts"] = hearts;
	esuits[diamonds] = "diamonds";
	esuits[spades] = "spades";
	esuits[clubs] = "clubs";
	esuits[hearts] = "hearts";
}

int main() {
	initSymbols();
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
	cout << stringfor(p1hand.card1.csuit) << " ";
	cout << stringfor(p1hand.card1.cvalue) << endl;
	cout << stringfor(p1hand.card2.csuit) << " ";
	cout << stringfor(p1hand.card2.cvalue) << endl;
	cout << stringfor(p1hand.card3.csuit) << " ";
	cout << stringfor(p1hand.card3.cvalue) << endl;
	cout << stringfor(p1hand.card4.csuit) << " ";
	cout << stringfor(p1hand.card4.cvalue) << endl;
	cout << stringfor(p2hand.card1.csuit) << " ";
	cout << stringfor(p2hand.card1.cvalue) << endl;
	cout << stringfor(p2hand.card2.csuit) << " ";
	cout << stringfor(p2hand.card2.cvalue) << endl;
	cout << stringfor(p2hand.card3.csuit) << " ";
	cout << stringfor(p2hand.card3.cvalue) << endl;
	cout << stringfor(p2hand.card4.csuit) << " ";
	cout << stringfor(p2hand.card4.cvalue) << endl;
}