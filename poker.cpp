#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class card {
public:
  void setsuit(char insuit) {
    suit = insuit;
  }
  void setvalue(int invalue) {
    value = invalue;
  }
  void setvalue(char invalue) {
    switch (invalue) {
    case 'K':
      value = 13;
      break;
    case 'Q':
      value = 12;
      break;
    case 'J':
      value = 11;
      break;
    case 'A':
      value = 14;
      break;
    case 'T':
      value = 10;
      break;
    case '9':
      value = 9;
      break;
    case '8':
      value = 8;
      break;
    case '7':
      value = 7;
      break;
    case '6':
      value = 6;
      break;
    case '5':
      value = 5;
      break;
    case '4':
      value = 4;
      break;
    case '3':
      value = 3;
      break;
    case '2':
      value = 2;
      break;
    }
  }
  char getsuit() {
    return suit;
  }
  int getvalue() {
    return value;
  }
  void printcard() {
    cout << suit << value;
  }
  card(char insuit, int invalue) {
    suit = insuit;
    value = invalue;
  }
  card(char insuit, char invalue) {
    suit = insuit;
    switch (invalue) {
    case 'K':
      value = 13;
      break;
    case 'Q':
      value = 12;
      break;
    case 'J':
      value = 11;
      break;
    case 'A':
      value = 14;
      break;
    case 'T':
      value = 10;
      break;
    case '9':
      value = 9;
      break;
    case '8':
      value = 8;
      break;
    case '7':
      value = 7;
      break;
    case '6':
      value = 6;
      break;
    case '5':
      value = 5;
      break;
    case '4':
      value = 4;
      break;
    case '3':
      value = 3;
      break;
    case '2':
      value = 2;
      break;
    }
  }
  card() {}
  friend bool operator >(card card1, card card2) {
    return (card1.value > card2.value);
  }
  friend bool operator <(card card1, card card2) {
    return (card1.value < card2.value);
  }
private:
  char suit;
  int value;
};

