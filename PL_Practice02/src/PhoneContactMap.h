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
	bool insert(string name, int number, string email);   // map ����
	bool remove(string name);                             // map ����

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
	map<string, ValueInfo> contactTable;
};

#endif /* PHONECONTACTMAP_H_ */
