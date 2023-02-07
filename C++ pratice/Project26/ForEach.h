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

//�M����k
/*
for_each	//�M���e��
transform	//�h�B�e����t�@�Ӯe����
*/

//-------------------------------------------------------------
//for_each		//�M���e��
//for_each(iterator begin, iterator end, _func);

//���q���
void MyPrint(int val) {
	cout << val << "  ";
}
//����
class print02 {
public:
	void operator()(int val) {
		cout << val << "  ";
	}
};

void testForEach() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	} 

	for_each(v.begin(), v.end(), MyPrint);		//���q���
	cout << "���q��� for_each �M��" << endl;

	for_each(v.begin(), v.end(), print02());	//����
	cout <<"���� for_each �M��"<< endl;
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//transform		//�h�B�e����t�@�Ӯe����
//transform(iterator begin1, iterator end1, iterator begin2, _func);
// (��e�����h�B��������,  ��e�����h�B��������, �ؼЮe�����h�B�ܪ���m, ��ƩΨ�ƹ�H)

//���q���
int MyTransform(int val) {
	return val + 500;
}

//����
class Transform {
public:
	int operator()(int val) {
		return val+200;
	}
};

void testTransform() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i+100);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "��Ϯe�� �h�B�e�� Transform" << endl;

	//���q���
	vector<int>vTarget01;	//�ؼЮe��
	vTarget01.resize(v.size());	//�ؼЮe���ݴ��e�}�P�Ŷ�

	transform(v.begin(), v.end(), vTarget01.begin(), MyTransform);
	for_each(vTarget01.begin(), vTarget01.end(), MyPrint);
	cout << "�ؼЮe�� �h�B�e�� Transform ���q���" << endl;

	//����
	vector<int>vTarget02;	//�ؼЮe��
	vTarget02.resize(v.size());	//�ؼЮe���ݴ��e�}�P�Ŷ�

	transform(v.begin(), v.end(), vTarget02.begin(), Transform());
	for_each(vTarget02.begin(), vTarget02.end(), MyPrint);
	cout << "�ؼЮe�� �h�B�e�� Transform ����" << endl;
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}


