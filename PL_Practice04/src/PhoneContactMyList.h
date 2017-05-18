#ifndef PHONECONTACTMYLIST_H_
#define PHONECONTACTMYLIST_H_

#include "List.h"
#include "Entry.h"
#include "PhoneContact.h"

class PhoneContactMyList : public PhoneContact {
public:
	PhoneContactMyList(){
		pListPhoneContact = new List;
	};
	~PhoneContactMyList();
	PhoneContactMyList(const PhoneContactMyList& right);
	PhoneContactMyList& operator=(const PhoneContactMyList& right);

	ValueInfo operator[](string name)const;
	ValueInfo& operator[](string name);
	PhoneContactMyList& operator+=(const PhoneContactMyList& right);

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
	Iterator findLoc(string name);
	Iterator findLocConst (string name) const;
	Iterator findNumConst (int num) const;
	Iterator findEmailConst (string email) const;
	Iterator findValueConst (ValueInfo val) const;
	List* pListPhoneContact;

};
#endif /* PHONECONTACTMYLIST_H_ */
