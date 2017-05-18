#ifndef PHONECONTACTLIST_H_
#define PHONECONTACTLIST_H_

#include "List.h"   // #include <list> -> #include "List.h"
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
typedef Iterator Iter;   // List.h�� �ִ� Iterator ��� (CIter, Iter -> Iter �ϳ��� ���)
typedef Iterator CIter;

class PhoneContactList: public PhoneContact {
public:
	PhoneContactList();
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
	ValueInfo viNull;
	List contactTable;   // List.h�� List ���
	Iter findLoc(string name);
	CIter findLocConst (string name) const;
	CIter findNumConst (int num) const;
	CIter findEmailConst (string email) const;
	CIter findValueConst (ValueInfo val) const;

};

#endif /* PHONECONTACTLIST_H_ */
