#ifndef SELSORT_H_
#define SELSORT_H_

#include "ListSort.h"

class SelSort: public ListSort {
public:
	SelSort(){};
	void sort(List& L);
};

#endif /* SELSORT_H_ */
