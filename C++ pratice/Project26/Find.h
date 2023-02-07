#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

#include"ForEach.h"

//�d���k
/*
find			//�d�䤸��
find_if			//�d�䤸�� ������
adjacend_find	//�d�䤸�� ��۾F����
binary_cearch	//�d�䤸�� �G���d��k
count			//�έp�����Ӽ�
count_if		//�έp�����Ӽ� ������
*/

//-------------------------------------------------------------
//find			//�d�䤸��
//find (begin(), end(), value);
//begin ~ end ������ value

//�d�䤺�m�ƾ�����
void testFind01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�d���� ���m�ƾ����� ��e�� �M��" << endl;

	//�d��e���� �ϧ_��"5"�s�b
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) {
		cout << "���M��" << endl;
	}
	else {
		cout << "�M��: " << *it << endl;
	}
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//�d��ۭq�ƾ�����
class FindPerson {
public:
	FindPerson(string name, int age) {
		m_name = name;
		m_age = age;
	}
	//�b�������������ާ@�� �~�������hfind ���D�p���� FindPerson����
	bool operator==(const FindPerson& p) {
		if (this->m_name == p.m_name && this->m_age == p.m_age) {
			return true;
		}
		else {
			return false;
		}
	}
	string m_name;
	int m_age;
};
void FindPersonPrint(FindPerson &p) {		//�M��
	cout << p.m_name << "  " << p.m_age << endl;
}
void testFind02() {
	vector<FindPerson>v;
	string strName = { "ABCDEFGHIJ" };
	for (int i = 0; i < 10; i++)
	{	
		string tt = "Person";
		tt += strName[i];
		FindPerson p(tt, i * 10);
		v.push_back(p);
	}

	for_each(v.begin(), v.end(), FindPersonPrint);
	cout << "�d���� �ۭq�ƾ����� ��e�� �M��" << endl;

	//�d��e���� �ϧ_��"PersonD,30"�s�b
	//���ɻݭn�b�������������ާ@�� �~�������hfind ���D�p���� FindPerson����
	FindPerson p("PersonD", 30);
	cout << "�M��ؼ�: " << p.m_name << "  Age = " << p.m_age << "\t\t";
	vector<FindPerson>::iterator it = find(v.begin(), v.end(), p);
	if (it == v.end()) {
		cout << "���M��" << endl;
	}
	else {
		cout << "�M��: " << it->m_name << "  Age = "  << it->m_age << endl;
	}
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//find_if			//�d�䤸�� ������
//find_if (begin(), end(), _Pred);
//begin ~ end ���� _Pred��ƩάO�׵�(��^bool����������)

//���m�ƾ�����
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
void testFindIf01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�d���� ������ ���m�ƾ����� ��e�� �M��" << endl;

	//�d��e���� �ϧ_���j��5�s�b
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "���M��" << endl;
	}
	else {
		cout << "�M��j��5���Ʀr��: " << *it << endl;
	}

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//�ۭq�ƾ�����
class FindIfPerson {
public:
	FindIfPerson(string name, int age) {
		m_name = name;
		m_age = age;
	}
	//�b���������ާ@�� �~�������hfind ���D�p���� FindIfPerson����
	bool operator==(const FindIfPerson& p) {
		return this->m_age == p.m_age;
	}
	
	string m_name;
	int m_age;
};
void FindIfPersonPrint(FindIfPerson& p) {		//�M��
	cout << p.m_name << "  " << p.m_age << endl;
}
//�׵�
class FindIfGreater {
public:
	bool operator()(FindIfPerson& p) {
		return p.m_age > 40;
	}
};

