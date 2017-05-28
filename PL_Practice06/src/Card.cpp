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

int Card::compare(const Card& right) const {     // Card compare (1����: suig(����), 2����: rank(����))
	int lrank, rrank;          // rank(����) �񱳸� ���� ����
	int lsuit, rsuit;          // suit(����) �񱳸� ���� ����

	lrank = rank;              // �ڽ��� rank(����)�� lrank�� ����
	rrank = right.rank;        // �� ����� rank(����)�� rrank�� ����

	lsuit = suit;              // �ڽ��� suit(����)�� lsuit�� ����
	rsuit = right.suit;        // �� ����� suit(����)�� rsuit�� ����

	int diff = lrank - rrank;   // �ڽŰ� �� ����� rank(����) �� ����� diff�� ����
	int _diff = lsuit - rsuit;     // �ڽŰ� �� ����� suit(����) �� ����� _diff�� ����

	if(_diff == 0)              // ������ ���� ��� rank(����)�� �� ����� diff�� ��ȯ
		return diff;
	else                        // ������ �ٸ� ��� suit(����)�� �� ����� _diff�� ��ȯ
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
