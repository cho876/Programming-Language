#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "ListSort.h"

class MergeSort: public ListSort {
public:
	MergeSort(){};
	void sort(List& L);
};

#endif /* MERGESORT_H_ */
