#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include "Worker.h"

using namespace std;

//�]�p�޲z��
class Employee : public Worker {
public:
	//�c�y���
	Employee(int ID, string Name, int DeptID);

	//��ܭӤH�H��	¾�u�s�� ¾�u�m�W ¾�u�����s��
	virtual void showInfo();

	//¾�u�^��W�� ¾��¾�d�H��
	virtual string getDeptName();

	//int m_ID;		//�s��
	//string m_Name;	//�m�W
	//int m_DeptID;	//�����s��
};

