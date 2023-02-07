#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include "Boss.h"

using namespace std;

Boss::Boss(int ID, string Name, int DeptID) {
	this->m_ID = ID;			//編號
	this->m_Name = Name;		//姓名
	this->m_DeptID = DeptID;	//部門編號
}

void Boss::showInfo() {
	cout << "Worker ID: \t" << this->m_ID
		<< "\tName: \t" << this->m_Name
		<< "\tDept: \t" << this->getDeptName()
		<< "\t負責管理所有事物" << endl;
}

string Boss::getDeptName() {
	return string("老闆");
}
