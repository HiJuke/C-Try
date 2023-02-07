#include"Manager.h"

Manager::Manager(){}

Manager::Manager(string name, string pwd){
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器
	this->initVector();

	//獲取機房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId, ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "當前機房數量為: " << vCom.size() << endl;
	ifs.close();

}

//初始化
void Manager::initVector() {
	ifstream ifs;

	vStu.clear();
	vTea.clear();

	//學生初始化
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件讀取失敗" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "當前學生數量為 " << vStu.size() << endl;
	ifs.close();

	//教師初始化
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件讀取失敗" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_Empid && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "當前教師數量為 " << vTea.size() << endl;
	ifs.close();
}

//去重	(我用自己的方法寫在添加成員裡了 所以這沒用到)
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_id) {
				return true;
			}
		}
	}
	else if (type == 2) {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_Empid) {
				return true;
			}
		}
	}
	return false;
}

//菜單
void Manager::openMenu(){
	while (true) {
		int select = 0;
		cout << "---現在使用者: 管理員 " << this->m_Name << "---" << endl;
		cout << "\t\t+------------------------------------+\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         1. 添  加  帳  號          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         2. 查  看  帳  號          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         3. 查  看  機  房          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         4. 清  空  預  約          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         0. 註  銷  登  錄          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t+------------------------------------+\t\t" << endl;
		cin >> select;

		if (select == 0) { //退出
			cout << "註銷登錄已順利執行" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == 1) {
			//添加帳號
			system("cls");
			this->addPerson();
		}
		else if (select == 2) {
			//查看帳號
			system("cls");
			this->showPerson();
		}
		else if (select == 3) {
			//查看機房信息
			this->showComputer();
		}
		else if (select == 4) {
			//清空預約紀錄
			this->cleanFile();
		}
		else {
			cout << "輸入錯誤 請重新輸入" << endl;
			system("pause");
			system("cls");
		}
	}
}

//添加帳號
void Manager::addPerson(){
		int select = 0;
		cout << "請輸入添加身分類型" << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          1. 添 加 學 生 帳 號         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          2. 添 加 教 師 帳 號         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          0.   返        回            |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cin >> select;

		if (select == 0) { //退出
			cout << "執行返回" << endl;
			system("pause");
			system("cls");
		}
		else if (select == 1) {
			//添加學生帳號
			int id;
			string name;
			string pwd;

			cout << "請輸入學生學號: ";
			cin >> id;
			cout << "請輸入姓名: ";
			cin >> name;
			cout << "請輸入密碼: ";
			cin >> pwd;

			//檢查是否重複
			int pos = -1;
			string data;
			ifstream ifs(STUDENT_FILE, ios::in);
			while (ifs >> data) {
				if (to_string(id) == data) {
					pos = 1;
				}
			}
			ifs.close();
			if (pos != -1) {
				cout << "此人已登錄於系統內" << endl;
			}
			else {
				ofstream ofs;
				ofs.open(STUDENT_FILE, ios::out | ios::app);	//用輸出的方式打開文件
				ofs << id << " " << name << " " << pwd << endl;

				ofs.close();
				this->initVector();
				cout << "已完成保存" << endl;
			}


			system("pause");
			system("cls");
		}
		else if (select == 2) {
			//添加教師帳號
			int id;
			string name;
			string pwd;

			cout << "請輸入教師職工號: ";
			cin >> id;
			cout << "請輸入姓名: ";
			cin >> name;
			cout << "請輸入密碼: ";
			cin >> pwd;

			//檢查是否重複
			int pos = -1;
			string data;
			ifstream ifs(TEACHER_FILE, ios::in);
			while (ifs >> data) {
				if (to_string(id) == data) {
					pos = 1;
				}
			}
			ifs.close();
			if (pos != -1) {
				cout << "此人已登錄於系統內" << endl;
			}
			else {
				ofstream ofs;
				ofs.open(TEACHER_FILE, ios::out | ios::app);	//用輸出的方式打開文件
				ofs << id << " " << name << " " << pwd << endl;
				
				ofs.close();
				this->initVector();
				cout << "已完成保存" << endl;
			}

			system("pause");
			system("cls");
		}
		else {
			cout << "輸入錯誤 重新導向" << endl;
			system("pause");
			system("cls");
		}

}

//查看帳號
void printStudent(Student& s) {
	cout << "學號: " << s.m_id << "\t姓名: " << s.m_Name << "\t密碼: " << s.m_Pwd << endl;
}
void printTeacher(Teacher& t) {
	cout << "工號: " << t.m_Empid << "\t姓名: " << t.m_Name << "\t密碼: " << t.m_Pwd << endl;
}
void Manager::showPerson(){
	int select = 0;
	cout << "請輸入查看身分類型" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          1. 查 看 學 生 帳 號         |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          2. 查 看 教 師 帳 號         |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          0.   返        回            |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cin >> select;

	if (select == 1) {
		cout << "所有學生信息如下" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2) {
		cout << "所有教師信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	else if (select == 0){
		cout << "執行返回" << endl;
	}
	else {
		cout << "輸入錯誤 重新導向" << endl;
	}
	system("pause");
	system("cls");
}

//查看機房信息
void Manager::showComputer() {
	cout << "顯示機房信息如下" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "機房編號: " << it->m_ComId << "\t機房最大容量: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空預約紀錄
void Manager::cleanFile(){
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "預約清空完成" << endl;
	system("pause");
	system("cls");
}

