#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>

using namespace std;

class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
		//this->m_Height = height;
	}

	string m_name;
	int m_age;
	//int m_Height;
};
//----------------------------------------------------------------

//set/ multiset �e��			include <set>
//�Ҧ������|�A���J�ɳQ�۰ʱƧ�
//�ݩ����p���e�� ���h�ΤG�e���{
//set		�����\�e���������Ƥ���
//multiset	�i���\�e���������Ƥ���
void printSet(const set<int>& S) {
	for (set<int>::const_iterator it = S.begin(); it != S.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

void printMsSet(const multiset<int>& S) {
	for (multiset<int>::const_iterator it = S.begin(); it != S.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

//----------------------------------------------------------------
//��ȻP�c�y���
/*
set<T> S;			//�q�{�c�y���	
set(const set &S);	//�����c�y���

set& operator = (const set &S);	//���������ާ@��
*/
void test01() {
	set<int> S;

	//1. set�|�۰ʱƧ�
	//2. �Y���J���ƪ��� �|���J���� �����¥i���� �N�O�S���i�h
	S.insert(rand() % 100 + 1);
	S.insert(rand() % 100 + 1);
	S.insert(rand() % 100 + 1);
	S.insert(rand() % 100 + 1);
	S.insert(rand() % 100 + 1);
	printSet(S);

	//����
	set<int>SS(S);
	printSet(SS);

	//���
	set<int>SSS;
	SSS = S;
	printSet(SSS);
}

//----------------------------------------------------------------
//�j�p�ާ@�P�洫
/*
empty();		�P�_�e���O�_����
size();			��^�e���������Ӽ�
swap(st);		�洫��Ӷ��X�e��
*/
void test02() {
	set<int> S1;
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	printSet(S1);

	if (S1.empty()) {		//���u �N��e������
		cout << "S1����" << endl;
	}
	else {
		cout << "S1������" << endl;
		cout << "�j�p��: " << S1.size() << endl;
	}

	cout << "------------------------------------------------------------" << endl;
	set<int> S2;
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);

	cout << "�洫�e" << endl;
	printSet(S1);
	printSet(S2);

	S1.swap(S2);
	cout << "�洫��" << endl;
	printSet(S1);
	printSet(S2);

}

//----------------------------------------------------------------
//���J�M�R��
/*
insert(ele);			-���J���� ele							��^�s������m
erase(pos);				-�R�����N�����V������					��^�U�@�Ӽƾڪ���m
erase(start, end);		-�R�����N�� start �� end ����������		��^�U�@�Ӽƾڪ���m
erase(ele);				-
clear();				-�R���e�����Ҧ�����
*/
void test03() {
	set<int> S1;
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	printSet(S1);

	S1.erase(++(++S1.begin()));
	printSet(S1);

	S1.erase(++S1.begin(), S1.end());
	printSet(S1);

	cout << "------------------------------------------------------------" << endl;
	set<int> S2;
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(87);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	printSet(S2);

	S2.erase(87);
	printSet(S2);

	S1.clear();
	S2.clear();
	printSet(S1);
	printSet(S2);

}

//----------------------------------------------------------------
//�d��M�έp
/*
find(key);		//�d�䤸��key �O�_�s�b ���K�|��^������m ���s�b��^set.end();
count(key);		//�έpkey �����Ӽ� ���]��set ���������� �ҥH�u�� 0 & 1
*/
void test04() {
	set<int> S1;
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(50);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	printSet(S1);

	set<int>::iterator pos1 = S1.find(50);
	set<int>::iterator pos2 = S1.find(30);
	if (pos1 != S1.end()) {
		cout << "���50��" << endl;
	}
	else {
		cout << "�S���50��" << endl;
	}

	if (pos2 != S1.end()) {
		cout << "���30��" << endl;
	}
	else {
		cout << "�S���30��" << endl;
	}

	//---------------------------------------------
	int num1 = S1.count(50);
	int num2 = S1.count(30);
	cout << "50 num = " << num1 << "\t30 num = " << num2 << endl;
}
//----------------------------------------------------------------
//set �M multiset �ϧO
/*
set		�����\�e���������Ƥ���
multiset	�i���\�e���������Ƥ���
multiset	���|�˴��ƾ� �ҥH�i���J���Ƽƾ�
*/
void test05() {
	set<int> S1;
	S1.insert(20);
	S1.insert(30);
	S1.insert(30);
	S1.insert(40);
	S1.insert(50);
	printSet(S1);
	//-----------------------------------------------------------------------
	pair<set<int>::iterator, bool> ret = S1.insert(60);
	if (ret.second) {
		cout << "���J���\" << endl;
	}
	else {
		cout << "���J����" << endl;
	}
	printSet(S1);
	//-----------------------------------------------------------------------
	ret = S1.insert(30);
	if (ret.second) {
		cout << "���J���\" << endl;
	}
	else {
		cout << "���J����" << endl;
	}
	printSet(S1);
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	cout << "multiset" << endl;
	multiset<int> MS;
	MS.insert(20);
	MS.insert(30);
	MS.insert(30);
	MS.insert(40);
	MS.insert(50);
	printMsSet(MS);
}
//----------------------------------------------------------------
//pair�ϥ� pair��ժ��Ы�
//pair ����X�{�ƾ� �Q�ι�եi�H��^��Ӽƾ�
/*
pair<type, type> p (value1, value2);
pair<type, type> p = make_pair( value1, value2 );
*/
void test06() {
	pair<string, int> p1("Peter", 20);
	cout << "Name: " << p1.first << "\tAge: " << p1.second << endl;

	pair<string, int> p2 = make_pair("Frank", 72);
	cout << "Name: " << p2.first << "\tAge: " << p2.second << endl;
}

//----------------------------------------------------------------
//���m�������w�ƧǳW�h
//set�q�{�Ѥp�ƨ�j �p����ܱƧǳW�h?
//�Q�Υ���
class MyCompara {
public:
	//�Ĥ@��()�N����  �ĤG��()�N��ƾڮ榡
	//�ȥ��[�Jconst ���M�|����
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};

void test07() {
	set<int> S1;
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	printSet(S1);

	//�令�q�j��p
	set<int, MyCompara> S2;
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	for (set<int, MyCompara>::const_iterator it = S2.begin(); it != S2.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}
//----------------------------------------------------------------
//�۩w�q�ƾ����� �ȥ� ���w�ƧǳW�h

class comparePerson {
public:
	bool operator()(const Person& p1, const Person& p2) const {
		//�̾ڦ~��
		//����
		return p1.m_age > p2.m_age;

		//�ɧ�
		//return p1.m_age < p2.m_age;
	}
};

void test08() {
	set<Person, comparePerson>S;

	Person P1("HumanA", 35);
	Person P2("HumanB", 45);
	Person P3("HumanC", 45);
	Person P4("HumanD", 76);
	Person P5("HumanE", 45);

	S.insert(P1);
	S.insert(P2);
	S.insert(P3);
	S.insert(P4);
	S.insert(P5);

	for (set<Person, comparePerson>::const_iterator it = S.begin(); it != S.end(); it++) {
		cout << "Name: "<< it->m_name << "\tAge: " << it->m_age << endl;
	}
	cout << endl;
}

//----------------------------------------------------------------


int main() {
	//���U�@�U�����|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	//��ȻP�c�y���
	//test01();

	//�j�p�ާ@�P�洫
	//test02();

	//���J�M�R��
	//test03();

	//�d��M�έp
	//test04();

	//set �M multiset �ϧO
	//test05();

	//pair�ϥ� pair��ժ��Ы�
	//test06();

	//���m�������w�ƧǳW�h
	//test07();

	//�۩w�q�ƾ��������w�ƧǳW�h
	test08();

	system("pause");
	return 0;
}
