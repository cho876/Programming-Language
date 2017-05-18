#ifndef PHONECONTACTLIST_H_
#define PHONECONTACTLIST_H_

#include "List.h"   // #include <list> -> #include "List.h"
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
typedef Iterator Iter;   // List.h에 있는 Iterator 사용 (CIter, Iter -> Iter 하나만 사용)
typedef Iterator CIter;

class PhoneContactList: public PhoneContact {
public:
	PhoneContactList();
	bool insert(string name, int number, string email);    // List 삽입
	bool remove(string name);                              // List 제거

	bool update(string name, int number, string email);   // 이름을 통해 번호, 이메일 수정
	bool update(string name, int number);                 // 이름을 통해 번호 수정
	bool update(string name, string email);               // 이름을 통해 이메일 수정

	string find(int num) const;                    // 번호를 통해 이름 찾기
	string find(ValueInfo) const;                  // ValueInfo를 통해 이름 찾기
	string findName(string email) const;           // 이메일을 통해 이름 찾기
	ValueInfo find(string name) const;             // 이름을 통해 ValueInfo 찾기
	void listAll() const;

private:
	ValueInfo viNull;
	List contactTable;   // List.h의 List 사용
	Iter findLoc(string name);
	CIter findLocConst (string name) const;
	CIter findNumConst (int num) const;
	CIter findEmailConst (string email) const;
	CIter findValueConst (ValueInfo val) const;

};

#endif /* PHONECONTACTLIST_H_ */
