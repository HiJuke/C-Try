#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���

#include "workManager.h"

using namespace std;

//¾�u�޲z�t��
//¾�u���T�� ���� �g�z ���u (����� ¾�u�s�� ¾�u�m�W ¾�u�^�� ¾�u¾�d)
//����¾�d: �޲z�Ҧ��ƪ�
//�g�z¾�d: �������󵹪����� �������ȵ����u
//���u¾�d: �����g�z��������
//------------------------------------------------------
//�ݹ�{�\��
/*
�h�X�޲z�{��
�W�[¾�u�H��
���¾�u�H��
�R����¾¾�u
�ק�¾�u�H��
�d��¾�u�H��
���ӽs���Ƨ�
�M�ũҦ�����
*/
//------------------------------------------------------

WorkerManager::WorkerManager(){
	//�P�_���O�_�s�b
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�p�G��󤣦s�b
	if (!ifs.is_open()) {
		cout << "���|���s�b" << endl;
		this->m_EmpNum = 0;			//��l�ƤH��
		this->m_EmpArray = NULL;	//��l�ƼƲզ�m
		this->m_FileIsEmpty = true;	//��l�Ƥ��O�_���żлx
		ifs.close();
		return;
	}
	//���s�b������
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "���s�b������" << endl;
		this->m_EmpNum = 0;			//��l�ƤH��
		this->m_EmpArray = NULL;	//��l�ƼƲզ�m
		this->m_FileIsEmpty = true;	//��l�Ƥ��O�_���żлx
		ifs.close();
		return;
	}
	//���s�b�B������
	if (!ifs.eof()) {
		cout << "���s�b�B������" << endl;
		int tNUM = this->get_EmuNum();
		cout << "�ثe¾�u��Ƽƶq��: " << tNUM << endl;
		this->m_EmpNum = tNUM;
		//�}�P�ƲժŶ� �N�ƾڦs����ʤ�
		this->m_EmpArray = new Worker * [this->m_EmpNum];
		this->init_Emp();		//�S���W�� �������榹��|�]���S�}�P�Ŷ��X��
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
	cout << "*************************�w��ϥ�¾�u�޲z�t��*************************" << endl;
	cout << "****************************0.�h�X�޲z�{��****************************" << endl;
	cout << "****************************1.�W�[¾�u�H��****************************" << endl;
	cout << "****************************2.���¾�u�H��****************************" << endl;
	cout << "****************************3.�R����¾¾�u****************************" << endl;
	cout << "****************************4.�ק�¾�u�H��****************************" << endl;
	cout << "****************************5.�d��¾�u�H��****************************" << endl;
	cout << "****************************6.���ӽs���Ƨ�****************************" << endl;
	cout << "****************************7.�M�ũҦ�����****************************" << endl;
	cout << "**********************************************************************" << endl;
	cout << "**********************************************************************" << endl;
	cout << "**********************************************************************" << endl;

}

void WorkerManager::exitSystem() {
	cout << "�P�¨ϥΥ��t��" << endl;
	system("pause");
	exit(0);		//�u�n����exit(0) �N�|�����h�X����
}

//--------------------���------------------------------
//�έp�H��
int WorkerManager::get_EmuNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;

	int tempNUM = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		tempNUM++;	//�����H��
	}
	ifs.close();
	return tempNUM;
}

//�O�s���\��
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

//��l�ƭ��u
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = NULL;

		if (did == 1) {	//���u
			worker = new Employee(id, name, did);
		}
		else if (did == 2) {	//�g�z
			worker = new Manager(id, name, did);
		}
		else {	//����
			worker = new Boss(id, name, did);
		}
		//�s�i�Ʋդ�
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//--------------------���------------------------------
//--------------------�\��------------------------------
//1.�W�[¾�u�H��
void WorkerManager::Add_Emp() {
	int AddNum;
	cout << "�п�J���[�J¾�u�ƶq" << endl;
	cin >> AddNum;

	//�K�[
	if (AddNum > 0) {
		//�p��s�Ŷ��j�p
		int newSize = this->m_EmpNum + AddNum;

		//�}�P�s�Ŷ�	�]���ª��Ŷ��i��|������
		Worker** newSpace = new Worker * [newSize];

		//�N��Ŷ����ƾک��s�Ŷ����U
		//�ˬd���ӪŶ��O�_����
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�K�[�s�ƾ�
		for (int i = 0; i < AddNum; i++) {
			int id;
			string name;
			int depertment;
			cout << "�п�J�� "<<i+1<<" ��s���u��ID: " << endl;
			cin >> id;
			cout << "�п�J�� " << i + 1 << " ��s���u���m�W: " << endl;
			cin >> name;
			cout << "�п�ܲ� " << i + 1 << " ��s���u������ID: " << endl;
			cout << "1. ���u" << endl;
			cout << "2. �g�z" << endl;
			cout << "3. ����" << endl;
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

		//����즳�Ŷ�
		delete[] this->m_EmpArray;
		//���s�Ŷ������V
		this->m_EmpArray = newSpace;
		//��s¾�u�H��
		this->m_EmpNum = newSize;
		
		//��s ¾�u������
		this->m_FileIsEmpty = false;

		cout << "�w�K�[ " << AddNum << " �W¾�u" << endl;

		//�O�s�ƾڦܤ��
		this->save();
	}
	else { cout << "��J���~" << endl; }

	cout << endl;
	system("pause");
	system("cls");
}

//2.���¾�u�H��
void WorkerManager::Show_Emp() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//�Q�Φh�A�եα��f
			this->m_EmpArray[i]->showInfo();
		}
	}
	else{ cout << "�ثe�L����¾�u�H��" << endl; }

	cout << endl;
	system("pause");
	system("cls");
} 

