/*
 * 	Project #4
	제목 project#3까지 만든 PhoneContact에 PhoneContactOperator를 참고해 다음과 같이 수정

	내용

	1. string을 String(StringProject에 있음)으로 바꿀 것
	2. String find(int phone) --> return Name 함수 추가
	3. main.cpp를 모든 수정 내용을 테스트 할 수 있게 수정
 */

#include <iostream>
#include "String.h"  // StringProject의 string 클래스 사용

using namespace std;

#include "PhoneContactMyList.h"
#include "PhoneContactMap.h"
#include "PhoneContactVector.h"

string nameData[] = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH", "Bae JM", "Lee DI", "Lee BH", "Jang WH",
		"Chun WY", "Cho SK", "Kwon JM", "Woo HK", "Song HY", "Yee HJ"};
	// "Cho SK", "Kwon JM", "Woo HK", "Song HY", "Yee HJ" 추가 입력

int numberData[] = {5023, 5002, 5008, 5067, 5038, 5381, 5125, 5165, 5684, 5752, 1111, 2222, 3333, 4444, 1234};
   // 1111, 2222, 3333, 4444, 1234 추가 입력

string emailData[] = {
		"parksh@email.com", "kangjh@email.com", "kimks@email.com", "leeyh@email.com", "kangsh@email.com",
		"baejm@email.com", "leedi@email.com", "leebh@email.com", "jangwh@email.com", "chunwy@email.com",
		"chosk@email.com", "kwonjm@email.com", "woohk@email.com", "songhy@email.com", "yeehj@email.com"
		};
	// "chosk@email.com", "kwonjm@email.com", "woohk@email.com", "songhy@email.com", "yeehj@email.com" 추가 입력

PhoneContactMyList pbList;
PhoneContactMap pbMap;
PhoneContactVector pbVector;

int incount = 15;
void testPhoneBook(PhoneContact* pb, string pbType){
	cout << "***Test "+pbType+"PhoneBook***" << endl;


	for (int i=0; i < incount; ++i){
		if (!pb->insert(nameData[i]+"-"+pbType[0], numberData[i], emailData[i])){    // List, map, Vector 삽입
			cout << "***Error in Insert***" + nameData[i]+"-"+pbType[0]<< endl;
		};
	}
	cout << "***List All "+pbType+" PhoneBook" << endl;
	pb->listAll();                                          // 수정하기 전 모든 값 출력

	cout<<endl;
	cout<<"################################# ERROR Code in "+pbType+"######################################"<<endl;
	if (!pb->insert(nameData[9]+"-"+pbType[0], numberData[9], emailData[9])){    // 값이 이미 존재하는 경우 수정 불가
		cout << "    Error in Insert -- " + nameData[9]+"-"+pbType[0]<< endl;
	};
	if (!pb->remove(string("Heo JM-")+pbType[0])){                               // 값이 존재하지 않을 경우 수정 불가
		cout << "    Error in Remove --" + string("Heo JM-")+pbType[0]<< endl;
	};
	if (!pb->update(string("Mu SH-")+pbType[0], 8909)){                          // 이름이 존재하지 않을 경우 수정 불가
		cout << "    Error in Update --" + string("Mu SH-")+pbType[0]<< endl;
	};
	if (!pb->update(string("Mu SH-")+pbType[0], "mush@email.com")){              // 이름이 존재하지 않을 경우 수정 불가
		cout << "    Error in Update --" + string("Mu SH-")+pbType[0]<< endl;
	};
	if (!pb->update(string("Mu SH-")+pbType[0], 8909, "mush@email.com")){        // 이름이 존재하지 않을 경우 수정 불가
		cout << "    Error in Update --" + string("Mu SH-")+pbType[0]<< endl;
	};

	cout<<endl<<"----------- find Error ------------"<<endl;
	cout << "[ERROR] Find Phone Number By Name -- Hu fs	" << pb->find(string("Hu fs-")+pbType[0]).phoneNumber<<endl;
		// 이름이 존재하지 않을 경우 번호 찾기 불가

	cout << "[ERROR] Find Email Address By Name -- Hu fs " << pb->find(string("Hu fs-")+pbType[0]).emailAddress<<endl;
		// 이름이 존재하지 않을 경우 이메일 찾기 불가

	cout << pb->find(1010)<<endl;
	cout << "[ERROR] Find Name By Phone Number -- 1010   " << endl;
		// 번호가 존재하지 않을 경우 이름 찾기 불가

	cout<< pb->findName("empty@email.com")<<endl;
	cout << "[ERROR] Find Name By Email Address -- empty@email.com  " << endl;
		// 이메일이 존재하지 않을 경우 이름 찾기 불가

	cout<<"################################################################################################"<<endl;


	if (!pb->insert(string("Kim CS-")+pbType[0], 5555, "kimcs@email.com")){   // 이름을 통해 번호, 이메일 수정
		cout << "*** Error in Insert --" + string("Kim CS-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->update(string("Kang JH-")+pbType[0], 5999)){                  // 이름을 통해 번호 수정
		cout << "*** Error in Update --" + string("Kang JH-")+pbType[0] + " ***"<< endl;
	};

	cout << "Find Phone Number By Name -- Kim CS	" << pb->find(string("Kim CS-")+pbType[0]).phoneNumber<<endl;
		// 이름을 통해 번호 찾기

	cout << "Find Email Address By Name -- Kim CS	" << pb->find(string("Kim CS-")+pbType[0]).emailAddress << endl;
		// 이름을 통해 이메일 찾기

	cout << "Find Name By Phone Number -- 1111    " << pb->find(1111)<<endl;
		// 번호를 통해 이름 찾기

	cout << "Find Name By Email Address -- kwonjm@email.com  " << pb->findName("kwonjm@email.com")<<endl;
		// 이메일을 통해 이름 찾기

	cout << "***List All Updated Entry" << endl;
	pb->listAll();                     // 수정 후 모든 리스트 값 출력
	cout<<endl;
}

int main ()
{

	PhoneContact* pBooks[] = {&pbList, &pbMap, &pbVector};
	string pbTypes[] = { "List", "Map", "Vector"};

	for (int i=0; i<3; ++i){
		testPhoneBook(pBooks[i], pbTypes[i]);
	}
	return 0;
}
