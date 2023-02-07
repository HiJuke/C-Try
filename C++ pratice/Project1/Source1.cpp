#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件

#define MAX 1000

using namespace std;


//聯絡人結構體
struct Person {
	string m_name;	//姓名
	int m_sex;		//性別
	int m_age;		//年齡
	string m_phone;	//電話
	string m_addr;	//地址
};

//通訊錄結構體
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size = 0;	//當前記錄人個數
};


//menu
void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1, 添加聯繫人 *****" << endl;
	cout << "***** 2, 顯示聯繫人 *****" << endl;
	cout << "***** 3, 刪除聯繫人 *****" << endl;
	cout << "***** 4, 查找聯繫人 *****" << endl;
	cout << "***** 5, 修改聯繫人 *****" << endl;
	cout << "***** 6, 清空聯繫人 *****" << endl;
	cout << "***** 0, 退出通訊錄 *****" << endl;
	cout << "*************************" << endl;
}

int Select() {	//選項函數
	int select = 0;	//用戶輸入的變量
	cin >> select;
	//cout << select << endl;
	return select;
}

void AddPerson(Addressbooks* abs) {	//1, 添加聯繫人
	//判斷通訊錄是否已滿
	if (abs->m_Size == MAX) {
		cout << "Book Full. Deny Enter!" << endl;
		return;
	}
	else {
		//添加聯繫人
		//姓名
		cout << "Enter New Person's Name." << endl;
		cin >> abs->personArray[abs->m_Size].m_name;
		//cout << abs->personArray[abs->m_Size].m_name << endl;

		//性別
		while (true) {
			cout << "1--Man" << endl;
			cout << "2--Woman" << endl;
			int sex;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			else {
				cout << "Sex Error. Please Enter Again." << endl;
			}
		}

		//年齡
		cout << "Enter Age" << endl;
		cin >> abs->personArray[abs->m_Size].m_age;

		//電話
		cout << "Enter PhoneNunmber" << endl;
		cin >> abs->personArray[abs->m_Size].m_phone;

		//地址
		cout << "Enter Address" << endl;
		cin >> abs->personArray[abs->m_Size].m_addr;

		abs->m_Size++;
		cout << endl << "Enter Success!" << endl;

		system("Pause");	//請按任意見繼續
		system("cls");		//清空屏幕
	}
}

void ShowPerson(const Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "Nothing in book." << endl;
		return;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			/*string sexx;
			if (abs->personArray[i].m_sex == 1) {
				sexx = "Man   ";
			}
			else {
				sexx = "Woman";
			}*/
			cout << "Name:" << abs->personArray[i].m_name << "\t";
			//cout << "Sex:" << sexx << "\t";
			cout << "Sex:" << (abs->personArray[i].m_sex == 1 ? "Man   " : "Woman ") << "\t";
			cout << "Age:" << abs->personArray[i].m_age << "\t";
			cout << "Phone:" << abs->personArray[i].m_phone << "\t";
			cout << "Address:" << abs->personArray[i].m_addr << endl;
		}
	}

	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs, string name) {	//檢測人名
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_name == name) {
			cout << "Fond..." << endl;
			return i;
		}
	}
	cout << "No Target" << endl;
	return -1;
}

void DeletePerson(Addressbooks* abs) {
	//檢測人名
	string tName;
	cout << "Enter target Name." << endl;
	cin >> tName;
	int nu = isExist(abs, tName);

	if (nu == -1) {}	//無尋獲不執行
	else if (nu != (abs->m_Size - 1)) {	//尋獲且非尾數則刪除由後遞補
		for (int i = nu; i < (abs->m_Size - 1); i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;	//總數-1
		cout << "Delete Success!" << endl;
	}
	else {
		abs->m_Size--;
		cout << "Delete Success!" << endl;
	}

	system("pause");
	system("cls");
}

void LookingPerson(Addressbooks* abs) {
	//檢測人名
	string tName;
	cout << "Enter target Name." << endl;
	cin >> tName;
	int nu = isExist(abs, tName);
	if (nu != -1) {
		cout << "Name:" << abs->personArray[nu].m_name << "\t";
		cout << "Sex:" << (abs->personArray[nu].m_sex == 1 ? "Man   " : "Woman ") << "\t";
		cout << "Age:" << abs->personArray[nu].m_age << "\t";
		cout << "Phone:" << abs->personArray[nu].m_phone << "\t";
		cout << "Address:" << abs->personArray[nu].m_addr << endl;
	}

	system("pause");
	system("cls");
}

void ChangePerson(Addressbooks* abs) {
	//檢測人名
	string tName;
	cout << "Enter target Name." << endl;
	cin >> tName;
	int nu = isExist(abs, tName);

	if (nu == -1) {}	//無尋獲不執行
	else {
		//添加聯繫人
		//姓名
		cout << "Enter New Person's Name." << endl;
		cin >> abs->personArray[nu].m_name;
		//cout << abs->personArray[abs->m_Size].m_name << endl;

		//性別
		while (true) {
			cout << "1--Man" << endl;
			cout << "2--Woman" << endl;
			int sex;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[nu].m_sex = sex;
				break;
			}
			else {
				cout << "Sex Error. Please Enter Again." << endl;
			}
		}

		//年齡
		cout << "Enter Age" << endl;
		cin >> abs->personArray[nu].m_age;

		//電話
		cout << "Enter PhoneNunmber" << endl;
		cin >> abs->personArray[nu].m_phone;

		//地址
		cout << "Enter Address" << endl;
		cin >> abs->personArray[nu].m_addr;

		cout << endl << "Enter Success!" << endl;
	}

	system("pause");
	system("cls");
}

void ClearPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "Clear Success!!" << endl;

	system("pause");
	system("cls");
}

bool CaseSwitch(int select, Addressbooks* abs) {	//選項函數
	//cout << abs << endl;
	switch (select) {
	case 1:	//1, 添加聯繫人
		AddPerson(abs);
		return true;
		break;
	case 2:	//2, 顯示聯繫人
		ShowPerson(abs);
		return true;
		break;
	case 3:	//3, 刪除聯繫人
		DeletePerson(abs);
		return true;
		break;
	case 4:	//4, 查找聯繫人
		LookingPerson(abs);
		return true;
		break;
	case 5:	//5, 修改聯繫人
		ChangePerson(abs);
		return true;
		break;
	case 6:	//6, 清空聯繫人
		ClearPerson(abs);
		return true;
		break;
	case 0:	//0, 退出通訊錄
		cout << "Thank Your Using!!" << endl;
		return false;
		break;
	default:
		break;
	}
}

void Menu() {
	Addressbooks abs;
	abs.m_Size = 0;

	bool con = false;
	do {
		showMenu();
		con = CaseSwitch(Select(), &abs);
		//cout << con << endl;
	} while (con == true);
}


int main() {
	srand((unsigned int)time(NULL));

	Menu();


	system("pause");
	return 0;
}