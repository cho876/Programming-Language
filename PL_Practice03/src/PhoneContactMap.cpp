#include <iostream>
#include <map>
using namespace std;

#include "Entry.h"
#include "PhoneContactMap.h"

//ValueInfo viNull;

PhoneContactMap::PhoneContactMap() { }

bool PhoneContactMap::insert(string name, int number, string email){   // map ����
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){              // �ߺ��Ǵ� �̸��� ���� ���
		contactTable[name] = ValueInfo(number, email);
		return true;
	}
	else{                                                  // �ߺ��Ǵ� �̸� �߰� ��, error �߻�
		cout << "*** [MAP] Error -- Already Exist in Map" << endl;
		return false;
	}
}

bool PhoneContactMap::remove(string name){       // map ����
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){             // �̸��� ã�� ������ ���
		cout << "*** [MAP] Error -- Name not found" << endl;
		return false;
	}
	contactTable.erase(iter);
	return true;
}

bool PhoneContactMap::update(string name, int number, string email){   // �̸��� ���� ��ȣ, �̸��� ����
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){             // �̸��� ã�� ������ ���
		cout << "*** [MAP] Error -- Name not found" << endl;
		return false;
	}
	contactTable[name] = ValueInfo(number, email);
	return true;
}

bool PhoneContactMap::update(string name, int number){      // �̸��� ���� ��ȣ ����
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){             // �̸��� ã�� ������ ���
		cout << "*** [MAP] Error -- Name not found" << endl;
		return false;
	}
	contactTable.at(name).phoneNumber = number;
	return true;
}

bool PhoneContactMap::update(string name, string email){    // �̸��� ���� �̸��� ����
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){              // �̸��� ã�� ������ ���
		cout << "*** [MAP] Error -- Name not found" << endl;
		return false;
	}
	contactTable.at(name).emailAddress = email;
	return true;
}

string PhoneContactMap::find(int num) const{        // ��ȣ�� ���� �̸� ã��
	CMIter cmiter = contactTable.begin();
	for(; cmiter != contactTable.end(); ++cmiter){
		if(cmiter->second.phoneNumber == num)
			return cmiter->first;
	}
	return "*** [MAP] Error -- Name not found";
}

string PhoneContactMap::find(ValueInfo val) const{     // ValueInfo�� ���� �̸� ã��
	CMIter cmiter = contactTable.begin();
	for(; cmiter != contactTable.end(); ++cmiter){
		if((cmiter->second.emailAddress == val.emailAddress) && (cmiter->second.phoneNumber == val.phoneNumber))
			return cmiter->first;
	}
	return "*** [MAP] Error -- ValueInfo not found";
}

string PhoneContactMap::findName(string email) const{   // �̸����� ���� �̸� ã��
	CMIter cmiter = contactTable.begin();
	for(; cmiter != contactTable.end(); ++cmiter){
		if(cmiter->second.emailAddress == email)
			return cmiter->first;
	}
	return "*** [MAP] Error -- E-mail not found";
}

ValueInfo PhoneContactMap::find(string name) const {    // �̸��� ���� ValueInfo ã��
	CMIter cmiter = contactTable.find(name);
	if (cmiter == contactTable.end()){  // ��ã���� ���
		cout << "*** [MAP] Error -- Name not found" << endl;
		return viNull;
	}
	return contactTable.at(name);
}

void PhoneContactMap::listAll() const {         // map ��� �� ���
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	CMIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		cout << iter->first << "		"
				<<	iter->second.phoneNumber << "	"
				<< iter->second.emailAddress << endl;
	}
}

