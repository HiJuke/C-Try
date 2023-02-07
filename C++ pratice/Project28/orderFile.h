#pragma once
#include<iostream>
#include <fstream>
#include<map>
#include"globalFile.h"
using namespace std;

class OrderFile {
public:
	OrderFile();

	//��s�w������
	void updateOrder();

	//�������e��
	map<int, map<string, string>> m_orderData;
	/*
	�jmap ��key  �s���O�w���Ӽ�
	�pmap ��key  �s���Odata, room, stuid�����������H��
	�pmap ���ƭ� �s���O�������Ӧ�����T
		key		|	information
		data	|	5
		room	|	3
		stuid	|	10005
		stuname	|	student05
		.
		.
		.
	*/

	//�w���O������
	int m_Size;
};

