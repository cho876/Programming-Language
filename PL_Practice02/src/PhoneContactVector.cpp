#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "PhoneContactVector.h"

PhoneContactVector::PhoneContactVector(){};


bool PhoneContactVector::insert(string name, int number, string email)  // Vector ����
{
   int loc = findLoc(name);
   if (loc == -1){
      vectorPhoneBook.push_back(Entry(name, number, email));
      return true;
   }
   else {
      cout << "*** [Vector] Error -- Already Exist in Vector" << endl;
      return false;
   }
}

bool PhoneContactVector::remove(string name){        // Vector ����
   int loc = findLoc(name);
   if (loc != -1){
      for (int i=loc+1; i<vectorPhoneBook.size(); ++i){
         vectorPhoneBook[i-1] = vectorPhoneBook[i];
      }
      vectorPhoneBook.pop_back();
      return true;
   }
   else {
      cout << "*** [Vector] Error -- Name not found" << endl;
      return false;
   }
}

bool PhoneContactVector::update(string name, int number, string email){    // �̸��� ���� ��ȣ, �̸��� ����
   int index = findLoc(name);

   if(index == -1){
      cout << "*** [Vector] Error -- Name not found" << endl;
      return false;
   }

   else{
      vectorPhoneBook[index].valueInfo.phoneNumber = number;
      vectorPhoneBook[index].valueInfo.emailAddress = email;
      return true;
   }
}

bool PhoneContactVector::update(string name, int number)    // �̸��� ���� ��ȣ ����
{
   int index = findLoc(name);
      if(index == -1){
         cout << "*** [Vector] Error -- Name not found" << endl;
         return false;
      }

      else{
         vectorPhoneBook[index].valueInfo.phoneNumber = number;
         return true;
      }
}

bool PhoneContactVector::update(string name, string email)   // �̸��� ���� �̸��� ����
{
   int index = findLoc(name);
   if(index == -1){
      cout << "*** [Vector] Error -- Name not found" << endl;
      return false;
   }

   else{
      vectorPhoneBook[index].valueInfo.emailAddress = email;
      return true;
   }
}

ValueInfo PhoneContactVector::find(string name) const   // �̸��� ���� ValueInfo ã��
{
   int loc = findLoc(name);
   if (loc == -1){
      cout << "*** [Vector] Error -- Name not found" << endl;
      return viNull; // not found
   }
   return vectorPhoneBook[loc].valueInfo;
}

string PhoneContactVector::find(int number) const   // ��ȣ�� ���� �̸� ã��
{
   for(int i=0; i<vectorPhoneBook.size(); i++)
   {
      if(vectorPhoneBook[i].valueInfo.phoneNumber == number)
      {
         return vectorPhoneBook[i].phoneName;
      }
   }
   return"*** [Vector] Error -- Number not found";
}

string PhoneContactVector::find(ValueInfo val) const   // ValueInfo�� ���� �̸� ã��
{
   for(int i=0; i<vectorPhoneBook.size(); i++)
   {
      if(vectorPhoneBook[i].valueInfo.phoneNumber == val.phoneNumber)
         if(vectorPhoneBook[i].valueInfo.emailAddress == val.emailAddress)
            return vectorPhoneBook[i].phoneName;
   }
   return"*** [Vector] Error -- ValueInfo not found";
}

string PhoneContactVector::findName(string email) const   // �̸����� ���� �̸� ã��
{
   for(int i=0; i<vectorPhoneBook.size(); i++)
   {
      if(vectorPhoneBook[i].valueInfo.emailAddress == email)
         return vectorPhoneBook[i].phoneName;
   }
   return"*** [Vector] Error -- Email not found";
}

void PhoneContactVector::listAll() const    // ��� Vector�� ���
{
   cout << "Name" << "      " << "Number" << "   "<< "Email" << endl;

   for (int i=0; i<vectorPhoneBook.size(); ++i){
      cout << vectorPhoneBook[i].phoneName << "      "
          <<   vectorPhoneBook[i].valueInfo.phoneNumber << "   "
          << vectorPhoneBook[i].valueInfo.emailAddress << endl;
   }
}

int PhoneContactVector::findLoc(string name) const   // �̸��� ���� ��ġ ���
{
   for (int i=0; i<vectorPhoneBook.size(); ++i){
      if (vectorPhoneBook[i].phoneName == name)
         return i;
   }
   return -1; // not found
}
