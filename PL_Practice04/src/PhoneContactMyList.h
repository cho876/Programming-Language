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

	bool insert(string name, int number, string email);    // List ����
	bool remove(string name);                              // List ����

	bool update(string name, int number, string email);   // �̸��� ���� ��ȣ, �̸��� ����
	bool update(string name, int number);                 // �̸��� ���� ��ȣ ����
	bool update(string name, string email);               // �̸��� ���� �̸��� ����

	string find(int num) const;                    // ��ȣ�� ���� �̸� ã��
	string find(ValueInfo) const;                  // ValueInfo�� ���� �̸� ã��
	string findName(string email) const;           // �̸����� ���� �̸� ã��
	ValueInfo find(string name) const;             // �̸��� ���� ValueInfo ã��
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
