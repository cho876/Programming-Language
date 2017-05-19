#include "SelSortR.h"

Iterator getMin (const List& L) {        // 가작 정은 값 반환
	Iterator minIter;
	String lowValue = "~~~";
	for (Iterator cp = L.begin(); cp!=L.end(); cp++) {
		if (lowValue > *cp){
			minIter = cp;
			lowValue = *cp;
		}
	}
	return minIter;
}

String removeMin(List& L){               // 가장 적은 값 반환 및 제거
	Iterator minit = getMin(L);
	String res = *minit;
	L.erase(minit);
	return res;
}

void SelSortR::sort (List& L) {          // SelSortR sorting 작업
	if (L.size() <= 1)
		return;
	String minVal = removeMin(L);
	sort(L);
	L.push_front(minVal);
}