class hand {
public:
  void sethand(ifstream &reader) {
    char test;
    reader.get(test);
    first.setvalue(test);
    reader.get(test);
    first.setsuit(test);
    reader.get(test);
    reader.get(test);
    second.setvalue(test);
    reader.get(test);
    second.setsuit(test);
    reader.get(test);
    reader.get(test);
    third.setvalue(test);
    reader.get(test);
    third.setsuit(test);
    reader.get(test);
    reader.get(test);
    fourth.setvalue(test);
    reader.get(test);
    fourth.setsuit(test);
    reader.get(test);
    reader.get(test);
    fifth.setvalue(test);
    reader.get(test);
    fifth.setsuit(test);
    reader.get(test);
  }
  void setfirst(card incard) {
    first = incard;
  }
  void setsecond(card incard) {
    second = incard;
  }
  void setthird(card incard) {
    third = incard;
  }
  void setfourth(card incard) {
    fourth = incard;
  }
  void setfifth(card incard) {
    fifth = incard;
  }
  card getfirst() {
    return first;
  }
  card getsecond() {
    return second;
  }
  card getthird() {
    return third;
  }
  card getfourth() {
    return fourth;
  }
  card getfifth() {
    return fifth;
  }
  void printhand() {
    first.printcard();
    cout << " ";
    second.printcard();
    cout << " ";
    third.printcard();
    cout << " ";
    fourth.printcard();
    cout << " ";
    fifth.printcard();
    cout << endl;
  }
  void firsttolast() {
    updatevector();
    card temp(list[0].getsuit(),list[0].getvalue());
    for (int i=0; i<5; i++) {
      for (int j=i; j<5; j++) {
	if (list[j].getvalue() > list[i].getvalue()) {
	  temp.setvalue(list[j].getvalue());
	  temp.setsuit(list[j].getsuit());
	  list[j].setvalue(list[i].getvalue());
	  list[j].setsuit(list[i].getsuit());
	  list[i].setvalue(temp.getvalue());
	  list[i].setsuit(temp.getsuit());
	}
      }
    }
    updatefromvector();
  }
  void makevector() {
    list.push_back(first);
    list.push_back(second);
    list.push_back(third);
    list.push_back(fourth);
    list.push_back(fifth);
  }
  void updatevector() {
    list[0].setvalue(first.getvalue());
    list[0].setsuit(first.getsuit());
    list[1].setvalue(second.getvalue());
    list[1].setsuit(second.getsuit());
    list[2].setvalue(third.getvalue());
    list[2].setsuit(third.getsuit());
    list[3].setvalue(fourth.getvalue());
    list[3].setsuit(fourth.getsuit());
    list[4].setvalue(fifth.getvalue());
    list[4].setsuit(fifth.getsuit());
  }
  void updatefromvector() {
    first.setvalue(list[0].getvalue());
    first.setsuit(list[0].getsuit());
    second.setvalue(list[1].getvalue());
    second.setsuit(list[1].getsuit());
    third.setvalue(list[2].getvalue());
    third.setsuit(list[2].getsuit());
    fourth.setvalue(list[3].getvalue());
    fourth.setsuit(list[3].getsuit());
    fifth.setvalue(list[4].getvalue());
    fifth.setsuit(list[4].getsuit());
  }
  bool hasflush() {
    updatevector();
    for (int i=1; i<5; i++) {
      if (list[0].getsuit() != list[i].getsuit()) {
	return 0;
      }
    }
    return 1;
  }
  bool hasstraight() {
    updatevector();
    if ((olma(most()) == 1) && ((first.getvalue() == (fifth.getvalue() + 4)) || (second.getvalue() == 5)))
      return 1;
    return 0;
  }
  bool hasstraightflush() {
    if (hasflush() && hasstraight())
      return 1;
    return 0;
  }
  bool hasfullhouse() {
    if (olma(most()) == 3 && olma(secondmost()) == 2)
      return 1;
    return 0;
  }
  bool hasfourofkind() {
    if (olma(most()) == 4)
      return 1;
    return 0;
  }
  bool hasthreeofkind() {
    if ((olma(most()) == 3) && (olma(secondmost()) == 1))
      return 1;
    return 0;
  }
  bool hastwopair() {
    if (olma(most()) == 2 && olma(secondmost()) == 2)
      return 1;
    return 0;
  }
  bool haspair() {
    if (olma(most()) == 2 && olma(secondmost()) == 1)
      return 1;
    return 0;
  }
  void analyse() {
    updatevector();
    for (int i = 0; i < 15; i++) {
      analysis[i] = 0;
    }
    for (int i=0; i < 5; i++) {
      analysis[list[i].getvalue()]++;
    }
  }
  int most() {
    analyse();
    int temp = 0;
    for (int i=0; i < 15; i++) {
      if (analysis[i] >= analysis[temp]) {
	temp = i;
      }
    }
    return temp;
  }
  int secondmost() {
    analyse();
    int temp =0;
    for (int i=0; i<15; i++) {
      if (analysis[i] >= analysis[temp] && i != most()) {
	temp = i;
      }
    }
    return temp;
  }
  int olma(int question) {
    analyse();
    return analysis[question];
  }
private:
  card first;
  card second;
  card third;
  card fourth;
  card fifth;
  vector<card> list;
  int analysis[15];
};

