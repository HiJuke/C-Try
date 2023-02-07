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

	//��l��
	void initVector();

	//�e��
	vector<Student> vStu;
	vector<Teacher> vTea;

	//�h��
	bool checkRepeat(int id, int type);

	//���
	virtual void openMenu();

	//�K�[�b��
	void addPerson();

	//�d�ݱb��
	void showPerson();

	//�d�ݾ��ЫH��
	vector<ComputerRoom> vCom;
	void showComputer();

	//�M�Źw������
	void cleanFile();

};

