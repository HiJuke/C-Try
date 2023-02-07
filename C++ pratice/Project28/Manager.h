#pragma once
#include<iostream>
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"

using namespace std;

class Manager :public Identity {
public:

	Manager();

	Manager(string name, string pwd);

	//初始化
	void initVector();

	//容器
	vector<Student> vStu;
	vector<Teacher> vTea;

	//去重
	bool checkRepeat(int id, int type);

	//菜單
	virtual void openMenu();

	//添加帳號
	void addPerson();

	//查看帳號
	void showPerson();

	//查看機房信息
	vector<ComputerRoom> vCom;
	void showComputer();

	//清空預約紀錄
	void cleanFile();

};

