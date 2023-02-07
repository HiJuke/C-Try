#include"Manager.h"

Manager::Manager(){}

Manager::Manager(string name, string pwd){
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��l�Ʈe��
	this->initVector();

	//������ЫH��
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId, ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "��e���мƶq��: " << vCom.size() << endl;
	ifs.close();

}

//��l��
void Manager::initVector() {
	ifstream ifs;

	vStu.clear();
	vTea.clear();

	//�ǥͪ�l��
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "���Ū������" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "��e�ǥͼƶq�� " << vStu.size() << endl;
	ifs.close();

	//�Юv��l��
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "���Ū������" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_Empid && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��e�Юv�ƶq�� " << vTea.size() << endl;
	ifs.close();
}

//�h��	(�ڥΦۤv����k�g�b�K�[�����̤F �ҥH�o�S�Ψ�)
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

//���
void Manager::openMenu(){
	while (true) {
		int select = 0;
		cout << "---�{�b�ϥΪ�: �޲z�� " << this->m_Name << "---" << endl;
		cout << "\t\t+------------------------------------+\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         1. �K  �[  �b  ��          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         2. �d  ��  �b  ��          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         3. �d  ��  ��  ��          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         4. �M  ��  �w  ��          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t|         0. ��  �P  �n  ��          |\t\t" << endl;
		cout << "\t\t|                                    |\t\t" << endl;
		cout << "\t\t+------------------------------------+\t\t" << endl;
		cin >> select;

		if (select == 0) { //�h�X
			cout << "���P�n���w���Q����" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == 1) {
			//�K�[�b��
			system("cls");
			this->addPerson();
		}
		else if (select == 2) {
			//�d�ݱb��
			system("cls");
			this->showPerson();
		}
		else if (select == 3) {
			//�d�ݾ��ЫH��
			this->showComputer();
		}
		else if (select == 4) {
			//�M�Źw������
			this->cleanFile();
		}
		else {
			cout << "��J���~ �Э��s��J" << endl;
			system("pause");
			system("cls");
		}
	}
}

//�K�[�b��
void Manager::addPerson(){
		int select = 0;
		cout << "�п�J�K�[��������" << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          1. �K �[ �� �� �b ��         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          2. �K �[ �� �v �b ��         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          0.   ��        �^            |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cin >> select;

		if (select == 0) { //�h�X
			cout << "�����^" << endl;
			system("pause");
			system("cls");
		}
		else if (select == 1) {
			//�K�[�ǥͱb��
			int id;
			string name;
			string pwd;

			cout << "�п�J�ǥ;Ǹ�: ";
			cin >> id;
			cout << "�п�J�m�W: ";
			cin >> name;
			cout << "�п�J�K�X: ";
			cin >> pwd;

			//�ˬd�O�_����
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
				cout << "���H�w�n����t�Τ�" << endl;
			}
			else {
				ofstream ofs;
				ofs.open(STUDENT_FILE, ios::out | ios::app);	//�ο�X���覡���}���
				ofs << id << " " << name << " " << pwd << endl;

				ofs.close();
				this->initVector();
				cout << "�w�����O�s" << endl;
			}


			system("pause");
			system("cls");
		}
		else if (select == 2) {
			//�K�[�Юv�b��
			int id;
			string name;
			string pwd;

			cout << "�п�J�Юv¾�u��: ";
			cin >> id;
			cout << "�п�J�m�W: ";
			cin >> name;
			cout << "�п�J�K�X: ";
			cin >> pwd;

			//�ˬd�O�_����
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
				cout << "���H�w�n����t�Τ�" << endl;
			}
			else {
				ofstream ofs;
				ofs.open(TEACHER_FILE, ios::out | ios::app);	//�ο�X���覡���}���
				ofs << id << " " << name << " " << pwd << endl;
				
				ofs.close();
				this->initVector();
				cout << "�w�����O�s" << endl;
			}

			system("pause");
			system("cls");
		}
		else {
			cout << "��J���~ ���s�ɦV" << endl;
			system("pause");
			system("cls");
		}

}

//�d�ݱb��
void printStudent(Student& s) {
	cout << "�Ǹ�: " << s.m_id << "\t�m�W: " << s.m_Name << "\t�K�X: " << s.m_Pwd << endl;
}
void printTeacher(Teacher& t) {
	cout << "�u��: " << t.m_Empid << "\t�m�W: " << t.m_Name << "\t�K�X: " << t.m_Pwd << endl;
}
void Manager::showPerson(){
	int select = 0;
	cout << "�п�J�d�ݨ�������" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          1. �d �� �� �� �b ��         |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          2. �d �� �� �v �b ��         |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          0.   ��        �^            |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cin >> select;

	if (select == 1) {
		cout << "�Ҧ��ǥͫH���p�U" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2) {
		cout << "�Ҧ��Юv�H���p�U" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	else if (select == 0){
		cout << "�����^" << endl;
	}
	else {
		cout << "��J���~ ���s�ɦV" << endl;
	}
	system("pause");
	system("cls");
}

//�d�ݾ��ЫH��
void Manager::showComputer() {
	cout << "��ܾ��ЫH���p�U" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "���нs��: " << it->m_ComId << "\t���г̤j�e�q: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//�M�Źw������
void Manager::cleanFile(){
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "�w���M�ŧ���" << endl;
	system("pause");
	system("cls");
}

