#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件

#include "workManager.h"

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

WorkerManager::WorkerManager(){
	//判斷文件是否存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//如果文件不存在
	if (!ifs.is_open()) {
		cout << "文件尚未存在" << endl;
		this->m_EmpNum = 0;			//初始化人數
		this->m_EmpArray = NULL;	//初始化數組位置
		this->m_FileIsEmpty = true;	//初始化文件是否為空標誌
		ifs.close();
		return;
	}
	//文件存在但為空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件存在但為空" << endl;
		this->m_EmpNum = 0;			//初始化人數
		this->m_EmpArray = NULL;	//初始化數組位置
		this->m_FileIsEmpty = true;	//初始化文件是否為空標誌
		ifs.close();
		return;
	}
	//文件存在且不為空
	if (!ifs.eof()) {
		cout << "文件存在且不為空" << endl;
		int tNUM = this->get_EmuNum();
		cout << "目前職工資料數量為: " << tNUM << endl;
		this->m_EmpNum = tNUM;
		//開闢數組空間 將數據存到數駔中
		this->m_EmpArray = new Worker * [this->m_EmpNum];
		this->init_Emp();		//沒有上行 直接執行此行會因為沒開闢空間出錯
	}
}
WorkerManager::~WorkerManager(){
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::ShowMenu() {
	cout << "**********************************************************************" << endl;
	cout << "**********************************************************************" << endl;
	cout << "**********************************************************************" << endl;
	cout << "*************************歡迎使用職工管理系統*************************" << endl;
	cout << "****************************0.退出管理程序****************************" << endl;
	cout << "****************************1.增加職工信息****************************" << endl;
	cout << "****************************2.顯示職工信息****************************" << endl;
	cout << "****************************3.刪除離職職工****************************" << endl;
	cout << "****************************4.修改職工信息****************************" << endl;
	cout << "****************************5.查找職工信息****************************" << endl;
	cout << "****************************6.按照編號排序****************************" << endl;
	cout << "****************************7.清空所有文檔****************************" << endl;
	cout << "**********************************************************************" << endl;
	cout << "**********************************************************************" << endl;
	cout << "**********************************************************************" << endl;

}

void WorkerManager::exitSystem() {
	cout << "感謝使用本系統" << endl;
	system("pause");
	exit(0);		//只要執行exit(0) 就會直接退出執行
}

//--------------------文件------------------------------
//統計人數
int WorkerManager::get_EmuNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;

	int tempNUM = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		tempNUM++;	//紀錄人數
	}
	ifs.close();
	return tempNUM;
}

//保存文件功能
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

//初始化員工
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = NULL;

		if (did == 1) {	//員工
			worker = new Employee(id, name, did);
		}
		else if (did == 2) {	//經理
			worker = new Manager(id, name, did);
		}
		else {	//老闆
			worker = new Boss(id, name, did);
		}
		//存進數組中
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//--------------------文件------------------------------
//--------------------功能------------------------------
//1.增加職工信息
void WorkerManager::Add_Emp() {
	int AddNum;
	cout << "請輸入欲加入職工數量" << endl;
	cin >> AddNum;

	//添加
	if (AddNum > 0) {
		//計算新空間大小
		int newSize = this->m_EmpNum + AddNum;

		//開闢新空間	因為舊的空間可能會不夠用
		Worker** newSpace = new Worker * [newSize];

		//將原空間的數據放到新空間之下
		//檢查員來空間是否為空
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新數據
		for (int i = 0; i < AddNum; i++) {
			int id;
			string name;
			int depertment;
			cout << "請輸入第 "<<i+1<<" 位新員工的ID: " << endl;
			cin >> id;
			cout << "請輸入第 " << i + 1 << " 位新員工的姓名: " << endl;
			cin >> name;
			cout << "請選擇第 " << i + 1 << " 位新員工的部門ID: " << endl;
			cout << "1. 員工" << endl;
			cout << "2. 經理" << endl;
			cout << "3. 老闆" << endl;
			cin >> depertment;
			cout << "----------------------------------------------------" << endl;

			Worker* worker = NULL;
			switch (depertment) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}

		//釋放原有空間
		delete[] this->m_EmpArray;
		//更改新空間的指向
		this->m_EmpArray = newSpace;
		//更新職工人數
		this->m_EmpNum = newSize;
		
		//更新 職工不為空
		this->m_FileIsEmpty = false;

		cout << "已添加 " << AddNum << " 名職工" << endl;

		//保存數據至文件
		this->save();
	}
	else { cout << "輸入錯誤" << endl; }

	cout << endl;
	system("pause");
	system("cls");
}

//2.顯示職工信息
void WorkerManager::Show_Emp() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//利用多態調用接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	else{ cout << "目前無任何職工信息" << endl; }

	cout << endl;
	system("pause");
	system("cls");
} 

