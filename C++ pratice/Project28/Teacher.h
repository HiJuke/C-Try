#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Identity.h"

using namespace std;

class Teacher : public Identity {
public:
	Teacher();

	Teacher(int id, string name, string pwd);

	//菜單
	virtual void openMenu();

	//查看所有預約
	void showAllOrder();

	//審核預約
	void validOrder();

	//註銷登錄


	//職公號
	int m_Empid;

};
