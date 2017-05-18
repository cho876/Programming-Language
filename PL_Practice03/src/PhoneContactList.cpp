#include <iostream>
#include "List.h"

using namespace std;

#include "Entry.h"
#include "PhoneContactList.h"

ValueInfo viNull;

PhoneContactList::PhoneContactList() { }

bool PhoneContactList::insert(string name, int number, string email){  // �̸��� ���� List �߰�
	Iter iter = findLoc(name);
	if (iter != contactTable.end()){               // �̹� �̸��� �ش��ϴ� ���� ���� ���
		cout << "*** [LIST] Error -- Already Exist in List" << endl;
		return false;
	}
	contactTable.push_back(Entry(name, number, email));  // �� ���� ��� push
	return true;
}

bool PhoneContactList::remove(string name){        // �̸��� ���� Lish ����
	Iter iter = findLoc(name);
	if (iter == contactTable.end()){               // �̸��� �ش��ϴ� ���� ���� ��
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	contactTable.erase(iter);
	return true;
}

bool PhoneContactList::update(string name, int number, string email){  // �̸��� ���� ��ȣ, �̸��� ����
	Iter iter = findLoc(name);
	if (iter == contactTable.end()){               // �̸��� �ش��ϴ� ���� ���� ���
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	else{
		iter->valueInfo.phoneNumber = number;
		iter->valueInfo.emailAddress = email;
		return true;
	}
}

bool PhoneContactList::update(string name, int number){       // �̸��� ���� ��ȣ ����
	Iter iter = findLoc(name);
	if (iter == contactTable.end()){               // �̸��� �ش��ϴ� ���� ���� ��
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	else{
		iter->valueInfo.phoneNumber = number;
		return true;
	}
}

bool PhoneContactList::update(string name, string email){   // �̸��� ���� �̸��� ����
	Iter iter = findLoc(name);
	if (iter == contactTable.end()){               // �̸��� �ش��ϴ� ���� ���� ��
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	else{
		iter->valueInfo.emailAddress = email;
		return true;
	}
}

ValueInfo PhoneContactList::find(string name) const {  // �̸��� ���� ValueInfo ã��
	Iter iter = findLocConst(name);
	if (iter==contactTable.end()){
		cout << "*** [LIST] Error -- Name not found" << endl;
		return viNull;
	}
	else
		return iter->valueInfo;
}

string PhoneContactList::find(int num) const{    // ��ȣ�� ���� �̸� ã��
	Iter iter = findNumConst(num);
	if (iter==contactTable.end())
		return "*** [LIST] Error -- Number not found";
	else
		return iter->phoneName;
}

string PhoneContactList::find(ValueInfo val) const{    // ValueInfo�� ���� �̸� ã��
	Iter iter = findValueConst(val);
	if (iter==contactTable.end())
		return "*** [LIST] Error -- ValueInfo not found";
	else
		return iter->phoneName;
}

string PhoneContactList::findName(string email) const{   // �̸����� ���� �̸� ã��
	Iter iter = findEmailConst(email);
	if (iter==contactTable.end())
		return "*** [LIST] Error -- E-mail not found";
	else
		return iter->phoneName;
}

void PhoneContactList::listAll() const{          // ��� List �� ���
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	Iter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		cout << iter->phoneName << "		"
				<<	iter->valueInfo.phoneNumber << "	"
				<< iter->valueInfo.emailAddress << endl;
	}
}
Iter PhoneContactList::findLoc(string name){    // �̸��� ���� ��ġ ã��
	Iter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}
CIter PhoneContactList::findLocConst (string name) const {   // �̸��� ���� ��ġ ã��
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}

CIter PhoneContactList::findNumConst (int num) const{   // ��ȣ�� ���� ��ġ ã��
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->valueInfo.phoneNumber == num)
			return iter;
	}
	return iter; // not found, iter==end()
}

CIter PhoneContactList::findEmailConst(string email) const{   // �̸����� ���� ��ġ ã��
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
	if (iter->valueInfo.emailAddress == email)
		return iter;
	}
	return iter; // not found, iter==end()
}

CIter PhoneContactList::findValueConst(ValueInfo val) const{   // ValueInfo�� ���� ��ġ ã��
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
	if (iter->valueInfo.emailAddress == val.emailAddress && iter->valueInfo.phoneNumber == val.phoneNumber)
		return iter;
	}
	return iter; // not found, iter==end()
}
