#include <iostream>
#include <map>
using namespace std;

#include "Entry.h"
#include "PhoneContactMap.h"

//ValueInfo viNull;

PhoneContactMap::PhoneContactMap() { }

bool PhoneContactMap::insert(string name, int number, string email){   // map 삽입
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){              // 중복되는 이름이 없을 경우
		contactTable[name] = ValueInfo(number, email);
		return true;
	}
	else{                                                  // 중복되는 이름 발견 시, error 발생
		cout << "*** [MAP] Error -- Already Exist in Map" << endl;
		return false;
	}
}

bool PhoneContactMap::remove(string name){       // map 제거
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){             // 이름을 찾지 못했을 경우
		cout << "*** [MAP] Error -- Name not found" << endl;
		return false;
	}
	contactTable.erase(iter);
	return true;
}

bool PhoneContactMap::update(string name, int number, string email){   // 이름을 통해 번호, 이메일 수정
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){             // 이름을 찾지 못했을 경우
		cout << "*** [MAP] Error -- Name not found" << endl;
		return false;
	}
	contactTable[name] = ValueInfo(number, email);
	return true;
}

bool PhoneContactMap::update(string name, int number){      // 이름을 통해 번호 수정
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){             // 이름을 찾지 못했을 경우
		cout << "*** [MAP] Error -- Name not found" << endl;
		return false;
	}
	contactTable.at(name).phoneNumber = number;
	return true;
}

bool PhoneContactMap::update(string name, string email){    // 이름을 통해 이메일 수정
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end()){              // 이름을 찾기 못했을 경우
		cout << "*** [MAP] Error -- Name not found" << endl;
		return false;
	}
	contactTable.at(name).emailAddress = email;
	return true;
}

string PhoneContactMap::find(int num) const{        // 번호를 통해 이름 찾기
	CMIter cmiter = contactTable.begin();
	for(; cmiter != contactTable.end(); ++cmiter){
		if(cmiter->second.phoneNumber == num)
			return cmiter->first;
	}
	return "*** [MAP] Error -- Name not found";
}

string PhoneContactMap::find(ValueInfo val) const{     // ValueInfo를 통해 이름 찾기
	CMIter cmiter = contactTable.begin();
	for(; cmiter != contactTable.end(); ++cmiter){
		if((cmiter->second.emailAddress == val.emailAddress) && (cmiter->second.phoneNumber == val.phoneNumber))
			return cmiter->first;
	}
	return "*** [MAP] Error -- ValueInfo not found";
}

string PhoneContactMap::findName(string email) const{   // 이메일을 통해 이름 찾기
	CMIter cmiter = contactTable.begin();
	for(; cmiter != contactTable.end(); ++cmiter){
		if(cmiter->second.emailAddress == email)
			return cmiter->first;
	}
	return "*** [MAP] Error -- E-mail not found";
}

ValueInfo PhoneContactMap::find(string name) const {    // 이름을 통해 ValueInfo 찾기
	CMIter cmiter = contactTable.find(name);
	if (cmiter == contactTable.end()){  // 못찾았을 경우
		cout << "*** [MAP] Error -- Name not found" << endl;
		return viNull;
	}
	return contactTable.at(name);
}

void PhoneContactMap::listAll() const {         // map 모든 값 출력
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	CMIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		cout << iter->first << "		"
				<<	iter->second.phoneNumber << "	"
				<< iter->second.emailAddress << endl;
	}
}

