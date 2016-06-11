#ifndef HAND_H
#define HAND_H

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

enum value_t {two,three,four,five,six,seven,eight,nine,ten,jack,queen,king,ace};
enum suit_t {diamonds,spades,clubs,hearts};

struct card_t {
	value_t cvalue;
	suit_t csuit;
};

struct Hand {
	card_t card1;
	card_t card2;
	card_t card3;
	card_t card4;
};

struct Board {
	card_t card1;
	card_t card2;
	card_t card3;
	card_t card4;
	card_t card5;
};

class Deck {
private:
	vector<card_t> cdeck;
public:
	Deck() {
		card_t temp;
		for (int i = two; i <= ace; i++) {
			for (int j = diamonds; j <= hearts; j++) {
				value_t tempv = static_cast<value_t>(i);
				suit_t temps = static_cast<suit_t>(j);
				temp.cvalue = tempv;
				temp.csuit = temps;
				cdeck.push_back(temp);
			}
		}
	}
	void shuffle() {
		cdeck.clear();
		card_t temp;
		for (int i = two; i <= ace; i++) {
			for (int j = diamonds; j <= hearts; j++) {
				value_t tempv = static_cast<value_t>(i);
				suit_t temps = static_cast<suit_t>(j);
				temp.cvalue = tempv;
				temp.csuit = temps;
				cdeck.push_back(temp);
			}
		}
	}
	card_t draw() {
		if (cdeck.size() != 0) {
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
