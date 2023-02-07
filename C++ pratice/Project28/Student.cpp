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

//��椶��
void Student::openMenu() {
	while (true) {
		int select = 0;
		cout << "---�{�b�ϥΪ�: �ǥ� " << this->m_Name << "---\t�Ǹ�:" << this->m_id << endl;
		cout << "\t\t+---------------------------------------+\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          1. ��   ��   �w   ��         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          2. �d �� �� �� �w ��         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          3. �d �� �� �� �w ��         |\t\t" << endl;
		cout << "\t\t|                                       |\t\t" << endl;
		cout << "\t\t|          4. ��   ��   �w   ��         |\t\t" << endl;
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
			//�ӽйw��
			system("cls");
			this->applyOrder();
		}
		else if (select == 2) {
			//�d�ݧڪ��w��
			this->showMyOrder();
		}
		else if (select == 3) {
			//�d�ݩҦ��w��
			this->showAllOrder();
		}
		else if (select == 4) {
			//�����w��
			this->cancelOrder();
		}
		else {
			cout << "��J���~ �Э��s��J" << endl;
			system("pause");
			system("cls");
		}
	}
}

//�ӽйw��
int selectRoom() {
	int select = 0;
	cout << "�п�J�ӽи�T" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          1.   ��    ��    �@          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          2.   ��    ��    �G          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          3.   ��    ��    �T          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cin >> select;
	return select;
}
int selectDay() {
	int select = 0;
	cout << "�п�J�ӽи�T" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          1.   �P    ��    �@          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          2.   �P    ��    �G          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          3.   �P    ��    �T          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          4.   �P    ��    �|          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          5.   �P    ��    ��          |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cin >> select;
	return select;
}
int selectUpDow() {
	int select = 0;
	cout << "�п�J�ӽи�T" << endl;
	cout << "\t\t+---------------------------------------+\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          1.    �W        ��           |\t\t" << endl;
	cout << "\t\t|                                       |\t\t" << endl;
	cout << "\t\t|          2.    �U        ��           |\t\t" << endl;
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
		cout << "��J���~ ���s�ɦV" << endl;
	}
	else {
		cout << "�w�����: �P�� " << daity << endl;
		cout << "�w���Ы�: �Ы� " << room << endl;
		cout << "�w���ɬq: ";
		if (updow == 1) {
			cout << "�W��" << endl;
		}
		else {
			cout << "�U��" << endl;
		}

		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::app);	//�ο�X���覡���}���
		ofs << "Date:" << daity << " ";
		ofs << "Room:" << room << " ";
		ofs << "Interval:" << updow << " ";
		ofs << "StuId:" << this->m_id << " ";
		ofs << "StuName:" << this->m_Name << " ";
		ofs << "Status:" << 1 << endl;
		ofs.close();

		cout << "�w���w�n�O ���ݼf��" << endl;
	}
	system("pause");
	system("cls");
}

//�d�ݧڪ��w��
void Student::showMyOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "�S���w������" << endl;
		system("pause");
		system("cls");
		return;
	}
	//Date:5 Room:3 Interval:2 StuId:10003 StuName:student03 Status:1
	//Date:2 Room:1 Interval:1 StuId:10002 StuName:student02 Status:1
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["StuId"].c_str()) == this->m_id) {
			cout << "�w�����: �P��" << of.m_orderData[i]["Date"];
			cout << "\t\t����: " << of.m_orderData[i]["Room"];
			cout << "\t\t�ɬq: " << (of.m_orderData[i]["Interval"] == "1" ? "�W��" : "�U��") << endl;

			if (of.m_orderData[i]["Status"] == "1") {
				cout << "�w���f�֤�" << endl;

			}else if (of.m_orderData[i]["Status"] == "2") {
				cout << "�w�����\" << endl;
			}
			else if (of.m_orderData[i]["Status"] == "-1") {
				cout << "�f�֥��q�L" << endl;
			}
			else {
				cout << "�w���w����" << endl;
			}
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}

//�d�ݩҦ��w��
void Student::showAllOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "�S���w������" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << "�w������ " << i+1 << endl;
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

//�����w��
void Student::cancelOrder(){
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "�S���w������" << endl;
		system("pause");
		system("cls");
		return;
	}

	int times = 0;
	map<int, int> m;	//key ���Ӿǥ͹w������,  value ���ӵ���Ʃ�m_orderData ����m
	//��ܥثe�Ӿǥͪ��w��
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["StuId"].c_str()) == this->m_id && of.m_orderData[i]["Status"] != "0") {
			times++;
			cout << "�w������ " << times << endl;
			cout << "\t�w�����: �P��" << of.m_orderData[i]["Date"];
			cout << "\t\t����: " << of.m_orderData[i]["Room"];
			cout << "\t\t�ɬq: " << (of.m_orderData[i]["Interval"] == "1" ? "�W��" : "�U��") << endl;

			if (of.m_orderData[i]["Status"] == "1") {
				cout << "\t�w���f�֤�" << endl;

			}
			else if (of.m_orderData[i]["Status"] == "2") {
				cout << "\t�w�����\" << endl;
			}
			else if (of.m_orderData[i]["Status"] == "-1") {
				cout << "\t�f�֥��q�L" << endl;
			}
			m.insert(make_pair(times, i));
		}
	}
	cout << endl;

	//�q�w���e������g�w�����p
	int target;
	cout << "�п�J���ק蠟�w�� �ο�J 0 ��^: ";
	cin >> target;
	if (target > 0 && target <= times) {
		map<int, int>::iterator pos = m.find(target);
		of.m_orderData[pos->second]["Status"] = "0";
		of.updateOrder();
		cout << "�w���{�Ǥw����" << endl;
	}
	else if (target == 0) {
		cout << "�����^" << endl;
	}
	else {
		cout << "��J���~ ���s�ɦV" << endl;
	}
	m.clear();
	cout << endl;


	system("pause");
	system("cls");
}
