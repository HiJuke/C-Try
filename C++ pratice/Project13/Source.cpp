#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件

#include "workManager.h"

#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

//職工管理系統
//職工分三類 老闆 經理 員工 (需顯示 職工編號 職工姓名 職工崗位 職工職責)
//老闆職責: 管理所有事物
//經理職責: 完成老闆給的任務 分派任務給員工
//員工職責: 完成經理給的任務
//------------------------------------------------------
//需實現功能
/*
退出管理程序
增加職工信息
顯示職工信息
刪除離職職工
修改職工信息
查找職工信息
按照編號排序
清空所有文檔
*/
//------------------------------------------------------

/*
			   +------Class Employee
Class Worker---+------Class Manager
			   +------Class Boss
*/

void ToolRunning() {
	WorkerManager wm;	//實例化管理類

	do {
		wm.ShowMenu();		//展示Menu
		//輸入選擇
		int choice;
		cout << "請輸入所需功能" << endl;
		cin >> choice;
		//執行選擇
		switch (choice) {
		case 0:		//退出管理程序
			wm.exitSystem();
			break;
		case 1:		//增加職工信息
			wm.Add_Emp();
			break;
		case 2:		//顯示職工信息
			wm.Show_Emp();
			break;
		case 3:		//刪除離職職工
			wm.Del_Emp();
			break;
		case 4:		//修改職工信息
			wm.Fix_Emp();
			break;
		case 5:		//查找職工信息
			wm.Find_Emp();
			break;
		case 6:		//按照編號排序
			wm.Sort_Emp();
			break;
		case 7:		//清空所有文檔
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