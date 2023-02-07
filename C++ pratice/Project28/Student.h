#pragma once
#include<iostream>
#include"Identity.h"

using namespace std;


class Student :public Identity {
public:
	Student();

	Student(int id, string name, string pwd);

	//機房容器
	vector<ComputerRoom> vCom;

	//菜單介面
	virtual void openMenu();

	//申請預約
	void applyOrder();

	//查看我的預約
	void showMyOrder();

	//查看所有預約
	void showAllOrder();
	
	//取消預約
	void cancelOrder();

	//註銷登陸


	//學號
	int m_id;
};

