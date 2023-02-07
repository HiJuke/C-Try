#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���

#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include <fstream>
#define FILENAME "empFile.txt"

using namespace std;

//�]�p�޲z��
class WorkerManager {
public:
	WorkerManager();

	//�i��Menu
	void ShowMenu();

	//�h�X�޲z�{��
	void exitSystem();

	//--------------------���------------------------------
	//�O�s���
	void save();

	//�έp�H��
	int get_EmuNum();
	
	//��l�ƭ��u
	void init_Emp();

	//--------------------���------------------------------

	//--------------------�\��------------------------------
	//1.�W�[¾�u�H��
	void Add_Emp();

	//2.���¾�u�H��
	void Show_Emp();

	//3.�R����¾¾�u
	void Del_Emp();
	int IsExist(int id);	//�P�_���u�O�_�s�b

	//4.�ק�¾�u�H��
	void Fix_Emp();

	//5.�d��¾�u�H��
	void Find_Emp();

	//6.���ӽs���Ƨ�
	void Sort_Emp();

	//7.�M�ũҦ�����
	void Clean_File();

	//--------------------�\��------------------------------

	~WorkerManager();

	int m_EmpNum;			//���u�`��
	Worker** m_EmpArray;	//���u�Ʋժ����w

	bool m_FileIsEmpty;		//���O�_����

};