//3.刪除離職職工
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或記錄為空" << endl;
	}
	else {
		cout << "請輸入要刪除的員工" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != (-1)) {
			if (index == this->m_EmpNum - 1) {}
			else {
				for (int i = index; i < this->m_EmpNum - 1; i++) {
					//數據前移
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
			}
			this->m_EmpNum--;

			if (this->m_EmpNum == 0) {
				//釋放原有空間
				delete[] this->m_EmpArray;
			}
			else {
				//開闢新空間
				Worker** newSpace = new Worker * [this->m_EmpNum];

				//將原空間的數據放到新空間之下
				//檢查員來空間是否為空
				if (this->m_EmpArray != NULL) {
					for (int i = 0; i < this->m_EmpNum; i++) {
						newSpace[i] = this->m_EmpArray[i];
					}
				}

				//釋放原有空間
				delete[] this->m_EmpArray;
				//更改新空間的指向
				this->m_EmpArray = newSpace;
			}
			
			cout << "刪除完成 現在剩餘員工為: " << this->m_EmpNum << endl;
		}
		else { cout << "刪除失敗 未尋獲此員工" << endl; }
		this->save();
	}

	cout << endl;
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_ID == id) {
			index = i;
			break;
		}
	}
	return index;
}

//4.修改職工信息
void WorkerManager::Fix_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或記錄為空" << endl;
	}
	else {
		cout << "請輸入要修改的員工" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != (-1)) {
			cout << "尋獲欲修改資料之員工" << endl;
			int Tid;
			string Tname;
			int Tdepertment;
			cout << "請輸入員工新的ID: " << endl;
			cin >> Tid;
			cout << "請輸入員工新的姓名: " << endl;
			cin >> Tname;
			cout << "請選擇員工新的部門ID: " << endl;
			cout << "1. 員工" << endl;
			cout << "2. 經理" << endl;
			cout << "3. 老闆" << endl;
			cin >> Tdepertment;

			Worker* worker = NULL;
			switch (Tdepertment) {
			case 1:
				worker = new Employee(Tid, Tname, 1);
				break;
			case 2:
				worker = new Manager(Tid, Tname, 2);
				break;
			case 3:
				worker = new Boss(Tid, Tname, 3);
				break;
			default:
				break;
			}

			this->m_EmpArray[index] = worker;

			cout << "修改完成" << endl;
		}
		else { cout << "修改失敗 未尋獲此員工" << endl; }
		this->save();
	}

	cout << endl;
	system("pause");
	system("cls");
}

//5.查找職工信息
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或記錄為空" << endl;
	}
	else {
		cout << "請輸入要查找的方式" << endl;
		int select = 0;
		cout << "1.查編號 " << endl;
		cout << "2.查姓名 " << endl;
		cin >> select;
		if (select == 1 || select == 2) {
			if (select == 1) {
				cout << "請輸入要修改員工ID" << endl;
				int id = 0;
				cin >> id;

				int index = this->IsExist(id);
				if (index != (-1)) {
					cout << "尋獲欲尋找資料之員工" << endl;
					this->m_EmpArray[index]->showInfo();
				}
				else { cout << "修改失敗 未尋獲此員工" << endl; }

			}
			else if (select == 2) {
				cout << "請輸入要查找員工姓名" << endl;
				string sst;
				cin >> sst;
				int TTTid = -1;
				for (int i = 0; i < this->m_EmpNum; i++) {
					if (this->m_EmpArray[i]->m_Name == sst) {
						TTTid = i;
						break;
					}
				}
				if (TTTid != (-1)) {
					cout << "尋獲欲尋找資料之員工" << endl;
					this->m_EmpArray[TTTid]->showInfo();
				}
				else { cout << "查找失敗 未尋獲此員工" << endl; }
			}
		}
		else { cout << "輸入無效" << endl; }
	}

	cout << endl;
	system("pause");
	system("cls");
}

//6.按照編號排序
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或記錄為空" << endl;
	}
	else {
		cout << "請輸入要排序的方式" << endl;
		int select = 0;
		cout << "1.編號小到大 " << endl;
		cout << "2.編號大到小 " << endl;
		cin >> select;
		if (select == 1) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				int MinOrMax = i;
				for (int j = i + 1; j < this->m_EmpNum; j++) {
					if (m_EmpArray[MinOrMax]->m_ID > m_EmpArray[j]->m_ID) {
						MinOrMax = j;
					}
				}
				if (i != MinOrMax) {
					Worker* temp = m_EmpArray[i];
					m_EmpArray[i] = m_EmpArray[MinOrMax];
					m_EmpArray[MinOrMax] = temp;
				}
			}
		}
		else if(select == 2){
			for (int i = 0; i < this->m_EmpNum; i++) {
				int MinOrMax = i;
				for (int j = i+1; j < this->m_EmpNum; j++) {
					if (m_EmpArray[MinOrMax]->m_ID < m_EmpArray[j]->m_ID) {
						MinOrMax = j;
					}
				}
				if (i != MinOrMax) {
					Worker* temp = m_EmpArray[i];
					m_EmpArray[i] = m_EmpArray[MinOrMax];
					m_EmpArray[MinOrMax] = temp;
				}
			}
		}
		else { cout << "輸入無效" << endl; }

		if (select == 1 || select == 2) {
			cout << "排序結果為:" << endl;
			this->save();

			if (this->m_EmpArray != NULL) {
				for (int i = 0; i < this->m_EmpNum; i++) {
					//利用多態調用接口
					this->m_EmpArray[i]->showInfo();
				}
			}
		}
	}


	cout << endl;
	system("pause");
	system("cls");
}

//7.清空所有文檔
void WorkerManager::Clean_File() {
	cout << "確定要清空嗎?" << endl;
	int select = 0;
	cout << "1.確定 " << endl;
	cout << "2.返回 " << endl;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "Clear Success" << endl;
	}

	cout << endl;
	system("pause");
	system("cls");
}


//--------------------功能------------------------------