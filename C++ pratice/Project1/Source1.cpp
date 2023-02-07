#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���

#define MAX 1000

using namespace std;


//�p���H���c��
struct Person {
	string m_name;	//�m�W
	int m_sex;		//�ʧO
	int m_age;		//�~��
	string m_phone;	//�q��
	string m_addr;	//�a�}
};

//�q�T�����c��
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size = 0;	//��e�O���H�Ӽ�
};


//menu
void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1, �K�[�pô�H *****" << endl;
	cout << "***** 2, ����pô�H *****" << endl;
	cout << "***** 3, �R���pô�H *****" << endl;
	cout << "***** 4, �d���pô�H *****" << endl;
	cout << "***** 5, �ק��pô�H *****" << endl;
	cout << "***** 6, �M���pô�H *****" << endl;
	cout << "***** 0, �h�X�q�T�� *****" << endl;
	cout << "*************************" << endl;
}

int Select() {	//�ﶵ���
	int select = 0;	//�Τ��J���ܶq
	cin >> select;
	//cout << select << endl;
	return select;
}

void AddPerson(Addressbooks* abs) {	//1, �K�[�pô�H
	//�P�_�q�T���O�_�w��
	if (abs->m_Size == MAX) {
		cout << "Book Full. Deny Enter!" << endl;
		return;
	}
	else {
		//�K�[�pô�H
		//�m�W
		cout << "Enter New Person's Name." << endl;
		cin >> abs->personArray[abs->m_Size].m_name;
		//cout << abs->personArray[abs->m_Size].m_name << endl;

		//�ʧO
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

		//�~��
		cout << "Enter Age" << endl;
		cin >> abs->personArray[abs->m_Size].m_age;

		//�q��
		cout << "Enter PhoneNunmber" << endl;
		cin >> abs->personArray[abs->m_Size].m_phone;

		//�a�}
		cout << "Enter Address" << endl;
		cin >> abs->personArray[abs->m_Size].m_addr;

		abs->m_Size++;
		cout << endl << "Enter Success!" << endl;

		system("Pause");	//�Ы����N���~��
		system("cls");		//�M�ū̹�
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

int isExist(Addressbooks* abs, string name) {	//�˴��H�W
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
	//�˴��H�W
	string tName;
	cout << "Enter target Name." << endl;
	cin >> tName;
	int nu = isExist(abs, tName);

	if (nu == -1) {}	//�L�M�򤣰���
	else if (nu != (abs->m_Size - 1)) {	//�M��B�D���ƫh�R���ѫỼ��
		for (int i = nu; i < (abs->m_Size - 1); i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;	//�`��-1
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
	//�˴��H�W
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
	//�˴��H�W
	string tName;
	cout << "Enter target Name." << endl;
	cin >> tName;
	int nu = isExist(abs, tName);

	if (nu == -1) {}	//�L�M�򤣰���
	else {
		//�K�[�pô�H
		//�m�W
		cout << "Enter New Person's Name." << endl;
		cin >> abs->personArray[nu].m_name;
		//cout << abs->personArray[abs->m_Size].m_name << endl;

		//�ʧO
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

		//�~��
		cout << "Enter Age" << endl;
		cin >> abs->personArray[nu].m_age;

		//�q��
		cout << "Enter PhoneNunmber" << endl;
		cin >> abs->personArray[nu].m_phone;

		//�a�}
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

bool CaseSwitch(int select, Addressbooks* abs) {	//�ﶵ���
	//cout << abs << endl;
	switch (select) {
	case 1:	//1, �K�[�pô�H
		AddPerson(abs);
		return true;
		break;
	case 2:	//2, ����pô�H
		ShowPerson(abs);
		return true;
		break;
	case 3:	//3, �R���pô�H
		DeletePerson(abs);
		return true;
		break;
	case 4:	//4, �d���pô�H
		LookingPerson(abs);
		return true;
		break;
	case 5:	//5, �ק��pô�H
		ChangePerson(abs);
		return true;
		break;
	case 6:	//6, �M���pô�H
		ClearPerson(abs);
		return true;
		break;
	case 0:	//0, �h�X�q�T��
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