//return 1 means hand1 wins.
bool winner(hand hand1, hand hand2) {
  //straight flush comparison.
  if (hand1.hasstraightflush()) {
    if (!hand2.hasstraightflush()) {
      return 1;
    }
    return (hand1.most() > hand2.most());
  }
  if (!hand1.hasstraightflush() && hand2.hasstraightflush())
    return 0;
  
  //four of a kind comparison.
  if (hand1.hasfourofkind()) {
    if (!hand2.hasfourofkind())
      return 1;
    return (hand1.most() > hand2.most());
  }
  if (!hand1.hasfourofkind() && hand2.hasfourofkind())
    return 0;
  
  //Full house comparison.
  if (hand1.hasfullhouse()) {
    if (!hand2.hasfullhouse())
      return 1;
    return (hand1.most() > hand2.most());
  }
  if (!hand1.hasfullhouse() && hand2.hasfullhouse())
    return 0;
  
  // flush comparison.
  if (hand1.hasflush()) {
    if (!hand2.hasflush())
      return 1;
    if(hand1.getfirst() > hand2.getfirst())
      return 1;
    if (hand1.getfirst() < hand2.getfirst())
      return 0;
    if(hand1.getsecond() > hand2.getsecond())
      return 1;
    if (hand1.getsecond() < hand2.getsecond())
      return 0;
    if(hand1.getthird() > hand2.getthird())
      return 1;
    if (hand1.getthird() < hand2.getthird())
      return 0;
    if(hand1.getfourth() > hand2.getfourth())
      return 1;
    if (hand1.getfourth() < hand2.getfourth())
      return 0;
    if(hand1.getfifth() > hand2.getfifth())
      return 1;
    if (hand1.getfifth() < hand2.getfifth())
      return 0;
  }
  if (!hand1.hasflush() && hand2.hasflush())
    return 0;

  // straight comp
  if (hand1.hasstraight()) {
    if (!hand2.hasstraight())
      return 1;
    if (hand1.getfirst().getvalue() == 14 && hand1.getsecond().getvalue() == 5)
      return 0;
    return (hand1.getsecond() > hand2.getsecond());
  }
  if (!hand1.hasstraight() && hand2.hasstraight())
    return 0;
  
  //three of kind comp
  if (hand1.hasthreeofkind()) {
    if (!hand2.hasthreeofkind())
      return 1;
    if (hand1.most() > hand2.most())
      return 1;
    if (hand1.most() < hand2.most())
      return 0;
    if(hand1.getfirst() > hand2.getfirst())
      return 1;
    if (hand1.getfirst() < hand2.getfirst())
      return 0;
    if(hand1.getsecond() > hand2.getsecond())
      return 1;
    if (hand1.getsecond() < hand2.getsecond())
      return 0;
    if(hand1.getthird() > hand2.getthird())
      return 1;
    if (hand1.getthird() < hand2.getthird())
      return 0;
    if(hand1.getfourth() > hand2.getfourth())
      return 1;
    if (hand1.getfourth() < hand2.getfourth())
      return 0;
    if(hand1.getfifth() > hand2.getfifth())
      return 1;
    if (hand1.getfifth() < hand2.getfifth())
      return 0;
  }
  if (!hand1.hasthreeofkind() && hand2.hasthreeofkind())
    return 0;
  
  //two pair comp
  if (hand1.hastwopair()) {
    if (!hand2.hastwopair())
      return 1;
    if (hand1.most() > hand2.most())
      return 1;
    if (hand1.most() < hand2.most())
      return 0;
    if (hand1.secondmost() > hand2.secondmost())
      return 1;
    if (hand1.secondmost() < hand2.secondmost())
      return 0;
    if(hand1.getfirst() > hand2.getfirst())
      return 1;
    if (hand1.getfirst() < hand2.getfirst())
      return 0;
    if(hand1.getsecond() > hand2.getsecond())
      return 1;
    if (hand1.getsecond() < hand2.getsecond())
      return 0;
    if(hand1.getthird() > hand2.getthird())
      return 1;
    if (hand1.getthird() < hand2.getthird())
      return 0;
    if(hand1.getfourth() > hand2.getfourth())
      return 1;
    if (hand1.getfourth() < hand2.getfourth())
      return 0;
    if(hand1.getfifth() > hand2.getfifth())
      return 1;
    if (hand1.getfifth() < hand2.getfifth())
      return 0;
  }
  if (!hand1.hastwopair() && hand2.hastwopair())
    return 0;

  //pair comp
  if (hand1.haspair()) {
    if (!hand2.haspair())
      return 1;
    if (hand1.most() > hand2.most())
      return 1;
    if (hand1.most() < hand2.most())
      return 0;
    if(hand1.getfirst() > hand2.getfirst())
      return 1;
    if (hand1.getfirst() < hand2.getfirst())
      return 0;
    if(hand1.getsecond() > hand2.getsecond())
      return 1;
    if (hand1.getsecond() < hand2.getsecond())
      return 0;
    if(hand1.getthird() > hand2.getthird())
      return 1;
    if (hand1.getthird() < hand2.getthird())
      return 0;
    if(hand1.getfourth() > hand2.getfourth())
      return 1;
    if (hand1.getfourth() < hand2.getfourth())
      return 0;
    if(hand1.getfifth() > hand2.getfifth())
      return 1;
    if (hand1.getfifth() < hand2.getfifth())
      return 0;
  }
  if (!hand1.haspair() && hand2.haspair())
    return 0;
  
  //high card comp
  
    if (hand1.getfirst() > hand2.getfirst())
      return 1;
    if (hand1.getfirst() < hand2.getfirst())
      return 0;
    if(hand1.getsecond() > hand2.getsecond())
      return 1;
    if (hand1.getsecond() < hand2.getsecond())
      return 0;
    if(hand1.getthird() > hand2.getthird())
      return 1;
    if (hand1.getthird() < hand2.getthird())
      return 0;
    if(hand1.getfourth() > hand2.getfourth())
      return 1;
    if (hand1.getfourth() < hand2.getfourth())
      return 0;
    if(hand1.getfifth() > hand2.getfifth())
      return 1;
    if (hand1.getfifth() < hand2.getfifth())
      return 0;
    
}
    

