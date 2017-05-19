#include "SelSortR.h"

Iterator getMin (const List& L) {        // ���� ���� �� ��ȯ
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

String removeMin(List& L){               // ���� ���� �� ��ȯ �� ����
	Iterator minit = getMin(L);
	String res = *minit;
	L.erase(minit);
	return res;
}

void SelSortR::sort (List& L) {          // SelSortR sorting �۾�
	if (L.size() <= 1)
		return;
	String minVal = removeMin(L);
	sort(L);
	L.push_front(minVal);
}
