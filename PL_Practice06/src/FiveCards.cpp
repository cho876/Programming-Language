#include "FiveCards.h"
Card FIVEHIGHCARD[] = { Card(1,15), Card(1,15), Card(1,15), Card(1,15), Card(1,15) };
FiveCards& FiveCards::getHighValue(){
	FiveCards* p5Cards = new FiveCards();
	p5Cards->pelem = FIVEHIGHCARD;
	return *p5Cards;
}
FiveCards::FiveCards() {
	pelem = new Card[FIVE];
}
FiveCards::FiveCards(const FiveCards& right) {
	pelem = new Card[FIVE];
	 for(int i=0; i<FIVE; ++i) 
		 pelem[i] = right.pelem[i];
}

FiveCards& FiveCards::operator=(const FiveCards& right) {
	if(this != &right) {
		delete[] pelem;
		pelem = new Card[FIVE];
		for(int i=0; i<FIVE; ++i) 
			pelem[i]=right.pelem[i];
	}
	return *this;
}
FiveCards::~FiveCards() {
	delete[] pelem;
}
Card& FiveCards::operator[](int index) {
	assert((index >= 0) && (index < FIVE));
	return pelem[index];
}

Card FiveCards::operator[](int index) const {
	assert((index >= 0) && (index < FIVE));
	return pelem[index];
}

void FiveCards::sort(){          // �����ϰ� ���� 5���� ī�带 ������������ ����
	int _diff;
	for(int i=0; i<5; i++){
		for(int j=i; j<5; j++){
			_diff = pelem[i].compare(pelem[j]);      // �ڽ��� ù ��°ī����� ������ ī����� ���� ��
			if(_diff>0){                 // ���� ī���� ���� �ٸ� ��� swap�� ���� �ڽ��� 5���� ī�� ������������ ����
				Card temp = pelem[i];
				pelem[i] = pelem[j];
				pelem[j] = temp;
			}
		}
	}
}
int FiveCards::compare(const FiveCards& right) const {       // FiceCards �� �Լ�
	int diff;
	for(int i = 0; i<5; i++){                  // 5���� ī�� �� ù ��° ī����� ������ 5��° ī����� �� �ݺ�
		diff = pelem[i].compare(right[i]);     // �ڽ��� 5�� ī��� �� ����� 5�� ī�带 �� (Card�� compare ���)
		if(diff)                               // �� ����� 0�� �ƴ� ��(�� ī�� ���� �ٸ� ���) break
			break;
	}
	return diff;                   // �� ��� ��ȯ
}

string FiveCards::tostring() const {

	string result = "[";
	for(int i=0; i<FIVE; ++i) {
		 if ( i != 0 ) result+=", ";
		 result += pelem[i].tostring();
	}
	result += "]\n";
	return result;
}

bool operator<(const FiveCards& left, const FiveCards& right)
{
	return left.compare(right) < 0;
}

bool operator<=(const FiveCards& left, const FiveCards& right)    // <= operator �߰� overloading
		{
	return left.compare(right) <= 0;
		}

bool operator==(const FiveCards& left, const FiveCards& right)    // == operator �߰� overloading
		{
	return left.compare(right) == 0;
		}

bool operator!=(const FiveCards& left, const FiveCards& right)    // != operator �߰� overloading
		{
	return left.compare(right) != 0;
		}

bool operator>=(const FiveCards& left, const FiveCards& right)    // >= operator �߰� overloading
		{
	return left.compare(right) >= 0;
		}

bool operator>(const FiveCards& left, const FiveCards& right)
{
	return left.compare(right) > 0;
}
ostream& operator<<(ostream& out, const FiveCards& cards) {
	out << cards.tostring();
	return out;
}
