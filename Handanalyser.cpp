#include <string>
#include "hand.h"
#include "handanalyser.h"
#include <vector>

using namespace std;

int handAnalyser(Hand inHand1, Hand inHand2, Board board) {
	return 0;
}

class Analyser {
private:
	int histogram[13];
	int suitgram[5];
public:
	int highest() {
		for (int i = 12; i >= 0; i--) {
			if (histogram[i] != 0)
				return i;
		}
		return 0;
	}
	int secondhighest() {
		for (int i = highest() - 1; i >= 0; i--) {
			if (histogram[i] != 0)
				return i;
		}
		return 0;
	}
	int thirdhighest() {
		for (int i = secondhighest() - 1; i >= 0; i--) {
			if (histogram[i] != 0)
				return i;
		}
		return 0;
	}
	int fourthhighest() {
		for (int i = thirdhighest() - 1; i >= 0; i--) {
			if (histogram[i] != 0)
				return i;
		}
		return 0;
	}
	int fifthhighest() {
		for (int i = fourthhighest() - 1; i >= 0; i--) {
			if (histogram[i] != 0)
				return i;
		}
		return 0;
	}
	int most() {

	}
	int secondmost();
	int thirdmost();
	bool sraightflush();
	bool fourkind();
	bool fullhouse();
	bool flush() {
		if (suitgram[0]==4 or suitgram[1]==4 or suitgram[2]==4 or suitgram[3]==4)
			return true;
		return false;
	}
	bool straight();
	bool threekind();
	bool twopair();
	bool pair();
	Analyser(card_t c1, card_t c2, card_t c3, card_t c4, card_t c5) {
		for (int i = 0; i < 13; i++) {
			histogram[i] = 0;
		}
		for (int i = 0; i < 4; i++) {
			suitgram[i] = 0;
		}
		suitgram[static_cast<int>(c1.csuit)]++;
		histogram[static_cast<int>(c1.cvalue)]++;
		suitgram[static_cast<int>(c2.csuit)]++;
		histogram[static_cast<int>(c2.cvalue)]++;
		suitgram[static_cast<int>(c3.csuit)]++;
		histogram[static_cast<int>(c3.cvalue)]++;
		suitgram[static_cast<int>(c4.csuit)]++;
		histogram[static_cast<int>(c4.cvalue)]++;
		suitgram[static_cast<int>(c5.csuit)]++;
		histogram[static_cast<int>(c5.cvalue)]++;
	}
};

int better(card_t p1c1, card_t p1c2, card_t p1c3, card_t p1c4, card_t p1c5, card_t p2c1, card_t p2c2, card_t p2c3, card_t p2c4, card_t p2c5) {
	int analyser1[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int analyser2[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	vector<card_t> temp1, temp2;
	temp1.push_back(p1c1);
	temp1.push_back(p1c2);
	temp1.push_back(p1c3);
	temp1.push_back(p1c4);
	temp1.push_back(p1c5);
	temp2.push_back(p2c1);
	temp2.push_back(p2c2);
	temp2.push_back(p2c3);
	temp2.push_back(p2c4);
	temp2.push_back(p2c5);
	for (int i = 0; i < temp1.size(); i++) {
		analyser[static_cast<int>(temp1[i].cvalue)]++;
	}
	for (int i = 0; i < temp2.size(); i++) {
		analyser[static_cast<int>(temp2[i].cvalue)]++;
	}
	if (checkFlush(temp1) && checkStraight(analyser1)) {
		if (!(checkFlush(temp2) && checkStraight(analyser2))) {
			return 1;
		}
		else {
			return 2;
		}
	}
	
}