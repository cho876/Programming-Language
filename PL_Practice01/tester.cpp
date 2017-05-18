/*
 * 	Project #1
	제목 STL vector를 이용해서 만드는 전화번호부

	내용

	1. 주어진 PhoneContactVector 사용
	2. PhoneContactArray를 vector로 바꾼다
	3. update 함수를 remove, insert로 하지 말고, 직접 찾아 수정하는 것으로 바꿈
	4. listAll()
	5. 번호, 이메일 주소로부터 이름을 찾아내는 find 함수 완성(테스트)
	6. 테스트 케이스 추가 -- insert, remove, update 에 있는 이름, 없는 이름 각각 적용
	7. 마지막 listAll()
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string nameData[] = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH",
				  "Bae JM", "Lee DI", "Lee BH", "Jang WH", "Chun WY"};
int numberData[] = {5023, 5002, 5008, 5067, 5038, 5381, 5125, 5165, 5684, 5752};
string emailData[] = {
		"parksh@email.com", "kangjh@email.com", "kimks@email.com", "leeyh@email.com", "kangsh@email.com",
		"baejm@email.com", "leedi@email.com", "leebh@email.com", "jangwh@email.com", "chunwy@email.com"
		};

class ValueInfo {
public:
	int phoneNumber;
	string emailAddress;
	ValueInfo(){
		phoneNumber = -99;
	}
	ValueInfo(int n, string em){
		phoneNumber = n;
		emailAddress = em;
	}
};

ValueInfo viNull;
class Entry {
public:
	string phoneName;
	ValueInfo valueInfo;
	Entry(){
		phoneName = "";
		valueInfo.phoneNumber = -1;
		valueInfo.emailAddress = "";
	}
	Entry(string s, int n, string em) {
		phoneName = s;
		valueInfo.phoneNumber = n;
		valueInfo.emailAddress = em;
	}
};

vector<Entry> vectorPhoneBook;           // Entry -> vector를 통한 동적 할당

void insert(string name, int number, string email);
void remove(string name);
void update(string name, int number, string email);

string find(int number);                 // 번호를 통해 사용자 이름 반환
string find(ValueInfo val);              // ValueInfo를 통해 사용자 이름 반환
string findName(string email);           // 이메일을 통해 사용자 이름 반환


string find(int number)                                         // 전화번호를 통해 사용자 이름 반환
{
	for(int i=0; i<vectorPhoneBook.size(); i++)
	{
		if(vectorPhoneBook[i].valueInfo.phoneNumber == number)
		{
			return vectorPhoneBook[i].phoneName;
		}
	}
	return "number를 찾을 수 없습니다.";
}

string find(ValueInfo val)                                  // 번호와 이메일 주소를 통해 사용자 이름을 반환
{
	for(int i=0; i<vectorPhoneBook.size(); i++)
	{
		if(vectorPhoneBook[i].valueInfo.phoneNumber == val.phoneNumber)
			if(vectorPhoneBook[i].valueInfo.emailAddress == val.emailAddress)
				return vectorPhoneBook[i].phoneName;
	}
	return "ValueInfo를 찾을 수 없습니다.";
}

string findName(string email)                                   // 이메일을 통해 사용자 이름 반환
{
	for(int i=0; i<vectorPhoneBook.size(); i++)
	{
		if(vectorPhoneBook[i].valueInfo.emailAddress == email)
			return vectorPhoneBook[i].phoneName;
	}
	return "E-mail을 찾을 수 없습니다.";
}

int findLoc(string name){                                       // 이름을 통해 vector 내 index 값 반환
	for (int i=0; i<vectorPhoneBook.size(); ++i){
		if (vectorPhoneBook[i].phoneName == name)
			return i;
	}
	return -1; // not found
}

ValueInfo find(string name){                                     // 이름을 통해 ValueInfo(이메일, 전화번호) 반환
	int loc = findLoc(name);
	if (loc == -1)
		return viNull; // not found
	return vectorPhoneBook[loc].valueInfo;
}

void insert(string name, int number, string email){               // 배열에 선언한 모든 값들 vector에 삽입
	int loc = findLoc(name);
	if (loc == -1){ // insert
		vectorPhoneBook.push_back(Entry(name, number, email));
	}
	else {
		cout << "***Error -- Duplicated Name" << endl;
	}
}
void remove(string name){
	int loc = findLoc(name);
	if (loc != -1){ // there exist name
		// remove array entry at loc
		for (int i=loc+1; i<vectorPhoneBook.size(); ++i){
			vectorPhoneBook[i-1] = vectorPhoneBook[i];
		}
		vectorPhoneBook.pop_back();
	}
	else {
		cout << "***Error -- Name not found" << endl;
	}
}

void update(string name, int number, string email){        // update 함수를 remove, insert로 하지 말고, 직접 찾아 수정
	int index = findLoc(name);

	if(index == -1)
		cout << "***Error -- Name not found" << endl;

	else{
		vectorPhoneBook[index].valueInfo.phoneNumber = number;
		vectorPhoneBook[index].valueInfo.emailAddress = email;
	}
}

void update(string name, int number){                  // 이름(key)을 통해 vector index를 찾고 번호를 수정
	int index = findLoc(name);
	if(index == -1)
		cout << "***Error -- Name not found" << endl;

	else
		vectorPhoneBook[index].valueInfo.phoneNumber = number;
}

void update(string name, string email){                // 이름(key)을 통해 vector index를 찾고 E-mail을 수정
	int index = findLoc(name);
	if(index == -1)
		cout << "***Error -- Name not found" << endl;

	else
		vectorPhoneBook[index].valueInfo.emailAddress = email;
}

void listAll(){                                                       // 모든 vector 내부 리스트 값 출력
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;

	for (int i=0; i<vectorPhoneBook.size(); ++i){
		cout << vectorPhoneBook[i].phoneName << "		"
			 <<	vectorPhoneBook[i].valueInfo.phoneNumber << "	"
			 << vectorPhoneBook[i].valueInfo.emailAddress << endl;
	}
}

int main ()
{
	int incount = 10;
	for (int i=0; i < incount; ++i)
		insert(nameData[i], numberData[i], emailData[i]);

	ValueInfo* trueValue = new ValueInfo(5165, "leebh@email.com");      // 올바른 번호와 이메일을 담은 ValueInfo 저장
	ValueInfo* falseValue = new ValueInfo(0000, "sungkwon@email.com");  // 올바르지 않은 번호와 이메일을 함께 담은 ValueInfo 저장

	cout << "List All Inserted Entry" << endl;
	listAll();

	remove("Kim KS");
	insert("Kim CS", 5555, "kimcs@email.com");
	update("Kang JH", 5999);
	update("Park SH", "ILovePL@email.com");
	update("Lee YH", 0000, "PLA+@email.com");
	cout << "Find Phone Number By Name -- Kim CS	" << find("Kim CS").phoneNumber << endl;  // 이름 -> 번호 찾기
	cout << "Find Name By Phone Number -- 5125	" << find(5125) << endl;                      // 번호 -> 이름 찾기
	cout << "Find Email Address By Name -- Kim CS	" << find("Kim CS").emailAddress << endl;  // 이름 -> 이메일 찾기
	cout << "Find Name By Email Address -- leedi@email.com    " << findName("leedi@email.com") << endl;  // 이메일 -> 이름 찾기
	cout << "Find Name By Email & Number -- 5165, leebh@email.com    "<<find(*trueValue)<<endl;   // ValueInfo(번호, 이메일) -> 이름
	cout<<endl;


	cout<<"  -------------- ERROR Code --------------------"<<endl;     // Test case - vector 내부 값이 아닌 것을 찾을 경우
	cout<<endl;

	remove("Sung CK");                                // Sung CK가 없기때문에 Error 발생
	insert("Kang JH", 0000, "Sungkwon@email.com");    // Kang JH가 이미 존재하기 때문에 삽입 불가
	update("Cho SK", 0000);                           // Cho SK가 없기때문에 Error 발생
	update("Cho SK", "ChoSung@email.com");            // Cho SK가 없기때문에 Error 발생
	update("Cho SK", 0000, "Chosung@email.com");      // Cho SK가 없기때문에 Error dh발생
	cout << "[ERROR] Find Email Address By Name -- Cho SK	" << find("Cho SK").phoneNumber << endl;
	cout << "[ERROR] Find Name By Phone Number -- 1233	" << find(1233) << endl;
	cout << "[ERROR] Find Email Address By Name -- Cho SK	" << find("Cho SK").emailAddress << endl;
	cout << "[ERROR] Find Name By Email Address -- Sungkwon@email.com	" << findName("Sungkwon@email.com")<< endl;
	cout << "[ERROR] Find Name By Email & Number -- 0000, sungkwon@email.com    "<<find(*falseValue)<<endl;
	cout << endl;

	cout << "List All Updated Entry" << endl;
	listAll();

	return 0;
}







