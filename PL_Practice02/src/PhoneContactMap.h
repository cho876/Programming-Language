#ifndef PHONECONTACTMAP_H_
#define PHONECONTACTMAP_H_

#include <map>
#include "Entry.h"

typedef map<string, ValueInfo>::const_iterator CMIter;
typedef map<string, ValueInfo>::iterator MIter;
#include "PhoneContact.h"

class PhoneContactMap: public PhoneContact {
public:
	PhoneContactMap();
	bool insert(string name, int number, string email);   // map 삽입
	bool remove(string name);                             // map 제거

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
	map<string, ValueInfo> contactTable;
};

#endif /* PHONECONTACTMAP_H_ */
