/*
 * 	Project #5
	제목
	MyListSortTest 프로그램예 Card class 에 적용

	내용

	1. MyListSortTest 참고
	2. MyListSelSort의 selSort와 selSortR을 SelSort, SelSortR class 로 만들어 추가
	3. main.cpp에는 MergeSort, QuickSort 외에 SelSort, SelSortR class test가 있어야 함.
 */
#include <string>
#include <iostream>
#include <cassert>

#include "List.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelSort.h"          // SelSort.h 추가
#include "SelSortR.h"         // SelSortR.h 추가

using namespace std;

const int  LINE_MAX = 13;
enum PIP { ACE=1, JACK=11, QUEEN, KING };
enum SUIT { CLUB=1, DIAMOND, HEART, SPADE };
String cardimage (int suit, int rank) {
	String image;
	switch (suit) {
	case CLUB:		image = "C"; break;
	case DIAMOND:	image = "D"; break;
	case HEART:		image = "H"; break;
	case SPADE:		image = "S"; break;
	}
	switch (rank) {
	case ACE:	image += "A "; break;
	case JACK:	image += "J "; break;
	case QUEEN:	image += "Q "; break;
	case KING:	image += "K "; break;
	case 10:	image += "10"; break;
	default:	image = image + ((char)('0'+rank) + String(" "));
	}
	return image;
}
void printList(List& L)
{
	int i = 0;
	for (Iterator cp = L.begin(); cp!=L.end(); cp.next()) {
		cout << cp.get() << " ";
		i++;
		if (i % LINE_MAX == 0) cout << endl;
	}
	cout << endl;
}
void sortTest(ListSort& sorter ){
	List deck;

	// Make a Card Deck
	for (int s=CLUB; s<=SPADE; s++)
		for (int r=ACE; r<=KING; r++){
			deck.push_back(cardimage(s,r));
		}
	// Display the Deck
	printList(deck);
	cout << "Node Cur Count = " << Node::getCurCount();
	cout << endl;
	cout << "Node Max Count = " << Node::getMaxCount();
	cout << endl;

	sorter.sort(deck);

	printList(deck);
	cout << "Node Cur Count = " << Node::getCurCount();
	cout << endl;
	cout << "Node Max Count = " << Node::getMaxCount();
	cout << endl;
}
int main()
{
	MergeSort msort;
	sortTest(msort);

	QuickSort qsort;
	sortTest(qsort);

	SelSort ssort;          // SelSort class 추가
	sortTest(ssort);

	SelSortR ssort_R;       // SelSortR class 추가
	sortTest(ssort_R);

	cout << "Node Cur Count = " << Node::getCurCount();
	cout << endl;
	cout << "Node Max Count = " << Node::getMaxCount();

	return 0;
}





