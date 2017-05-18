#ifndef PHONECONTACT_H_
#define PHONECONTACT_H_

#include "String.h"  // StringProject�� string Ŭ���� ���
using namespace std;

class PhoneContact {
public:
	PhoneContact(){}
	virtual bool insert(string name, int number, string email)=0;  // ���� �Լ�
	virtual bool remove(string name)=0;                           // ���� �Լ�

	virtual bool update(string name, int number, string email)=0;   // �̸��� ���� ��ȣ, �̸��� ����
	virtual bool update(string name, int number)=0;             // �̸��� ���� ��ȣ ����
	virtual bool update(string name, string email)=0;          // �̸��� ���� �̸��� ����

	virtual string find(int num) const=0;   // ��ȣ�� ���� �̸��� ã��
	virtual string find(ValueInfo) const=0;  // valueInfo�� ���� �̸��� ã��
	virtual string findName(string email) const=0;  // �̸����� ���� �̸��� ã��
	virtual ValueInfo find(string name) const=0;    // �̸��� ���� ValueInfo ã��

	virtual void listAll()const=0;    // ��� �� ���
};

#endif /* PHONECONTACT_H_ */
