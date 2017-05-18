#ifndef PHONECONTACTLIST_H_
#define PHONECONTACTLIST_H_

#include <list>
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
typedef list<Entry>::iterator Iter;
typedef list<Entry>::const_iterator CIter;

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
	list<Entry> contactTable;
	Iter findLoc(string name);
	CIter findLocConst (string name) const;
	CIter findNumConst (int num) const;
	CIter findEmailConst (string email) const;
	CIter findValueConst (ValueInfo val) const;

};

#endif /* PHONECONTACTLIST_H_ */
