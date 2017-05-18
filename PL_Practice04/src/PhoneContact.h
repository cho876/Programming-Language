#ifndef PHONECONTACT_H_
#define PHONECONTACT_H_

#include "String.h"  // StringProject의 string 클래스 사용
using namespace std;

class PhoneContact {
public:
	PhoneContact(){}
	virtual bool insert(string name, int number, string email)=0;  // 삽입 함수
	virtual bool remove(string name)=0;                           // 제거 함수

	virtual bool update(string name, int number, string email)=0;   // 이름을 통해 번호, 이메일 수정
	virtual bool update(string name, int number)=0;             // 이름을 통해 번호 수정
	virtual bool update(string name, string email)=0;          // 이름을 통해 이메일 수정

	virtual string find(int num) const=0;   // 번호를 통해 이름을 찾기
	virtual string find(ValueInfo) const=0;  // valueInfo를 통해 이름을 찾기
	virtual string findName(string email) const=0;  // 이메일을 통해 이름츨 찾기
	virtual ValueInfo find(string name) const=0;    // 이름을 통해 ValueInfo 찾기

	virtual void listAll()const=0;    // 모든 값 출력
};

#endif /* PHONECONTACT_H_ */
