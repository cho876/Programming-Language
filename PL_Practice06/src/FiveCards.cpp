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

void FiveCards::sort(){          // 랜덤하게 뽑은 5장의 카드를 오름차순으로 정리
	int _diff;
	for(int i=0; i<5; i++){
		for(int j=i; j<5; j++){
			_diff = pelem[i].compare(pelem[j]);      // 자신의 첫 번째카드부터 마지막 카드까지 서로 비교
			if(_diff>0){                 // 만약 카드의 값이 다를 경우 swap을 통해 자신의 5장의 카드 오름차순으로 정리
				Card temp = pelem[i];
				pelem[i] = pelem[j];
				pelem[j] = temp;
			}
		}
	}
}
int FiveCards::compare(const FiveCards& right) const {       // FiceCards 비교 함수
	int diff;
	for(int i = 0; i<5; i++){                  // 5장의 카드 중 첫 번째 카드부터 마지막 5번째 카드까지 비교 반복
		diff = pelem[i].compare(right[i]);     // 자신의 5장 카드와 비교 대상의 5장 카드를 비교 (Card의 compare 사용)
		if(diff)                               // 비교 결과가 0이 아닌 값(두 카드 값이 다를 경우) break
			break;
	}
	return diff;                   // 비교 결과 반환
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

bool operator<=(const FiveCards& left, const FiveCards& right)    // <= operator 추가 overloading
		{
	return left.compare(right) <= 0;
		}

bool operator==(const FiveCards& left, const FiveCards& right)    // == operator 추가 overloading
		{
	return left.compare(right) == 0;
		}

bool operator!=(const FiveCards& left, const FiveCards& right)    // != operator 추가 overloading
		{
	return left.compare(right) != 0;
		}

bool operator>=(const FiveCards& left, const FiveCards& right)    // >= operator 추가 overloading
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
