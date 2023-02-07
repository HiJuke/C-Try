#include"Student.h"


Student::Student() {

}

Student::Student(int id, string name, string pwd) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	ifs.close();
}

//菜單介面
void Student::openMenu() {
	while (true) {
		int select = 0;
		cout << "---現在使用者: 學生 " << this->m_Name << "---\t學號:" << this->m_id << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          1. 申   請   預   約         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          2. 查 看 我 的 預 約         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          3. 查 看 所 有 預 約         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          4. 取   消   預   約         |\t\t" << endl;
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
			//申請預約
			system("cls");
			this->applyOrder();
		}
		else if (select == 2) {
			//查看我的預約
			this->showMyOrder();
		}
		else if (select == 3) {
			//查看所有預約
			this->showAllOrder();
		}
		else if (select == 4) {
			//取消預約
			this->cancelOrder();
		}
		else {
			cout << "輸入錯誤 請重新輸入" << endl;
			system("pause");
			system("cls");
		}
	}
}

//申請預約
int selectRoom() {
	int select = 0;
	cout << "請輸入申請資訊" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          1.   教    室    一          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          2.   教    室    二          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          3.   教    室    三          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cin >> select;
	return select;
}
int selectDay() {
	int select = 0;
	cout << "請輸入申請資訊" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          1.   星    期    一          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          2.   星    期    二          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          3.   星    期    三          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          4.   星    期    四          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          5.   星    期    五          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cin >> select;
	return select;
}
int selectUpDow() {
	int select = 0;
	cout << "請輸入申請資訊" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          1.    上        午           |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          2.    下        午           |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cin >> select;
	return select;
}
void Student::applyOrder(){
	int daity = selectDay();
	int room = selectRoom();
	int updow = selectUpDow();
	if (room > 3 || room <1 || daity >5 || daity <1 || updow >2 || updow <1) {
		cout << "輸入錯誤 重新導向" << endl;
	}
	else {
		cout << "預約日期: 星期 " << daity << endl;
		cout << "預約教室: 教室 " << room << endl;
		cout << "預約時段: ";
		if (updow == 1) {
			cout << "上午" << endl;
		}
		else {
			cout << "下午" << endl;
		}

		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::app);	//用輸出的方式打開文件
		ofs << "Date:" << daity << " ";
		ofs << "Room:" << room << " ";
		ofs << "Interval:" << updow << " ";
		ofs << "StuId:" << this->m_id << " ";
		ofs << "StuName:" << this->m_Name << " ";
		ofs << "Status:" << 1 << endl;
		ofs.close();

		cout << "預約已登記 等待審核" << endl;
	}
	system("pause");
	system("cls");
}

//查看我的預約
void Student::showMyOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "沒有預約紀錄" << endl;
		system("pause");
		system("cls");
		return;
	}
	//Date:5 Room:3 Interval:2 StuId:10003 StuName:student03 Status:1
	//Date:2 Room:1 Interval:1 StuId:10002 StuName:student02 Status:1
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["StuId"].c_str()) == this->m_id) {
			cout << "預約日期: 星期" << of.m_orderData[i]["Date"];
			cout << "\t\t機房: " << of.m_orderData[i]["Room"];
			cout << "\t\t時段: " << (of.m_orderData[i]["Interval"] == "1" ? "上午" : "下午") << endl;

			if (of.m_orderData[i]["Status"] == "1") {
				cout << "預約審核中" << endl;

			}else if (of.m_orderData[i]["Status"] == "2") {
				cout << "預約成功" << endl;
			}
			else if (of.m_orderData[i]["Status"] == "-1") {
				cout << "審核未通過" << endl;
			}
			else {
				cout << "預約已取消" << endl;
			}
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看所有預約
void Student::showAllOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "沒有預約紀錄" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << "預約筆數 " << i+1 << endl;
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

//取消預約
void Student::cancelOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "沒有預約紀錄" << endl;
		system("pause");
		system("cls");
		return;
	}

	int times = 0;
	map<int, int> m;	//key 為該學生預約筆數,  value 為該筆資料於m_orderData 的位置
	//顯示目前該學生的預約
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["StuId"].c_str()) == this->m_id && of.m_orderData[i]["Status"] != "0") {
			times++;
			cout << "預約筆數 " << times << endl;
			cout << "\t預約日期: 星期" << of.m_orderData[i]["Date"];
			cout << "\t\t機房: " << of.m_orderData[i]["Room"];
			cout << "\t\t時段: " << (of.m_orderData[i]["Interval"] == "1" ? "上午" : "下午") << endl;

			if (of.m_orderData[i]["Status"] == "1") {
				cout << "\t預約審核中" << endl;

			}
			else if (of.m_orderData[i]["Status"] == "2") {
				cout << "\t預約成功" << endl;
			}
			else if (of.m_orderData[i]["Status"] == "-1") {
				cout << "\t審核未通過" << endl;
			}
			m.insert(make_pair(times, i));
		}
	}
	cout << endl;

	//從預約容器中改寫預約狀況
	int target;
	cout << "請輸入欲修改之預約 或輸入 0 返回: ";
	cin >> target;
	if (target > 0 && target <= times) {
		map<int, int>::iterator pos = m.find(target);
		of.m_orderData[pos->second]["Status"] = "0";
		of.updateOrder();
		cout << "預約程序已取消" << endl;
	}
	else if (target == 0) {
		cout << "執行返回" << endl;
	}
	else {
		cout << "輸入有誤 重新導向" << endl;
	}
	m.clear();
	cout << endl;


	system("pause");
	system("cls");
}
