#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���

#include "workManager.h"

#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

//¾�u�޲z�t��
//¾�u���T�� ���� �g�z ���u (����� ¾�u�s�� ¾�u�m�W ¾�u�^�� ¾�u¾�d)
//����¾�d: �޲z�Ҧ��ƪ�
//�g�z¾�d: �������󵹪����� �������ȵ����u
//���u¾�d: �����g�z��������
//------------------------------------------------------
//�ݹ�{�\��
/*
�h�X�޲z�{��
�W�[¾�u�H��
���¾�u�H��
�R����¾¾�u
�ק�¾�u�H��
�d��¾�u�H��
���ӽs���Ƨ�
�M�ũҦ�����
*/
//------------------------------------------------------

/*
			   +------Class Employee
Class Worker---+------Class Manager
			   +------Class Boss
*/

void ToolRunning() {
	WorkerManager wm;	//��Ҥƺ޲z��

	do {
		wm.ShowMenu();		//�i��Menu
		//��J���
		int choice;
		cout << "�п�J�һݥ\��" << endl;
		cin >> choice;
		//������
		switch (choice) {
		case 0:		//�h�X�޲z�{��
			wm.exitSystem();
			break;
		case 1:		//�W�[¾�u�H��
			wm.Add_Emp();
			break;
		case 2:		//���¾�u�H��
			wm.Show_Emp();
			break;
		case 3:		//�R����¾¾�u
			wm.Del_Emp();
			break;
		case 4:		//�ק�¾�u�H��
			wm.Fix_Emp();
			break;
		case 5:		//�d��¾�u�H��
			wm.Find_Emp();
			break;
		case 6:		//���ӽs���Ƨ�
			wm.Sort_Emp();
			break;
		case 7:		//�M�ũҦ�����
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	} while (true);
}


void test01() {
	Worker* w = NULL;
	w = new Employee(1, "Peter", 1);
	w->showInfo();
	delete w;

	Manager* m = NULL;
	m = new Manager(2, "Jonny", 2);
	m->showInfo();
	delete m;

	Boss* b = NULL;
	b = new Boss(3, "Wang", 3);
	b->showInfo();
	delete b;
}


int main() {
	srand((unsigned int)time(NULL));

	ToolRunning();

	//test01();

	system("pause");
	return 0;
}