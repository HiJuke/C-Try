#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include "Worker.h"

using namespace std;

//設計管理類
class Employee : public Worker {
public:
	//構造函數
	Employee(int ID, string Name, int DeptID);

	//顯示個人信息	職工編號 職工姓名 職工部門編號
	virtual void showInfo();

	//職工崗位名稱 職公職責信息
	virtual string getDeptName();

	//int m_ID;		//編號
	//string m_Name;	//姓名
	//int m_DeptID;	//部門編號
};

