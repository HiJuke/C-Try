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

#include"Find.h"

//�`�αƧǺ�k
/*
sort				//��e���������i��Ƨ�
random_shuffle		//�~�P ���w�d�򤸯��H���վ㦸��
merge				//�e�������X��  ���x�s��t�@�e����
reverse				//������w�d�򪺤���
*/

class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

//-------------------------------------------------------------
//sort				//��e���������i��Ƨ�
//sort(begin(), end(), _Pred);	//_Pred�i�H���� �q�{�ɧ� �n�񪺸ܱo��׵�

void testSort() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand()%10);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e���Ƨ� �����Ƨ� �Ƨǫe �M��" << endl;

	//�Ƨ� �ɧ�
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e���Ƨ� �Ƨǫ� �ɧ� �M��" << endl;

	//�Ƨ� ����
	sort(v.begin(), v.end(), greater<int>());	//greater �O #include <functional> ���ت���ƹ�H
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e���Ƨ� �Ƨǫ� ���� �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//random_shuffle	//�~�P ���w�d�򤸯��H���վ㦸��
//random_shuffle(begin(), end())
//�p�Gmain ���S���[�J srand((unsigned int)time(NULL)); ����|���S�[���檺rand�@�� ���O�H�����C���~�P�᳣�@��

void testRandomShuffle(){
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e���Ƨ� �����~�P �Ƨǫe �M��" << endl;

	//�~�P
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e���Ƨ� �����~�P �~�P�� �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//merge				//�e�������X��  ���x�s��t�@�e����
//merge (begin 1, end 1, begin 2, end 2, dest);		//dest �O�ؼЮe��
//��Ӯe�����������Ǫ�

void testMerge() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 8; i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "�e���Ƨ� �����X�� �e��1 �M��" << endl;

	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "�e���Ƨ� �����X�� �e��2 �M��" << endl;

	//�e���X��
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());	//���ؼЮe���}�P�Ŷ�

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
	cout << "�e���Ƨ� �����X�� �ؼЮe�� �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//reverse			//������w�d�򪺤���
//reverse(begin(), end());

void testReverse() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e���Ƨ� �������� ����e �M��" << endl;

	//���स��
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e���Ƨ� �������� ����� �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}
