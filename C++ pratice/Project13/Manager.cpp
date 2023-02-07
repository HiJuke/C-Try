#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include "Manager.h"

using namespace std;

Manager::Manager(int ID, string Name, int DeptID) {
	this->m_ID = ID;			//編號
	this->m_Name = Name;		//姓名
	this->m_DeptID = DeptID;	//部門編號
}

void Manager::showInfo() {
	cout << "Worker ID: \t" << this->m_ID
		<< "\tName: \t" << this->m_Name
		<< "\tDept: \t" << this->getDeptName()
		<< "\t負責完成老闆給的任務 分派任務給員工" << endl;
}

string Manager::getDeptName() {
	return string("經理");
}
