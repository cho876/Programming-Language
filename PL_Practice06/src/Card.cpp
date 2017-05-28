#include "String.h"
#include "Card.h"

Card Card::getHighValue(){
	return Card(1,15);
}

Card::Card () {
	suit = SPADE;
	rank = ACE;
}
Card::Card (int s, int r) { 
	suit = (SUIT) s;
	rank = (PIP) r;
}

String Card::toString () const {
	String image;
	switch (suit) {
	case CLUB:		image = "CL "; break;
	case DIAMOND:	image = "DI "; break;
	case HEART:		image = "HE "; break;
	case SPADE:		image = "SP "; break;
	}
	switch ((int)rank) {
	case ACE:	image += "A "; break;
	case JACK:	image += "J "; break;
	case KING:	image += "K "; break;
	case QUEEN:	image += "Q "; break;
	case 10:	image += "10"; break;
	default:	image = image + ((char)('0'+(int)rank) + String(" "));
	}
	return image;
}

string Card::tostring () const {
	string image;
	switch (suit) {
	case CLUB:		image = "CL "; break;
	case DIAMOND:	image = "DI "; break;
	case HEART:		image = "HE "; break;
	case SPADE:		image = "SP "; break;
	}
	switch ((int)rank) {
	case ACE:	image += "A "; break;
	case JACK:	image += "J "; break;
	case KING:	image += "K "; break;
	case QUEEN:	image += "Q "; break;
	case 10:	image += "10"; break;
	default:	image = image + (char)('0'+rank) + " ";
	}
	return image;
}
/*
ostream& Card::outstr(ostream& sout) const {

	sout << tostring();
	return sout;
}
 */
ostream& operator<<(ostream& out, const Card& card)
{
	out << card.tostring();

	return out;
}

int Card::compare(const Card& right) const {     // Card compare (1순위: suig(문양), 2순위: rank(숫자))
	int lrank, rrank;          // rank(숫자) 비교를 위한 변수
	int lsuit, rsuit;          // suit(문양) 비교를 위한 변수

	lrank = rank;              // 자신의 rank(숫자)를 lrank에 저장
	rrank = right.rank;        // 비교 대상의 rank(숫자)를 rrank에 저장

	lsuit = suit;              // 자신의 suit(문양)을 lsuit에 저장
	rsuit = right.suit;        // 비교 대상의 suit(문양)을 rsuit에 저장

	int diff = lrank - rrank;   // 자신과 비교 대상의 rank(숫자) 비교 결과를 diff에 저장
	int _diff = lsuit - rsuit;     // 자신과 비교 대상의 suit(문양) 비교 결과를 _diff에 저장

	if(_diff == 0)              // 문양이 같을 경우 rank(숫자)의 비교 결과인 diff를 반환
		return diff;
	else                        // 문양이 다를 경우 suit(문양)의 비교 결과인 _diff를 반환
		return _diff;
}

bool operator<(const Card& left, const Card& right)
{
	return left.compare(right) < 0;
}

bool operator<=(const Card& left, const Card& right)
		{
	return left.compare(right) <= 0;
		}

bool operator==(const Card& left, const Card& right)
		{
	return left.compare(right) == 0;
		}

bool operator!=(const Card& left, const Card& right)
		{
	return left.compare(right) != 0;
		}

bool operator>=(const Card& left, const Card& right)
		{
	return left.compare(right) >= 0;
		}

bool operator>(const Card& left, const Card& right)
{
	return left.compare(right) > 0;
}
