#pragma once
#include<iostream>
#include"Identity.h"

using namespace std;


class Student :public Identity {
public:
	Student();

	Student(int id, string name, string pwd);

	//���Юe��
	vector<ComputerRoom> vCom;

	//��椶��
	virtual void openMenu();

	//�ӽйw��
	void applyOrder();

	//�d�ݧڪ��w��
	void showMyOrder();

	//�d�ݩҦ��w��
	void showAllOrder();
	
	//�����w��
	void cancelOrder();

	//���P�n��


	//�Ǹ�
	int m_id;
};

