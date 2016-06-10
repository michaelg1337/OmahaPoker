#ifndef ANALYSER_H
#define ANALYSER_H
#include "hand.h"

int handAnalyser(Hand inHand1, Hand inHand2, Board board);

int better(card_t p1c1, card_t p1c2, card_t p1c3, card_t p1c4, card_t p1c5, card_t p2c1, card_t p2c2, card_t p2c3, card_t p2c4, card_t p2c5);

#endif // !ANALYSR_H
