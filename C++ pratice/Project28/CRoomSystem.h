#pragma once
#include<iostream>
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"globalFile.h"

using namespace std;




//管理員菜單
/*
void managerMenu(Identity*& manager) {
	manager->openMenu();
}
*/

//登錄
void LoginIn(string filename, int type) {
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	//若是文件不存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}


	int id;
	string name;
	string pwd;

	//管理員不需要員工號
	if (type == 1) {	//student
		cout << "請輸入你的學生學號: ";
		cin >> id;
	}
	else if (type == 2) {	//teacher
		cout << "請輸入你的教職員工號: ";
		cin >> id;
	}

	cout << "請輸入你的姓名: ";
	cin >> name;
	cout << "請輸入你的密碼: ";
	cin >> pwd;

	//準備驗證

	if (type == 1) {	
		//學生身分驗證
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "\t+--------------+" << endl;
				cout << "\t| 學生驗證成功 |" << endl;
				cout << "\t+--------------+" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//辦正事
				person->openMenu();
				delete person;

				return;
			}
		}
	}
	else if (type == 2) {	
		//教師身分驗證
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "\t+--------------+" << endl;
				cout << "\t| 教師驗證成功 |" << endl;
				cout << "\t+--------------+" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//辦正事
				person->openMenu();
				delete person;

				return;
			}
		}
	}
	else if (type == 3) {
		//管理員身分驗證
		string fname;
		string fpwd;

		while (ifs >> fname && ifs >> fpwd) {
			if (name == fname && pwd == fpwd) {
				cout << "\t+----------------+" << endl;
				cout << "\t| 管理員驗證成功 |" << endl;
				cout << "\t+----------------+" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//辦正事
				person->openMenu();
				delete person;

				return;
			}
		}
	}

	cout << "\t+--------------+" << endl;
	cout << "\t| 身分驗證失敗 |" << endl;
	cout << "\t+--------------+" << endl;

	system("pause");
	system("cls");
	return;
}

void FirstMenu() {
	int select = 0;
	cout << "\t\t+------------------------------------+\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t|          1. 學        生           |\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t|          2. 教        師           |\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t|          3. 管   理   員           |\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t|          0. 退        出           |\t\t" << endl;
	cout << "\t\t|                                    |\t\t" << endl;
	cout << "\t\t+------------------------------------+\t\t" << endl;
	cout << "請輸入身分" << endl;

	cin >> select;

	switch (select){
	case 1:	//學生
		LoginIn(STUDENT_FILE,1);
		break;
	case 2:	//老師
		LoginIn(TEACHER_FILE, 2);
		break;
	case 3:	//管理
		LoginIn(ADMIN_FILE, 3);
		break;
	case 0:	//退出
		cout << "期待您再次使用本系統" << endl;
		system("pause");
		exit(0);
		break;
	default:
		cout << "輸入錯誤 請重新輸入" << endl;
		system("pause");
		system("cls");
		break;
	}
}




