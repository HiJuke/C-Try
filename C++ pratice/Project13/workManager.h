#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件

#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include <fstream>
#define FILENAME "empFile.txt"

using namespace std;

//設計管理類
class WorkerManager {
public:
	WorkerManager();

	//展示Menu
	void ShowMenu();

	//退出管理程序
	void exitSystem();

	//--------------------文件------------------------------
	//保存文件
	void save();

	//統計人數
	int get_EmuNum();
	
	//初始化員工
	void init_Emp();

	//--------------------文件------------------------------

	//--------------------功能------------------------------
	//1.增加職工信息
	void Add_Emp();

	//2.顯示職工信息
	void Show_Emp();

	//3.刪除離職職工
	void Del_Emp();
	int IsExist(int id);	//判斷員工是否存在

	//4.修改職工信息
	void Fix_Emp();

	//5.查找職工信息
	void Find_Emp();

	//6.按照編號排序
	void Sort_Emp();

	//7.清空所有文檔
	void Clean_File();

	//--------------------功能------------------------------

	~WorkerManager();

	int m_EmpNum;			//員工總數
	Worker** m_EmpArray;	//員工數組的指針

	bool m_FileIsEmpty;		//文件是否為空

};

