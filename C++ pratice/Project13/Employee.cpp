#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include "Employee.h"

using namespace std;

Employee::Employee(int ID, string Name, int DeptID){
	this->m_ID = ID;			//�s��
	this->m_Name = Name;		//�m�W
	this->m_DeptID = DeptID;	//�����s��
}

void Employee::showInfo() {
	cout << "Worker ID: \t" << this->m_ID
		<< "\tName: \t" << this->m_Name
		<< "\tDept: \t" << this->getDeptName()
		<< "\t�t�d�����g�z��������" << endl;
}

string Employee::getDeptName() {
	return string("���u");
}
