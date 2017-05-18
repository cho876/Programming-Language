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
	list<Entry> contactTable;
	Iter findLoc(string name);
	CIter findLocConst (string name) const;
	CIter findNumConst (int num) const;
	CIter findEmailConst (string email) const;
	CIter findValueConst (ValueInfo val) const;

};

#endif /* PHONECONTACTLIST_H_ */
