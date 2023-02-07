#include"Teacher.h"


Teacher::Teacher(){}

Teacher::Teacher(int EmpId, string name, string pwd){
	this->m_Empid = EmpId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

//菜單
void Teacher::openMenu(){
	while (true) {
		int select = 0;
		cout << "---現在使用者: 教師 " << this->m_Name << "---\t職工號:" << this->m_Empid << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          1. 查 看 所 有 預 約         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          2. 審   核   預   約         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          0. 註   銷   登   錄         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cout << "請輸入功能" << endl;
		cin >> select;

		if (select == 0) { //退出
			cout << "註銷登錄已順利執行" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == 1) {
			//查看所有預約
			this->showAllOrder();
		}
		else if (select == 2) {
			//審核預約
			this->validOrder();
		}
		else {
			cout << "輸入錯誤 請重新輸入" << endl;
			system("pause");
			system("cls");
		}
	}
}

//查看所有預約
void Teacher::showAllOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "沒有預約紀錄" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << "預約筆數 " << i + 1 << endl;
		cout << "\t預約日期: 星期" << of.m_orderData[i]["Date"];
		cout << "\t\t機房: " << of.m_orderData[i]["Room"];
		cout << "\t\t時段: " << (of.m_orderData[i]["Interval"] == "1" ? "上午" : "下午") << endl;
		cout << "\t預約學生: " << of.m_orderData[i]["StuName"];
		cout << "\t\t學號: " << of.m_orderData[i]["StuId"] << endl;
		if (of.m_orderData[i]["Status"] == "1") {
			cout << "\t預約審核中" << endl;

		}
		else if (of.m_orderData[i]["Status"] == "2") {
			cout << "\t預約成功" << endl;
		}
		else if (of.m_orderData[i]["Status"] == "-1") {
			cout << "\t審核未通過" << endl;
		}
		else {
			cout << "\t預約已取消" << endl;
		}
	}
	cout << endl;
	system("pause");
	system("cls");
}

//審核預約
void Teacher::validOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "沒有預約紀錄" << endl;
		system("pause");
		system("cls");
		return;
	}

	//顯示等待預約的紀錄
	cout << "待預約的紀錄如下" << endl;
	int times = 0;
	map<int, int> m;	//key 為該學生預約筆數,  value 為該筆資料於m_orderData 的位置
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderData[i]["Status"] == "1") {
			times++;
			cout << "預約筆數 " << times << endl;
			cout << "\t預約日期: 星期" << of.m_orderData[i]["Date"];
			cout << "\t\t機房: " << of.m_orderData[i]["Room"];
			cout << "\t\t時段: " << (of.m_orderData[i]["Interval"] == "1" ? "上午" : "下午") << endl;
			cout << "\t預約審核中" << endl;
			m.insert(make_pair(times, i));
		}
	}
	cout << endl;
	//從預約容器中改寫預約狀況
	while (true) {
		int target;
		cout << "請輸入欲修改之預約 或輸入 0 返回: ";
		cin >> target;
		if (target > 0 && target <= times) {
			map<int, int>::iterator pos = m.find(target);
			if (of.m_orderData[pos->second]["Status"] != "1") {
				cout << "該預約已完成審核" << endl;
			}
			else {
				int ret = 0;
				cout << "請輸入選擇結果:	1.通過		2.不通過" << endl;
				cin >> ret;
				if (ret == 1) {
					of.m_orderData[pos->second]["Status"] = "2";
				}
				else if (ret == 2) {
					of.m_orderData[pos->second]["Status"] = "-1";
				}
				else {
					cout << "輸入有誤 重新導向" << endl;
					break;
				}
			}
		}
		else if (target == 0) {
			cout << "執行返回" << endl;
			break;
		}
		else {
			cout << "輸入有誤 重新導向" << endl;
			break;
		}
	}
	of.updateOrder();
	m.clear();
	cout << endl;

	cout << endl;
	system("pause");
	system("cls");
}
