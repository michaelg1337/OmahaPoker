#ifndef HAND_H
#define HAND_H
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

enum value_t {2,3,4,5,6,7,8,9,T,J,Q,K,A};
enum suit_t {D,S,C,H};

struct card_t {
	value_t cvalue;
	suit_t csuit;
};

struct Hand {
	card card1;
	card card2;
	card card3;
	card card4;
};

struct Board {
	card card1;
	card card2;
	card card3;
	card card4;
	card card5;
};

class Deck {
private:
	vector<card_t> cdeck;
public:
	Deck() {
		srand(TIME(null));
		card_t temp;
		for (card_t i = 2; i <= A; i++) {
			for (suit_t j = D; j <= H; j++) {
				temp.cvalue = i;
				temp.csuit = j;
				cdeck.push_back(temp);
			}
		}
	}
	void shuffle() {
		cdeck.clear();
		card_t temp;
		for (card_t i = 2; i <= A; i++) {
			for (suit_t j = D; j <= H; j++) {
				temp.cvalue = i;
				temp.csuit = j;
				cdeck.push_back(temp);
			}
		}
	}
	card_t draw() {
		if (deck.size() != 0) {
			int selector = rand() % cdeck.size();
			card_t outcard = cdeck[selector];
			cdeck.erase(cdeck.begin() + selector);
			return outcard;
		}
		else {
			cerr << "Cannot draw from empty deck" << endl;
			exit(-1);
		}
	}
};

#endif // !HAND_H