void testFindIf02() {
	vector<FindIfPerson>v;
	string strName = { "ABCDEFGHIJ" };
	for (int i = 0; i < 10; i++)
	{
		string tt = "Person";
		tt += strName[i];
		FindIfPerson p(tt, i * 10);
		v.push_back(p);
	}
	for_each(v.begin(), v.end(), FindIfPersonPrint);
	cout << "�d���� ������ �ۭq�ƾ����� ��e�� �M��" << endl;

	//��~�֤j��40�����H �ϥο׵�
	vector<FindIfPerson>::iterator it = find_if(v.begin(), v.end(), FindIfGreater());
	if (it == v.end()) {
		cout << "���M��" << endl;
	}
	else {
		while (it != v.end()) {
			cout << "�M��j�� 40�~�֪�������: " << it->m_name << "\t\tAge " << it->m_age << endl;
			it++;
		}
	}

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//adjacend_find	//�d�䤸�� ��۾F����
//adjacent_find(begin(), end());

void testAdjacendFind() {
	vector<int>v;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(rand()%4);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�d���� ��۾F���� ���m�ƾ����� ��e�� �M��" << endl;

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		cout << "���M��۾F����" << endl;
	}
	else {
		cout << "�M�򭺦�۾F���ƼƬ�: " << *it << endl;
	}

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//binary_search	//�d�䤸�� �G���d��k ��bool �^�Ы��w�����O�_�s�b �t�׫D�`��
//bool binary_search (begin(), end(), value);
//���i�Ω�L�ǧǦC (�������ɧ� �άO ����)

void testBinarySearch() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		if (i == 7) {
			int r = rand() % 2;
			if (r == 0) {
				v.push_back(8);
			}
			else {
				v.push_back(7);
			}
		}
		else {
			v.push_back(i);
		}
		
	}
	
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�d���� �G���d��k ���w�����O�_�s�b ���m�ƾ����� ��e�� �M��" << endl;

	//���ݮe�����O�_������"7"
	bool ret = binary_search(v.begin(), v.end(), 7);
	if (ret) {
		cout << "���\�M�򤸯� 7 " << endl;
	}
	else {
		cout << "����M�򤸯� 7 " << endl;
	}

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//count			//�έp�����Ӽ�
//count(begin(), end(), value);

//���m�ƾ�����
void testCount01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 3);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�d���� �έp�����Ӽ� ���m�ƾ����� ��e�� �M��" << endl;
	//�έp�����Ӽ�
	cout << "�e���� 0 ���ӼƬ� " << count(v.begin(), v.end(), 0) << endl;
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//�ۭq�ƾ�����
void testCount02() {
	vector<FindIfPerson>v;
	string strName = { "ABCDEFGHIJ" };
	for (int i = 0; i < 10; i++)
	{
		string tt = "Person";
		tt += strName[i];
		FindIfPerson p(tt, rand()%3);
		v.push_back(p);
	}
	for_each(v.begin(), v.end(), FindIfPersonPrint);
	cout << "�d���� �έp�����Ӽ� �ۭq�ƾ����� ��e�� �M��" << endl;

	//�έp�����Ӽ�	�M���Target �@�˦P��0���H
	//�b�������������ާ@�� �~�������hfind ���D�p���� FindIfPerson����
	FindIfPerson Target("Target", 0);	
	cout << "�e���� ��Target �@�˦P��0���H ���ӼƬ� " << count(v.begin(), v.end(), Target) << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//count_if		//�έp�����Ӽ� ������
//count(begin(), end(), _Pred);		//_Pred���׵�

//���m�ƾ�����
class CountIf01 {
public:
	bool operator()(int val) {
		return val > 3;
	}
};
void testCountIf01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 5+1);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�d���� �έp�����Ӽ� ������ ���m�ƾ����� ��e�� �M��" << endl;
	//�έp �j��3 �����Ӽ�
	cout << "�e���� �j��3 ���ӼƬ� " << count_if(v.begin(), v.end(), CountIf01()) << endl;
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//�ۭq�ƾ�����
class CountIf02 {
public:
	bool operator()(const FindIfPerson &p) {
		return p.m_age > 3;
	}
};
void testCountIf02() {
	vector<FindIfPerson>v;
	string strName = { "ABCDEFGHIJ" };
	for (int i = 0; i < 10; i++)
	{
		string tt = "Person";
		tt += strName[i];
		FindIfPerson p(tt, rand() % 5+1);
		v.push_back(p);
	}
	for_each(v.begin(), v.end(), FindIfPersonPrint);
	cout << "�d���� �έp�����Ӽ� ������ �ۭq�ƾ����� ��e�� �M��" << endl;

	//�έp�����Ӽ�	�M��j��3���H
	//�b�������������ާ@�� �~�������hfind ���D�p���� FindIfPerson����
	cout << "�e���� �j��3���H ���ӼƬ� " << count_if(v.begin(), v.end(), CountIf02()) << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}
