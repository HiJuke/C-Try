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

#include"Numeric.h"

//���X��k
/*
set_intersection	//��e���涰
set_union			//��e���p��
set_different		//��e���t��
*/
//�`�N ��e�������������Ǫ�


//-------------------------------------------------------------
//set_intersection		//��e���涰
//set_intersection (begin1, end1, begin2, end2, dest);	//dest ���ؼЮe�����N��

void testSetItersection() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 15; i++)
	{
		v1.push_back(i+11);
		v2.push_back(i+16);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "���X��k �e���涰 ��l�e��1 �M��" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "���X��k �e���涰 ��l�e��2 �M��" << endl;

	//��e���涰
	vector<int> vTarget;
	vTarget.resize(min(v1.size(), v2.size()));	//�H�̯S���p�}�P�Ŷ� �涰���p�����p�e����size

	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
	cout << "���X��k �e���涰 �̾ڥؼЮe�� �M��" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint);
	cout << "���X��k �e���涰 �̾ڦ^�Ǯy�� �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//set_union		//��e���p��
//set_union(begin1, end1, begin2, end2, dest);

void testSetUnion() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 15; i++)
	{
		v1.push_back(i + 11);
		v2.push_back(i + 16);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "���X��k �e���p�� ��l�e��1 �M��" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "���X��k �e���p�� ��l�e��2 �M��" << endl;

	//��e���p��
	vector<int> vTarget;
	vTarget.resize( v1.size() + v2.size());	//�H�̯S���p�}�P�Ŷ� �p�����p����̥��@�̩Ҿ֦������� �̷��ݬ���̤j�p�[�`

	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
	cout << "���X��k �e���p�� �̾ڥؼЮe�� �M��" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint);
	cout << "���X��k �e���p�� �̾ڦ^�Ǯy�� �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//set_difference		//��e���t��
//set_difference(begin1, end1, begin2, end2, dest);

void testSetDifference() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 15; i++)
	{
		v1.push_back(i + 11);
		v2.push_back(i + 16);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "���X��k �e���t�� ��l�e��1 �M��" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "���X��k �e���t�� ��l�e��2 �M��" << endl;

	//��e���t��
	vector<int> vTarget;
	vTarget.resize(max(v1.size(), v2.size()));	//�H�̯S���p�}�P�Ŷ� �t�����p�����X1�����P���X2���ƪ������Ҳզ������X �̷��ݬ���̸��j�̪��j�p

	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
	cout << "���X��k �e���t�� �̾ڥؼЮe�� �M��" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint);
	cout << "���X��k �e���t�� �̾ڦ^�Ǯy�� �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------



