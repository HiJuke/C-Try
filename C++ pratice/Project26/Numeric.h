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

#include"Copy.h"

//��ƥͦ��k
//�ݩ�p����k �ϥή��Y��� #include <numeric>
//accumulate	//�p��e�������֭p�`�X
//fill			//�V�e�����K�[����


//-------------------------------------------------------------
//accumulate	//�p��e�������֭p�`�X
//accumulate(begin, end, value);	//value ���_�l���֥[�ƭ�
//����k���ĥ|�ӰѼƥi��J �i�Ω�۩w�q���� �һݪ����� �Ψ�ƿ�J

void testAccumulate() {
	vector<int>v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i+1);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "��ƥͦ��k �֭p�`�X ��l�e�� �M��" << endl;

	//�֭p�`�M		����1~100���֥[
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "��ƥͦ��k �֭p�`�X �֥[��: "<< total << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//fill			//�V�e�����K�[����
//fill (begin, end, value);	//�bbegin ~ end ���� value

void testFill() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "��ƥͦ��k �K�[���� ��l�e�� �M��" << endl;

	//�K�[����
	fill(v.begin() + 1, v.end() - 1, 5);
	for_each(v.begin(), v.end(), MyPrint);
	cout << "��ƥͦ��k �K�[���� �����K�[ �M��" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------