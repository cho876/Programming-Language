#include "PhoneContactMyList.h"

#include <iostream>

ValueInfo viNull;


PhoneContactMyList::~PhoneContactMyList(){
	delete pListPhoneContact;
}

PhoneContactMyList::PhoneContactMyList(const PhoneContactMyList& right){
	pListPhoneContact = new List;
	Iterator iter;
	for (iter=right.pListPhoneContact->begin(); iter!=right.pListPhoneContact->end(); iter++){
		pListPhoneContact->push_back(Entry(iter->phoneName, iter->valueInfo.phoneNumber, iter->valueInfo.emailAddress));
	}
}

bool PhoneContactMyList::insert(string name, int number, string email)  // 이름을 통해 List 추가
{
	Iterator iter = findLoc(name);
	if (iter != pListPhoneContact->end()){               // 이미 이름에 해당하는 값이 있을 경우
		cout << "*** [LIST] Error -- Already Exist in List" << endl;
		return false;
	}
	pListPhoneContact->push_back(Entry(name, number, email));  // 그 외의 경우 push
	return true;
}

bool PhoneContactMyList::remove(string name)        // 이름을 통해 Lish 제거
{
	Iterator iter = findLoc(name);
	if (iter == pListPhoneContact->end()){               // 이름에 해당하는 값이 없을 때
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	pListPhoneContact->erase(iter);
	return true;
}

bool PhoneContactMyList::update(string name, int number, string email)  // 이름을 통해 번호, 이메일 수정
{
	Iterator iter = findLoc(name);
	if (iter == pListPhoneContact->end()){               // 이름에 해당하는 값이 없을 경우
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	iter->valueInfo.phoneNumber = number;
	iter->valueInfo.emailAddress = email;
	return true;
}

bool PhoneContactMyList::update(string name, int number){       // 이름을 통해 번호 수정
	Iterator iter = findLoc(name);
	if (iter == pListPhoneContact->end()){               // 이름에 해당하는 값이 없을 때
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	else{
		iter->valueInfo.phoneNumber = number;
		return true;
	}
}

bool PhoneContactMyList::update(string name, string email){   // 이름을 통해 이메일 수정
	Iterator iter = findLoc(name);
	if (iter == pListPhoneContact->end()){               // 이름에 해당하는 값이 없을 때
		cout << "*** [LIST] Error -- Name not found" << endl;
		return false;
	}
	else{
		iter->valueInfo.emailAddress = email;
		return true;
	}
}

ValueInfo PhoneContactMyList::find(string name) const {  // 이름을 통해 ValueInfo 찾기
	Iterator iter = findLocConst(name);
	if (iter==pListPhoneContact->end()){
		cout << "*** [LIST] Error -- Name not found" << endl;
		return viNull;
	}
	return iter->valueInfo;
}

string PhoneContactMyList::find(int num) const{    // 번호를 통해 이름 찾기
	Iterator iter = findNumConst(num);
	if (iter==pListPhoneContact->end())
		return "*** [LIST] Error -- Number not found";
	else
		return iter->phoneName;
}

string PhoneContactMyList::find(ValueInfo val) const{    // ValueInfo를 통해 이름 찾기
	Iterator iter = findValueConst(val);
	if (iter==pListPhoneContact->end())
		return "*** [LIST] Error -- ValueInfo not found";
	else
		return iter->phoneName;
}

string PhoneContactMyList::findName(string email) const{   // 이메일을 통해 이름 찾기
	Iterator iter = findEmailConst(email);
	if (iter==pListPhoneContact->end())
		return "*** [LIST] Error -- E-mail not found";
	else
		return iter->phoneName;
}

void PhoneContactMyList::listAll() const          // 모든 List 값 출력
{
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
		cout << iter->phoneName << "		"
				<<	iter->valueInfo.phoneNumber << "	"
				<< iter->valueInfo.emailAddress << endl;
	}
}

ValueInfo PhoneContactMyList::operator[](string name) const
{
	return find(name);
}
ValueInfo& PhoneContactMyList::operator[](string name)
{
	Iterator iter = findLoc(name);
	if (iter == pListPhoneContact->end()){
		pListPhoneContact->insert(iter, Entry(name, -1, ""));
		iter = findLoc(name);
	}
	return iter->valueInfo;
}

Iterator PhoneContactMyList::findLoc(string name)   // 이름을 통해 위치 찾기
{
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
		if (iter->phoneName == name) return iter;
	}
	return iter;
}
Iterator PhoneContactMyList::findLocConst(string name) const   // 이름을 통해 위치 찾기
{
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
		if (iter->phoneName == name) return iter;
	}
	return iter;
}

Iterator PhoneContactMyList::findNumConst (int num) const{   // 번호를 통해 위치 찾기
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
		if (iter->valueInfo.phoneNumber == num)
			return iter;
	}
	return iter; // not found, iter==end()
}

Iterator PhoneContactMyList::findEmailConst(string email) const{   // 이메일을 통해 위치 찾기
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
	if (iter->valueInfo.emailAddress == email)
		return iter;
	}
	return iter; // not found, iter==end()
}

Iterator PhoneContactMyList::findValueConst(ValueInfo val) const{   // ValueInfo를 통해 위치 찾기
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
	if (iter->valueInfo.emailAddress == val.emailAddress && iter->valueInfo.phoneNumber == val.phoneNumber)
		return iter;
	}
	return iter; // not found, iter==end()
}

PhoneContactMyList& PhoneContactMyList::operator=(const PhoneContactMyList& right){
	if (this != &right){
		delete pListPhoneContact;
		pListPhoneContact = new List;
		Iterator iter;
		for (iter=right.pListPhoneContact->begin(); iter!=right.pListPhoneContact->end(); iter++){
			pListPhoneContact->push_back(Entry(iter->phoneName, iter->valueInfo.phoneNumber, iter->valueInfo.emailAddress));
		}
	}
	return *this;
}

PhoneContactMyList& PhoneContactMyList::operator+=(const PhoneContactMyList& right)
{
	Iterator ir;
	for (ir=right.pListPhoneContact->begin(); ir!=right.pListPhoneContact->end(); ir++){
		insert(ir->phoneName, ir->valueInfo.phoneNumber,ir->valueInfo.emailAddress);
	}
   return *this;
}