int main() {
  hand hand1;
  ifstream reader;
  hand hand2;
  char jump;
  int sum = 0, sf = 0, fok = 0, fh = 0, tok=0, f=0, s=0, tp = 0, p=0, no=0;
  reader.open("poker.txt");
  hand1.sethand(reader);
  hand1.makevector();
  hand1.firsttolast();
  hand2.sethand(reader);
  hand2.makevector();
  hand2.firsttolast();
  sum += winner(hand1, hand2);
  while (!reader.eof()) {
    hand1.sethand(reader);
    hand1.firsttolast();
    hand2.sethand(reader);
    hand2.firsttolast();
    sum += winner(hand1, hand2);

    
    if ((winner(hand1, hand2) && winner(hand2, hand1)) || (!winner(hand1, hand2) && !winner(hand2, hand1))) {
	hand1.printhand();
	hand2.printhand();
	cout << sum << " " << hand1.hasstraightflush() << hand1.hasfourofkind() << hand1.hasfullhouse() << hand1.hasflush() << hand1.hasstraight() << hand1.hasthreeofkind() << hand1.hastwopair() << hand1.haspair() << " " << hand2.hasstraightflush() << hand2.hasfourofkind() << hand2.hasfullhouse() << hand2.hasflush() << hand2.hasstraight() << hand2.hasthreeofkind() << hand2.hastwopair() << hand2.haspair() << " " <<endl;
      }
    
    /*
    if (hand1.hasstraightflush() && hand2.hasstraightflush())
      sf++;
    if (hand1.hasfourofkind() && hand2.hasfourofkind())
      fok++;
    if (hand1.hasfullhouse() && hand2.hasfullhouse())
      fh++;
    if (hand1.hasthreeofkind() && hand2.hasthreeofkind())
      tok++;
    if (hand1.hasflush() && hand2.hasflush())
      f++;
    if (hand1.hasstraight() && hand2.hasstraight())
      s++;
    if (hand1.hastwopair() && hand2.hastwopair())
      tp++;
    if (hand1.haspair() && hand2.haspair())
      p++;
    if (!hand1.hasstraightflush() && !hand1.hasfourofkind() && !hand1.hasfullhouse() && !hand1.hasthreeofkind() && !hand1.hasflush() && !hand1.hasstraight() && !hand1.hastwopair() && !hand1.haspair() && !hand2.hasstraightflush() && !hand2.hasfourofkind() && !hand2.hasfullhouse() && !hand2.hasthreeofkind() && !hand2.hasflush() && !hand2.hasstraight() && !hand2.hastwopair() && !hand2.haspair())
      no++;
    */
  }


  /*
  cout << sf << " " << fok << " " << fh << " " << tok << " " << f << " " << s << " " << tp << " " << p << " " << no << endl;
  */
  cout << sum -1 << endl;
  return 0;
}
