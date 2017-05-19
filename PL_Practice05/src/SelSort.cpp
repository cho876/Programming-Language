#include "SelSort.h"

Iterator nPos(List& L, int n){                     // n번째 만큼 list 이동
	Iterator cp;
	int count = 0;
	for (cp = L.begin(); cp!=L.end(); cp++) {
		if (count == n){
			break;
		}
		count ++;
	}
	return cp;
}

Iterator getMin (const List& L, Iterator pos) {         // 가장 작은 값 반환
	Iterator minIter;
	String lowValue = "~~~";
	for (Iterator cp = pos; cp!=L.end(); cp++) {
		if (lowValue > *cp){
			minIter = cp;
			lowValue = *cp;
		}
	}
	return minIter;
}

void swapNode (List& L, Iterator it1, Iterator it2){    // swaping
	if (it1 == L.end() || it2 == L.end())
		return;
	if (it1 == it2)
		return;
	String val1 = *it1;
	String val2 = *it2;
	*it1 = val2;
	*it2 = val1;

}

void SelSort::sort(List& L){      // SelSort sorting 작업
	int lsize = L.size();
	for (int i=0; i<lsize; ++i){
		for (int j=i; j<lsize; ++j){
			Iterator rest = nPos(L, j);
			Iterator minit = getMin(L, rest);
			swapNode(L, rest, minit);
		}
	}
}
