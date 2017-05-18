#ifndef SRC_PHONECONTACTVECTOR_H_
#define SRC_PHONECONTACTVECTOR_H_

#include <vector>
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
class PhoneContactVector: public PhoneContact {
public:
   PhoneContactVector();
   bool insert(string name, int number, string email);   // Vector ����
   bool remove(string name);                             // Vector ����

   bool update(string name, int number, string email);   // �̸��� ���� ��ȣ, �̸��� ����
   bool update(string name, int number);                 // �̸��� ���� ��ȣ ����
   bool update(string name, string email);               // �̸��� ���� �̸��� ����

   string find(int num) const;                    // ��ȣ�� ���� �̸� ã��
   string find(ValueInfo) const;                  // ValueInfo�� ���� �̸� ã��
   string findName(string email) const;           // �̸����� ���� �̸� ã��
   ValueInfo find(string name) const;             // �̸��� ���� ValueInfo ã��
   void listAll() const;

private:
   ValueInfo viNull;
   vector<Entry> vectorPhoneBook;
   int findLoc(string name) const;
};

#endif /* SRC_PHONECONTACTVECTOR_H_ */
