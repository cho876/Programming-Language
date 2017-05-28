#ifndef MY_FIVECARDS_H
#define MY_FIVECARDS_H
#include <cassert>
#include "Card.h"

const int FIVE = 5;

class FiveCards {
public:
	FiveCards();
	FiveCards(const FiveCards& r);
	FiveCards& operator=(const FiveCards& r);
	Card& operator[](int i);
	Card operator[](int i) const;
	~FiveCards();
	void sort();
	int compare(const FiveCards& right) const;
	string tostring() const;
	static FiveCards& getHighValue();
private:
	Card* pelem;

};
bool operator<(const FiveCards& left, const FiveCards& right);
bool operator<=(const FiveCards& left, const FiveCards& right);    // <= operator 추가 overloading
bool operator==(const FiveCards& left, const FiveCards& right);    // == operator 추가 overloading
bool operator!=(const FiveCards& left, const FiveCards& right);    // != operator 추가 overloading
bool operator>=(const FiveCards& left, const FiveCards& right);    // >= operator 추가 overloading
bool operator>(const FiveCards& left, const FiveCards& right);

ostream& operator<<(ostream& out, const FiveCards& value);

#endif
