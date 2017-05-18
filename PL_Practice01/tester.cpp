/*
 * 	Project #1
	���� STL vector�� �̿��ؼ� ����� ��ȭ��ȣ��

	����

	1. �־��� PhoneContactVector ���
	2. PhoneContactArray�� vector�� �ٲ۴�
	3. update �Լ��� remove, insert�� ���� ����, ���� ã�� �����ϴ� ������ �ٲ�
	4. listAll()
	5. ��ȣ, �̸��� �ּҷκ��� �̸��� ã�Ƴ��� find �Լ� �ϼ�(�׽�Ʈ)
	6. �׽�Ʈ ���̽� �߰� -- insert, remove, update �� �ִ� �̸�, ���� �̸� ���� ����
	7. ������ listAll()
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

vector<Entry> vectorPhoneBook;           // Entry -> vector�� ���� ���� �Ҵ�

void insert(string name, int number, string email);
void remove(string name);
void update(string name, int number, string email);

string find(int number);                 // ��ȣ�� ���� ����� �̸� ��ȯ
string find(ValueInfo val);              // ValueInfo�� ���� ����� �̸� ��ȯ
string findName(string email);           // �̸����� ���� ����� �̸� ��ȯ


string find(int number)                                         // ��ȭ��ȣ�� ���� ����� �̸� ��ȯ
{
	for(int i=0; i<vectorPhoneBook.size(); i++)
	{
		if(vectorPhoneBook[i].valueInfo.phoneNumber == number)
		{
			return vectorPhoneBook[i].phoneName;
		}
	}
	return "number�� ã�� �� �����ϴ�.";
}

string find(ValueInfo val)                                  // ��ȣ�� �̸��� �ּҸ� ���� ����� �̸��� ��ȯ
{
	for(int i=0; i<vectorPhoneBook.size(); i++)
	{
		if(vectorPhoneBook[i].valueInfo.phoneNumber == val.phoneNumber)
			if(vectorPhoneBook[i].valueInfo.emailAddress == val.emailAddress)
				return vectorPhoneBook[i].phoneName;
	}
	return "ValueInfo�� ã�� �� �����ϴ�.";
}

string findName(string email)                                   // �̸����� ���� ����� �̸� ��ȯ
{
	for(int i=0; i<vectorPhoneBook.size(); i++)
	{
		if(vectorPhoneBook[i].valueInfo.emailAddress == email)
			return vectorPhoneBook[i].phoneName;
	}
	return "E-mail�� ã�� �� �����ϴ�.";
}

int findLoc(string name){                                       // �̸��� ���� vector �� index �� ��ȯ
	for (int i=0; i<vectorPhoneBook.size(); ++i){
		if (vectorPhoneBook[i].phoneName == name)
			return i;
	}
	return -1; // not found
}

ValueInfo find(string name){                                     // �̸��� ���� ValueInfo(�̸���, ��ȭ��ȣ) ��ȯ
	int loc = findLoc(name);
	if (loc == -1)
		return viNull; // not found
	return vectorPhoneBook[loc].valueInfo;
}

void insert(string name, int number, string email){               // �迭�� ������ ��� ���� vector�� ����
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

void update(string name, int number, string email){        // update �Լ��� remove, insert�� ���� ����, ���� ã�� ����
	int index = findLoc(name);

	if(index == -1)
		cout << "***Error -- Name not found" << endl;

	else{
		vectorPhoneBook[index].valueInfo.phoneNumber = number;
		vectorPhoneBook[index].valueInfo.emailAddress = email;
	}
}

void update(string name, int number){                  // �̸�(key)�� ���� vector index�� ã�� ��ȣ�� ����
	int index = findLoc(name);
	if(index == -1)
		cout << "***Error -- Name not found" << endl;

	else
		vectorPhoneBook[index].valueInfo.phoneNumber = number;
}

void update(string name, string email){                // �̸�(key)�� ���� vector index�� ã�� E-mail�� ����
	int index = findLoc(name);
	if(index == -1)
		cout << "***Error -- Name not found" << endl;

	else
		vectorPhoneBook[index].valueInfo.emailAddress = email;
}

void listAll(){                                                       // ��� vector ���� ����Ʈ �� ���
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

	ValueInfo* trueValue = new ValueInfo(5165, "leebh@email.com");      // �ùٸ� ��ȣ�� �̸����� ���� ValueInfo ����
	ValueInfo* falseValue = new ValueInfo(0000, "sungkwon@email.com");  // �ùٸ��� ���� ��ȣ�� �̸����� �Բ� ���� ValueInfo ����

	cout << "List All Inserted Entry" << endl;
	listAll();

	remove("Kim KS");
	insert("Kim CS", 5555, "kimcs@email.com");
	update("Kang JH", 5999);
	update("Park SH", "ILovePL@email.com");
	update("Lee YH", 0000, "PLA+@email.com");
	cout << "Find Phone Number By Name -- Kim CS	" << find("Kim CS").phoneNumber << endl;  // �̸� -> ��ȣ ã��
	cout << "Find Name By Phone Number -- 5125	" << find(5125) << endl;                      // ��ȣ -> �̸� ã��
	cout << "Find Email Address By Name -- Kim CS	" << find("Kim CS").emailAddress << endl;  // �̸� -> �̸��� ã��
	cout << "Find Name By Email Address -- leedi@email.com    " << findName("leedi@email.com") << endl;  // �̸��� -> �̸� ã��
	cout << "Find Name By Email & Number -- 5165, leebh@email.com    "<<find(*trueValue)<<endl;   // ValueInfo(��ȣ, �̸���) -> �̸�
	cout<<endl;


	cout<<"  -------------- ERROR Code --------------------"<<endl;     // Test case - vector ���� ���� �ƴ� ���� ã�� ���
	cout<<endl;

	remove("Sung CK");                                // Sung CK�� ���⶧���� Error �߻�
	insert("Kang JH", 0000, "Sungkwon@email.com");    // Kang JH�� �̹� �����ϱ� ������ ���� �Ұ�
	update("Cho SK", 0000);                           // Cho SK�� ���⶧���� Error �߻�
	update("Cho SK", "ChoSung@email.com");            // Cho SK�� ���⶧���� Error �߻�
	update("Cho SK", 0000, "Chosung@email.com");      // Cho SK�� ���⶧���� Error dh�߻�
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







