#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Identity.h"

using namespace std;

class Teacher : public Identity {
public:
	Teacher();

	Teacher(int id, string name, string pwd);

	//���
	virtual void openMenu();

	//�d�ݩҦ��w��
	void showAllOrder();

	//�f�ֹw��
	void validOrder();

	//���P�n��


	//¾����
	int m_Empid;

};
