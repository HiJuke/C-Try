#pragma once
#include<iostream>
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"globalFile.h"

using namespace std;




//�޲z�����
/*
void managerMenu(Identity*& manager) {
	manager->openMenu();
}
*/

//�n��
void LoginIn(string filename, int type) {
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	//�Y�O��󤣦s�b
	if (!ifs.is_open()) {
		cout << "��󤣦s�b" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}


	int id;
	string name;
	string pwd;

	//�޲z�����ݭn���u��
	if (type == 1) {	//student
		cout << "�п�J�A���ǥ;Ǹ�: ";
		cin >> id;
	}
	else if (type == 2) {	//teacher
		cout << "�п�J�A����¾���u��: ";
		cin >> id;
	}

	cout << "�п�J�A���m�W: ";
	cin >> name;
	cout << "�п�J�A���K�X: ";
	cin >> pwd;

	//�ǳ�����

	if (type == 1) {	
		//�ǥͨ�������
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "\t+--------------+" << endl;
				cout << "\t| �ǥ����Ҧ��\ |" << endl;
				cout << "\t+--------------+" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//�쥿��
				person->openMenu();
				delete person;

				return;
			}
		}
	}
	else if (type == 2) {	
		//�Юv��������
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "\t+--------------+" << endl;
				cout << "\t| �Юv���Ҧ��\ |" << endl;
				cout << "\t+--------------+" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//�쥿��
				person->openMenu();
				delete person;

				return;
			}
		}
	}
	else if (type == 3) {
		//�޲z����������
		string fname;
		string fpwd;

		while (ifs >> fname && ifs >> fpwd) {
			if (name == fname && pwd == fpwd) {
				cout << "\t+----------------+" << endl;
				cout << "\t| �޲z�����Ҧ��\ |" << endl;
				cout << "\t+----------------+" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//�쥿��
				person->openMenu();
				delete person;

				return;
			}
		}
	}

	cout << "\t+--------------+" << endl;
	cout << "\t| �������ҥ��� |" << endl;
	cout << "\t+--------------+" << endl;

	system("pause");
	system("cls");
	return;
}

void FirstMenu() {
	int select = 0;
	cout << "\t\t+------------------------------------+\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t|          1. ��        ��           |\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t|          2. ��        �v           |\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t|          3. ��   �z   ��           |\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t|          0. �h        �X           |\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t+------------------------------------+\t\t" << endl;
	cout << "�п�J����" << endl;

	cin >> select;

	switch (select){
	case 1:	//�ǥ�
		LoginIn(STUDENT_FILE,1);
		break;
	case 2:	//�Ѯv
		LoginIn(TEACHER_FILE, 2);
		break;
	case 3:	//�޲z
		LoginIn(ADMIN_FILE, 3);
		break;
	case 0:	//�h�X
		cout << "���ݱz�A���ϥΥ��t��" << endl;
		system("pause");
		exit(0);
		break;
	default:
		cout << "��J���~ �Э��s��J" << endl;
		system("pause");
		system("cls");
		break;
	}
}




