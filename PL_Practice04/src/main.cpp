/*
 * 	Project #4
	���� project#3���� ���� PhoneContact�� PhoneContactOperator�� ������ ������ ���� ����

	����

	1. string�� String(StringProject�� ����)���� �ٲ� ��
	2. String find(int phone) --> return Name �Լ� �߰�
	3. main.cpp�� ��� ���� ������ �׽�Ʈ �� �� �ְ� ����
 */

#include <iostream>
#include "String.h"  // StringProject�� string Ŭ���� ���

using namespace std;

#include "PhoneContactMyList.h"
#include "PhoneContactMap.h"
#include "PhoneContactVector.h"

string nameData[] = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH", "Bae JM", "Lee DI", "Lee BH", "Jang WH",
		"Chun WY", "Cho SK", "Kwon JM", "Woo HK", "Song HY", "Yee HJ"};
	// "Cho SK", "Kwon JM", "Woo HK", "Song HY", "Yee HJ" �߰� �Է�

int numberData[] = {5023, 5002, 5008, 5067, 5038, 5381, 5125, 5165, 5684, 5752, 1111, 2222, 3333, 4444, 1234};
   // 1111, 2222, 3333, 4444, 1234 �߰� �Է�

string emailData[] = {
		"parksh@email.com", "kangjh@email.com", "kimks@email.com", "leeyh@email.com", "kangsh@email.com",
		"baejm@email.com", "leedi@email.com", "leebh@email.com", "jangwh@email.com", "chunwy@email.com",
		"chosk@email.com", "kwonjm@email.com", "woohk@email.com", "songhy@email.com", "yeehj@email.com"
		};
	// "chosk@email.com", "kwonjm@email.com", "woohk@email.com", "songhy@email.com", "yeehj@email.com" �߰� �Է�

PhoneContactMyList pbList;
PhoneContactMap pbMap;
PhoneContactVector pbVector;

int incount = 15;
void testPhoneBook(PhoneContact* pb, string pbType){
	cout << "***Test "+pbType+"PhoneBook***" << endl;


	for (int i=0; i < incount; ++i){
		if (!pb->insert(nameData[i]+"-"+pbType[0], numberData[i], emailData[i])){    // List, map, Vector ����
			cout << "***Error in Insert***" + nameData[i]+"-"+pbType[0]<< endl;
		};
	}
	cout << "***List All "+pbType+" PhoneBook" << endl;
	pb->listAll();                                          // �����ϱ� �� ��� �� ���

	cout<<endl;
	cout<<"################################# ERROR Code in "+pbType+"######################################"<<endl;
	if (!pb->insert(nameData[9]+"-"+pbType[0], numberData[9], emailData[9])){    // ���� �̹� �����ϴ� ��� ���� �Ұ�
		cout << "    Error in Insert -- " + nameData[9]+"-"+pbType[0]<< endl;
	};
	if (!pb->remove(string("Heo JM-")+pbType[0])){                               // ���� �������� ���� ��� ���� �Ұ�
		cout << "    Error in Remove --" + string("Heo JM-")+pbType[0]<< endl;
	};
	if (!pb->update(string("Mu SH-")+pbType[0], 8909)){                          // �̸��� �������� ���� ��� ���� �Ұ�
		cout << "    Error in Update --" + string("Mu SH-")+pbType[0]<< endl;
	};
	if (!pb->update(string("Mu SH-")+pbType[0], "mush@email.com")){              // �̸��� �������� ���� ��� ���� �Ұ�
		cout << "    Error in Update --" + string("Mu SH-")+pbType[0]<< endl;
	};
	if (!pb->update(string("Mu SH-")+pbType[0], 8909, "mush@email.com")){        // �̸��� �������� ���� ��� ���� �Ұ�
		cout << "    Error in Update --" + string("Mu SH-")+pbType[0]<< endl;
	};

	cout<<endl<<"----------- find Error ------------"<<endl;
	cout << "[ERROR] Find Phone Number By Name -- Hu fs	" << pb->find(string("Hu fs-")+pbType[0]).phoneNumber<<endl;
		// �̸��� �������� ���� ��� ��ȣ ã�� �Ұ�

	cout << "[ERROR] Find Email Address By Name -- Hu fs " << pb->find(string("Hu fs-")+pbType[0]).emailAddress<<endl;
		// �̸��� �������� ���� ��� �̸��� ã�� �Ұ�

	cout << pb->find(1010)<<endl;
	cout << "[ERROR] Find Name By Phone Number -- 1010   " << endl;
		// ��ȣ�� �������� ���� ��� �̸� ã�� �Ұ�

	cout<< pb->findName("empty@email.com")<<endl;
	cout << "[ERROR] Find Name By Email Address -- empty@email.com  " << endl;
		// �̸����� �������� ���� ��� �̸� ã�� �Ұ�

	cout<<"################################################################################################"<<endl;


	if (!pb->insert(string("Kim CS-")+pbType[0], 5555, "kimcs@email.com")){   // �̸��� ���� ��ȣ, �̸��� ����
		cout << "*** Error in Insert --" + string("Kim CS-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->update(string("Kang JH-")+pbType[0], 5999)){                  // �̸��� ���� ��ȣ ����
		cout << "*** Error in Update --" + string("Kang JH-")+pbType[0] + " ***"<< endl;
	};

	cout << "Find Phone Number By Name -- Kim CS	" << pb->find(string("Kim CS-")+pbType[0]).phoneNumber<<endl;
		// �̸��� ���� ��ȣ ã��

	cout << "Find Email Address By Name -- Kim CS	" << pb->find(string("Kim CS-")+pbType[0]).emailAddress << endl;
		// �̸��� ���� �̸��� ã��

	cout << "Find Name By Phone Number -- 1111    " << pb->find(1111)<<endl;
		// ��ȣ�� ���� �̸� ã��

	cout << "Find Name By Email Address -- kwonjm@email.com  " << pb->findName("kwonjm@email.com")<<endl;
		// �̸����� ���� �̸� ã��

	cout << "***List All Updated Entry" << endl;
	pb->listAll();                     // ���� �� ��� ����Ʈ �� ���
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
