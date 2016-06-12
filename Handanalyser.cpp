#include <string>
#include "hand.h"
#include "handanalyser.h"
#include <vector>

using namespace std;

int handAnalyser(Hand inHand1, Hand inHand2, Board board) {
	return 0;
}

bool checkFlush(vector<card_t> inlist) {
	if (inlist[0].csuit == inlist[1].csuit && inlist[1].csuit == inlist[2].csuit && inlist[2].csuit == inlist[3].csuit && inlist[3] == inlist[4].csuit)
		return true;
	return false;
}

bool checkStraight(int inlist[]) {
	int lowest = -1, highest = 0;
	for (int i = 0; i < 13; i++) {
		if (inlist[i] > 1)
			return false;
		if (inlist[i] == 1 && lowest == -1)
			lowest = i;
		if (inlist[i] == 1)
			highest == i;
	}
	if (highest - lowest == 4)
		return true;
	if (inlist[0] == inlist[1] == inlist[2] == inlist[3] == inlist[12])
		return true;
	return false;
}

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