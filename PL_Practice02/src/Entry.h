#ifndef ENTRY_H_
#define ENTRY_H_

#include <string>
using namespace std;

class ValueInfo {
public:
	int phoneNumber;
	string emailAddress;
	ValueInfo(){
		phoneNumber = -99;
	}
	ValueInfo(int num, string email){
		phoneNumber = num;
		emailAddress = email;
	}
};

class Entry {
public:
	string phoneName;
	ValueInfo valueInfo;
	Entry(){
		phoneName = "";
		valueInfo.phoneNumber = -1;
		valueInfo.emailAddress = "";
	}
	Entry(string name, int num){
		phoneName = name;
		valueInfo.phoneNumber = num;
		valueInfo.emailAddress = this->valueInfo.emailAddress;
	}
	Entry(string name, int num, string email) {
		phoneName = name;
		valueInfo.phoneNumber = num;
		valueInfo.emailAddress = email;
	}
};

#endif /* ENTRY_H_ */
