#include"Teacher.h"


Teacher::Teacher(){}

Teacher::Teacher(int EmpId, string name, string pwd){
	this->m_Empid = EmpId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

//���
void Teacher::openMenu(){
	while (true) {
		int select = 0;
		cout << "---�{�b�ϥΪ�: �Юv " << this->m_Name << "---\t¾�u��:" << this->m_Empid << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          1. �d �� �� �� �w ��         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          2. �f   ��   �w   ��         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          0. ��   �P   �n   ��         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cout << "�п�J�\��" << endl;
		cin >> select;

		if (select == 0) { //�h�X
			cout << "���P�n���w���Q����" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == 1) {
			//�d�ݩҦ��w��
			this->showAllOrder();
		}
		else if (select == 2) {
			//�f�ֹw��
			this->validOrder();
		}
		else {
			cout << "��J���~ �Э��s��J" << endl;
			system("pause");
			system("cls");
		}
	}
}

//�d�ݩҦ��w��
void Teacher::showAllOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "�S���w������" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << "�w������ " << i + 1 << endl;
		cout << "\t�w�����: �P��" << of.m_orderData[i]["Date"];
		cout << "\t\t����: " << of.m_orderData[i]["Room"];
		cout << "\t\t�ɬq: " << (of.m_orderData[i]["Interval"] == "1" ? "�W��" : "�U��") << endl;
		cout << "\t�w���ǥ�: " << of.m_orderData[i]["StuName"];
		cout << "\t\t�Ǹ�: " << of.m_orderData[i]["StuId"] << endl;
		if (of.m_orderData[i]["Status"] == "1") {
			cout << "\t�w���f�֤�" << endl;

		}
		else if (of.m_orderData[i]["Status"] == "2") {
			cout << "\t�w�����\" << endl;
		}
		else if (of.m_orderData[i]["Status"] == "-1") {
			cout << "\t�f�֥��q�L" << endl;
		}
		else {
			cout << "\t�w���w����" << endl;
		}
	}
	cout << endl;
	system("pause");
	system("cls");
}

//�f�ֹw��
void Teacher::validOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "�S���w������" << endl;
		system("pause");
		system("cls");
		return;
	}

	//��ܵ��ݹw��������
	cout << "�ݹw���������p�U" << endl;
	int times = 0;
	map<int, int> m;	//key ���Ӿǥ͹w������,  value ���ӵ���Ʃ�m_orderData ����m
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderData[i]["Status"] == "1") {
			times++;
			cout << "�w������ " << times << endl;
			cout << "\t�w�����: �P��" << of.m_orderData[i]["Date"];
			cout << "\t\t����: " << of.m_orderData[i]["Room"];
			cout << "\t\t�ɬq: " << (of.m_orderData[i]["Interval"] == "1" ? "�W��" : "�U��") << endl;
			cout << "\t�w���f�֤�" << endl;
			m.insert(make_pair(times, i));
		}
	}
	cout << endl;
	//�q�w���e������g�w�����p
	while (true) {
		int target;
		cout << "�п�J���ק蠟�w�� �ο�J 0 ��^: ";
		cin >> target;
		if (target > 0 && target <= times) {
			map<int, int>::iterator pos = m.find(target);
			if (of.m_orderData[pos->second]["Status"] != "1") {
				cout << "�ӹw���w�����f��" << endl;
			}
			else {
				int ret = 0;
				cout << "�п�J��ܵ��G:	1.�q�L		2.���q�L" << endl;
				cin >> ret;
				if (ret == 1) {
					of.m_orderData[pos->second]["Status"] = "2";
				}
				else if (ret == 2) {
					of.m_orderData[pos->second]["Status"] = "-1";
				}
				else {
					cout << "��J���~ ���s�ɦV" << endl;
					break;
				}
			}
		}
		else if (target == 0) {
			cout << "�����^" << endl;
			break;
		}
		else {
			cout << "��J���~ ���s�ɦV" << endl;
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
