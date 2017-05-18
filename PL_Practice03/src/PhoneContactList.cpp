#include <iostream>
#include "List.h"

using namespace std;

#include "Entry.h"
#include "PhoneContactList.h"

ValueInfo viNull;

PhoneContactList::PhoneContactList() { }

bool PhoneContactList::insert(string name, int number, string email){  // 이름을 통해 List 추가
	Iter iter = findLoc(name);
	if (iter != contactTable.end()){               // 이미 이름에 해당하는 값이 있을 경우
		cout << "*** [LIST] Error -- Already Exist in List" << endl;
		return false;
	}
	contactTable.push_back(Entry(name, number, email));  // 그 외의 경우 push
	return true;
}

bool PhoneContactList::remove(string name){        // 이름을 통해 Lish 제거
	Iter iter = findLoc(name);
	if (iter == contactTable.end()){               // 이름에 해당하는 값이 없을 때
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	contactTable.erase(iter);
	return true;
}

bool PhoneContactList::update(string name, int number, string email){  // 이름을 통해 번호, 이메일 수정
	Iter iter = findLoc(name);
	if (iter == contactTable.end()){               // 이름에 해당하는 값이 없을 경우
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	else{
		iter->valueInfo.phoneNumber = number;
		iter->valueInfo.emailAddress = email;
		return true;
	}
}

bool PhoneContactList::update(string name, int number){       // 이름을 통해 번호 수정
	Iter iter = findLoc(name);
	if (iter == contactTable.end()){               // 이름에 해당하는 값이 없을 때
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	else{
		iter->valueInfo.phoneNumber = number;
		return true;
	}
}

bool PhoneContactList::update(string name, string email){   // 이름을 통해 이메일 수정
	Iter iter = findLoc(name);
	if (iter == contactTable.end()){               // 이름에 해당하는 값이 없을 때
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	else{
		iter->valueInfo.emailAddress = email;
		return true;
	}
}

ValueInfo PhoneContactList::find(string name) const {  // 이름을 통해 ValueInfo 찾기
	Iter iter = findLocConst(name);
	if (iter==contactTable.end()){
		cout << "*** [LIST] Error -- Name not found" << endl;
		return viNull;
	}
	else
		return iter->valueInfo;
}

string PhoneContactList::find(int num) const{    // 번호를 통해 이름 찾기
	Iter iter = findNumConst(num);
	if (iter==contactTable.end())
		return "*** [LIST] Error -- Number not found";
	else
		return iter->phoneName;
}

string PhoneContactList::find(ValueInfo val) const{    // ValueInfo를 통해 이름 찾기
	Iter iter = findValueConst(val);
	if (iter==contactTable.end())
		return "*** [LIST] Error -- ValueInfo not found";
	else
		return iter->phoneName;
}

string PhoneContactList::findName(string email) const{   // 이메일을 통해 이름 찾기
	Iter iter = findEmailConst(email);
	if (iter==contactTable.end())
		return "*** [LIST] Error -- E-mail not found";
	else
		return iter->phoneName;
}

void PhoneContactList::listAll() const{          // 모든 List 값 출력
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	Iter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		cout << iter->phoneName << "		"
				<<	iter->valueInfo.phoneNumber << "	"
				<< iter->valueInfo.emailAddress << endl;
	}
}
Iter PhoneContactList::findLoc(string name){    // 이름을 통해 위치 찾기
	Iter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}
CIter PhoneContactList::findLocConst (string name) const {   // 이름을 통해 위치 찾기
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}

CIter PhoneContactList::findNumConst (int num) const{   // 번호를 통해 위치 찾기
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->valueInfo.phoneNumber == num)
			return iter;
	}
	return iter; // not found, iter==end()
}

CIter PhoneContactList::findEmailConst(string email) const{   // 이메일을 통해 위치 찾기
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
	if (iter->valueInfo.emailAddress == email)
		return iter;
	}
	return iter; // not found, iter==end()
}

CIter PhoneContactList::findValueConst(ValueInfo val) const{   // ValueInfo를 통해 위치 찾기
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
	if (iter->valueInfo.emailAddress == val.emailAddress && iter->valueInfo.phoneNumber == val.phoneNumber)
		return iter;
	}
	return iter; // not found, iter==end()
}