//3.�R����¾¾�u
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ΰO������" << endl;
	}
	else {
		cout << "�п�J�n�R�������u" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != (-1)) {
			if (index == this->m_EmpNum - 1) {}
			else {
				for (int i = index; i < this->m_EmpNum - 1; i++) {
					//�ƾګe��
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
			}
			this->m_EmpNum--;

			if (this->m_EmpNum == 0) {
				//����즳�Ŷ�
				delete[] this->m_EmpArray;
			}
			else {
				//�}�P�s�Ŷ�
				Worker** newSpace = new Worker * [this->m_EmpNum];

				//�N��Ŷ����ƾک��s�Ŷ����U
				//�ˬd���ӪŶ��O�_����
				if (this->m_EmpArray != NULL) {
					for (int i = 0; i < this->m_EmpNum; i++) {
						newSpace[i] = this->m_EmpArray[i];
					}
				}

				//����즳�Ŷ�
				delete[] this->m_EmpArray;
				//���s�Ŷ������V
				this->m_EmpArray = newSpace;
			}
			
			cout << "�R������ �{�b�Ѿl���u��: " << this->m_EmpNum << endl;
		}
		else { cout << "�R������ ���M�򦹭��u" << endl; }
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

//4.�ק�¾�u�H��
void WorkerManager::Fix_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ΰO������" << endl;
	}
	else {
		cout << "�п�J�n�ק諸���u" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != (-1)) {
			cout << "�M����ק��Ƥ����u" << endl;
			int Tid;
			string Tname;
			int Tdepertment;
			cout << "�п�J���u�s��ID: " << endl;
			cin >> Tid;
			cout << "�п�J���u�s���m�W: " << endl;
			cin >> Tname;
			cout << "�п�ܭ��u�s������ID: " << endl;
			cout << "1. ���u" << endl;
			cout << "2. �g�z" << endl;
			cout << "3. ����" << endl;
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

			cout << "�ק粒��" << endl;
		}
		else { cout << "�ק異�� ���M�򦹭��u" << endl; }
		this->save();
	}

	cout << endl;
	system("pause");
	system("cls");
}

//5.�d��¾�u�H��
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ΰO������" << endl;
	}
	else {
		cout << "�п�J�n�d�䪺�覡" << endl;
		int select = 0;
		cout << "1.�d�s�� " << endl;
		cout << "2.�d�m�W " << endl;
		cin >> select;
		if (select == 1 || select == 2) {
			if (select == 1) {
				cout << "�п�J�n�ק���uID" << endl;
				int id = 0;
				cin >> id;

				int index = this->IsExist(id);
				if (index != (-1)) {
					cout << "�M����M���Ƥ����u" << endl;
					this->m_EmpArray[index]->showInfo();
				}
				else { cout << "�ק異�� ���M�򦹭��u" << endl; }

			}
			else if (select == 2) {
				cout << "�п�J�n�d����u�m�W" << endl;
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
					cout << "�M����M���Ƥ����u" << endl;
					this->m_EmpArray[TTTid]->showInfo();
				}
				else { cout << "�d�䥢�� ���M�򦹭��u" << endl; }
			}
		}
		else { cout << "��J�L��" << endl; }
	}

	cout << endl;
	system("pause");
	system("cls");
}

//6.���ӽs���Ƨ�
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ΰO������" << endl;
	}
	else {
		cout << "�п�J�n�ƧǪ��覡" << endl;
		int select = 0;
		cout << "1.�s���p��j " << endl;
		cout << "2.�s���j��p " << endl;
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
		else { cout << "��J�L��" << endl; }

		if (select == 1 || select == 2) {
			cout << "�Ƨǵ��G��:" << endl;
			this->save();

			if (this->m_EmpArray != NULL) {
				for (int i = 0; i < this->m_EmpNum; i++) {
					//�Q�Φh�A�եα��f
					this->m_EmpArray[i]->showInfo();
				}
			}
		}
	}


	cout << endl;
	system("pause");
	system("cls");
}

//7.�M�ũҦ�����
void WorkerManager::Clean_File() {
	cout << "�T�w�n�M�Ŷ�?" << endl;
	int select = 0;
	cout << "1.�T�w " << endl;
	cout << "2.��^ " << endl;
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


//--------------------�\��------------------------------