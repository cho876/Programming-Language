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

int Card::compare(const Card& right) const {
	int lrank, rrank;
	int lsuit, rsuit;

	lrank = rank;
	rrank = right.rank;

	lsuit = suit;
	rsuit = right.suit;
	int diff = lrank - rrank;
	int _diff = lsuit - rsuit;
	if(_diff == 0)
		return diff;
	else
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
