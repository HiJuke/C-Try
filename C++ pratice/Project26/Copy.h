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

#include"Sort.h"

//�����P������k
/*
copy		//�e�����w�d�򪺤���������t�@�e��
replace		//�e�����w�d�򤸯��אּ�s����
replace_if	//�e�����w�d�򺡨����󪺤����אּ�s����
swap		//��e����������
*/


//-------------------------------------------------------------
//copy		//�e�����w�d�򪺤���������t�@�e��
//copy (begin, end, dest);		//dest �O�ؼЮe�����N��
//�i�H����������� �S���n�b�C�ӮɭԳ��γo�F��

void testCopy() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e�������P���� �����ܥt�@�e�� ��e�� �M��" << endl;

	//����
	vector<int>v2;
	v2.resize(v.size());

	copy(v.begin(), v.end(), v2.begin());
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "�e�������P���� �����ܥt�@�e�� �ؼЮe�� �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//replace	//�e�����w�d�򤸯��אּ�s����
//replace (begin, end, Old_value, New_value);	//�´��s

void testReplace() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand()%2);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e�������P���� ���w���� �����e �M��" << endl;

	//����
	replace(v.begin(), v.end(), 0, 9);
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e�������P���� ���w���� ������ �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//replace_if	//�e�����w�d�򺡨����󪺤����אּ�s����
//replace_if (begin, end, _pred, New_value);	//�S�ݨ�p�F �׵�

class ReIfGreater {
public:
	bool operator()(int val) {
		return val > 2;		//�j��2 ����
	}
};

void testReplaceIf() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 5);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e�������P���� ������� �����e �M��" << endl;

	//�N�j�� 2 ���ƴ����� 9
	replace_if(v.begin(), v.end(), ReIfGreater(), 9);
	for_each(v.begin(), v.end(), MyPrint);
	cout << "�e�������P���� ������� ������ �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//swap		//��e����������

void testSwap() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back((i+1)*11);
		v2.push_back((9 - i)*11);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "�e�������P���� �e������ �����e �e��1 �M��" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "�e�������P���� �e������ �����e �e��2 �M��" << endl;

	//�����㬡
	cout << "\t|" << endl;
	cout << "\t|" << endl;
	cout << "\t|" << endl;
	cout << "\tV" << endl;

	//����
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "�e�������P���� �e������ ������ �e��1 �M��" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "�e�������P���� �e������ ������ �e��2 �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

